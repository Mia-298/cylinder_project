#include <rclcpp/rclcpp.hpp>
#include "dev/virt/virt.hpp"
#include "dev/robot/robot.hpp"
int main(int argc, char **argv)
{
    std::string project_id = "tmp"; //引入sdk项目的名称

    rclcpp::init(argc, argv);
    // std::string dev_id = "vitDev0001";  //设备唯一id
    // using DevType = VirtProxy::VirtDev; //设备类型

    std::string dev_id = "robAub0001";     //设备唯一id
    using DevType = RobotProxy::AuboRobot; //设备类型

    auto dev = std::make_shared<DevType>(dev_id + "_proxy_" + project_id);
    //该设备的生命周期由引入sdk的项目决定,需要手动spin
    rclcpp::executors::SingleThreadedExecutor executor;
    std::thread spin_thread1([&executor]()
                             { executor.spin(); });
    executor.add_node(dev);
    if (dev->connect() == 0)
    {
        std::cout << "连接成功" << std::endl;
        dev->disconnect();
    }
    else
    {
        std::cout << "连接失败" << std::endl;
    }

    return 0;
}