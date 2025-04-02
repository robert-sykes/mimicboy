cmake_minimum_required(VERSION 3.30)
project(mimicboy)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable testing
enable_testing()

# Find GoogleTest package
find_package(GTest REQUIRED)

# Add a library for shared code (CPU, Memory, etc.)
add_library(mimicboy_core
        src/Memory.cc
        src/CPU.cc
        src/CPU_Load.cc
)

# Include directories for the library target
target_include_directories(mimicboy_core PUBLIC ${CMAKE_SOURCE_DIR})

# Add the main executable
add_executable(mimicboy
        src/main.cc
)

# Link the main executable to the shared library
target_link_libraries(mimicboy PRIVATE mimicboy_core)

# Add test executable for unit tests
add_executable(mimicboy_test
        tests/unit/CPUTest.cc
        tests/unit/MemoryTest.cc
)

# Link test executable to shared library and GTest
target_link_libraries(mimicboy_test PRIVATE mimicboy_core GTest::GTest GTest::Main pthread)

# Include GTest and project headers in tests
target_include_directories(mimicboy_test PRIVATE ${GTEST_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR})

# Register the test with CTest
add_test(NAME CPUTest COMMAND mimicboy_test --gtest_filter=CPUTest.*)
add_test(NAME MemoryTest COMMAND mimicboy_test --gtest_filter=MemoryTest.*)