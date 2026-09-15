#ifndef __PLC_HPP__
#define __PLC_HPP__

#include "dev/dev_proxy.hpp"
#include "utils/string_util.hpp"

#ifdef HYRMS_ENV
#include "service/id_parser.hpp"
#include "service/state_manager.hpp"
#include "rclcpp_components/component_manager.hpp"
#endif

#include "plc/include/defines/ERROR_CODE.h"

#include "com_interfaces/srv/siemens_plc_cmd_interface.hpp"
#include "com_interfaces/msg/siemens_plc_state.hpp"
#include "plc/include/defines/SIEMENS_PLC_COMMAND_ID.h"

namespace PlcProxy
{
    using json = nlohmann::json;
    class SiemensPlc : public HySimpleDevProxy<SiemensPlc,
                                               DEVS::SiemensPlcCmdInterface,
                                               DEVM::SiemensPlcState>
    {
    public:
        std::string msg;
        SiemensPlc(const std::string &name);
        int32_t connect();
        int32_t disconnect();
        int32_t writeDO(uint16_t pin, uint8_t state);
        int32_t readDO(uint16_t pin, uint8_t *state);
        int32_t readDI(uint16_t pin, uint8_t *state);
        int32_t send_request();

    private:
        std::shared_ptr<DEVS::SiemensPlcCmdInterface::Request> req_ = std::make_shared<DEVS::SiemensPlcCmdInterface::Request>();
        std::shared_ptr<DEVS::SiemensPlcCmdInterface::Response> res_ = std::make_shared<DEVS::SiemensPlcCmdInterface::Response>();

    public:
        static nlohmann::json state2json(const DEVM::SiemensPlcState &state);
#ifdef HYRMS_ENV
        static void config_linker_server_impl(std::shared_ptr<CS::LoadNode_Request> req, std::string name);
        static void config_linker_publisher_impl(std::shared_ptr<CS::LoadNode_Request> req, std::string name);
        static std::shared_ptr<HyDevProxy> config_proxy_impl(std::string name);
#endif
    };
    // DEV_CLASS_INSERT_ANCHOR 用于脚本匹配,追加脚本类
}

#endif
