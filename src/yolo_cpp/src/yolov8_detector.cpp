#include "yolov8_detector.hpp"

#include <algorithm>
#include <array>
#include <cmath>
#include <filesystem>
#include <stdexcept>
#include <utility>
#include <limits>
#include <string>
#include <vector>
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>

namespace
{

const std::vector<std::string> &
getCocoClassNames()
{
  static const std::vector<std::string> names{
    "person",
    "bicycle",
    "car",
    "motorcycle",
    "airplane",
    "bus",
    "train",
    "truck",
    "boat",
    "traffic light",
    "fire hydrant",
    "stop sign",
    "parking meter",
    "bench",
    "bird",
    "cat",
    "dog",
    "horse",
    "sheep",
    "cow",
    "elephant",
    "bear",
    "zebra",
    "giraffe",
    "backpack",
    "umbrella",
    "handbag",
    "tie",
    "suitcase",
    "frisbee",
    "skis",
    "snowboard",
    "sports ball",
    "kite",
    "baseball bat",
    "baseball glove",
    "skateboard",
    "surfboard",
    "tennis racket",
    "bottle",
    "wine glass",
    "cup",
    "fork",
    "knife",
    "spoon",
    "bowl",
    "banana",
    "apple",
    "sandwich",
    "orange",
    "broccoli",
    "carrot",
    "hot dog",
    "pizza",
    "donut",
    "cake",
    "chair",
    "couch",
    "potted plant",
    "bed",
    "dining table",
    "toilet",
    "tv",
    "laptop",
    "mouse",
    "remote",
    "keyboard",
    "cell phone",
    "microwave",
    "oven",
    "toaster",
    "sink",
    "refrigerator",
    "book",
    "clock",
    "vase",
    "scissors",
    "teddy bear",
    "hair drier",
    "toothbrush"
  };

  return names;
}


std::string getClassName(
  const int class_id,
  const int class_count)
{
  /*
   * 只有模型确实有80个类别时，
   * 才按照COCO类别解释。
   */
  if (class_count == 80) {
    const auto & names =
      getCocoClassNames();

    if (
      class_id >= 0 &&
      static_cast<std::size_t>(class_id) <
      names.size())
    {
      return names.at(
        static_cast<std::size_t>(class_id));
    }
  }

  /*
   * 自定义模型还没有传入类别名时，
   * 暂时使用class_0、class_1等名称。
   */
  return "class_" +
         std::to_string(class_id);
}

}  // namespace

YoloV8Detector::YoloV8Detector(
  const std::string & model_path)
: model_path_(model_path),
  ort_env_(
    ORT_LOGGING_LEVEL_WARNING,
    "yolov8_detector")
{
  validateModelPath();
  loadModel();
  loadModelMetadata();
}


std::vector<Detection>
YoloV8Detector::infer(
  const cv::Mat & frame)
{
  if (frame.empty()) {
    throw std::runtime_error(
      "Cannot infer an empty image");
  }

  const LetterboxResult letterbox_result =
    letterbox(frame);

  cv::Mat input_blob =
    createInputBlob(letterbox_result.image);

  std::vector<Ort::Value> output_tensors =
    forward(input_blob);

  if (output_tensors.size() != 1) {
    throw std::runtime_error(
      "YOLOv8 model must return exactly one output");
  }

  return postprocess(
    output_tensors.front(),
    letterbox_result,
    frame.size());
}

void YoloV8Detector::validateModelPath() const
{
  if (model_path_.empty()) {
    throw std::runtime_error(
      "Model path is empty");
  }

  if (!std::filesystem::exists(model_path_)) {
    throw std::runtime_error(
      "ONNX model does not exist: " +
      model_path_);
  }

  if (!std::filesystem::is_regular_file(
      model_path_))
  {
    throw std::runtime_error(
      "Model path is not a regular file: " +
      model_path_);
  }

  const std::filesystem::path path(
    model_path_);

  if (path.extension() != ".onnx") {
    throw std::runtime_error(
      "Model must use the .onnx extension");
  }
}


