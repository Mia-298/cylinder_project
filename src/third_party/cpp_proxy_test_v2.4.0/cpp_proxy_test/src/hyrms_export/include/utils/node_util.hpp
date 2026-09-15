#pragma once

#include "rclcpp/rclcpp.hpp"

namespace node_util
{
    // 查找网络上有没有同名的节点
    inline bool find_name(const std::shared_ptr<rclcpp::Node> &node,
                          const std::string &name)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        auto node_names = node->get_node_names();

        for (const auto &node_name : node_names)
        {
            if (node_name.find(name) != std::string::npos)
            {
                return true;
            }
        }

        return false;
    }

    // 生成新节点名,自动退让函数
    inline std::string get_unique_name(const std::shared_ptr<rclcpp::Node> &node, std::string base_name)
    {
        // 获取网络上所有节点名
        auto node_names = node->get_node_names();

        int max_index = 0;
        for (const auto &name : node_names)
        {
            std::cout << name << std::endl;
            if (name.find(base_name) == 1)
            {
                std::cout << "找到basename" << base_name << std::endl;
                std::string suffix = name.substr(base_name.size() + 1);
                try
                {
                    int index = std::stoi(suffix);
                    if (index > max_index)
                        max_index = index;
                }
                catch (...)
                {
                    continue;
                }
            }
        }

        int next_index = max_index + 1;
        std::ostringstream oss;
        oss << base_name << std::setw(4) << std::setfill('0') << next_index;

        return oss.str();
    }
}
