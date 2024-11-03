import extended;

#include <print>
#include "calc/calc.h"

int main() {
    std::println("Addition 2 + 2 = {}", Add(2,2));
    std::println("Multiplication 2 * 3 = {}", Multiply(2,3));
    std::println("Division 4 / 1 = {}", Division(4,1));
}
