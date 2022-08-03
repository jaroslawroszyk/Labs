#include <gtest/gtest.h>
#include "mergeSort.h"
#include <tuple>

using namespace Task1;

class mergeSortTestsParameterizedTestFixture : public ::testing::TestWithParam<std::tuple<std::string, std::string>>
{
};

TEST_P(mergeSortTestsParameterizedTestFixture, OddYearsAreNotLeapYears)
{
    Merge sut;
    std::string input = std::get<0>(GetParam());
    std::string expected = std::get<1>(GetParam());
    int startPos {0};
    auto size = input.size() - 1;
    EXPECT_EQ(expected, sut.quickSort(input, startPos, size));
}

INSTANTIATE_TEST_SUITE_P(
        mergeSortTestsParameterizedTest,
        mergeSortTestsParameterizedTestFixture,
        ::testing::Values(
                std::make_tuple("QPRLR", "LPQRR"),
                std::make_tuple("BCDA", "ABCD"),
                std::make_tuple("DWUUB", "BDUUW"),
                std::make_tuple("IEDYYPWA", "ADEIPWYY"),
                std::make_tuple("JDHCFIXRIK", "CDFHIIJKRX"),
                std::make_tuple("HKMZOLTCE", "CEHKLMOTZ"),
                std::make_tuple("VNTGFO", "FGNOTV"),
                std::make_tuple("KRBIYLIGX", "BGIIKLRXY"),
                std::make_tuple("RLOHUXPXZR", "HLOPRRUXXZ"),
                std::make_tuple("NDCPVAZEL", "ACDELNPVZ"),
                std::make_tuple("PHOYJCSPWA", "ACHJOPPSWY"),
                std::make_tuple("PHOYJCSPWANDCPVAZEL", "AACCDEHJLNOPPPSVWYZ"),
                std::make_tuple("SXTYS", "SSTXY")));

class MergeSortTests : public ::testing::Test
{
protected:

    MergeSortTests() { };

    ~MergeSortTests() override { };
};

TEST_F(MergeSortTests, ifTheEntranceIsEmptyItShouldThrowAnException)
{
    Merge sut;
    std::string input = "";
    std::string expected = "";
    int startPos {0};
    auto size = input.size() - 1;
    EXPECT_THROW({
        try
        {
            EXPECT_EQ(sut.quickSort(input, startPos, size), expected);
        }
        catch (const std::invalid_argument &e)
        {
            EXPECT_STREQ("string is empty", e.what());
            throw;
        }
    }, std::exception);
}

TEST_F(MergeSortTests, IfTheEndPositionIsLessThanOneItShouldThrowAnException)
{
    Merge sut;
    std::string input = "ba";
    std::string expected = "ab";
    int startPos {0};
    auto size = 0;
    EXPECT_THROW({
        try
        {
            EXPECT_EQ(sut.quickSort(input, startPos, size), expected);
        }
        catch (const std::invalid_argument &e)
        {
            EXPECT_STREQ("End of array cannot be zero", e.what());
            throw;
        }
    }, std::exception);

}