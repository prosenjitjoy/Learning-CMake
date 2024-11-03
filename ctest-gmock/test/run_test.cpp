#include <gtest/gtest.h>
#include <string>
#include <iostream>
#include <sstream>

int run();

TEST(RunTest, RunOutputsCorrectEquations) {
    std::string expected {"2 + 2 = 4\n3 * 3 = 9\n"};
    std::stringstream buffer;

    // redirect cout
    auto prevoutbuf = std::cout.rdbuf(buffer.rdbuf());

    run();

    std::string output = buffer.str();

    // restore original buffer
    std::cout.rdbuf(prevoutbuf);
    EXPECT_EQ(0, output.rfind("Random dice throw + 1 = ", 0)) << "Incorrect message";
}
