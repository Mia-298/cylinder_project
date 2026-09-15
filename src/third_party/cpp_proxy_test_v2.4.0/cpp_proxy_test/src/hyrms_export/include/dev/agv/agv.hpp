#ifndef __AGV_HPP__
#define __AGV_HPP__

#include "dev/dev_proxy.hpp"
#include "utils/string_util.hpp"

#ifdef HYRMS_ENV
#include "service/id_parser.hpp"
#include "service/state_manager.hpp"
#include "rclcpp_components/component_manager.hpp"
#endif

#include "agv/include/defines/ERROR_CODE.h"

#include "com_interfaces/msg/agv_station.hpp"
#include "com_interfaces/msg/agv_control.hpp"
#include "com_interfaces/msg/agv_loc.hpp"
#include "com_interfaces/srv/seer_ctrl_cmd_interface.hpp"
#include "com_interfaces/msg/seer_ctrl_state.hpp"
#include "agv/include/defines/SEER_CTRL_COMMAND_ID.h"
#include "com_interfaces/srv/seer_m4_cmd_interface.hpp"
#include "com_interfaces/msg/seer_m4_state.hpp"
#include "com_interfaces/msg/agv_order_state.hpp"
#include "agv/include/defines/SEER_M4_COMMAND_ID.h"

namespace AgvProxy
{
    using json = nlohmann::json;
    class SeerCtrl : public HySimpleDevProxy<SeerCtrl,
                                             DEVS::SeerCtrlCmdInterface,
                                             DEVM::SeerCtrlState>
    {
    public:
        std::string msg;
        int task_status;            // 导航状态 0 = NONE, 1 = WAITING(目前不可能出现该状态), 2 = RUNNING, 3 = SUSPENDED, 4 = COMPLETED, 5 = FAILED, 6 = CANCELED
        int task_type;              // 导航类型 0 = 没有导航, 1 = 自由导航到任意点, 2 = 自由导航到站点, 3 = 路径导航到站点, 7 = 平动转动, 100 = 其他
        std::string target_station; // 导航目标站点

        DEVM::AgvStation current_station;
        std::vector<DEVM::AgvStation> station_list;
        DEVM::AgvControl control;
        DEVM::AgvLoc loc;
        SeerCtrl(const std::string &name);
        int32_t connect();
        int32_t disconnect();

        /**
         * @brief 导航到站点
         * @param [in] station 要导航到的站点
         * @return 返回0为执行成功,其余值为错误码
         */
        int guideGoTarget(std::string station);

        /**
         * @brief 导航到一系列站点
         * @param [in] station_list 要导航到的站点列表,按照顺序导航
         * @return 返回0为执行成功,其余值为错误码
         */
        int guideGoTargetList(std::vector<std::string> station_list);

        /**
         * @brief 暂停导航
         * @return 返回0为执行成功,其余值为错误码
         */
        int guidePause();

        /**
         * @brief 继续导航
         * @return 返回0为执行成功,其余值为错误码
         */
        int guideContinue();

        /**
         * @brief 取消导航
         * @return 返回0为执行成功,其余值为错误码
         */
        int guideCancel();

        /**
         * @brief 查询当前导航任务状态
         * @return 返回0为执行成功,其余值为错误码
         * @note  修改的公有成员变量(在下一次请求前保留)：
         *        - task_status      导航状态
         *              0 NONE        无任务
         *              1 WAITING     等待中（当前不会出现）
         *              2 RUNNING     执行中
         *              3 SUSPENDED   暂停
         *              4 COMPLETED   已完成
         *              5 FAILED      失败
         *              6 CANCELED    已取消
         *        - task_type        导航类型
         *              0 NONE              无导航
         *              1 FREE_POINT        自由导航到任意点
         *              2 FREE_STATION      自由导航到站点
         *              3 PATH_STATION      路径导航到站点
         *              7 MOVE_ROTATE       平动+转动
         *              100 OTHER           其他
         *        - target_station  目标站点名称
         */
        int checkGuide();

        /**
         * @brief 查询已知的所有站点信息
         * @return 返回0为执行成功,其余值为错误码
         * @note  修改的公有成员变量(在下一次请求前保留)：
         *        - station_list 站点信息列表
         */
        int checkStation();
        int checkLoc();

        int acquireControl();
        int releaseControl();
        int checkControl();

        /**
         * @brief 手动操控小车（开环速度控制）
         * 说明：
         * 该接口用于直接下发机器人底盘速度指令（vx, vy, w）。
         * @param x  对应 vx，机器人坐标系下 x 轴方向线速度,单位 m/s ,x+ 前进
         * @param y  对应 vy，机器人坐标系下 y 轴方向线速度,单位 m/s
         * @param w  机器人坐标系下角速度，单位 rad/s
         *           约定：逆时针为正，顺时针为负
         * @param duration  速度持续时间，单位 ms
         *                      0：一直保持当前速度（直到下次指令）
         *                      >0：持续指定时间后停止
         */
        int startManualCtrl(float x, float y, float w, int duration);

        /**
         * @brief 停止手动操控小车,小车得先停止手动操作模式,才能进行导航
         */
        int stopManualCtrl();

        int32_t send_request();

    private:
        std::shared_ptr<DEVS::SeerCtrlCmdInterface::Request> req_ = std::make_shared<DEVS::SeerCtrlCmdInterface::Request>();
        std::shared_ptr<DEVS::SeerCtrlCmdInterface::Response> res_ = std::make_shared<DEVS::SeerCtrlCmdInterface::Response>();

    public:
        static nlohmann::json state2json(const DEVM::SeerCtrlState &state);
        static int32_t state2error(const DEVM::SeerCtrlState &state);
#ifdef HYRMS_ENV
        static void config_linker_server_impl(std::shared_ptr<CS::LoadNode_Request> req, std::string name);
        static void config_linker_publisher_impl(std::shared_ptr<CS::LoadNode_Request> req, std::string name);
        static std::shared_ptr<HyDevProxy> config_proxy_impl(std::string name);
#endif
    };
    class SeerM4 : public HySimpleDevProxy<SeerM4,
                                            DEVS::SeerM4CmdInterface,
                                            DEVM::SeerM4State>
    {
    public:
        std::string msg;
        DEVM::AgvOrderState order_state;
        SeerM4(const std::string &name);
        int32_t connect();
        int32_t disconnect();
        int32_t getOrderId(std::string &order_id);
        int32_t getOrderState(std::string order_id);
        int32_t cancelOrder(std::string order_id);
        int32_t loadCargo(std::string point, std::string container_id, std::string order_id = "");
        int32_t unloadCargo(std::string point, std::string container_id, std::string order_id = "");
        int32_t goPoint(std::string point, std::string order_id = "");
        int32_t send_request();

    private:
        std::shared_ptr<DEVS::SeerM4CmdInterface::Request> req_ = std::make_shared<DEVS::SeerM4CmdInterface::Request>();
        std::shared_ptr<DEVS::SeerM4CmdInterface::Response> res_ = std::make_shared<DEVS::SeerM4CmdInterface::Response>();
    public:
        static nlohmann::json state2json(const DEVM::SeerM4State &state);
#ifdef HYRMS_ENV
        static void config_linker_server_impl(std::shared_ptr<CS::LoadNode_Request> req, std::string name);
        static void config_linker_publisher_impl(std::shared_ptr<CS::LoadNode_Request> req, std::string name);
        static std::shared_ptr<HyDevProxy> config_proxy_impl(std::string name);
#endif
    };
    // DEV_CLASS_INSERT_ANCHOR 用于脚本匹配,追加脚本类
}

#endif
