#include <iostream>
#include "calc.h"
#include "rng_mtprg.h"

int run() {
    auto rng = new MersenneTwisterPRG();
    Calc c(rng);
    std::cout << "Random dice throw + 1 = " << c.AddRandomNumber(1) << std::endl;
    delete rng;

    return 0;
}
