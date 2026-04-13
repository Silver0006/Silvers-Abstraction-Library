cmake_minimum_required(VERSION 3.23)

project("Silver's Abstraction Library")

if(BUILD_SHARED_LIBS)
    add_library(SilversAbstractionLibrary SHARED SAL/SAL.cpp)
else()
    add_library(SilversAbstractionLibrary STATIC SAL/SAL.cpp)
endif()

target_include_directories(SilversAbstractionLibrary PUBLIC include/)

target_compile_options(SilversAbstractionLibrary PRIVATE
    $<$<CONFIG:Debug>:-g -O0 -DDEBUG>
    $<$<CONFIG:Release>:-O3 -flto=auto>
    $<$<CONFIG:Size>:-Os -flto=auto -ffunction-sections -fdata-sections>
)

