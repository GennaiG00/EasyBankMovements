cmake_minimum_required(VERSION 3.21)
project(ProgettoProgrammazione)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(Bank main.cpp Utility.h Account/MovementsException.h File/File.h File/File.cpp File/IbanFile.h File/IbanFile.cpp File/ClientFile.h File/ClientFile.cpp Account/Account.cpp Account/Account.h Account/Movements.cpp Account/Movements.h Account/User.h Account/User.cpp Account/AccountManager.h Account/AccountManager.cpp)
