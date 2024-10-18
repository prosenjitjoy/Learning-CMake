#include <print>
#include "car.h"

int main()
{
    std::println("A car rental");
    Car volvo;
    std::println("{}", volvo.Honk());
    return 0;
}
