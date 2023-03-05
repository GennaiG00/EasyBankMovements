cmake_minimum_required(VERSION 3.21)
project(Bank)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_VERBOSE_MAKEFILE ON)

add_executable(Bank main.cpp Account/User.cpp Account/User.h Account/Account.cpp Account/Account.h Utility.h File/File.cpp File/File.h Account/Movements.cpp Account/Movements.h File/IbanFile.cpp File/IbanFile.h File/MovementsClientFile.cpp File/MovementsClientFile.h Observer.h Subject.h Account/AccountManager.cpp Account/AccountManager.h)
