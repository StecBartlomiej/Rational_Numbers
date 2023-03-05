cmake_minimum_required(VERSION 3.0)
PROJECT(Rational_Numbers)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

set(SRC_FILE
        src/rational.cc
        )

add_executable(${PROJECT_NAME} main.cc ${SRC_FILE})