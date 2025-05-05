cmake_minimum_required(VERSION 3.10)
project(project-name)

set(CMAKE_CXX_STANDARD 11)

enable_testing()

add_subdirectory(tests)

include(GoogleTest)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(runTests tests/main.cpp)
target_link_libraries(runTests GTest::GTest GTest::Main)

gtest_discover_tests(runTests)