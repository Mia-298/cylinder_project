#include <algorithm>
#include <atomic>
#include <chrono>
#include <cctype>
#include <cstdio>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <filesystem>
#include <iomanip>
#include <limits>
#include <memory>
#include <mutex>
#include <sstream>
#include <string>
#include <system_error>
#include <vector>

#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>

#include <cv_bridge/cv_bridge.h>
#include <pcl/PCLPointCloud2.h>
#include <pcl/io/pcd_io.h>
#include <pcl_conversions/pcl_conversions.h>
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/image_encodings.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>

class ImageCaptureNode : public rclcpp::Node
{
public:
  ImageCaptureNode()
  : Node("image_capture_node")
  {
    declareParameters();
    loadParameters();
    validateParameters();

    color_save_directory_ =
      expandHomeDirectory(color_save_directory_);

    depth_save_directory_ =
      expandHomeDirectory(depth_save_directory_);

    pointcloud_save_directory_ =
      expandHomeDirectory(pointcloud_save_directory_);

    std::filesystem::create_directories(
      color_save_directory_);

    std::filesystem::create_directories(
      depth_save_directory_);

    std::filesystem::create_directories(
      pointcloud_save_directory_);

    /*
     * 自动彩色保存模式启用时，允许第一张彩色图像立即保存。
     */
    last_auto_save_time_ =
      std::chrono::steady_clock::now() -
      std::chrono::duration_cast<
      std::chrono::steady_clock::duration>(
      std::chrono::duration<double>(
        interval_sec_));

    /*
     * Orbbec 驱动当前三个发布端均为：
     * RELIABLE + KEEP_LAST(10) + VOLATILE。
     *
     * 这里使用完全相同的 QoS，避免不同 DDS 实现下
     * RELIABLE 发布端与 BEST_EFFORT 订阅端虽然已发现，
     * 但数据未按预期送达的问题。
     */
    const rclcpp::QoS camera_qos =
      rclcpp::QoS(
      rclcpp::KeepLast(10))
      .reliable()
      .durability_volatile();

    color_subscription_ =
      create_subscription<sensor_msgs::msg::Image>(
      color_topic_,
      camera_qos,
      std::bind(
        &ImageCaptureNode::colorCallback,
        this,
        std::placeholders::_1));

    depth_subscription_ =
      create_subscription<sensor_msgs::msg::Image>(
      depth_topic_,
      camera_qos,
      std::bind(
        &ImageCaptureNode::depthCallback,
        this,
        std::placeholders::_1));

    pointcloud_subscription_ =
      create_subscription<sensor_msgs::msg::PointCloud2>(
      pointcloud_topic_,
      camera_qos,
      std::bind(
        &ImageCaptureNode::pointCloudCallback,
        this,
        std::placeholders::_1));

    configureKeyboard();

    diagnostic_timer_ =
      create_wall_timer(
      std::chrono::seconds(1),
      [this]()
      {
        RCLCPP_INFO(
          get_logger(),
          "Receive counters: color=%lu depth=%lu cloud=%lu | "
          "matched publishers: color=%zu depth=%zu cloud=%zu",
          static_cast<unsigned long>(
            color_receive_count_.load()),
          static_cast<unsigned long>(
            depth_receive_count_.load()),
          static_cast<unsigned long>(
            pointcloud_receive_count_.load()),
          color_subscription_->get_publisher_count(),
          depth_subscription_->get_publisher_count(),
          pointcloud_subscription_->get_publisher_count());
      });

    RCLCPP_INFO(
      get_logger(),
      "Color topic: %s",
      color_topic_.c_str());

    RCLCPP_INFO(
      get_logger(),
      "Depth topic: %s",
      depth_topic_.c_str());

    RCLCPP_INFO(
      get_logger(),
      "Point cloud topic: %s",
      pointcloud_topic_.c_str());

    RCLCPP_INFO(
      get_logger(),
      "Color save directory: %s",
      color_save_directory_.c_str());

    RCLCPP_INFO(
      get_logger(),
      "Depth save directory: %s",
      depth_save_directory_.c_str());

    RCLCPP_INFO(
      get_logger(),
      "Point cloud save directory: %s",
      pointcloud_save_directory_.c_str());

    if (auto_save_) {
      RCLCPP_INFO(
        get_logger(),
        "Automatic color capture interval: %.3f s",
        interval_sec_);
    } else {
      RCLCPP_INFO(
        get_logger(),
        "Automatic color capture disabled");
    }

    if (keyboard_available_) {
      RCLCPP_INFO(
        get_logger(),
        "Keyboard: p = save next color frame, "
        "d = save the first color + depth + point cloud messages "
        "received after the key press, q = quit");
    }
  }

