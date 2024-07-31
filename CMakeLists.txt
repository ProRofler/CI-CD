cmake_minimum_required(VERSION 3.8)

project(CI-CD)
set(CMAKE_CONFIGURATION_TYPES "Release" CACHE STRING "" FORCE)

if(WIN32)
    set(CMAKE_MSVC_RUNTIME_LIBRARY MultiThreaded)
    set(CMAKE_CXX_FLAGS_RELEASE "/MT") # for static libs
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Release>:Release>DLL")
endif(WIN32)

if(MINGW)
    link_libraries(ws2_32 wsock32)
endif()

include(CTest)

add_library(CI-CD-HelloWorld_lib 01_HelloWorld/lib.cpp)

add_subdirectory(01_HelloWorld)
add_subdirectory(02_IP_Sort)
add_subdirectory(03_Allocator)
add_subdirectory(04_Nominal_IP)
add_subdirectory(libs/gtest)