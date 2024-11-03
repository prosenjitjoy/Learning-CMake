add_executable(unit-tests unit_tests.cpp
    calc_test.cpp
    run_test.cpp)

target_link_libraries(unit-tests PRIVATE sut)

add_test(NAME SumAddsTwoInts COMMAND unit-tests 1)
add_test(NAME MultiplyMultipliesTwoInts COMMAND unit-tests 2)
add_test(NAME RunOutputsCorrectEquations COMMAND unit-tests 3)
