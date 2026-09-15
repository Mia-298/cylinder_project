#ifndef __DEV_PROXY__
#define __DEV_PROXY__

#include <any>
#include "rclcpp/rclcpp.hpp"
#include "utils/string_util.hpp"
#include "dev/json.hpp"

#define ERR_DEV_PROXY_SEND_OK 0          // 正常
#define ERR_DEV_PROXY_SEND_TIMEOUT -1001 // 超时
#define ERR_DEV_PROXY_SEND_PARAM -1002   // 参数错误
#define ERR_DEV_PROXY_SEND_OTHERS -1009  // 其他错误

#if __has_include("hyrms/include/config.hpp")

#include "hyrms/include/config.hpp"
#include "service/state_manager.hpp"
#include "rclcpp_components/component_manager.hpp"
#include "service/config_manager.hpp"

namespace CS = composition_interfaces::srv; // NOLINT 基础缩写

#else
#define ERR_HYRMS_DEV_OK 0                 // 设备正常
#define ERR_HYRMS_DEV_REG -1199            // 设备未注册至该类
#define ERR_HYRMS_DEV_WARN -1110           // 设备警告
#define ERR_HYRMS_DEV_ERROR -1120          // 设备普通错误
#define ERR_HYRMS_DEV_EMERGENCY_STOP -1130 // 设备急停错误
#define ERR_HYRMS_DEV_FATAL -1140          // 设备致命错误

#define SIMPLE_DEV_PROXY_SUB_QUEUE 10
#define SIMPLE_DEV_FUTURE_TIMEOUT 8
#endif

// 传入设备接口
#include "com_interfaces/srv/virt_dev_cmd_interface.hpp"
#include "com_interfaces/msg/virt_dev_state.hpp"

namespace DEVS = com_interfaces::srv; // NOLINT 基础缩写
namespace DEVM = com_interfaces::msg; // NOLINT 基础缩写

// 设备代理基类,具体设备通过继承该类，
// 与设备包 Linker 通信并模拟成可用的 c++ 设备
class HyDevProxy : public rclcpp::Node
{
public:
    HyDevProxy(const std::string &name) : Node(name){};

    virtual ~HyDevProxy() = default;
    // 必须实现
    virtual int32_t init_client() = 0;
    virtual int32_t init_subscription() = 0;

    // 获取根名称，取下划线前的字符 Fr1_client => Fr1
    std::string get_base_name()
    {
        return string_util::name_info(this->get_name());
    }

    // 获取ros service的名称
    std::string get_service_name()
    {
        return get_base_name() + "_cmd";
    }

    // 获取ros topic的名称
    std::string get_topic_name()
    {
        return get_base_name() + "_state";
    }
    // 解析返回错误
    std::string err2string(int32_t err)
    {
        switch (err)
        {
        case 0:
            return "请求成功";
        case ERR_DEV_PROXY_SEND_TIMEOUT:
            return "请求超时";
        case ERR_DEV_PROXY_SEND_PARAM:
            return "请求参数错误";
        case ERR_DEV_PROXY_SEND_OTHERS:
            return "其他错误";
        default:
            return "设备错误:" + std::to_string(err);
        }
    }

    std::shared_ptr<rclcpp::ClientBase> client_;
    std::shared_ptr<rclcpp::SubscriptionBase> subscription_;
};
// 需要实现CRTP,用来实现静态函数的多态,https://en.wikipedia.org/wiki/Curiously_recurring_template_pattern#Static_polymorphism
// 必须实现的后缀有_impl
template <typename Derived, typename DevCmdInterfaceType, typename DevStateType>
class HySimpleDevProxy : public HyDevProxy
{
#ifdef HYRMS_ENV
protected:
    static nlohmann::json state2json(const DevStateType &state)
    {
        (void)state;
        using namespace std::chrono;
        using namespace string_util;
        nlohmann::json j;
        nlohmann::json js;
        j["ts"] = std::to_string(duration_cast<milliseconds>(
                                     system_clock::now().time_since_epoch())
                                     .count());
        j["type"] = "nil";
        j["module"] = "nil";
        j["id"] = "nilnil0001";
        js["name"] = "nil";
        j["state"] = js;
        j["err_code"] = 0;
        j["msg"] = "无异常";
        return j;
    }
    static int32_t state2error(const DevStateType &state)
    {
        (void)state;
        return ERR_HYRMS_DEV_OK;
    }

public:
    static void config_linker_server(std::shared_ptr<composition_interfaces::srv::LoadNode_Request> req, std::string name)
    {
        Derived::config_linker_server_impl(req, name);
    }
    static void config_linker_publisher(std::shared_ptr<composition_interfaces::srv::LoadNode_Request> req, std::string name)
    {
        Derived::config_linker_publisher_impl(req, name);
    }
    static std::shared_ptr<HyDevProxy> config_proxy(std::string name)
    {
        return Derived::config_proxy_impl(name);
    }
#endif
protected:
    void state_received(std::shared_ptr<DevStateType> state)
    {
        if (!state)
        {
            RCLCPP_WARN(this->get_logger(), "Proxy节点收到空的消息");
            return;
        }
#ifdef HYRMS_ENV
        StateManager::instance().update_state<DevStateType>(get_base_name(), state);
#endif
        return;
    }