  ~ImageCaptureNode() override
  {
    restoreKeyboard();
  }

private:
  void declareParameters()
  {
    declare_parameter<std::string>(
      "color_topic",
      "/camera/color/image_raw");

    declare_parameter<std::string>(
      "depth_topic",
      "/camera/depth/image_raw");

    declare_parameter<std::string>(
      "pointcloud_topic",
      "/camera/depth_registered/points");

    /*
     * 保持彩色图保存目录兼容性。
     */
    declare_parameter<std::string>(
      "save_directory",
      "~/cylinder_dataset/images");

    declare_parameter<std::string>(
      "depth_save_directory",
      "~/cylinder_dataset/depth");

    declare_parameter<std::string>(
      "pointcloud_save_directory",
      "~/cylinder_dataset/pointclouds");

    declare_parameter<bool>(
      "auto_save",
      false);

    declare_parameter<double>(
      "interval_sec",
      0.5);

    declare_parameter<std::string>(
      "image_format",
      "jpg");

    declare_parameter<std::string>(
      "filename_prefix",
      "color");

    declare_parameter<std::string>(
      "depth_filename_prefix",
      "depth");

    declare_parameter<std::string>(
      "pointcloud_filename_prefix",
      "cloud");

    declare_parameter<int>(
      "jpeg_quality",
      95);

    declare_parameter<int>(
      "png_compression",
      3);
  }

  void loadParameters()
  {
    color_topic_ =
      get_parameter("color_topic").as_string();

    depth_topic_ =
      get_parameter("depth_topic").as_string();

    pointcloud_topic_ =
      get_parameter("pointcloud_topic").as_string();

    color_save_directory_ =
      get_parameter("save_directory").as_string();

    depth_save_directory_ =
      get_parameter("depth_save_directory").as_string();

    pointcloud_save_directory_ =
      get_parameter("pointcloud_save_directory").as_string();

    auto_save_ =
      get_parameter("auto_save").as_bool();

    interval_sec_ =
      get_parameter("interval_sec").as_double();

    image_format_ =
      get_parameter("image_format").as_string();

    filename_prefix_ =
      get_parameter("filename_prefix").as_string();

    depth_filename_prefix_ =
      get_parameter("depth_filename_prefix").as_string();

    pointcloud_filename_prefix_ =
      get_parameter("pointcloud_filename_prefix").as_string();

    jpeg_quality_ =
      static_cast<int>(
      get_parameter("jpeg_quality").as_int());

    png_compression_ =
      static_cast<int>(
      get_parameter("png_compression").as_int());

    for (char & character : image_format_) {
      character = static_cast<char>(
        std::tolower(
          static_cast<unsigned char>(character)));
    }
  }

  void validateParameters() const
  {
    if (interval_sec_ <= 0.0) {
      throw std::invalid_argument(
              "interval_sec must be greater than zero");
    }

    if (
      image_format_ != "jpg" &&
      image_format_ != "jpeg" &&
      image_format_ != "png")
    {
      throw std::invalid_argument(
              "image_format must be jpg, jpeg, or png");
    }

    if (jpeg_quality_ < 0 || jpeg_quality_ > 100) {
      throw std::invalid_argument(
              "jpeg_quality must be between 0 and 100");
    }

    if (png_compression_ < 0 || png_compression_ > 9) {
      throw std::invalid_argument(
              "png_compression must be between 0 and 9");
    }
  }

  static std::string expandHomeDirectory(
    const std::string & path)
  {
    if (path.empty() || path.front() != '~') {
      return path;
    }

    const char * home = std::getenv("HOME");

    if (home == nullptr) {
      return path;
    }

    if (path.size() == 1) {
      return std::string(home);
    }

    if (path.size() > 1 && path.at(1) == '/') {
      return std::string(home) + path.substr(1);
    }

    return path;
  }

