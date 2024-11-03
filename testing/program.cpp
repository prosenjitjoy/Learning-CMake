#include <print>

int start_program(int argc, const char** argv) {
    if (argc <= 1) {
        std::println("Not enough arguments");
        return 1;
    }

    return 0;
}
