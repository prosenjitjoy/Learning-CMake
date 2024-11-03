include(FetchContent)
FetchContent_Declare(Catch2
    GIT_REPOSITORY  https://github.com/catchorg/Catch2.git
    GIT_TAG v3.7.1
)
FetchContent_MakeAvailable(Catch2)

add_executable(unit-tests
    calc_test.cpp
    run_test.cpp)

target_link_libraries(unit-tests PRIVATE sut Catch2::Catch2WithMain)
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)

include(Catch)
catch_discover_tests(unit-tests)
