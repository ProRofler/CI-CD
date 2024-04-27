cmake_minimum_required(VERSION 3.8)
project(CI-CD-HelloWorld VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(CI-CD-HelloWorld main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set_target_properties(CI-CD-HelloWorld PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)


install(TARGETS CI-CD-HelloWorld RUNTIME DESTINATION bin)

enable_testing()