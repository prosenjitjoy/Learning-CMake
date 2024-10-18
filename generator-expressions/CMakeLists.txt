cmake_minimum_required(VERSION 3.30)

project(generator-expressions LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(myvar "small text")
set(myvar2 "small $<ANGLE-R> text")

file(GENERATE OUTPUT nesting CONTENT "
    1 $<PLATFORM_ID>
    2 $<UPPER_CASE:$<PLATFORM_ID>>
    3 $<UPPER_CASE:hello world>
    4 $<UPPER_CASE:${myvar}>
    5 $<UPPER_CASE:${myvar2}>
")

file(GENERATE OUTPUT boolean CONTENT "
    1 $<0:TRUE>
    2 $<0:TRUE,FALSE> (won't work)
    3 $<1:TRUE,FALSE>
    4 $<IF:0,TRUE,FALSE>
    5 $<IF:0,TRUE,>
")

add_executable(generator-expressions main.cpp)

target_compile_options(generator-expressions PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>)

target_compile_definitions(generator-expressions PRIVATE
    $<$<COMPILE_LANG_AND_ID:CXX,AppleClang,Clang>:CXX_CLANG>
    $<$<COMPILE_LANG_AND_ID:CXX,Intel>:CXX_INTEL>
    $<$<COMPILE_LANG_AND_ID:C,Clang>:C_CLANG>
)

target_compile_options(generator-expressions PRIVATE $<$<CONFIG:DEBUG>:-ginline-points>)

target_compile_definitions(generator-expressions PRIVATE $<$<PLATFORM_ID:Linux>:LINUX=1>)

include(GNUInstallDirs)
install(TARGETS generator-expressions
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
