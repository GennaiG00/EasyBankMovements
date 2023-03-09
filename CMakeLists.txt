cmake_minimum_required(VERSION 3.21)
project(ProgettoProgrammazione)

set(CMAKE_CXX_STANDARD 14)

add_executable(ProgettoProgrammazione main.cpp Utility.h File/File.h File/File.cpp File/IbanFile.h File/IbanFile.cpp File/ClientFile.h File/ClientFile.cpp Account/Account.cpp Account/Account.h Account/Movements.cpp Account/Movements.h Account/User.h Account/User.cpp Account/AccountManager.h Account/AccountManager.cpp)