  void colorCallback(
    const sensor_msgs::msg::Image::ConstSharedPtr message)
  {
    ++color_receive_count_;

    const std::uint64_t color_sequence =
      ++color_sequence_;

    const auto now =
      std::chrono::steady_clock::now();

    const double elapsed_seconds =
      std::chrono::duration<double>(
      now - last_auto_save_time_).count();

    const bool automatic_capture_due =
      auto_save_ &&
      elapsed_seconds >= interval_sec_;

    /*
     * 按一次 p，由下一张到达的彩色帧消费该请求。
     */
    const bool manual_color_capture_requested =
      manual_color_capture_requested_.exchange(false);

    if (
      automatic_capture_due ||
      manual_color_capture_requested)
    {
      if (saveColorImage(
            message,
            "single",
            ++single_color_index_))
      {
        if (automatic_capture_due) {
          last_auto_save_time_ = now;
        }

        RCLCPP_INFO(
          get_logger(),
          "Saved color frame %lu",
          static_cast<unsigned long>(
            color_sequence));
      }
    }

    bool accepted_for_bundle = false;

    {
      std::lock_guard<std::mutex> lock(bundle_mutex_);

      /*
       * 按下 d 后，只锁定第一张到达的彩色图。
       * 后续彩色帧不会覆盖它。
       */
      if (
        bundle_capture_requested_ &&
        captured_color_message_ == nullptr)
      {
        captured_color_message_ = message;
        accepted_for_bundle = true;
      }
    }

    if (accepted_for_bundle) {
      RCLCPP_INFO(
        get_logger(),
        "Captured first color message after d");
    }

    trySaveRequestedBundle();
  }

  void depthCallback(
    const sensor_msgs::msg::Image::ConstSharedPtr message)
  {
    ++depth_receive_count_;

    bool accepted_for_bundle = false;

    {
      std::lock_guard<std::mutex> lock(bundle_mutex_);

      /*
       * 按下 d 后，只锁定第一张到达的深度图。
       */
      if (
        bundle_capture_requested_ &&
        captured_depth_message_ == nullptr)
      {
        captured_depth_message_ = message;
        accepted_for_bundle = true;
      }
    }

    if (accepted_for_bundle) {
      RCLCPP_INFO(
        get_logger(),
        "Captured first depth message after d");
    }

    trySaveRequestedBundle();
  }

  void pointCloudCallback(
    const sensor_msgs::msg::PointCloud2::ConstSharedPtr message)
  {
    ++pointcloud_receive_count_;

    bool accepted_for_bundle = false;

    {
      std::lock_guard<std::mutex> lock(bundle_mutex_);

      /*
       * 按下 d 后，只锁定第一帧到达的点云。
       */
      if (
        bundle_capture_requested_ &&
        captured_pointcloud_message_ == nullptr)
      {
        captured_pointcloud_message_ = message;
        accepted_for_bundle = true;
      }
    }

    if (accepted_for_bundle) {
      RCLCPP_INFO(
        get_logger(),
        "Captured first point cloud message after d");
    }

    trySaveRequestedBundle();
  }

  void requestSynchronizedBundle()
  {
    std::lock_guard<std::mutex> lock(bundle_mutex_);

    /*
     * 每次按 d 都启动一轮全新的采集。
     * 不检查时间戳，也不使用按键前缓存的数据。
     */
    captured_color_message_.reset();
    captured_depth_message_.reset();
    captured_pointcloud_message_.reset();

    bundle_capture_requested_ = true;

    RCLCPP_INFO(
      get_logger(),
      "Color + depth + point cloud capture requested; "
      "waiting for the first message from each topic after d");
  }

