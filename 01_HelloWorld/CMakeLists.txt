cmake_minimum_required(VERSION 3.28)

set(PATCH_VERSION "4" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(CI-CD-HelloWorld VERSION ${PROJECT_VERSION})

configure_file(version.h.in version.h)

if(MINGW)
    link_libraries(ws2_32 wsock32)
endif()


add_executable(CI-CD-HelloWorld main.cpp)
add_executable(test_version test_version.cpp)
#add_library(CI-CD-HelloWorld_lib lib.cpp)

include(CTest)

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    enable_testing()
    add_custom_target(run_tests
        COMMAND ${CMAKE_CTEST_COMMAND} --config Release --output-on-failure
        DEPENDS test_version
    )
endif()

target_link_libraries(test_version CI-CD-HelloWorld_lib gtest gtest_main)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set_target_properties(CI-CD-HelloWorld PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(CI-CD-HelloWorld_lib
    PRIVATE "${CMAKE_BINARY_DIR}"
)

target_link_libraries(CI-CD-HelloWorld PRIVATE
CI-CD-HelloWorld_lib
)

if (MSVC)
    target_compile_options(CI-CD-HelloWorld PRIVATE
        /W4
    )
    target_compile_options(CI-CD-HelloWorld_lib PRIVATE
        /W4
    )
else ()
    target_compile_options(CI-CD-HelloWorld PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(CI-CD-HelloWorld_lib PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

install(TARGETS CI-CD-HelloWorld RUNTIME DESTINATION bin)

add_test(test_version test_version)