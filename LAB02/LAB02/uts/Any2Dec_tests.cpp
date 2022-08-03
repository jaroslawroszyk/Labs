#include <gtest/gtest.h>
#include "Any2Dec.h"

using namespace TaskFour;

class Any2DecTests : public ::testing::Test
{
protected:
    Any2DecTests() = default;

    ~Any2DecTests() override = default;
};

static Any2Dec sut;

TEST_F(Any2DecTests, ShouldThrowExceptionWhenBaseIsLessThanTwo)
{

    EXPECT_THROW({
        try
        {
            EXPECT_EQ(sut.any2Dec("23", 1), 0);
            EXPECT_EQ(sut.any2Dec("23", 37), 0);
        }
        catch (const std::out_of_range &e)
        {
            EXPECT_STREQ("Base cannot be less than 2 or more than thirtysix", e.what());
            throw;
        }
    }, std::exception);
}

class Any2DecTestsParameterizedTestFixture : public ::testing::TestWithParam<std::tuple<const char*, int, int>>
{
};

TEST_P(Any2DecTestsParameterizedTestFixture, OddYearsAreNotLeapYears)
{
    const char* inputValue = std::get<0>(GetParam());
    auto inputBase = std::get<1>(GetParam());
    auto output = std::get<2>(GetParam());
    EXPECT_EQ(output, sut.any2Dec(inputValue, inputBase));
}

INSTANTIATE_TEST_SUITE_P(
        Any2DecTestsParameterizedTests,
        Any2DecTestsParameterizedTestFixture,
        ::testing::Values(
                std::make_tuple("16AH", 19, 9232),
                std::make_tuple("16Ah", 19, 9232),
                std::make_tuple("1101", 2, 13),
                std::make_tuple("11111100110", 2, 2022),
                std::make_tuple("1111011", 2, 123),
                std::make_tuple("1210", 4, 100),
                std::make_tuple("2221", 4, 169),
                std::make_tuple("41", 5, 21),
                std::make_tuple("10231", 5, 691),
                std::make_tuple("14411", 5, 1231),
                std::make_tuple("30", 7, 21),
                std::make_tuple("1331", 7, 512),
                std::make_tuple("376", 9, 312),
                std::make_tuple("6038177", 9, 3214312),
                std::make_tuple("1A", 11, 21),
                std::make_tuple("1a", 11, 21),
                std::make_tuple("14A60", 11, 21241),
                std::make_tuple("13A", 11, 164),
                std::make_tuple("13a", 11, 164),
                std::make_tuple("14A", 13, 231),
                std::make_tuple("A6A9", 13, 23123),
                std::make_tuple("a6a9", 13, 23123),
                std::make_tuple("77", 15, 112),
                std::make_tuple("34C7", 15, 11212),
                std::make_tuple("27", 17, 41),
                std::make_tuple("E3F", 17, 4112),
                std::make_tuple("864G", 17, 41122),
                std::make_tuple("C4", 19, 232),
                std::make_tuple("16AH", 19, 9232),
                std::make_tuple("JD", 21, 412),
                std::make_tuple("K4", 21, 424),
                std::make_tuple("HL", 23, 412),
                std::make_tuple("hl", 23, 412),
                std::make_tuple("1H81", 23, 21345),
                std::make_tuple("5G", 20, 116),
                std::make_tuple("5g", 20, 116)));

