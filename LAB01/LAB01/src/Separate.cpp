#include "Separate.h"
#include <iostream>
int f{2};
int f2{2};
namespace Task2
{
    auto es{2};
    int foo{0};
    auto wtf{0};
    auto Separate::printArray(std::vector<int> vec) -> void
    {
        for (auto el : vec)
        {
            std::cout << el << " ";
        }
        std::cout << "\n";
    }

    auto Separate::isEven(int a) -> bool
    {
        if (a % 2 == 0)
            return true;
        return false;
    }

    template<typename T>
    auto Separate::swapArr(T &a, T &b) -> void
    {
        T temp = a;
        a = b;
        b = temp;
    }

    auto Separate::SwapForBubble(int* a, int* b) -> void
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    auto Separate::BubbleSort(std::vector<int> &array) -> void
    {
        for (size_t i = 0 ; i < array.size() ; i++)
        {
            for (size_t j = 0 ; j < array.size() - 1 ; j++)
            {
                if (array[j] > array[j + 1])
                    SwapForBubble(&array[j], &array[j + 1]);
            }
        }
    }

    auto Separate::sortAscending(std::vector<int> &arr, int last) -> std::vector<int> &
    {
        for (int j = 0 ; j < last - 1 ; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swapArr(arr[j], arr[j + 1]);
            }
        }
        return arr;
    }

    auto Separate::sortDescending(std::vector<int> &arr, int last) -> std::vector<int> &
    {
        for (size_t j = last ; j < arr.size() - 1 ; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                swapArr(arr[j], arr[j + 1]);
            }
        }
        return arr;
    }

    auto Separate::sortAcendinglyDescending(std::vector<int> &arr, int last) -> std::vector<int> &
    {
        for (int i = 0 ; i < last ; i++)
        {
            arr = sortAscending(arr, last);
            arr = sortDescending(arr, last);
        }
        return arr;
    }

    auto Separate::separateOddEven(std::vector<int> arr) -> std::vector<int>
    {
        auto isEven = [](int a) { return a % 2 == 0; };
        BubbleSort(arr);
        bool czyDalejSzukac = true;
        int last = 0;

        for (int i = 0 ; czyDalejSzukac ; i++)
        {
            if (isEven(arr[i]))
            {
                for (int j = arr.size() - 1 ; j > i ; j--)
                {
                    if (!isEven(arr[j]))
                    {
                        swapArr(arr[i], arr[j]);
                        break;
                    }
                    if (i + 1 == j)
                    {
                        czyDalejSzukac = false;
                        last = i;
                    }
                }
            }
        }

        arr = sortAcendinglyDescending(arr, last);

        return arr;
    }
} //namespace Task2
