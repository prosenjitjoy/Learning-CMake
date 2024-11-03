add_library(sut STATIC calc.h calc.cpp
    run.cpp
    rng.h
    rng_mtprg.h rng_mtprg.cpp
)
target_include_directories(sut PUBLIC .)

add_executable(bootstrap bootstrap.cpp)
target_link_libraries(bootstrap PRIVATE sut)
