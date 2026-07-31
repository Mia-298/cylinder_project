#include <atomic>
#include <chrono>
#include <cstdlib>
#include <filesystem>
#include <iomanip>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

#include <opencv2/imgcodecs.hpp>

#include <cv_bridge/cv_bridge.h>
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>

class ImageCaptureNode : public rclcpp::Node
{
public:
  ImageCaptureNode()
  : Node("image_capture_node")
  {
    declareParameters();
    loadParameters();
    validateParameters();

    save_directory_ = expandHomeDirectory(save_directory_);
    std::filesystem::create_directories(save_directory_);

    /*
     * 第一张收到的图像可以立即保存。
     */
    last_auto_save_time_ =
      std::chrono::steady_clock::now() -
      std::chrono::duration_cast<std::chrono::steady_clock::duration>(
      std::chrono::duration<double>(interval_sec_));

    image_subscription_ =
      create_subscription<sensor_msgs::msg::Image>(
      image_topic_,
      rclcpp::SensorDataQoS(),
      std::bind(
        &ImageCaptureNode::imageCallback,
        this,
        std::placeholders::_1));

    configureKeyboard();

    RCLCPP_INFO(
      get_logger(),
      "Subscribed topic: %s",
      image_topic_.c_str());

    RCLCPP_INFO(
      get_logger(),
      "Save directory: %s",
      save_directory_.c_str());

    if (auto_save_) {
      RCLCPP_INFO(
        get_logger(),
        "Automatic capture interval: %.3f s",
        interval_sec_);
    } else {
      RCLCPP_INFO(
        get_logger(),
        "Automatic capture disabled");
    }

    if (keyboard_available_) {
      RCLCPP_INFO(
        get_logger(),
        "Press p to save the next received frame, q to quit");
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
      "image_topic",
      "/camera/color/image_raw");

    declare_parameter<std::string>(
      "save_directory",
      "~/cylinder_dataset/images");

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

    declare_parameter<int>(
      "jpeg_quality",
      95);

    declare_parameter<int>(
      "png_compression",
      3);
  }

  void loadParameters()
  {
    image_topic_ =
      get_parameter("image_topic").as_string();

    save_directory_ =
      get_parameter("save_directory").as_string();

    auto_save_ =
      get_parameter("auto_save").as_bool();

    interval_sec_ =
      get_parameter("interval_sec").as_double();

    image_format_ =
      get_parameter("image_format").as_string();

    filename_prefix_ =
      get_parameter("filename_prefix").as_string();

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

  void validateParameters()
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

  void imageCallback(
    const sensor_msgs::msg::Image::ConstSharedPtr message)
  {
    ++received_frame_count_;

    const auto now = std::chrono::steady_clock::now();

    const double elapsed_seconds =
      std::chrono::duration<double>(
      now - last_auto_save_time_).count();

    const bool automatic_capture_due =
      auto_save_ && elapsed_seconds >= interval_sec_;

    /*
     * exchange(false)：
     * 读取当前按键请求，同时清除请求。
     *
     * 因此按一次 p，只会保存下一张收到的图像。
     */
    const bool manual_capture_requested =
      manual_capture_requested_.exchange(false);

    if (!automatic_capture_due &&
      !manual_capture_requested)
    {
      return;
    }

    try {
      /*
       * 当前回调对应的 message 就是新收到的图像。
       * 不再从共享缓存中读取旧帧。
       */
      const cv_bridge::CvImageConstPtr cv_image =
        cv_bridge::toCvShare(message, "bgr8");

      const std::string output_path =
        generateOutputPath(message->header.stamp);

      std::vector<int> write_parameters;

      if (
        image_format_ == "jpg" ||
        image_format_ == "jpeg")
      {
        write_parameters = {
          cv::IMWRITE_JPEG_QUALITY,
          jpeg_quality_
        };
      } else {
        write_parameters = {
          cv::IMWRITE_PNG_COMPRESSION,
          png_compression_
        };
      }

      const bool success =
        cv::imwrite(
        output_path,
        cv_image->image,
        write_parameters);

      if (!success) {
        RCLCPP_ERROR(
          get_logger(),
          "Failed to save image: %s",
          output_path.c_str());

        return;
      }

      ++saved_image_count_;

      /*
       * 自动触发成功后更新时间。
       * 手动触发不会改变自动采集周期。
       */
      if (automatic_capture_due) {
        last_auto_save_time_ = now;
      }

      RCLCPP_INFO(
        get_logger(),
        "Saved frame %lu -> %s | ROS stamp: %d.%09u",
        static_cast<unsigned long>(received_frame_count_),
        output_path.c_str(),
        message->header.stamp.sec,
        message->header.stamp.nanosec);

    } catch (const cv_bridge::Exception & error) {
      RCLCPP_ERROR(
        get_logger(),
        "cv_bridge conversion failed: %s",
        error.what());

    } catch (const cv::Exception & error) {
      RCLCPP_ERROR(
        get_logger(),
        "OpenCV error: %s",
        error.what());

    } catch (const std::exception & error) {
      RCLCPP_ERROR(
        get_logger(),
        "Image saving failed: %s",
        error.what());
    }
  }

  std::string generateOutputPath(
    const builtin_interfaces::msg::Time & ros_stamp)
  {
    const std::uint64_t image_index =
      ++image_index_;

    const std::string extension =
      image_format_ == "png" ? "png" : "jpg";

    std::ostringstream filename;

    filename
      << filename_prefix_
      << "_"
      << std::setw(6)
      << std::setfill('0')
      << image_index
      << "_ros_"
      << ros_stamp.sec
      << "_"
      << std::setw(9)
      << std::setfill('0')
      << ros_stamp.nanosec
      << "."
      << extension;

    return (
      std::filesystem::path(save_directory_) /
      filename.str()).string();
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

    /*
     * 关闭规范输入和字符回显。
     * 保留 ISIG，因此 Ctrl+C 仍然有效。
     */
    settings.c_lflag &=
      static_cast<tcflag_t>(~(ICANON | ECHO));

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
      fcntl(STDIN_FILENO, F_GETFL, 0);

    if (original_file_flags_ < 0) {
      restoreKeyboard();
      return;
    }

    if (
      fcntl(
        STDIN_FILENO,
        F_SETFL,
        original_file_flags_ | O_NONBLOCK) < 0)
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

    while (read(STDIN_FILENO, &key, 1) > 0) {
      if (key == 'p' || key == 'P') {
        /*
         * 不立即保存缓存图像。
         * 请求图像回调保存下一帧。
         */
        manual_capture_requested_.store(true);

        RCLCPP_INFO(
          get_logger(),
          "Manual capture requested; "
          "waiting for the next image frame");

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
  std::string image_topic_;
  std::string save_directory_;
  std::string image_format_;
  std::string filename_prefix_;

  bool auto_save_{true};
  bool keyboard_available_{false};
  bool terminal_configured_{false};

  double interval_sec_{0.5};

  int jpeg_quality_{95};
  int png_compression_{3};

  rclcpp::Subscription<
    sensor_msgs::msg::Image>::SharedPtr
    image_subscription_;

  rclcpp::TimerBase::SharedPtr
    keyboard_timer_;

  std::atomic<bool>
    manual_capture_requested_{false};

  std::atomic<std::uint64_t>
    received_frame_count_{0};

  std::atomic<std::uint64_t>
    saved_image_count_{0};

  std::atomic<std::uint64_t>
    image_index_{0};

  std::chrono::steady_clock::time_point
    last_auto_save_time_;

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