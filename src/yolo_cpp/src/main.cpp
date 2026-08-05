#include "yolo_detect_node.hpp"
#include <rclcpp/rclcpp.hpp>
int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);
    const auto node =std::make_shared<YoloDetectNode>();

    rclcpp::spin(node);
}