cmake_minimum_required(VERSION 3.23)
project(lab1)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab1 main.cpp Console.cpp Console.h Utils.cpp Utils.h Symbol.cpp Symbol.h Line.cpp Line.h AppManager.cpp AppManager.h)
