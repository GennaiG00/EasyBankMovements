cmake_minimum_required(VERSION 3.21)
project(Bank)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(Test)

set(SOURCE_FILE  Account/MovementsException.h File/File.h File/File.cpp File/IbanFile.h File/IbanFile.cpp File/ClientFile.h File/ClientFile.cpp Account/Account.cpp Account/Account.h Account/Transactions.cpp Account/Transactions.h Account/User.h Account/User.cpp Account/AccountManager.h Account/AccountManager.cpp)
add_executable(Bank main.cpp Utility.h)
add_library(core ${SOURCE_FILE})
target_link_libraries(Bank core)