  void trySaveRequestedBundle()
  {
    sensor_msgs::msg::Image::ConstSharedPtr color_message;
    sensor_msgs::msg::Image::ConstSharedPtr depth_message;
    sensor_msgs::msg::PointCloud2::ConstSharedPtr pointcloud_message;

    {
      std::lock_guard<std::mutex> lock(bundle_mutex_);

      if (!bundle_capture_requested_) {
        return;
      }

      if (
        captured_color_message_ == nullptr ||
        captured_depth_message_ == nullptr ||
        captured_pointcloud_message_ == nullptr)
      {
        return;
      }

      color_message =
        captured_color_message_;

      depth_message =
        captured_depth_message_;

      pointcloud_message =
        captured_pointcloud_message_;

      /*
       * 一次 d 请求只保存一组数据。
       * 在执行磁盘写入前先关闭本轮请求，防止重复保存。
       */
      bundle_capture_requested_ = false;

      captured_color_message_.reset();
      captured_depth_message_.reset();
      captured_pointcloud_message_.reset();
    }

    const std::uint64_t bundle_index =
      ++bundle_index_;

    if (
      saveSynchronizedBundle(
        color_message,
        depth_message,
        pointcloud_message,
        bundle_index))
    {
      RCLCPP_INFO(
        get_logger(),
        "Saved bundle %06lu using the first color, depth, "
        "and point cloud messages received after d",
        static_cast<unsigned long>(
          bundle_index));
    }
  }

  bool saveColorImage(
    const sensor_msgs::msg::Image::ConstSharedPtr & message,
    const std::string & mode,
    const std::uint64_t image_index)
  {
    try {
      const cv_bridge::CvImageConstPtr cv_image =
        cv_bridge::toCvShare(
        message,
        "bgr8");

      const std::string output_path =
        generateColorOutputPath(
        message->header.stamp,
        mode,
        image_index);

      const bool success =
        cv::imwrite(
        output_path,
        cv_image->image,
        colorWriteParameters());

      if (!success) {
        RCLCPP_ERROR(
          get_logger(),
          "Failed to save color image: %s",
          output_path.c_str());

        return false;
      }

      RCLCPP_INFO(
        get_logger(),
        "Color image: %s",
        output_path.c_str());

      return true;

    } catch (const cv_bridge::Exception & error) {
      RCLCPP_ERROR(
        get_logger(),
        "Color conversion failed: %s",
        error.what());

    } catch (const cv::Exception & error) {
      RCLCPP_ERROR(
        get_logger(),
        "Color image write failed: %s",
        error.what());

    } catch (const std::exception & error) {
      RCLCPP_ERROR(
        get_logger(),
        "Color image saving failed: %s",
        error.what());
    }

    return false;
  }

  bool saveSynchronizedBundle(
    const sensor_msgs::msg::Image::ConstSharedPtr & color_message,
    const sensor_msgs::msg::Image::ConstSharedPtr & depth_message,
    const sensor_msgs::msg::PointCloud2::ConstSharedPtr & pointcloud_message,
    const std::uint64_t bundle_index)
  {
    const std::string color_output_path =
      generateColorOutputPath(
      color_message->header.stamp,
      "bundle",
      bundle_index);

    const std::string depth_output_path =
      generateDepthOutputPath(
      color_message->header.stamp,
      bundle_index);

    const std::string pointcloud_output_path =
      generatePointCloudOutputPath(
      color_message->header.stamp,
      bundle_index);

    try {
      const cv_bridge::CvImageConstPtr color_image =
        cv_bridge::toCvShare(
        color_message,
        "bgr8");

      const cv::Mat depth_image =
        convertDepthForPng(depth_message);

      if (depth_image.empty()) {
        RCLCPP_ERROR(
          get_logger(),
          "Converted depth image is empty");

        return false;
      }

      const bool color_success =
        cv::imwrite(
        color_output_path,
        color_image->image,
        colorWriteParameters());

      if (!color_success) {
        RCLCPP_ERROR(
          get_logger(),
          "Failed to save color image: %s",
          color_output_path.c_str());

        return false;
      }

      const bool depth_success =
        cv::imwrite(
        depth_output_path,
        depth_image,
        {
          cv::IMWRITE_PNG_COMPRESSION,
          png_compression_
        });

      if (!depth_success) {
        RCLCPP_ERROR(
          get_logger(),
          "Failed to save depth image: %s",
          depth_output_path.c_str());

        removeIfExists(color_output_path);
        return false;
      }

      if (!savePointCloud(pointcloud_message, pointcloud_output_path)) {
        removeIfExists(color_output_path);
        removeIfExists(depth_output_path);
        return false;
      }

      RCLCPP_INFO(
        get_logger(),
        "Bundle color: %s",
        color_output_path.c_str());

      RCLCPP_INFO(
        get_logger(),
        "Bundle depth: %s | encoding=%s",
        depth_output_path.c_str(),
        depth_message->encoding.c_str());

      RCLCPP_INFO(
        get_logger(),
        "Bundle point cloud: %s",
        pointcloud_output_path.c_str());

      return true;

    } catch (const cv_bridge::Exception & error) {
      RCLCPP_ERROR(
        get_logger(),
        "Synchronized bundle conversion failed: %s",
        error.what());

    } catch (const cv::Exception & error) {
      RCLCPP_ERROR(
        get_logger(),
        "Synchronized bundle image write failed: %s",
        error.what());

    } catch (const std::exception & error) {
      RCLCPP_ERROR(
        get_logger(),
        "Synchronized bundle saving failed: %s",
        error.what());
    }

    removeIfExists(color_output_path);
    removeIfExists(depth_output_path);
    removeIfExists(pointcloud_output_path);

    return false;
  }

