#include "mergeSort.h"
#include <string>
#include <stdexcept>
int fo;
namespace Task1
{

    template<typename T>
    auto Merge::swapArray(T &a, T &b) -> void
    {
        T temp = a;
        a = b;
        b = temp;
    }

    auto Merge::quickSort(std::string &str, int start, int end) -> std::string
    {
        if (str == "")
            throw std::invalid_argument("string is empty");

        if (end <= 0)
            throw std::invalid_argument("End of array cannot be zero");

        int startPos = start;
        int endPos = end;
        int pivot = str[(startPos + endPos) / 2];
        do
        {
            while (str[startPos] < pivot) startPos++;

            while (str[endPos] > pivot) endPos--;

            if (startPos <= endPos)
            {
                swapArray(str[startPos], str[endPos]);
                startPos++;
                endPos--;
            }
        }
        while (startPos <= endPos);

        if (start < endPos) quickSort(str, start, endPos);

        if (startPos < end) quickSort(str, startPos, end);
        return str;
    }
} //namespace Task1
