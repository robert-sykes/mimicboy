cmake_minimum_required(VERSION 3.30)
project(mimicboy)

set(CMAKE_CXX_STANDARD 26)

add_executable(mimicboy
        src/main.cc
        src/Memory.cc
)
