cmake_minimum_required(VERSION 3.20)

add_subdirectory(lib/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES BankFixture.cpp runAllTest.cpp)
add_executable(runBankProjectTest ${TEST_SOURCE_FILES})
target_link_libraries(runBankProjectTest gtest gtest_main core)