void YoloV8Detector::loadModel()
{
  try {
    session_options_.SetIntraOpNumThreads(1);
    session_options_.SetInterOpNumThreads(1);

    session_options_.SetGraphOptimizationLevel(
      GraphOptimizationLevel::ORT_ENABLE_ALL);

    session_ =
      std::make_unique<Ort::Session>(
        ort_env_,
        model_path_.c_str(),
        session_options_);

  } catch (const Ort::Exception & error) {
    throw std::runtime_error(
      std::string(
        "Failed to load ONNX model: ") +
      error.what());
  }
}
void YoloV8Detector::loadModelMetadata()
{
  if (!session_) {
    throw std::runtime_error(
      "Cannot load model metadata: session is null");
  }

  if (session_->GetInputCount() != 1) {
    throw std::runtime_error(
      "YOLOv8 model must have exactly one input");
  }

  if (session_->GetOutputCount() != 1) {
    throw std::runtime_error(
      "YOLOv8 model must have exactly one output");
  }

  Ort::AllocatorWithDefaultOptions allocator;

  {
    const auto allocated_name =
      session_->GetInputNameAllocated(
        0,
        allocator);

    input_name_ = allocated_name.get();
  }

  {
    const auto allocated_name =
      session_->GetOutputNameAllocated(
        0,
        allocator);

    output_name_ = allocated_name.get();
  }

  const auto input_type_info =
    session_->GetInputTypeInfo(0);

  const auto input_tensor_info =
    input_type_info.GetTensorTypeAndShapeInfo();

  input_shape_ =
    input_tensor_info.GetShape();

  const auto output_type_info =
    session_->GetOutputTypeInfo(0);

  const auto output_tensor_info =
    output_type_info.GetTensorTypeAndShapeInfo();

  output_shape_ =
    output_tensor_info.GetShape();

  if (input_shape_.size() != 4) {
    throw std::runtime_error(
      "YOLOv8 input must have four dimensions");
  }

  if (output_shape_.size() != 3) {
    throw std::runtime_error(
      "YOLOv8 output must have three dimensions");
  }
}

YoloV8Detector::LetterboxResult
YoloV8Detector::letterbox(
  const cv::Mat & frame) const
{
  if (frame.empty()) {
    throw std::runtime_error(
      "Cannot letterbox an empty image");
  }

  const int input_height =
    static_cast<int>(input_shape_.at(2));

  const int input_width =
    static_cast<int>(input_shape_.at(3));

  const float width_scale =
    static_cast<float>(input_width) /
    static_cast<float>(frame.cols);

  const float height_scale =
    static_cast<float>(input_height) /
    static_cast<float>(frame.rows);

  const float scale =
    std::min(width_scale, height_scale);

  const int resized_width =
    static_cast<int>(
      std::round(frame.cols * scale));

  const int resized_height =
    static_cast<int>(
      std::round(frame.rows * scale));

  cv::Mat resized_image;

  cv::resize(
    frame,
    resized_image,
    cv::Size(resized_width, resized_height),
    0.0,
    0.0,
    cv::INTER_LINEAR);

  const int total_padding_width =
    input_width - resized_width;

  const int total_padding_height =
    input_height - resized_height;

  const int pad_left =
    static_cast<int>(
      std::round(
        total_padding_width / 2.0F - 0.1F));

  const int pad_right =
    static_cast<int>(
      std::round(
        total_padding_width / 2.0F + 0.1F));

  const int pad_top =
    static_cast<int>(
      std::round(
        total_padding_height / 2.0F - 0.1F));

  const int pad_bottom =
    static_cast<int>(
      std::round(
        total_padding_height / 2.0F + 0.1F));

  cv::Mat letterboxed_image;

  cv::copyMakeBorder(
    resized_image,
    letterboxed_image,
    pad_top,
    pad_bottom,
    pad_left,
    pad_right,
    cv::BORDER_CONSTANT,
    cv::Scalar(114, 114, 114));

  LetterboxResult result;

  result.image =
    std::move(letterboxed_image);

  result.scale =
    scale;

  result.pad_left =
    pad_left;

  result.pad_top =
    pad_top;

  return result;
}

