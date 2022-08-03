#pragma once

#include <string>

namespace TaskFour
{
    struct Any2Dec
    {
        static auto replaceNumberToChar(char c) -> int; //think about name
        auto any2Dec(std::string str, int base) -> int;
    };
} //namespace TaskFour