#ifndef __CAMERA_HPP__
#define __CAMERA_HPP__

#include <mutex>

#include "dev/dev_proxy.hpp"
#include "utils/string_util.hpp"

#ifdef HYRMS_ENV
#include "service/id_parser.hpp"
#include "service/state_manager.hpp"
#include "rclcpp_components/component_manager.hpp"
#endif

#include "camera/include/defines/ERROR_CODE.h"

#include "com_interfaces/srv/realsense_cmd_interface.hpp"
#include "com_interfaces/msg/realsense_state.hpp"
#include "camera/include/defines/REALSENSE_COMMAND_ID.h"
#include "com_interfaces/srv/smart_more_cmd_interface.hpp"
#include "com_interfaces/msg/smart_more_state.hpp"
#include "camera/include/defines/SMART_MORE_COMMAND_ID.h"

namespace CameraProxy
{
    using json = nlohmann::json;
    class Realsense : public HySimpleDevProxy<Realsense,
                                              DEVS::RealsenseCmdInterface,
                                              DEVM::RealsenseState>
    {
    public:
        std::string msg;
        Realsense(const std::string &name);
        int32_t connect();
        int32_t disconnect();
        int32_t send_request();

    private:
        std::shared_ptr<DEVS::RealsenseCmdInterface::Request> req_ = std::make_shared<DEVS::RealsenseCmdInterface::Request>();
        std::shared_ptr<DEVS::RealsenseCmdInterface::Response> res_ = std::make_shared<DEVS::RealsenseCmdInterface::Response>();

    public:
        static nlohmann::json state2json(const DEVM::RealsenseState &state);
#ifdef HYRMS_ENV
        static void config_linker_server_impl(std::shared_ptr<CS::LoadNode_Request> req, std::string name);
        static void config_linker_publisher_impl(std::shared_ptr<CS::LoadNode_Request> req, std::string name);
        static std::shared_ptr<HyDevProxy> config_proxy_impl(std::string name);
#endif
    };
    class SmartMore : public HySimpleDevProxy<SmartMore,
                                            DEVS::SmartMoreCmdInterface,
                                            DEVM::SmartMoreState>
    {
    public:
        std::string msg;
        SmartMore(const std::string &name);
        int32_t connect();
        int32_t disconnect();
        int32_t send_msg(const std::string &req, std::string &res);
        int32_t send_request();

    private:
        std::shared_ptr<DEVS::SmartMoreCmdInterface::Request> req_ = std::make_shared<DEVS::SmartMoreCmdInterface::Request>();
        std::shared_ptr<DEVS::SmartMoreCmdInterface::Response> res_ = std::make_shared<DEVS::SmartMoreCmdInterface::Response>();
    public:
        static nlohmann::json state2json(const DEVM::SmartMoreState &state);
#ifdef HYRMS_ENV
        static void config_linker_server_impl(std::shared_ptr<CS::LoadNode_Request> req, std::string name);
        static void config_linker_publisher_impl(std::shared_ptr<CS::LoadNode_Request> req, std::string name);
        static std::shared_ptr<HyDevProxy> config_proxy_impl(std::string name);
#endif
    };
    // DEV_CLASS_INSERT_ANCHOR 用于脚本匹配,追加脚本类
}

#endif
