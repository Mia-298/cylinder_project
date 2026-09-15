#ifndef __ROBOT_HPP__
#define __ROBOT_HPP__

#include "dev/dev_proxy.hpp"
#include "utils/string_util.hpp"

#ifdef HYRMS_ENV
#include "service/id_parser.hpp"
#include "service/state_manager.hpp"
#include "rclcpp_components/component_manager.hpp"
#endif

#include "robot/include/defines/ERROR_CODE.h"

#include "com_interfaces/srv/fr_cmd_interface.hpp"
#include "com_interfaces/msg/fr_robot_state.hpp"
#include "robot/include/defines/FR_COMMAND_ID.h"

#include "com_interfaces/srv/aubo_cmd_interface.hpp"
#include "com_interfaces/msg/aubo_robot_state.hpp"
#include "robot/include/defines/AUBO_COMMAND_ID.h"

namespace RobotProxy
{
    using json = nlohmann::json;
    class FrRobot : public HySimpleDevProxy<FrRobot,
                                            DEVS::FrCmdInterface,
                                            DEVM::FrRobotState>
    {
    public:
        std::string msg;                  // 错误消息
        DEVM::FrRobotState state_pkg;     // 机器人状态信息
        DEVM::ForceTorque ft;             // 力与力矩信息
        DEVM::ForcePayload force_payload; // 力传感器负载重量和质心
        bool motion_done;                 // 标志运动是否完成
        double reg_value;                 // 机器人寄存器
        bool io_value;                    // 机器人io口
        double joint_pose[6];             // 机器人关节位置
        double desc_pose[6];              // 机器人笛卡尔位置

        FrRobot(const std::string &name);
        /**
         * @brief 连接机械臂
         */
        int32_t connect();
        /**
         * @brief 机器人使能
         * @param [in] enable 机器人使能标签 UP_ENABLE-下使能,DOWN_ENABLE-上使能
         */
        int32_t enable(bool enable);

        /**
         * @brief 关节点动
         * @param  [in]  axid 1-6对应1-6轴
         * @param  [in]  dir CW-顺时针；CCW-逆时针
         * @param  [in]  deg 单次点动最大角度，单位[°]或距离，单位[mm]
         */
        int32_t moveAxis(uint8_t axid, uint8_t dir, double deg);

        /**
         * @brief 关节运动到点
         * @param [in] pos_point 坐标点
         * @param [in] joint_desc 坐标标签；JOINT-关节点 DESC-笛卡尔点
         */
        int32_t moveJ(double pos_point[6], bool joint_desc);

        /**
         * @brief 笛卡尔运动到点
         * @param [in] pos_point 坐标点
         * @param [in] joint_desc 坐标标签；JOINT-关节点 DESC-笛卡尔点
         */
        int32_t moveL(double pos_point[6], bool joint_desc);

        /**
         * @brief 设置机器人速度
         * @param [in] vec 速度值 0-100
         */
        int32_t setVec(int32_t vec);

        /**
         * @brief 设置机器人加速度
         * @param [in] acc 加速度值 0-100
         */
        int32_t setAcc(int32_t acc);

        /**
         * @brief 机械臂清除报警错误
         */
        int32_t errClear();

        /**
         * @brief 关闭机械臂连接
         */
        int32_t disconnect();

        /**
         * @brief 设置机器人操作模式
         * @param [in] mode 机器人的操作模式 MANUAL_MODE-手动模式/手动模式1 AUTO_MODE-自动模式 MANUAL2_MODE-手动模式2 EXTRA_MODE-外部模式 DRAG_MODE-拖动模式
         */
        int32_t setMode(int32_t mode);

        /**
         * @brief 设置机器人系统变量（法奥）或者R寄存器（华数）
         * @param [in] register_index 系统变量或者R寄存器的编号
         * @param [in] register_value 系统变量或者R寄存器的值
         */
        int32_t setR(int32_t register_index, double register_value);

        /**
         * @brief 设置IO口的状态
         * @param [in] input_or_output IO口标签；D_INPUT-I口 D_OUTPUT-O口
         * @param [in] io_index io口的编号 法奥0-15 华数0-31
         * @param [in] io_value io口的值 ON-高 OFF-低
         */
        int32_t setIO(bool input_or_output, int32_t io_index, bool io_value);

        /**
         * @brief 获取机器人系统变量和寄存器
         * @param [in] register_index 系统变量的编号
         */
        int32_t getR(int32_t register_index);

        /**
         * @brief 获取机器人的IO口值
         * @param [in] input_or_output IO口标签；D_INPUT-I口 D_OUTPUT-O口
         * @param [in] io_index io口的编号 法奥0-15 华数0-31
         */
        int32_t getIO(bool input_or_output, int32_t io_index);
        /**
         * @brief 获取机器人当前关节位置
         */
        int32_t getJointPose();
        /**
         * @brief 获取机器人当前笛卡尔位置
         */
        int32_t getDescPose();
        /**
         * @brief 获取机器人实时状态,存储在成员变量robot_state_中
         */
        int32_t getState();

        /**
         * @brief 获取机器人移动状态,存储在成员变量motion_done中
         */
        int32_t getRobotMotionDone();

        /**
         * @brief 查询力传感器下负载重量和质心,存储在成员变量force_payload中
         */
        int32_t getForceSensorPayload();

        /**
         * @brief 加载机器人程序
         * @param [in] programName 程序名称
         */
        int32_t programLoad(std::string programName);

        /**
         * @brief 关节路径运动
         * @param [in] joint_path 关节路径
         */
        int32_t movePath(std::vector<std::array<double, 6>> joint_path);

        /**
         * @brief 记录拖动示教点位
         * @param [in] filename 保存的CSV文件名，不需要带csv。
         * @param [in] interval 保存点位的时间间隔，多少毫秒记录一点
         */
        int32_t recordPath(std::string filename, int interval);

        /**
         * @brief 运行拖动示教点位
         * @param [in] filename 需要运行的路径CSV文件
         */
        int32_t CSVMovePath(std::string filename);

        /**
         * @brief 激活夹爪
         * @param [in] index 夹爪编号
         * @param [in] act  0-复位，1-激活
         */
        int32_t actGripper(int index, uint8_t act);

        /**
         * @brief  控制夹爪
         * @param  [in] index  夹爪编号
         * @param  [in] pos  位置百分比，范围[0~100]
         * @param  [in] vel  速度百分比，范围[0~100]
         * @param  [in] force  力矩百分比，范围[0~100]
         * @param  [in] max_time  最大等待时间，范围[0~30000]，单位ms
         * @param  [in] block  0-阻塞，1-非阻塞
         */
        int32_t moveGripper(int index, int pos, int vel, int force, int max_time, uint8_t block);
        /**
         * @brief 非阻塞关节运动
         * @param [in] pos_point 目标点
         * @param [in] joint_desc JOINT-关节点 DESC-笛卡尔点
         */
        int32_t startMoveJ(double pos_point[6], bool joint_desc);

        /**
         * @brief 非阻塞直线运动
         * @param [in] pos_point 目标点
         * @param [in] joint_desc JOINT-关节点 DESC-笛卡尔点
         */
        int32_t startMoveL(double pos_point[6], bool joint_desc);

        /**
         * @brief 终止运动
         */
        int32_t stopMotion();

        /**
         * @brief 暂停运动
         */
        int32_t pauseMotion();

        /**
         * @brief 恢复运动
         */
        int32_t resumeMotion();

        /**
         * @brief 力传感器激活
         * @param [in] act 0-复位 1-激活
         */
        int32_t ftActivate(uint8_t act);

        /**
         * @brief 力传感器校零
         * @param [in] act 0-去零 1-校零
         */
        int32_t ftSetZero(uint8_t act);

        /**
         * @brief 获取参考坐标系力/力矩
         */
        int32_t getForceTorqueRCS();

        /**
         * @brief 获取原始力/力矩
         */
        int32_t getForceTorqueOrigin();

        /**
         * @brief 伺服运动开始，配合Servo开头指令使用
         * @return 错误码
         */
        int32_t ServoMoveStart();

        /**
         * @brief 伺服运动结束，配合Servo开头指令使用
         * @return 错误码
         */
        int32_t ServoMoveEnd();

        /**
         * @brief 笛卡尔空间伺服模式运动
         * @param  [in]  mode  0-绝对运动(基坐标系)，1-增量运动(基坐标系)，2-增量运动(工具坐标系)
         * @param  [in]  desc_pos  目标笛卡尔位姿或位姿增量
         * @param  [in]  pos_gain  位姿增量比例系数，仅在增量运动下生效，范围[0 ~ 1]
         * @param  [in]  cmdT  指令下发周期，单位s，建议范围[0.001 ~ 0.0016]
         * @return 错误码
         */
        int32_t ServoDescMove(int mode, double desc_pos[6], float pos_gain[6], float cmdT);

        int32_t send_request();
        static std::string tran_errcode(int code);

    private:
        std::shared_ptr<DEVS::FrCmdInterface::Request> req_ = std::make_shared<DEVS::FrCmdInterface::Request>();
        std::shared_ptr<DEVS::FrCmdInterface::Response> res_ = std::make_shared<DEVS::FrCmdInterface::Response>();

    public:
        static nlohmann::json state2json(const DEVM::FrRobotState &s); // override
        static int32_t state2error(const DEVM::FrRobotState &state);   // override
#ifdef HYRMS_ENV
        static void config_linker_server_impl(std::shared_ptr<CS::LoadNode_Request> req, std::string name);
        static void config_linker_publisher_impl(std::shared_ptr<CS::LoadNode_Request> req, std::string name);
        static std::shared_ptr<HyDevProxy> config_proxy_impl(std::string name);
#endif
    };
    // DEV_CLASS_INSERT_ANCHOR 用于脚本匹配,追加脚本类

