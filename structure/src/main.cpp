#include <print>
#include "class_a.h"
#include "class_b.h"

int main()
{
    std::println("Structure main");

    Class_a class_a;
    std::println("{}", class_a.method());

    Class_b class_b;
    std::println("{}", class_b.method());

    return 0;
}
