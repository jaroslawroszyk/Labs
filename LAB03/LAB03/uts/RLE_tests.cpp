#include <gtest/gtest.h>
#include "RLE.h"
#include <vector>
#include <numeric>
#include <tuple>

using namespace Task2;

class RleTests : public ::testing::Test
{
protected:

    RleTests() = default;

    ~RleTests() override = default;
};

static Rle sut;

template<typename... Inputs>
auto print_inputs(Inputs const& ... inputs)
{
    for (auto const& input: {inputs...})
    {
        for (auto const& el: input) std::cout << static_cast<int>(el);
    }
}

void checkSum(const std::string& str)
{
    auto result = sut.RLE(str);
    int sum = std::accumulate(result.begin(), result.end(), 0);
    EXPECT_EQ(sum, str.size()*8);
}

TEST_F(RleTests,foo)
{
    checkSum("!AB*");
    checkSum("!BA$69*");
    checkSum("!ABC");
}

TEST_F(RleTests, TestsWithDiffrentInput)
{
    auto result = sut.RLE("!AB*");
    auto input2 = sut.RLE("!BA$69");
    auto input3 = sut.RLE("ABC");
    std::vector<uint8_t> vec{2, 1, 4, 1, 2, 1, 2, 1, 3, 1, 6};

    EXPECT_EQ(sut.RLE("!$@"), vec);

    for (auto& el: result)
    {
        std::cout << static_cast<int>(el);
    }
    std::cout << std::endl;
    for (auto& el: input2)
    {
        std::cout << static_cast<int>(el);
    }
    std::cout << std::endl;
    for (auto& el: input3)
    {
        std::cout << static_cast<int>(el);
    }
}

class RleTestsParameterizedTestFixture : public ::testing::TestWithParam<std::tuple<std::string,std::vector<uint8_t>>>
{};

TEST_P(RleTestsParameterizedTestFixture,CheckRle)
{
    auto[input,expectedResult] = GetParam();
    EXPECT_EQ(expectedResult,sut.RLE(input));
}

INSTANTIATE_TEST_SUITE_P(
        RleTestsParameterizedTest,
        RleTestsParameterizedTestFixture,
        ::testing::Values(std::make_tuple("!$@",std::vector<uint8_t>({2, 1, 4, 1, 2, 1, 2, 1, 3, 1, 6}))));