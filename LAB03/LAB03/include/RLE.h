#pragma once
#include <vector>
#include <string>

namespace Task2
{
    struct Rle
    {
        auto countBit(const uint8_t*& ptr, uint8_t& bitMask, const uint8_t* end) -> int;
        auto RLE(const std::string& str) -> std::vector<uint8_t>;
    };
} // namespace Task2