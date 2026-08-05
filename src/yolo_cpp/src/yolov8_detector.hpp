#pragma once

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include <onnxruntime_cxx_api.h>

#include <opencv2/core.hpp>


struct Detection
{
  int class_id{-1};

  std::string class_name;

  float confidence{0.0F};

  // 坐标已经恢复到原始图像坐标系
  cv::Rect box;

  cv::Point2f center;
};


class YoloV8Detector
{
public:
  explicit YoloV8Detector(
    const std::string & model_path);
  // 对外接口：输入bgr图像，输出推理结果结构体Detection
  std::vector<Detection> infer(
    const cv::Mat & frame);


private:
  struct LetterboxResult
  {
    cv::Mat image;

    float scale{1.0F};

    int pad_left{0};
    int pad_top{0};
  };

  void validateModelPath() const;

  void loadModel();

  void loadModelMetadata();

  LetterboxResult letterbox(
    const cv::Mat & frame) const;

  cv::Mat createInputBlob(
    const cv::Mat & image) const;

  std::vector<Ort::Value> forward(
    cv::Mat & input_blob);

  std::vector<Detection> postprocess(
    const Ort::Value & output_tensor,
    const LetterboxResult & letterbox_result,
    const cv::Size & original_size) const;

private:
  std::string model_path_;

  /*
   * 成员声明顺序很重要：
   * Env和SessionOptions必须先于Session存在。
   */
  Ort::Env ort_env_;

  Ort::SessionOptions session_options_;

  std::unique_ptr<Ort::Session> session_;

  std::string input_name_;
  std::string output_name_;

  std::vector<std::int64_t> input_shape_;
  std::vector<std::int64_t> output_shape_;

  float confidence_threshold_{0.25F};
  float nms_threshold_{0.45F};
};