cmake_minimum_required(VERSION 3.23)

project("Silver's Abstraction Library")

option(SAL_BUILD_SHARED "Build SAL as a shared library" OFF)

if(SAL_BUILD_SHARED)
    add_library(SilversAbstractionLibrary SHARED SAL/SAL.cpp)
else()
    add_library(SilversAbstractionLibrary STATIC SAL/SAL.cpp)
endif()

target_include_directories(SilversAbstractionLibrary PUBLIC include/)

target_compile_options(SilversAbstractionLibrary PUBLIC
    $<$<CONFIG:Debug>:-g -O0 -DDEBUG>
    $<$<CONFIG:Release>:-O3>
)

