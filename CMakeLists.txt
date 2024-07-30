cmake_minimum_required(VERSION 3.8)

project(CI-CD)

if(MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Release>:Release>DLL")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MD")
endif()

add_library(CI-CD-HelloWorld_lib 01_HelloWorld/lib.cpp)

add_subdirectory(01_HelloWorld)
add_subdirectory(02_IP_Sort)
add_subdirectory(03_Allocator)
add_subdirectory(04_Nominal_IP)
add_subdirectory(libs/gtest)

enable_testing()