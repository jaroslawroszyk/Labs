#include "RLE.h"
#include <iostream>

namespace Task2
{
    auto Rle::countBit(const uint8_t*&ptr, uint8_t &bitMask, const uint8_t* end) -> int
    {
        auto c = *ptr;
        bool bit = c & bitMask;
        int count{1};
        while(true)
        {
            bitMask = bitMask >> 1;
            if (bitMask==0)
            {
                bitMask = 0x80;
                ++ptr;
                if(ptr == end) break;
                c = *ptr;
            }
            bool nextBit = c & bitMask;
            if (bit!=nextBit)
                break;
            ++count;
        }
        return count;
    }

    auto Rle::RLE(const std::string &str) -> std::vector<uint8_t>
    {
        uint8_t i{0x80};
        const auto *ptr = reinterpret_cast<const uint8_t*>(&*str.begin());
        const auto *end = reinterpret_cast<const uint8_t*>(&*str.end());
        std::vector<uint8_t> result{};
        while(ptr!=end)
        {
            auto x = countBit(ptr,i,end);
            while(x > 255)
            {
                result.push_back(255);
                result.push_back(0);
                x -= 255;
            }
            result.push_back(x);
        }

        return result;
    }
} // namespace Task2
