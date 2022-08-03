#include <gtest/gtest.h>
#include "Palindrom.h"

using namespace TaskOne;

class PalindromeTests : public ::testing::Test
{
protected:
    PalindromeTests() = default;

    ~PalindromeTests() override = default;
};

static Palindrome sut;

TEST_F(PalindromeTests, GivenInputLenghtIsTwoOrOneShouldReturnFalse)
{
    EXPECT_FALSE(sut.containsPalindrome("AB"));
    EXPECT_FALSE(sut.containsPalindrome("A"));
}

TEST_F(PalindromeTests, IfTheInputIsEqualToTwoCompareTheZeroIndexWithTheFirst)
{
    EXPECT_TRUE(sut.containsPalindrome("aa"));
    EXPECT_TRUE(sut.containsPalindrome("bb"));
    EXPECT_FALSE(sut.containsPalindrome("cd"));
}

class PalindromeTestsParameterizedTestFixture : public ::testing::TestWithParam<std::tuple<std::string, bool>>
{
};

TEST_P(PalindromeTestsParameterizedTestFixture, OddYearsAreNotLeapYears)
{
    std::string inputPalindrome = std::get<0>(GetParam());
    bool expected = std::get<1>(GetParam());
    EXPECT_EQ(expected, sut.containsPalindrome(inputPalindrome));
}

INSTANTIATE_TEST_SUITE_P(
        PalindromeTestsParameterizedTests,
        PalindromeTestsParameterizedTestFixture,
        ::testing::Values(
                std::make_tuple("CABCBAB", true),
                std::make_tuple("CABCAB", false),
                std::make_tuple("ECAAAEECDDEACBAEBBCABCCCCCDEDDEBCDCCADADCADEDBDADAEBACBEEBB", true),
                std::make_tuple("BCDCBCDABAAABEEEBABDAADDBBBBDBACBDCCABBBDDCEBEBCBAECECCBDCACEDADCCADDAECAEBDCE", true),
                std::make_tuple("BCDCBCDABAAABEEEBABDAADDBBBBDBACBDCCABBBDDCEBEBCBAECECCBDCACEDADCCADDAECAEBDCE", true),
                std::make_tuple(
                        "BCDAECABBEABBCBBDBDDEBADAEBBBCDDBAEDEADCAAEEADCCCAAEBEBEBEBDCBEBADACBCEAEBADAAEACCEEBDBCEECEEDDEACDEDCBBAA",
                        true),
                std::make_tuple("dasjdasjhdashdiqwhdiwqhdioq", false),
                std::make_tuple("POQIDJALCMNZH", false),
                std::make_tuple("ABCDEFGHIJKLMNOPRSTUWXYZ", false),
                std::make_tuple(
                        "BDADBEEDAADCADCACDDAADDDDBACEACADEBCDCEABDADDECBDDDDCAAACEEBAEBBCECCEDCEDDDACBCEEDDDCCCADBEABEECDBEACAADCEAECCCEBDDCBECDCDCCBEBDEDDBBEDBCDEAECDCBCBCEEDDDBEDABDAEACCDBBEBADBCECCCBBCBDABEDABCABA",
                        true),
                std::make_tuple("ACDBCDABEEEAACEDABECDDCCBDBBACABCBABDDDDDDDDBABCBACABBDBCCDDCEBADECAAEEEBADCBDCA",
                        true)));
