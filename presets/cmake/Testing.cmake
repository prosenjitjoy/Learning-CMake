include(FetchContent)
FetchContent_Declare(googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.2
)

option(INSTALL_GTEST "Install GTest" OFF)
option(INSTALL_GMOCK "Install GMock" OFF)
FetchContent_MakeAvailable(googletest)


include(GoogleTest)
include(Coverage)
include(Memcheck)

macro(AddTests target)
    message("Adding tests to ${target}")
    target_link_libraries(${target} PRIVATE gtest_main gmock)
    gtest_discover_tests(${target})
    AddCoverage(${target})
    AddMemcheck(${target})
endmacro()
