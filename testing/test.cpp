#include <print>

extern int start_program(int, const char**);

int main() {
    std::println("Test 1: Passing zero arguments to start_program");
    auto exit_code = start_program(0, nullptr);
    if (exit_code == 0) {
        std::println("Test FAILED: Unexpected zero exit code.");
    } else {
        std::println("Test PASSED: Non-zero exit code returned.\n");
    }

    std::println("Test 2: Passing 2 arguments to start_program");
    const char *arguments[2] = {"Hello", "World"};
    exit_code = start_program(2, arguments);
    if (exit_code != 0) {
        std::println("Test FAILED: Unexpected non-zero exit code");
    } else {
        std::println("Test PASSED");
    }
}
