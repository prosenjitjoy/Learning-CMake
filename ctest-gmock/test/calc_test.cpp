#include <gtest/gtest.h>
#include "calc.h"
#include "mocks/rng_mock.h"

using namespace ::testing;

class CalcTestSuite : public Test {
protected:
    RandomNumberGeneratorMock rng_mock;
    Calc sut{&rng_mock};
};

TEST_F(CalcTestSuite, SumAddsTwoInts) {
    EXPECT_EQ(4, sut.Sum(2,2));
}

TEST_F(CalcTestSuite, MultiplyMultipliesTwoInts) {
    EXPECT_EQ(12, sut.Multiply(3,4));
}

TEST_F(CalcTestSuite, AddRandomNumberAddsThree) {
    EXPECT_CALL(rng_mock, Get()).Times(1).WillOnce(Return(3));
    EXPECT_EQ(4, sut.AddRandomNumber(1));
}
