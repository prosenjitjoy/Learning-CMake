#include <gtest/gtest.h>
#include "calc.h"

class CalcTestSuite : public ::testing::Test {
protected:
    Calc sut;
};

TEST_F(CalcTestSuite, SumAddsTwoInts) {
    EXPECT_EQ(4, sut.Sum(2,2));
}

TEST_F(CalcTestSuite, MultiplyMultipliesTwoInts) {
    EXPECT_EQ(12, sut.Multiply(3,4));
}
