#include <catch2/catch_template_test_macros.hpp>
#include <string>
#include <iostream>
#include <sstream>

int run();

TEST_CASE("RunOutputsCorrectEquations", "[run]") {
    std::string expected {"2 + 2 = 4\n3 * 3 = 9\n"};
    std::stringstream buffer;

    // redirect cout
    auto prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    run();

    std::string output = buffer.str();

    // restore original buffer
    std::cout.rdbuf(prevcoutbuf);

    CHECK(expected == output);
}