cv::Mat YoloV8Detector::createInputBlob(
  const cv::Mat & image) const
{
  if (image.empty()) {
    throw std::runtime_error(
      "Cannot create blob from an empty image");
  }

  const int input_height =
    static_cast<int>(input_shape_.at(2));

  const int input_width =
    static_cast<int>(input_shape_.at(3));

  cv::Mat input_blob;

  cv::dnn::blobFromImage(
    image,
    input_blob,
    1.0 / 255.0,
    cv::Size(input_width, input_height),
    cv::Scalar(),
    true,
    false,
    CV_32F);

  if (input_blob.empty()) {
    throw std::runtime_error(
      "OpenCV produced an empty input blob");
  }

  if (!input_blob.isContinuous()) {
    input_blob = input_blob.clone();
  }

  return input_blob;
}

std::vector<Ort::Value>
YoloV8Detector::forward(
  cv::Mat & input_blob)
{
  if (!session_) {
    throw std::runtime_error(
      "Cannot run inference: session is null");
  }

  Ort::MemoryInfo memory_info =
    Ort::MemoryInfo::CreateCpu(
      OrtArenaAllocator,
      OrtMemTypeDefault);

  Ort::Value input_tensor =
    Ort::Value::CreateTensor<float>(
      memory_info,
      input_blob.ptr<float>(),
      input_blob.total(),
      input_shape_.data(),
      input_shape_.size());

  const std::array<const char *, 1>
  input_names{
    input_name_.c_str()
  };

  const std::array<const char *, 1>
  output_names{
    output_name_.c_str()
  };

  return session_->Run(
    Ort::RunOptions{nullptr},
    input_names.data(),
    &input_tensor,
    input_names.size(),
    output_names.data(),
    output_names.size());
}

