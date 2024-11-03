#ifndef CALC_H
#define CALC_H

#include "rng.h"

class Calc {
    RandomNumberGenerator* rng;
public:
    Calc(RandomNumberGenerator* rng);
    int Sum(int a, int b);
    int Multiply(int a, int b);
    int AddRandomNumber(int a);
};

#endif // CALC_H
