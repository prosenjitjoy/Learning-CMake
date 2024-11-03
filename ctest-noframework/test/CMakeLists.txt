add_executable(unit-tests unit_tests.cpp calc_test.cpp ../src/calc.cpp)
target_include_directories(unit-tests PRIVATE ../src)

add_test(NAME SumAddsTwoInts COMMAND unit-tests 1)
add_test(NAME MultiplyMultipliesTwoInts COMMAND unit-tests 2)