  bool savePointCloud(
    const sensor_msgs::msg::PointCloud2::ConstSharedPtr & message,
    const std::string & output_path) const
  {
    try {
      pcl::PCLPointCloud2 pcl_cloud;

      pcl_conversions::toPCL(
        *message,
        pcl_cloud);

      /*
       * savePCDFileBinary(filename, cloud) 的常用两参数版本
       * 是面向 pcl::PointCloud<PointT> 的函数模板。
       *
       * 当前对象是 pcl::PCLPointCloud2，因此使用 PCDWriter
       * 的 PCLPointCloud2 重载，能够保留 PointCloud2 中的
       * x/y/z、rgb 等现有字段。
       */
      pcl::PCDWriter writer;

      const int result =
        writer.writeBinary(
        output_path,
        pcl_cloud);

      if (result != 0) {
        RCLCPP_ERROR(
          get_logger(),
          "Failed to save point cloud: %s",
          output_path.c_str());

        return false;
      }

      return true;

    } catch (const std::exception & error) {
      RCLCPP_ERROR(
        get_logger(),
        "Point cloud saving failed: %s",
        error.what());

      return false;
    }
  }

  cv::Mat convertDepthForPng(
    const sensor_msgs::msg::Image::ConstSharedPtr & message) const
  {
    /*
     * 常见深度编码为 16UC1。
     * 对于 16UC1/mono16，原始数值直接写入 16 位 PNG，
     * 不做归一化，便于后续恢复每个像素的深度值。
     */
    if (
      message->encoding ==
        sensor_msgs::image_encodings::TYPE_16UC1 ||
      message->encoding ==
        sensor_msgs::image_encodings::MONO16)
    {
      const cv_bridge::CvImageConstPtr depth_image =
        cv_bridge::toCvShare(
        message,
        message->encoding);

      if (depth_image->image.type() != CV_16UC1) {
        throw std::runtime_error(
                "Depth encoding reports 16UC1/mono16, "
                "but OpenCV matrix type is not CV_16UC1");
      }

      return depth_image->image.clone();
    }

    /*
     * 某些驱动使用 32FC1，单位通常为米。
     * 保存前转换为 uint16 毫米，0 表示无效深度。
     */
    if (
      message->encoding ==
      sensor_msgs::image_encodings::TYPE_32FC1)
    {
      const cv_bridge::CvImageConstPtr depth_image =
        cv_bridge::toCvShare(
        message,
        message->encoding);

      if (depth_image->image.type() != CV_32FC1) {
        throw std::runtime_error(
                "Depth encoding reports 32FC1, "
                "but OpenCV matrix type is not CV_32FC1");
      }

      cv::Mat depth_millimeters(
        depth_image->image.rows,
        depth_image->image.cols,
        CV_16UC1,
        cv::Scalar(0));

      for (
        int row = 0;
        row < depth_image->image.rows;
        ++row)
      {
        const float * source_row =
          depth_image->image.ptr<float>(row);

        std::uint16_t * destination_row =
          depth_millimeters.ptr<std::uint16_t>(
          row);

        for (
          int column = 0;
          column < depth_image->image.cols;
          ++column)
        {
          const float depth_meters =
            source_row[column];

          if (
            !std::isfinite(depth_meters) ||
            depth_meters <= 0.0F)
          {
            destination_row[column] = 0;
            continue;
          }

          const double depth_mm =
            static_cast<double>(
            depth_meters) * 1000.0;

          const double clipped_depth_mm =
            std::clamp(
            depth_mm,
            1.0,
            static_cast<double>(
              std::numeric_limits<
              std::uint16_t>::max()));

          destination_row[column] =
            static_cast<std::uint16_t>(
            std::lround(
              clipped_depth_mm));
        }
      }

      return depth_millimeters;
    }

    throw std::runtime_error(
            "Unsupported depth encoding: " +
            message->encoding +
            ". Expected 16UC1, mono16, or 32FC1.");
  }

