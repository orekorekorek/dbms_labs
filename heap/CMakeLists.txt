cmake_minimum_required(VERSION 3.14)

project(heap)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.14.x
)

FetchContent_MakeAvailable(googletest)

add_executable(
  heap_test
  test/heap_test.cpp
)

target_link_libraries(
  heap_test
  GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(heap_test)

