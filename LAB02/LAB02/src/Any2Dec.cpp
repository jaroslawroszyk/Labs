#include "Any2Dec.h"
#include <cctype>
#include <algorithm>

namespace TaskFour
{
    auto Any2Dec::replaceNumberToChar(char c) -> int
    {
        if(c >= '0' && c <= '9')
            return static_cast<int>(c - '0');
        else
            return static_cast<int>(c - 'A' + 10);
    }

    auto Any2Dec::any2Dec(std::string str, int base) -> int
    {
        auto power = 1;
        int outputNumber = 0;
        std::transform(str.cbegin(), str.cend(), str.begin(), [](char c) { return std::toupper(c); });
//        for (auto & c: str) c = std::toupper(c); if we can't use transform, try this function do it

        if(base < 2 || base > 36)
        {
            throw std::out_of_range("Base cannot be less than 2 or more than thirtysix");
        }

        for(int i = str.size() - 1; i >= 0; --i)
        {
            outputNumber += replaceNumberToChar(str[i]) * power;
            power *= base;
        }

        return outputNumber;
    }
} // namespace TaskFour