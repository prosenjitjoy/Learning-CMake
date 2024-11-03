#ifndef RNG_MOCK_H
#define RNG_MOCK_H

#include "rng.h"
#include "gmock/gmock.h"

class RandomNumberGeneratorMock : public RandomNumberGenerator {
public:
    MOCK_METHOD(int, Get, (), (override));
};

#endif // RNG_MOCK_H
