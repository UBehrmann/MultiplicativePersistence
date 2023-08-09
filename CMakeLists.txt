cmake_minimum_required(VERSION 3.25)
project(MultiplicativePersistence)

set(CMAKE_CXX_STANDARD 17)

add_executable(MultiplicativePersistence
        src/main.cpp
        src/MultiplicativePersistence.cpp
        src/MultiplicativePersistence.h
        src/ConsoleOutput.cpp
        src/ConsoleOutput.h
        src/MPType.h
        src/DataManagement.cpp
        src/DataManagement.h)
