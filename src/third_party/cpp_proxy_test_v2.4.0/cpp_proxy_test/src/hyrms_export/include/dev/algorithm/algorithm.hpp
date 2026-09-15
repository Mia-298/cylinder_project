#ifndef __ALGORITHM_HPP__
#define __ALGORITHM_HPP__

#include "dev/dev_proxy.hpp"
#include "utils/string_util.hpp"

#ifdef HYRMS_ENV
#include "service/id_parser.hpp"
#include "service/state_manager.hpp"
#include "rclcpp_components/component_manager.hpp"
#endif

#include "algorithm/include/defines/ERROR_CODE.h"
#include "com_interfaces/srv/vision_engine_cmd_interface.hpp"
#include "com_interfaces/msg/vision_engine_state.hpp"
#include "com_interfaces/msg/yolo_result.hpp"
#include "com_interfaces/msg/sphere_loc.hpp"
#include "algorithm/include/defines/VISION_ENGINE_COMMAND_ID.h"

namespace AlgorithmProxy
{
    using json = nlohmann::json;
    class VisionEngine : public HySimpleDevProxy<VisionEngine,
                                                 DEVS::VisionEngineCmdInterface,
                                                 DEVM::VisionEngineState>
    {
    public:
        std::string msg;
        VisionEngine(const std::string &name);
        int32_t connect();
        int32_t disconnect();
        int32_t send_request();
        int32_t handEyeClearSample();
        int32_t handEyeAddSample(const std::array<double, 6> &desc);
        int32_t handEyeCalcMatT();

        /**
         * @brief 初始化YOLO检测模型
         * @param model_path ONNX模型文件路径
         * @param H 模型输入图像高度
         * @param W 模型输入图像宽度
         * @return 错误码,0表示成功
         */
        int32_t yoloInit(const std::string &model_path, int32_t H, int32_t W);

        /**
         * @brief 对当前彩色图像执行YOLO目标检测
         * @param confidence_threshold 置信度阈值
         * @param nms_threshold 非极大值抑制阈值
         * @param results 输出检测结果
         * @return 错误码,0表示成功
         */
        int32_t yoloDetect(double confidence_threshold,
                          double nms_threshold,
                          std::vector<DEVM::YoloResult> &results);

        /**
         * @brief 检测球体并输出球心在相机坐标系中的位置
         * @param sphere_loc 输出球心坐标,单位m
         * @return 错误码,0表示成功
         */
        int32_t sphereDetect(DEVM::SphereLoc &sphere_loc);

    private:
        std::shared_ptr<DEVS::VisionEngineCmdInterface::Request> req_ = std::make_shared<DEVS::VisionEngineCmdInterface::Request>();
        std::shared_ptr<DEVS::VisionEngineCmdInterface::Response> res_ = std::make_shared<DEVS::VisionEngineCmdInterface::Response>();

    public:
        static nlohmann::json state2json(const DEVM::VisionEngineState &state);
#ifdef HYRMS_ENV
        static void config_linker_server_impl(std::shared_ptr<CS::LoadNode_Request> req, std::string name);
        static void config_linker_publisher_impl(std::shared_ptr<CS::LoadNode_Request> req, std::string name);
        static std::shared_ptr<HyDevProxy> config_proxy_impl(std::string name);
#endif
    };
    // DEV_CLASS_INSERT_ANCHOR 用于脚本匹配,追加脚本类
}

#endif
