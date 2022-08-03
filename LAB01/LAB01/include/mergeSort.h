#pragma once

#include <string>

namespace Task1
{
    struct Merge
    {
        template<typename T>
        auto swapArray(T &a, T &b) -> void;

        auto quickSort(std::string &, int, int) -> std::string;
    };

} //namespace zad1
