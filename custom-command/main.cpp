#include <print>
#include "constants.h"

int main()
{
    std::println("Custom Command");
    std::println("{}", CONSTANT(It works));
    return 0;
}
