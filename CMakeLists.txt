cmake_minimum_required(VERSION 3.8)

project(CI-CD)

add_library(CI-CD-HelloWorld_lib 01_HelloWorld/lib.cpp)

add_subdirectory(01_HelloWorld)
add_subdirectory(02_IP_Sort)
add_subdirectory(03_Allocator)
add_subdirectory(04_Nominal_IP)
add_subdirectory(libs/gtest)

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    enable_testing()
    add_custom_target(run_tests
        COMMAND ${CMAKE_CTEST_COMMAND} --config Release --output-on-failure
        DEPENDS test_version
    )
endif()