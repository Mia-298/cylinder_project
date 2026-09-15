#ifndef __SENSOR_HPP__
#define __SENSOR_HPP__

#include "dev/dev_proxy.hpp"
#include "utils/string_util.hpp"

#ifdef HYRMS_ENV
#include "service/id_parser.hpp"
#include "service/state_manager.hpp"
#include "rclcpp_components/component_manager.hpp"
#endif

#include "sensor/include/defines/ERROR_CODE.h"
#include "com_interfaces/srv/rfid_reader_cmd_interface.hpp"
#include "com_interfaces/msg/rfid_reader_state.hpp"
#include "sensor/include/defines/RFID_READER_COMMAND_ID.h"

namespace SensorProxy
{
    using json = nlohmann::json;
    class RfidReader : public HySimpleDevProxy<RfidReader,
                                            DEVS::RfidReaderCmdInterface,
                                            DEVM::RfidReaderState>
    {
    public:
        // 最近一次 service 调用的错误信息。
        std::string msg;
        RfidReader(const std::string &name);
        // 连接/断开设备，对应 linker 的 OpenPort/ClosePort。
        int32_t connect();
        int32_t disconnect();
        // 读取一条标签 ID/EPC，结果通过输出参数返回。
        int32_t ReadID(std::string &id);
        int32_t ReadEPC(std::string &epc);
        // 控制读写器功率和主动读取状态。
        int32_t ChangePower(int power);
        int32_t StartRead();
        int32_t StopRead();
        // 发送当前请求并保存 service 返回的错误信息。
        int32_t send_request();

    private:
        std::shared_ptr<DEVS::RfidReaderCmdInterface::Request> req_ = std::make_shared<DEVS::RfidReaderCmdInterface::Request>();
        std::shared_ptr<DEVS::RfidReaderCmdInterface::Response> res_ = std::make_shared<DEVS::RfidReaderCmdInterface::Response>();
    public:
        static nlohmann::json state2json(const DEVM::RfidReaderState &state);
#ifdef HYRMS_ENV
        static void config_linker_server_impl(std::shared_ptr<CS::LoadNode_Request> req, std::string name);
        static void config_linker_publisher_impl(std::shared_ptr<CS::LoadNode_Request> req, std::string name);
        static std::shared_ptr<HyDevProxy> config_proxy_impl(std::string name);
#endif
    };
    // DEV_CLASS_INSERT_ANCHOR 用于脚本匹配,追加脚本类
}

#endif
