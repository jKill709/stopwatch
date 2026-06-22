cmake_minimum_required(VERSION 3.15)

project(Stopwatch)


add_library(Stopwatch INTERFACE)


target_include_directories(
    Stopwatch
    INTERFACE
    include
)



add_executable(
    StopwatchExample
    examples/StopwatchExample.cpp
)


target_link_libraries(
    StopwatchExample
    PRIVATE
    Stopwatch
)