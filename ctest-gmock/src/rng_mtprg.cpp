#include <random>
#include "rng_mtprg.h"

int MersenneTwisterPRG::Get() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1,6);
    return distrib(gen);
}
