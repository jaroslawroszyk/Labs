#pragma once

#include <string>
#include <string_view>
#include <iostream>

namespace Essentials
{
//    std::string negativeToPositiveForLetters(std::string_view str)
//    {
//        if (str.empty())
//            return {};
//        if (str[0] == '-')
//            return std::string(str.substr(1));
//        return std::string(str);
//    }

//    const std::string checkBase(int base)
//    {
//        if(base < 2 || base > 36)
//        {
//            return "0";
//          throw std::out_of_range("Base cannot be less than 2 or more than thirtysix");
//        }
//        return "";
//    }

    template<typename T>
    T negativeToPositive(T &value)
    {
        if(value < 0)
        {
            return value * -1;
        }
        return value;
    }

} //namespace Essentials
