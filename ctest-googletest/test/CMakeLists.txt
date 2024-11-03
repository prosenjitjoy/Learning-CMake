include(FetchContent)
FetchContent_Declare(googletest
    GIT_REPOSITORY  https://github.com/google/googletest.git
    GIT_TAG v1.15.2
)
FetchContent_MakeAvailable(googletest)

add_executable(unit-tests
    calc_test.cpp
    run_test.cpp)

target_link_libraries(unit-tests PRIVATE sut gtest_main)

include(GoogleTest)
gtest_discover_tests(unit-tests)
