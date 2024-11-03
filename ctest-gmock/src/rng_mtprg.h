#ifndef RNG_MTPRG_H
#define RNG_MTPRG_H

#include "rng.h"

class MersenneTwisterPRG : public RandomNumberGenerator {
public:
    int Get() override;
};

#endif // RNG_MTPRG_H
