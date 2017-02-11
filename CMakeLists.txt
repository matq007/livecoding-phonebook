cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 14)

set(PROJECT_NAME livecoding-phonebook)
project(${PROJECT_NAME})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Wall -Wextra")
find_package(Boost REQUIRED COMPONENTS regex)

include_directories(include)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_INCLUDE_DIRS})

set(SOURCES src/app.cpp src/Contact.cpp src/PhoneBook.cpp src/PhoneBookCollection.cpp src/PhoneBookParser.cpp src/tinyxml2/tinyxml2.cpp)

add_executable(${PROJECT_NAME} ${SOURCES} src/main.cpp)
add_executable(${PROJECT_NAME}-test ${SOURCES} test/ContactTest.cpp test/PhoneBookCollectionTest.cpp)

target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
target_link_libraries(${PROJECT_NAME}-test gtest gtest_main pthread ${Boost_LIBRARIES})

enable_testing()