    class AuboRobot : public HySimpleDevProxy<AuboRobot,
                                              DEVS::AuboCmdInterface,
                                              DEVM::AuboRobotState>
    {
    public:
        std::string msg;                // 错误消息
        DEVM::AuboRobotState state_pkg; // 机器人状态信息
        DEVM::ForceTorque ft;           // 力与力矩信息
        double reg_value;               // 机器人寄存器
        bool is_conn = false;           // 机器人连接状态
        bool io_value;                  // 机器人io口
        double joint_pose[6];           // 机器人关节位置
        double desc_pose[6];            // 机器人笛卡尔位置

        AuboRobot(const std::string &name);

        /**
         * @brief 连接机械臂
         */
        int32_t connect();

        /**
         * @brief 关闭机械臂连接
         */
        int32_t disconnect();

        /**
         * @brief 查询机械臂是否连接
         */
        int32_t isConnect();

        int32_t send_request();

        /**
         * @brief 机器人使能
         * @param [in] enable 机器人使能标签 UP_ENABLE-下使能,DOWN_ENABLE-上使能
         */
        int32_t enable(bool enable);

        /**
         * @brief 设置机器人速度
         * @param [in] vec 速度值 0-100
         */
        int32_t setSpeed(double speed);

        /**
         * @brief 设置机器人加速度
         * @param [in] acc 加速度 0-100
         */
        int32_t setAcc(double acc);

        // 单关节运动
        int32_t moveAxis(uint8_t axid, uint8_t dir, double deg);

        /**
         * @brief 设置机器人操作模式
         * @param [in] mode 机器人的操作模式 MANUAL_MODE-手动模式/手动模式1 AUTO_MODE-自动模式 MANUAL2_MODE-手动模式2 EXTRA_MODE-外部模式 DRAG_MODE-拖动模式
         */
        int32_t setMode(int32_t mode);

        /**
         * @brief 获取机器人系统变量和寄存器
         * @param [in] register_index 系统变量的编号
         */
        int32_t getR(int32_t register_index);

        /**
         * @brief 设置机器人系统变量（法奥）或者R寄存器（华数）
         * @param [in] register_index 系统变量或者R寄存器的编号
         * @param [in] register_value 系统变量或者R寄存器的值
         */
        int32_t setR(int32_t register_index, double register_value);

        /**
         * @brief 设置IO口的状态
         * @param [in] input_or_output IO口标签；D_INPUT-I口 D_OUTPUT-O口
         * @param [in] io_index io口的编号 法奥0-15 华数0-31
         * @param [in] io_value io口的值 ON-高 OFF-低
         */
        int32_t setIO(bool input_or_output, int32_t io_index, bool io_value);

        /**
         * @brief 获取机器人的IO口值
         * @param [in] input_or_output IO口标签；D_INPUT-I口 D_OUTPUT-O口
         * @param [in] io_index io口的编号 法奥0-15 华数0-31
         */
        int32_t getIO(bool input_or_output, int32_t io_index);

        /**
         * @brief 终止运动
         */
        int32_t stopMotion();

        /**
         * @brief 暂停运动
         */
        int32_t pauseMotion();

        /**
         * @brief 恢复运动
         */
        int32_t resumeMotion();

        /**
         * @brief 获取机器人当前关节位置
         */
        int32_t getJointPose();
        /**
         * @brief 获取机器人当前笛卡尔位置
         */
        int32_t getDescPose();

        /**
         * @brief 加载机器人程序
         * @param [in] programName 程序名称
         */
        int32_t programLoad(std::string programName);

        /**
         * @brief 关节运动到点
         * @param [in] pos_point 坐标点
         * @param [in] joint_desc 坐标标签；JOINT-关节点 DESC-笛卡尔点
         */
        int32_t moveJ(double pos_point[6], bool joint_desc);

        /**
         * @brief 笛卡尔运动到点
         * @param [in] pos_point 坐标点
         * @param [in] joint_desc 坐标标签；JOINT-关节点 DESC-笛卡尔点
         */
        int32_t moveL(double pos_point[6], bool joint_desc);

        /**
         * @brief 非阻塞关节运动
         * @param [in] pos_point 目标点
         * @param [in] joint_desc JOINT-关节点 DESC-笛卡尔点
         */
        int32_t startMoveJ(double pos_point[6], bool joint_desc);

        /**
         * @brief 非阻塞直线运动
         * @param [in] pos_point 目标点
         * @param [in] joint_desc JOINT-关节点 DESC-笛卡尔点
         */
        int32_t startMoveL(double pos_point[6], bool joint_desc);

        /**
         * @brief 力传感器激活
         * @param [in] act 0-复位 1-激活
         */
        int32_t ftActivate(uint8_t act);

        /**
         * @brief 力传感器校零
         * @param [in] act 0-去零 1-校零
         */
        int32_t ftSetZero(uint8_t act);

        /**
         * @brief 获取参考坐标系力/力矩
         */
        int32_t getForceTorqueRCS();

        /**
         * @brief 获取原始力/力矩
         */
        int32_t getForceTorqueOrigin();

    private:
        std::mutex request_mtx_;
        std::shared_ptr<DEVS::AuboCmdInterface::Request> req_ = std::make_shared<DEVS::AuboCmdInterface::Request>();
        std::shared_ptr<DEVS::AuboCmdInterface::Response> res_ = std::make_shared<DEVS::AuboCmdInterface::Response>();

    public:
        static nlohmann::json state2json(const DEVM::AuboRobotState &s); // override
        static int32_t state2error(const DEVM::AuboRobotState &state);   // override
#ifdef HYRMS_ENV
        static void config_linker_server_impl(std::shared_ptr<CS::LoadNode_Request> req, std::string name);
        static void config_linker_publisher_impl(std::shared_ptr<CS::LoadNode_Request> req, std::string name);
        static std::shared_ptr<HyDevProxy> config_proxy_impl(std::string name);
#endif
    };
}

#endif
