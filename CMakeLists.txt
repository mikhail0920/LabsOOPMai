cmake_minimum_required(VERSION 3.14)
project(ClosestPairTests)

set(CMAKE_CXX_STANDARD 17)

add_executable(test_runner
    closest_pair.cpp
    test.cpp
)

add_subdirectory(googletest)

target_link_libraries(test_runner
    gtest
    gtest_main
)
