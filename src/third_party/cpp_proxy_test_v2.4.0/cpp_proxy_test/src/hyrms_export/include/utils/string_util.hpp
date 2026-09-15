#pragma once
#include <string>

namespace string_util
{
    // 提取字符串中的所有数字,再从数字中提取四位
    inline std::string extract_code(const std::string &name)
    {
        std::string digits;
        for (char c : name)
            if (std::isdigit(static_cast<unsigned char>(c)))
                digits.push_back(c);

        if (digits.empty())
            digits = "0000";

        if (digits.size() > 4)
            digits = digits.substr(digits.size() - 4);

        while (digits.size() < 4)
            digits.insert(digits.begin(), '0');

        return digits;
    }
    /**
     * @brief 获取字符串第一个下划线之前的所有内容,没有下划线就返回原有字符串
     * @param [in] str 输入的字符串
     * @return result 获取的字符串结果
     */
    inline std::string name_info(std::string str)
    {
        std::string result;
        // 查找第一个下划线的位置
        size_t underscorePos = str.find('_');

        // 如果找到了下划线，则截取下划线之前的内容
        if (underscorePos != std::string::npos)
        {
            result = str.substr(0, underscorePos);
        }
        else
        {
            // 如果没有找到下划线，整个字符串都是结果
            result = str;
        }
        return result;
    }
    inline std::string pick3(std::string str)
    {
        std::string result;
        if (str.size() >= 3)
        {
            result = str.substr(0, 2) + str.back();
        }
        else if (str.size() == 2)
        {
            result = str + "0";
        }
        else if (str.size() == 1)
        {
            result = str + "00";
        }
        else if (str.size() == 0)
        {
            result = "000";
        }

        return result;
    }
}

