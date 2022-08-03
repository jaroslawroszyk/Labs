#include <gtest/gtest.h>
#include "Rlev2.h"

using namespace Task3;

class Rlev2Tests : public ::testing::Test
{
protected:

    Rlev2Tests() = default;

    ~Rlev2Tests() override = default;
};

class Rlev2TestsParameterizedTestFixture
        : public ::testing::TestWithParam<std::tuple<std::string, int, std::vector<uint8_t>>>
{
};

using VI = std::vector<uint8_t>;

TEST_P(Rlev2TestsParameterizedTestFixture, CheckRleV2)
{
    auto[input, bits, expectedResult] = GetParam();
    EXPECT_EQ(expectedResult, Rlev2(bits).RlE(input));
}

INSTANTIATE_TEST_SUITE_P(
        Rlev2TestsParameterizedTest,
        Rlev2TestsParameterizedTestFixture,
        ::testing::Values(
                std::make_tuple("A", 2, VI({2, 43, 146})),
                std::make_tuple("A", 8, VI({8, 160, 32, 32, 160, 32})),
                std::make_tuple("A", 1, VI({1, 61, 86})),
                std::make_tuple("Ala", 8, VI({8, 160, 32, 32, 160, 32, 32, 64, 32, 64, 96, 64, 128, 32}))));
/*
    * for2:
   input = A = 65 = 0100 0001
    1,1,5,1 sum  = 8
    1,1,3,0,2,1
    01,01,11,00,10,01
    2 ,001
   001 01 01 1 = 139
   100 10 01 x = 146

    * for8:
   input = A = 65 = 0100 0001
    1,1,5,1 sum  = 8
     1,1,5,1
    0000 0001,0000 0001,0000 0101,0000 0001
    8 ,101
    101 0000 0 = 160
    001 0000 0 =32
    001 0000 0= 32
    101 0000 0 = 160
    001 xxxx x = 32

   001 01 01 1 = 139
   100 10 01 x = 146

    * for1:
   input = A = 65 = 0100 0001
    1,1,5,1 sum  = 8
    1,1,1,0,1,0,1,0,1,0,1,1
    1 001
    001 11101 = 61
    010 10110 = 86*/

TEST_F(Rlev2Tests, foo)
{
//    using VI = std::vector<uint8_t>;
//    EXPECT_EQ(Rlev2(2).RlE("A"), VI({2, 43, 146}));
//    EXPECT_EQ(Rlev2(8).RlE("A"), VI({8, 160, 32, 32, 160, 32}));
//    EXPECT_EQ(Rlev2(1).RlE("A"), VI({1, 61, 86}));
//    EXPECT_EQ(Rlev2(8).RlE("Ala"), VI({8, 160, 32, 32, 160, 32, 32, 64, 32, 64, 96, 64, 128, 32}));
}