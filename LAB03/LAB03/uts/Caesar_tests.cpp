#include <gtest/gtest.h>
#include "Caesar.h"
#include <tuple>

using namespace Task1;

class CaesarTests : public ::testing::Test
{
protected:

    CaesarTests() =default;

    ~CaesarTests() override = default;
};

static Caesar sut;

TEST_F(CaesarTests, foo)
{
//    std::string str = "DO YOU WANNA JOIN";
//    std::string_view key = "PRO";
//    std::string output = "PTE EP SSLP";
////    sut.ceaser(str, key);
////    EXPECT_EQ(str,output);
//    EXPECT_EQ(sut.ceaser(str, key),output);
}

class CaesarTestsParameterizedTestFixture : public ::testing::TestWithParam<std::tuple<std::string,std::string,std::string>>
{};

TEST_P(CaesarTestsParameterizedTestFixture,IsCorrectConversionForCaesarCipher)
{
    auto str = std::get<0>(GetParam());
    auto key = std::get<1>(GetParam());
    auto output = std::get<2>(GetParam());
    EXPECT_EQ(output,sut.ceaser(str,key));
}

INSTANTIATE_TEST_SUITE_P(
        CaesarTestsParameterizedTest,
        CaesarTestsParameterizedTestFixture,
        ::testing::Values(
                std::make_tuple("ALA MA KOTA","PIES","PTE EP SSLP"),
                std::make_tuple("WSB MA STUDENTOW","SESJA","OWT VA KXMMEFXGF"),
                std::make_tuple("JESTEM PROGRAMISTA","CPP","LTHVTB RGDIGPOXHVP"),
                std::make_tuple("WSB","KURCZAK","GMS"),
                std::make_tuple("DO YOU WANNA JOIN","PRO","SF MDL KPEBP ACXE")));

class DecodeCaesarTestsParameterizedTestFixture : public ::testing::TestWithParam<std::tuple<std::string,std::string,std::string>>
{};

TEST_P(DecodeCaesarTestsParameterizedTestFixture,IsCorrectConversionForCaesarCipher)
{
    auto str = std::get<0>(GetParam());
    auto key = std::get<1>(GetParam());
    auto output = std::get<2>(GetParam());
    EXPECT_EQ(output,sut.decodeChiper(str,key));
}

INSTANTIATE_TEST_SUITE_P(
        DecodeCaesarTestsParameterizedTest,
        DecodeCaesarTestsParameterizedTestFixture,
        ::testing::Values(
                std::make_tuple("PTE EP SSLP","PIES","ALA MA KOTA"),
                std::make_tuple("OWT VA KXMMEFXGF","SESJA","WSB MA STUDENTOW"),
                std::make_tuple("LTHVTB RGDIGPOXHVP","CPP","JESTEM PROGRAMISTA"),
                std::make_tuple("GMS","KURCZAK","WSB"),
                std::make_tuple("SF MDL KPEBP ACXE","PRO","DO YOU WANNA JOIN")));