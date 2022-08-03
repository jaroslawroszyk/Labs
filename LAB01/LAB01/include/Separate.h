#pragma once

#include <vector>

namespace Task2
{
    struct Separate
    {
        template<typename T>
        auto swapArr(T &a, T &b) -> void;

        auto SwapForBubble(int* a, int* b) -> void;

        auto BubbleSort(std::vector<int> &array) -> void;

        auto printArray(std::vector<int> vec) -> void;

        auto separateOddEven(std::vector<int> arr) -> std::vector<int>;

        auto isEven(int a) -> bool;

        auto sortAscending(std::vector<int> &arr, int last) -> std::vector<int> &;

        auto sortDescending(std::vector<int> &arr, int last) -> std::vector<int> &;

        auto sortAcendinglyDescending(std::vector<int> &arr, int last) -> std::vector<int> &;
    };
} //namespace Task2