cmake_minimum_required(VERSION 3.25)
project(MultiplicativePersistence)

set(CMAKE_CXX_STANDARD 17)

add_executable(MultiplicativePersistence main.cpp MultiplicativePersistence.cpp MultiplicativePersistence.h ConsoleOutput.cpp ConsoleOutput.h)
