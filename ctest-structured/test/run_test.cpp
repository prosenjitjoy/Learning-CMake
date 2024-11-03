#include <string>
#include <iostream>
#include <sstream>

int run();

void RunOutputsCorrectEquations() {
    std::string expected {"2 + 2 = 4\n3 * 3 = 9\n"};
    std::stringstream buffer;

    // redirect cout
    auto prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    run();

    auto output = buffer.str();

    // restore original buffer
    std::cout.rdbuf(prevcoutbuf);

    if (expected != output) {
        exit(1);
    }
}
