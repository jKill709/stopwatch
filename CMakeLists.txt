cmake_minimum_required(VERSION 3.15)

project(Stopwatch)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



#
# Header-only library
#

add_library(Stopwatch INTERFACE)


target_include_directories(
    Stopwatch
    INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)


# Example

add_executable(
    StopwatchExample
    examples/StopwatchExample.cpp
)


target_link_libraries(
    StopwatchExample
    PRIVATE
    Stopwatch
)


# Tests

include(CTest)

enable_testing()


include(FetchContent)


FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

FetchContent_MakeAvailable(googletest)


add_executable(
    StopwatchTests
    tests/StopwatchTests.cpp
)


target_link_libraries(
    StopwatchTests
    PRIVATE
    Stopwatch
    GTest::gtest_main
)

add_test(
    NAME StopwatchTests
    COMMAND StopwatchTests
)
