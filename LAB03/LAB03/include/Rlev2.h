#pragma once
#include <string>
#include <vector>

namespace Task3
{
    class Rlev2
    {
    public:
        explicit Rlev2(int noBits = 8);
        auto RlE(const std::string& str) -> std::vector<uint8_t>;
    private:
        auto getRawRle(const std::string& str) -> std::vector<int>;
        auto copyNbits(uint32_t source,int n) -> void;
        auto printNbits(uint32_t source, int n) -> void;
        int maxNumbers;
        std::vector<uint8_t> destination;
        int used;
        int noBits;
    };
}
