cmake_minimum_required(VERSION 3.28)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(03_Allocator VERSION ${PROJECT_VERSION})

if(MINGW)
    link_libraries(ws2_32 wsock32)
endif()

include(CTest)
enable_testing()

add_executable(Allocator main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set_target_properties(Allocator PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

if (MSVC)
    target_compile_options(Allocator PRIVATE
        /W4
        add_definitions(-D_ENFORCE_MATCHING_ALLOCATORS=0)
    )
else ()
    target_compile_options(Allocator PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

install(TARGETS Allocator RUNTIME DESTINATION bin)

enable_testing()

add_test(test_version test_version)