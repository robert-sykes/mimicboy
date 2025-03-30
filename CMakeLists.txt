cmake_minimum_required(VERSION 3.30)
project(mimicboy)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable testing
enable_testing()

# Find GoogleTest package
find_package(GTest REQUIRED)

add_executable(mimicboy
        src/main.cc
        src/Memory.cc
        src/CPU.cc
)

add_executable(mimicboy_test
        tests/unit/CPUTest.cc
        tests/unit/MemoryTest.cc
)

target_include_directories(mimicboy PRIVATE ${CMAKE_SOURCE_DIR})
target_include_directories(mimicboy_test PRIVATE ${GTEST_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR})

# Link against GTest and pthread (required on macOS)
target_link_libraries(mimicboy_test PRIVATE GTest::GTest GTest::Main pthread)

# Register the test with CTest
add_test(NAME MemoryTest COMMAND MemoryTest)
add_test(NAME CPUTest COMMAND CPUTest)