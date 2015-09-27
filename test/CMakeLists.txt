
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(unitTest ContactTest.cpp PhoneBookCollectionTest.cpp)

target_link_libraries(unitTest gtest gtest_main app_lib)