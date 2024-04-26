cmake_minimum_required(VERSION 3.22)

add_library(test_lib1 SHARED)

target_sources(test_lib1 PRIVATE
    test_lib1.h
    test_lib1.cpp)

target_include_directories(test_lib1 PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../../core/test_dynamic_lib
)

