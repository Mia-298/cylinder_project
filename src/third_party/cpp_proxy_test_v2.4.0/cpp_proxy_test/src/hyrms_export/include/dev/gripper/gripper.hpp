#ifndef __GRIPPER_HPP__
#define __GRIPPER_HPP__

#include "dev/dev_proxy.hpp"
#include "utils/string_util.hpp"

#ifdef HYRMS_ENV
#include "service/id_parser.hpp"
#include "service/state_manager.hpp"
#include "rclcpp_components/component_manager.hpp"
#endif

#include "gripper/include/defines/ERROR_CODE.h"
#include "com_interfaces/srv/rm_ceu_cmd_interface.hpp"
#include "com_interfaces/msg/rm_ceu_state.hpp"
#include "gripper/include/defines/RM_CEU_COMMAND_ID.h"

namespace GripperProxy
{
    using json = nlohmann::json;
    class RmCeu : public HySimpleDevProxy<RmCeu,
                                            DEVS::RmCeuCmdInterface,
                                            DEVM::RmCeuState>
    {
    public:
        std::string msg;
        RmCeu(const std::string &name);
        int32_t connect();
        int32_t disconnect();
        int32_t goPoint(int32_t point);
        int32_t send_request();

    private:
        std::shared_ptr<DEVS::RmCeuCmdInterface::Request> req_ = std::make_shared<DEVS::RmCeuCmdInterface::Request>();
        std::shared_ptr<DEVS::RmCeuCmdInterface::Response> res_ = std::make_shared<DEVS::RmCeuCmdInterface::Response>();
    public:
        static nlohmann::json state2json(const DEVM::RmCeuState &state);
#ifdef HYRMS_ENV
        static void config_linker_server_impl(std::shared_ptr<CS::LoadNode_Request> req, std::string name);
        static void config_linker_publisher_impl(std::shared_ptr<CS::LoadNode_Request> req, std::string name);
        static std::shared_ptr<HyDevProxy> config_proxy_impl(std::string name);
#endif
    };
    // DEV_CLASS_INSERT_ANCHOR 用于脚本匹配,追加脚本类
}

#endif
