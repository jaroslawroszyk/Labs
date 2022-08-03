#include "Rlev2.h"
#include <iostream>

namespace
{
    auto countBit(const uint8_t*& ptr, uint8_t& bitMask, const uint8_t* end) -> int
    {
        auto c = *ptr;
        bool bit = c & bitMask;
        int count{1};
        while (true)
        {
            bitMask = bitMask >> 1;
            if (bitMask==0)
            {
                bitMask = 0x80;
                ++ptr;
                if (ptr==end) break;
                c = *ptr;
            }
            bool nextBit = c & bitMask;
            if (bit!=nextBit)
                break;
            ++count;
        }
        return count;
    }

    constexpr int maxOnNbits(int bits)
    {
        int r = 0;
        while (bits>0)
        {
            r = r*2+1;
            --bits;
        }
        return r;
    }
} // namespace

namespace Task3
{
    Rlev2::Rlev2(int noBits)
            :noBits(noBits)
    {
        maxNumbers = maxOnNbits(noBits);
    }

    auto Rlev2::getRawRle(const std::string& str) -> std::vector<int>
    {
        uint8_t i{0x80};
        const auto* ptr = reinterpret_cast<const uint8_t*>(&*str.begin());
        const auto* end = reinterpret_cast<const uint8_t*>(&*str.end());
        std::vector<int> result{};
        while (ptr!=end)
        {
            auto x = countBit(ptr, i, end);
            while (x>maxNumbers)
            {
                result.push_back(maxNumbers);
                result.push_back(0);
                x -= maxNumbers;
            }
            result.push_back(x);
        }
        return result;
    }

    auto Rlev2::printNbits(uint32_t source, int n) -> void
    {
        std::cout << "Source: " << source << " n = " << n << " :";
        for(int i = 0; i < n; ++i)
        {
            auto mask = 1 << (n - i - 1);
            bool bit = source & mask;
            std::cout << (bit ? 1 : 0);
        }
        std::cout << "\n";
    }

    auto Rlev2::copyNbits(uint32_t source, int n) -> void
    {
        int shift = used&7;
        auto ptr = &destination[used/8];
        printNbits(source,n);
        while(true)
        {
            auto x = 8 - shift; //ile bitow zmiesci sie w bajcie
            uint8_t mask = 255 << x; // ustawiamy maske aby byly 1 dla ktorych chcemy zachowac else dla 0 ktore sa wolne(zostana delete and set to 0)
            if(x >= n) // we have more space than we can save
            {
                source = source << (x - n); // move source, zeby bity ktore chcemy zachowac trafily z source na wlasciwe miejsce
                *ptr = (*ptr & mask) + source;
                used += n;
                break;
            }
            uint8_t tmp = static_cast<uint8_t>(source >> (n-x));
            *ptr = (*ptr & mask) + tmp;
            n -= x;
            shift = 0;
            used += x;
            ++ptr;
            *ptr=0;
        }
    }

    auto Rlev2::RlE(const std::string& str) -> std::vector<uint8_t>
    {
        auto raw = getRawRle(str); //surowy wektor
        int totalBits = noBits*raw.size()+8+3; //ilosc bitow ktora chcemy przechowac w wektorze wynikowym
        int lostBits = (8 - totalBits) & 7; //ilosc straconych bitow
        destination.resize((totalBits+7)/8);
        used = 0;
        copyNbits(noBits, 8); // zapisalismy sobie ile bitow maja te ciagi
        copyNbits(lostBits, 3);
        for (auto& el: raw)
        {
            copyNbits(el, noBits); // skopiujemy kolejne elementy z tego wektora wypelnimy odpowiednia iloscia bitow
        }
        return destination;
    }
} // namespace Task3
