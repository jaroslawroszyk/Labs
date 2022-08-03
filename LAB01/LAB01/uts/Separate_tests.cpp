#include <gtest/gtest.h>
#include "Separate.h"
#include <vector>
using namespace Task2;

class LabTests : public ::testing::Test
{
protected:

    LabTests() { };

    ~LabTests() override { };
};

TEST_F(LabTests, isNumberEven)
{
    Separate sut;
    EXPECT_TRUE(sut.isEven(0));
    EXPECT_FALSE(sut.isEven(1));
    EXPECT_TRUE(sut.isEven(100));
    EXPECT_FALSE(sut.isEven(999));
}

TEST_F(LabTests, sortingWithBubbleSort)
{
    std::vector<int> in {7, 5, 4, 1, 3, 2, 6};
    std::vector<int> out {1, 2, 3, 4, 5, 6, 7};

    Separate sut;
    sut.BubbleSort(in);
    EXPECT_EQ(in, out);
}

TEST_F(LabTests, sortDescendsToSizeOfArrMinusFourSizeShouldReturnTheCorrectOutput)
{
    Separate sut;
    std::vector<int> in {7, 5, 4, 1, 3, 2, 6};
    int last = in.size() - 4;
    std::vector<int> out {7, 5, 4, 3, 2, 6, 1};

    EXPECT_EQ(sut.sortDescending(in, last), out);
}

TEST_F(LabTests, sortDescendsToSizeOfArrMinusThreeSizeShouldReturnTheCorrectOutput)
{
    Separate sut;
    std::vector<int> in {7, 5, 4, 1, 3, 2, 6};
    int last = in.size() - 3;
    std::vector<int> out {5, 4, 1, 7, 3, 2, 6};

    EXPECT_EQ(sut.sortAscending(in, last), out);
}

TEST_F(LabTests, separateOddEvenShouldReturnCorrectSeparation)
{
    Separate sut;
    std::vector<int> input {6, 7, 5, 2, 3, 1, 9, 8, 10};
    std::vector<int> output {1, 3, 5, 7, 9, 10, 8, 6, 2};
    EXPECT_EQ(sut.separateOddEven(input), output);
}

TEST_F(LabTests, GivenInputShouldCorrectSeparation)
{
    Separate sut;
    std::vector<int> input {9, 6, 3, 4, 2, 1};
    std::vector<int> output {1, 3, 9, 6, 4, 2};
    EXPECT_EQ(sut.separateOddEven(input), output);
}

TEST_F(LabTests, GivenLongInputShouldCorrectSeparation)
{
    Separate sut;
    std::vector<int> input {12, 9, 7, 3, 4, 6, 2, 1, 5, 8, 11, 10};
    std::vector<int> output {1, 3, 5, 7, 9, 11, 12, 10, 8, 6, 4, 2};
    EXPECT_EQ(sut.separateOddEven(input), output);
}