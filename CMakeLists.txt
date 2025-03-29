cmake_minimum_required(VERSION 3.30)
project(mimicboy)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I/Library/Developer/CommandLineTools/usr/include/c++/v1")

add_executable(mimicboy
        src/main.cc
        src/Memory.cc
)