  std::vector<int> colorWriteParameters() const
  {
    if (
      image_format_ == "jpg" ||
      image_format_ == "jpeg")
    {
      return {
        cv::IMWRITE_JPEG_QUALITY,
        jpeg_quality_
      };
    }

    return {
      cv::IMWRITE_PNG_COMPRESSION,
      png_compression_
    };
  }

  std::string generateColorOutputPath(
    const builtin_interfaces::msg::Time & stamp,
    const std::string & mode,
    const std::uint64_t index) const
  {
    const std::string extension =
      image_format_ == "png" ? "png" : "jpg";

    std::ostringstream filename;

    filename
      << filename_prefix_
      << "_"
      << mode
      << "_"
      << std::setw(6)
      << std::setfill('0')
      << index
      << "_ros_"
      << stamp.sec
      << "_"
      << std::setw(9)
      << std::setfill('0')
      << stamp.nanosec
      << "."
      << extension;

    return (
      std::filesystem::path(
        color_save_directory_) /
      filename.str()).string();
  }

  std::string generateDepthOutputPath(
    const builtin_interfaces::msg::Time & color_stamp,
    const std::uint64_t index) const
  {
    std::ostringstream filename;

    filename
      << depth_filename_prefix_
      << "_bundle_"
      << std::setw(6)
      << std::setfill('0')
      << index
      << "_color_ros_"
      << color_stamp.sec
      << "_"
      << std::setw(9)
      << std::setfill('0')
      << color_stamp.nanosec
      << ".png";

    return (
      std::filesystem::path(
        depth_save_directory_) /
      filename.str()).string();
  }

  std::string generatePointCloudOutputPath(
    const builtin_interfaces::msg::Time & color_stamp,
    const std::uint64_t index) const
  {
    std::ostringstream filename;

    filename
      << pointcloud_filename_prefix_
      << "_bundle_"
      << std::setw(6)
      << std::setfill('0')
      << index
      << "_color_ros_"
      << color_stamp.sec
      << "_"
      << std::setw(9)
      << std::setfill('0')
      << color_stamp.nanosec
      << ".pcd";

    return (
      std::filesystem::path(
        pointcloud_save_directory_) /
      filename.str()).string();
  }

  static void removeIfExists(
    const std::string & path)
  {
    std::error_code error_code;
    std::filesystem::remove(
      path,
      error_code);
  }

  void configureKeyboard()
  {
    if (!isatty(STDIN_FILENO)) {
      RCLCPP_WARN(
        get_logger(),
        "No interactive terminal detected; "
        "keyboard capture is unavailable");

      return;
    }

    if (
      tcgetattr(
        STDIN_FILENO,
        &original_terminal_settings_) != 0)
    {
      RCLCPP_WARN(
        get_logger(),
        "Failed to read terminal settings");

      return;
    }

    termios settings =
      original_terminal_settings_;

    settings.c_lflag &=
      static_cast<tcflag_t>(
      ~(ICANON | ECHO));

    settings.c_cc[VMIN] = 0;
    settings.c_cc[VTIME] = 0;

    if (
      tcsetattr(
        STDIN_FILENO,
        TCSANOW,
        &settings) != 0)
    {
      RCLCPP_WARN(
        get_logger(),
        "Failed to configure terminal");

      return;
    }

    original_file_flags_ =
      fcntl(
      STDIN_FILENO,
      F_GETFL,
      0);

    if (original_file_flags_ < 0) {
      restoreKeyboard();
      return;
    }

    if (
      fcntl(
        STDIN_FILENO,
        F_SETFL,
        original_file_flags_ |
        O_NONBLOCK) < 0)
    {
      restoreKeyboard();
      return;
    }

    keyboard_available_ = true;
    terminal_configured_ = true;

    keyboard_timer_ =
      create_wall_timer(
      std::chrono::milliseconds(50),
      std::bind(
        &ImageCaptureNode::keyboardCallback,
        this));
  }

