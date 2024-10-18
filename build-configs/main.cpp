#include <print>

// #undef NDEBUG
#include <cassert>

int main()
{
    assert(false); // This won't work in release mode
    static_assert(false, "program should stop here"); // compile time assertions
    std::println("Build Configs");
    return 0;
}
