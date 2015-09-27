cmake_minimum_required(VERSION 3.1)

set(PROJECT_NAME livecoding-phonebook)
project(${PROJECT_NAME})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pedantic -Wall -Wextra")

set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)
add_subdirectory(${COMMON_INCLUDES}/gtest-1.7.0/)

add_subdirectory(src)
add_subdirectory(test)

enable_testing()

add_test(MyUnitTests unitTest)