std::vector<Detection>
YoloV8Detector::postprocess(
  const Ort::Value & output_tensor,
  const LetterboxResult & letterbox_result,
  const cv::Size & original_size) const
{
  /*
   * 1. 基础检查
   */
  if (!output_tensor.IsTensor()) {
    throw std::runtime_error(
      "YOLOv8 output is not a tensor");
  }

  if (
    original_size.width <= 0 ||
    original_size.height <= 0)
  {
    throw std::runtime_error(
      "Original image size is invalid");
  }

  if (letterbox_result.scale <= 0.0F) {
    throw std::runtime_error(
      "Letterbox scale must be positive");
  }

  const auto tensor_info =
    output_tensor.GetTensorTypeAndShapeInfo();

  if (
    tensor_info.GetElementType() !=
    ONNX_TENSOR_ELEMENT_DATA_TYPE_FLOAT)
  {
    throw std::runtime_error(
      "YOLOv8 output tensor must use float32");
  }

  const std::vector<std::int64_t> shape =
    tensor_info.GetShape();

  /*
   * 当前只处理：
   * [batch, attributes, candidates]
   *
   * 例如：
   * [1, 84, 8400]
   */
  if (
    shape.size() != 3 ||
    shape.at(0) != 1)
  {
    throw std::runtime_error(
      "Unexpected YOLOv8 output shape");
  }

  const std::int64_t attribute_count =
    shape.at(1);

  const std::int64_t candidate_count =
    shape.at(2);

  if (attribute_count <= 4) {
    throw std::runtime_error(
      "YOLOv8 output must contain box "
      "coordinates and class scores");
  }

  if (candidate_count <= 0) {
    throw std::runtime_error(
      "YOLOv8 output candidate count "
      "must be positive");
  }

  /*
   * YOLOv8检测输出：
   *
   * 4个边界框参数：
   * center_x
   * center_y
   * width
   * height
   *
   * 其余通道为类别分数。
   */
  const int class_count =
    static_cast<int>(
      attribute_count - 4);

  const float * output_data =
    output_tensor.GetTensorData<float>();

  if (output_data == nullptr) {
    throw std::runtime_error(
      "Failed to access YOLOv8 output data");
  }

  /*
   * 当前模型输入尺寸。
   */
  const float model_width =
    static_cast<float>(
      input_shape_.at(3));

  const float model_height =
    static_cast<float>(
      input_shape_.at(2));

  /*
   * 用于保存置信度过滤后的候选结果。
   *
   * 这些框仍处于模型640×640坐标系。
   */
  std::vector<cv::Rect> candidate_boxes;
  std::vector<float> candidate_scores;
  std::vector<int> candidate_class_ids;

  candidate_boxes.reserve(
    static_cast<std::size_t>(
      candidate_count));

  candidate_scores.reserve(
    static_cast<std::size_t>(
      candidate_count));

  candidate_class_ids.reserve(
    static_cast<std::size_t>(
      candidate_count));

  /*
   * 根据输出布局[channel][candidate]
   * 读取一个数值。
   */
  const auto outputAt =
    [output_data, candidate_count](
      const std::int64_t channel,
      const std::int64_t candidate)
    {
      const std::size_t index =
        static_cast<std::size_t>(
          channel * candidate_count +
          candidate);

      return output_data[index];
    };

  /*
   * 2. 遍历8400个候选框
   */
  for (
    std::int64_t candidate = 0;
    candidate < candidate_count;
    ++candidate)
  {
    /*
     * 找到该候选框最高的类别分数。
     */
    float best_score =
      -std::numeric_limits<float>::infinity();

    int best_class_id = -1;

    for (
      int class_id = 0;
      class_id < class_count;
      ++class_id)
    {
      const float class_score =
        outputAt(
          4 + class_id,
          candidate);

      if (!std::isfinite(class_score)) {
        continue;
      }

      if (class_score > best_score) {
        best_score = class_score;
        best_class_id = class_id;
      }
    }

    /*
     * 没有有效类别，或者置信度过低。
     */
    if (
      best_class_id < 0 ||
      best_score < confidence_threshold_)
    {
      continue;
    }

    /*
     * 读取中心点格式边界框。
     */
    const float center_x =
      outputAt(0, candidate);

    const float center_y =
      outputAt(1, candidate);

    const float width =
      outputAt(2, candidate);

    const float height =
      outputAt(3, candidate);

    if (
      !std::isfinite(center_x) ||
      !std::isfinite(center_y) ||
      !std::isfinite(width) ||
      !std::isfinite(height))
    {
      continue;
    }

    if (width <= 0.0F || height <= 0.0F) {
      continue;
    }

    /*
     * 从中心点格式转换为：
     *
     * left, top, right, bottom
     */
    float left =
      center_x - width * 0.5F;

    float top =
      center_y - height * 0.5F;

    float right =
      center_x + width * 0.5F;

    float bottom =
      center_y + height * 0.5F;

    /*
     * 裁剪到模型输入图像范围。
     */
    left =
      std::clamp(
        left,
        0.0F,
        model_width);

    top =
      std::clamp(
        top,
        0.0F,
        model_height);

    right =
      std::clamp(
        right,
        0.0F,
        model_width);

    bottom =
      std::clamp(
        bottom,
        0.0F,
        model_height);

    if (right <= left || bottom <= top) {
      continue;
    }

    const int box_left =
      static_cast<int>(
        std::floor(left));

    const int box_top =
      static_cast<int>(
        std::floor(top));

    const int box_right =
      static_cast<int>(
        std::ceil(right));

    const int box_bottom =
      static_cast<int>(
        std::ceil(bottom));

    const int box_width =
      box_right - box_left;

    const int box_height =
      box_bottom - box_top;

    if (box_width <= 0 || box_height <= 0) {
      continue;
    }

    candidate_boxes.emplace_back(
      box_left,
      box_top,
      box_width,
      box_height);

    candidate_scores.push_back(
      best_score);

    candidate_class_ids.push_back(
      best_class_id);
  }

  /*
   * 没有任何候选框通过置信度筛选。
   */
  if (candidate_boxes.empty()) {
    return {};
  }

  /*
   * 3. 按类别执行NMS
   *
   * 不能把person和car等不同类别的框
   * 放在同一组中相互抑制。
   */
  std::vector<int> kept_candidate_indices;

  for (
    int class_id = 0;
    class_id < class_count;
    ++class_id)
  {
    std::vector<cv::Rect> class_boxes;
    std::vector<float> class_scores;
    std::vector<int> original_indices;

    for (
      std::size_t index = 0;
      index < candidate_boxes.size();
      ++index)
    {
      if (
        candidate_class_ids.at(index) !=
        class_id)
      {
        continue;
      }

      class_boxes.push_back(
        candidate_boxes.at(index));

      class_scores.push_back(
        candidate_scores.at(index));

      original_indices.push_back(
        static_cast<int>(index));
    }

    if (class_boxes.empty()) {
      continue;
    }

    std::vector<int> local_kept_indices;

    cv::dnn::NMSBoxes(
      class_boxes,
      class_scores,
      confidence_threshold_,
      nms_threshold_,
      local_kept_indices);

    for (
      const int local_index :
      local_kept_indices)
    {
      if (
        local_index < 0 ||
        static_cast<std::size_t>(
          local_index) >=
        original_indices.size())
      {
        continue;
      }

      kept_candidate_indices.push_back(
        original_indices.at(
          static_cast<std::size_t>(
            local_index)));
    }
  }

  /*
   * OpenCV的NMSBoxes接收边界框、分数、
   * 分数阈值和NMS阈值，并返回保留框索引。
   */
  std::vector<Detection> detections;

  detections.reserve(
    kept_candidate_indices.size());

  /*
   * 4. 将NMS后的框恢复到原始图像坐标
   */
  for (
    const int candidate_index :
    kept_candidate_indices)
  {
    if (
      candidate_index < 0 ||
      static_cast<std::size_t>(
        candidate_index) >=
      candidate_boxes.size())
    {
      continue;
    }

    const cv::Rect & model_box =
      candidate_boxes.at(
        static_cast<std::size_t>(
          candidate_index));

    /*
     * 先移除letterbox填充，
     * 再除以缩放比例。
     */
    float original_left =
      (
        static_cast<float>(
          model_box.x) -
        static_cast<float>(
          letterbox_result.pad_left)
      ) /
      letterbox_result.scale;

    float original_top =
      (
        static_cast<float>(
          model_box.y) -
        static_cast<float>(
          letterbox_result.pad_top)
      ) /
      letterbox_result.scale;

    float original_right =
      (
        static_cast<float>(
          model_box.x +
          model_box.width) -
        static_cast<float>(
          letterbox_result.pad_left)
      ) /
      letterbox_result.scale;

    float original_bottom =
      (
        static_cast<float>(
          model_box.y +
          model_box.height) -
        static_cast<float>(
          letterbox_result.pad_top)
      ) /
      letterbox_result.scale;

    /*
     * 裁剪到原始图像范围。
     */
    original_left =
      std::clamp(
        original_left,
        0.0F,
        static_cast<float>(
          original_size.width));

    original_top =
      std::clamp(
        original_top,
        0.0F,
        static_cast<float>(
          original_size.height));

    original_right =
      std::clamp(
        original_right,
        0.0F,
        static_cast<float>(
          original_size.width));

    original_bottom =
      std::clamp(
        original_bottom,
        0.0F,
        static_cast<float>(
          original_size.height));

    if (
      original_right <= original_left ||
      original_bottom <= original_top)
    {
      continue;
    }

    int left =
      static_cast<int>(
        std::floor(original_left));

    int top =
      static_cast<int>(
        std::floor(original_top));

    int right =
      static_cast<int>(
        std::ceil(original_right));

    int bottom =
      static_cast<int>(
        std::ceil(original_bottom));

    left =
      std::clamp(
        left,
        0,
        original_size.width - 1);

    top =
      std::clamp(
        top,
        0,
        original_size.height - 1);

    right =
      std::clamp(
        right,
        0,
        original_size.width);

    bottom =
      std::clamp(
        bottom,
        0,
        original_size.height);

    const int final_width =
      right - left;

    const int final_height =
      bottom - top;

    if (
      final_width <= 0 ||
      final_height <= 0)
    {
      continue;
    }

    const int class_id =
      candidate_class_ids.at(
        static_cast<std::size_t>(
          candidate_index));

    Detection detection;

    detection.class_id =
      class_id;

    detection.class_name =
      getClassName(
        class_id,
        class_count);

    detection.confidence =
      candidate_scores.at(
        static_cast<std::size_t>(
          candidate_index));

    detection.box =
      cv::Rect(
        left,
        top,
        final_width,
        final_height);

    detection.center =
      cv::Point2f(
        (
          original_left +
          original_right
        ) * 0.5F,
        (
          original_top +
          original_bottom
        ) * 0.5F);

    detections.push_back(
      std::move(detection));
  }

  /*
   * 5. 按置信度从高到低排列
   */
  std::sort(
    detections.begin(),
    detections.end(),
    [](
      const Detection & left,
      const Detection & right)
    {
      return
        left.confidence >
        right.confidence;
    });

  return detections;
}