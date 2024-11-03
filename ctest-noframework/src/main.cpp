#include <print>
#include "calc.h"

int main() {
    Calc c;
    std::println("2 + 2 = {}", c.Sum(2,2));
    std::println("3 * 3 = {}", c.Multiply(3,3));

    return 0;
}