  void keyboardCallback()
  {
    char key = '\0';

    while (
      read(
        STDIN_FILENO,
        &key,
        1) > 0)
    {
      if (key == 'p' || key == 'P') {
        manual_color_capture_requested_.store(true);

        RCLCPP_INFO(
          get_logger(),
          "Color capture requested; "
          "waiting for next color frame");

      } else if (key == 'd' || key == 'D') {
        requestSynchronizedBundle();

      } else if (key == 'q' || key == 'Q') {
        RCLCPP_INFO(
          get_logger(),
          "Exit requested");

        rclcpp::shutdown();
        return;
      }
    }
  }

  void restoreKeyboard()
  {
    if (!terminal_configured_) {
      return;
    }

    tcsetattr(
      STDIN_FILENO,
      TCSANOW,
      &original_terminal_settings_);

    if (original_file_flags_ >= 0) {
      fcntl(
        STDIN_FILENO,
        F_SETFL,
        original_file_flags_);
    }

    terminal_configured_ = false;
  }

private:
  std::string color_topic_;
  std::string depth_topic_;
  std::string pointcloud_topic_;

  std::string color_save_directory_;
  std::string depth_save_directory_;
  std::string pointcloud_save_directory_;

  std::string image_format_;
  std::string filename_prefix_;
  std::string depth_filename_prefix_;
  std::string pointcloud_filename_prefix_;

  bool auto_save_{false};
  bool keyboard_available_{false};
  bool terminal_configured_{false};

  double interval_sec_{0.5};

  int jpeg_quality_{95};
  int png_compression_{3};

  rclcpp::Subscription<
    sensor_msgs::msg::Image>::SharedPtr
    color_subscription_;

  rclcpp::Subscription<
    sensor_msgs::msg::Image>::SharedPtr
    depth_subscription_;

  rclcpp::Subscription<
    sensor_msgs::msg::PointCloud2>::SharedPtr
    pointcloud_subscription_;

  rclcpp::TimerBase::SharedPtr
    keyboard_timer_;

  rclcpp::TimerBase::SharedPtr
    diagnostic_timer_;

  std::atomic<std::uint64_t>
    color_receive_count_{0};

  std::atomic<std::uint64_t>
    depth_receive_count_{0};

  std::atomic<std::uint64_t>
    pointcloud_receive_count_{0};

  std::atomic<bool>
    manual_color_capture_requested_{false};

  std::atomic<std::uint64_t>
    single_color_index_{0};

  std::atomic<std::uint64_t>
    bundle_index_{0};

  std::chrono::steady_clock::time_point
    last_auto_save_time_;

  /*
   * 以下变量由 bundle_mutex_ 保护。
   * 按下 d 后，每个指针只记录对应话题随后到达的第一条消息。
   */
  std::mutex bundle_mutex_;

  sensor_msgs::msg::Image::ConstSharedPtr
    captured_color_message_;

  sensor_msgs::msg::Image::ConstSharedPtr
    captured_depth_message_;

  sensor_msgs::msg::PointCloud2::ConstSharedPtr
    captured_pointcloud_message_;

  bool bundle_capture_requested_{false};

  std::atomic<std::uint64_t>
    color_sequence_{0};

  termios original_terminal_settings_{};
  int original_file_flags_{-1};
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);

  try {
    const auto node =
      std::make_shared<ImageCaptureNode>();

    rclcpp::spin(node);

  } catch (const std::exception & error) {
    std::fprintf(
      stderr,
      "Node failed: %s\n",
      error.what());
  }

  if (rclcpp::ok()) {
    rclcpp::shutdown();
  }

  return 0;
}