#include <gtest/gtest.h>
#include "Boyera.h"
#include <string>

using namespace TaskTwo;

static Boyer sut;

class BoyeraTestsParameterizedTestFixture : public ::testing::TestWithParam<std::tuple<std::string, std::string, int>>
{
};

TEST_P(BoyeraTestsParameterizedTestFixture, OddYearsAreNotLeapYears)
{
    auto inputValue = std::get<0>(GetParam());
    auto inputBase = std::get<1>(GetParam());
    auto output = std::get<2>(GetParam());
    EXPECT_EQ(output, sut.boyermoore(inputValue, inputBase));
}

INSTANTIATE_TEST_SUITE_P(
        Dec2AnyTestsParameterizedTests,
        BoyeraTestsParameterizedTestFixture,
        ::testing::Values(
                std::make_tuple("ABAAABCD", "ABC", 4),
                std::make_tuple("AACBEG", "BEG", 4),
                std::make_tuple("Jarekmakota", "ako", 6),
                std::make_tuple("WSBALGORAWDKIANFW", "GOR", 5),
                std::make_tuple("KUWAMAC", "WAM", 3)
                ));


