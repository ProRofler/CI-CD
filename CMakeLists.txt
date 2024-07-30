cmake_minimum_required(VERSION 3.8)

project(CI-CD)

add_library(CI-CD-HelloWorld_lib 01_HelloWorld/lib.cpp)

add_subdirectory(01_HelloWorld)
add_subdirectory(02_IP_Sort)
add_subdirectory(03_Allocator)
add_subdirectory(04_Nominal_IP)
add_subdirectory(libs/gtest)

set_target_properties(test_version PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CMAKE_BUILD_TYPE Release
)

enable_testing()
if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_test(NAME test_version COMMAND test_version)
endif()