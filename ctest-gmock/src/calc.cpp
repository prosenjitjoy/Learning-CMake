#include "calc.h"

Calc::Calc(RandomNumberGenerator* _rng) {
    rng = _rng;
}

int Calc::Sum(int a, int b) {
    return a + b;
}

int Calc::Multiply(int a, int b) {
    return a * b;
}

int Calc::AddRandomNumber(int a) {
    return a + rng->Get();
}