    int32_t call_service(std::shared_ptr<typename DevCmdInterfaceType::Request> req,
                         std::shared_ptr<typename DevCmdInterfaceType::Response> res)
    {
        if (!rclcpp::ok())
        {
            return ERR_DEV_PROXY_SEND_OTHERS;
        }
        auto result_future = this->client_->async_send_request(req);
        auto start = std::chrono::steady_clock::now();
        auto timeout = std::chrono::seconds(future_timeout_);

        while (rclcpp::ok())
        {
            auto status = result_future.wait_for(std::chrono::milliseconds(1));
            if (status == std::future_status::ready)
            {
                if (res == nullptr)
                {
                    return ERR_DEV_PROXY_SEND_PARAM;
                }
                *res = std::move(*result_future.get());
                RCLCPP_INFO(this->get_logger(), "-->linker");
                return ERR_DEV_PROXY_SEND_OK;
            }
            // 检查超时,timeout小于等于0永不检查超时
            if (future_timeout_ > 0 && std::chrono::steady_clock::now() - start >= timeout)
            {
                RCLCPP_ERROR(this->get_logger(), "-/>linker 发送指令超时");
                return ERR_DEV_PROXY_SEND_TIMEOUT;
            }
        }

        return ERR_DEV_PROXY_SEND_OTHERS;
    }

    int32_t init_client() override
    {
        auto callback_group = create_callback_group(rclcpp::CallbackGroupType::Reentrant);
        this->client_ =
            this->create_client<DevCmdInterfaceType>(get_service_name());
        return 0;
    }

    int32_t init_subscription() override
    {
        
#ifdef HYRMS_ENV
        size_t sub_queue = static_cast<size_t>(ConfigManager::instance().get().simple_dev_proxy_sub_queue);
#else
        size_t sub_queue = SIMPLE_DEV_PROXY_SUB_QUEUE;
#endif
        this->subscription_ =
            this->create_subscription<DevStateType>(
                get_topic_name(),
                sub_queue,
                [this](std::shared_ptr<DevStateType> state)
                {
                    this->state_received(state);
                });
        return 0;
    }

public:
    HySimpleDevProxy(const std::string &name) : HyDevProxy(name)
    {
        if (init_client() != 0)
        {
            RCLCPP_ERROR(this->get_logger(), "创建Proxy节点:创建ros客户端失败");
        }

        if (init_subscription() != 0)
        {
            RCLCPP_ERROR(this->get_logger(), "创建Proxy节点:创建ros订阅者失败");
        }
#ifdef HYRMS_ENV
        // 初始化业务层
        StateManager::instance()
            .add_dev<DevStateType>(
                get_base_name(),
                [](const std::any &a)
                {
                    return Derived::state2json(std::any_cast<const DevStateType &>(a));
                },
                [](const std::any &a)
                {
                    return Derived::state2error(std::any_cast<const DevStateType &>(a));
                });
#endif
    }
#ifdef HYRMS_ENV
    virtual ~HySimpleDevProxy()
    {
        StateManager::instance().del_dev(get_base_name());
    }
#endif
    std::shared_ptr<rclcpp::Client<DevCmdInterfaceType>> client_;
    std::shared_ptr<rclcpp::Subscription<DevStateType>> subscription_;
    // 简易 Proxy 的消息超时时间
#ifdef HYRMS_ENV
    int32_t future_timeout_ = ConfigManager::instance().get().simple_dev_future_timeout;
#else
    int32_t future_timeout_ = SIMPLE_DEV_FUTURE_TIMEOUT;
#endif
};

#endif //!__DEV_PROXY__
