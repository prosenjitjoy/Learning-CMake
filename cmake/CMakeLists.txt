cmake_minimum_required(VERSION 3.30)

project(cmake LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cmake main.cpp)

include(GNUInstallDirs)
install(TARGETS cmake
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

set(INNER inner)
set(OUTERinner outer)
set(CMAKE_VERSION 1.2.3)
message(${CMAKE_VERSION})
message("shell: " $ENV{SHELL})

block()
    message("Hello scope")
    set(mylist "a;list;of;five;elements")
    set(mylist1 a list of five elements)
    message(${mylist})
    message(${mylist1})
    set(length 0)
    list(GET mylist 4 length)
    message(${length})
    list(SORT mylist)
    message(${mylist})
endblock()

block()
    if (1 LESS 2)
      message("Correct.")
    endif()

    if ("2 Z 0" LESS 2)
      message("Incorrect 1")
    endif()

    if (1 LESS "20 Z 20")
      message("Incorrect 2")
    endif()

    if (20 EQUAL "30 Z 20")
      message("Incorrect 3")
    endif()
endblock()

block()
    set(MY_LIST 1 2 3)
    foreach(VAR IN LISTS MY_LIST ITEMS e f)
      message(${VAR})
    endforeach()
endblock()

block()
    function(MyFunction FirstArg)
      message("Function: ${CMAKE_CURRENT_FUNCTION}")
      message("File: ${CMAKE_CURRENT_FUNCTION_LIST_FILE}")
      message("FirstArg: ${FirstArg}")
      set(FirstArg "new value")
      message("FirstArg again: ${FirstArg}")
      message("ARGV0: ${ARGV0} ARGV1: ${ARGV1} ARGC: ${ARGC}")
    endfunction()

    set(FirstArg "first value")
    MyFunction("Value1" "Value2")
    message("FirstArg in global scope: ${FirstArg}")
endblock()

macro(main)
  message("main()")
  setup_first_target()
  setup_second_target()
  setup_tests()
  message("end main()")
endmacro()

function(setup_first_target)
  message("  setup_first_target()")
endfunction()

function(setup_second_target)
  message("  setup_second_target()")
endfunction()

function(setup_tests)
  message("  setup_tests()")
endfunction()

main()

block()
    function(foo)
      list(APPEND CMAKE_MESSAGE_CONTEXT "foo")
      message("foo message")
    endfunction()

    list(APPEND CMAKE_MESSAGE_CONTEXT "top")

    message("Before `foo`")
    foo()
    message("After `foo`")
endblock()

execute_process(COMMAND pwd)

message(FATAL_ERROR "Stop processing")
message("This won't be printed")
