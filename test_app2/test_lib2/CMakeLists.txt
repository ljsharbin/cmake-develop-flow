cmake_minimum_required(VERSION 3.22)

add_library(test_lib2 SHARED)

target_sources(test_lib2 PRIVATE
    test_lib2.h
    test_lib2.cpp)

target_include_directories(test_lib2 PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../../core/test_dynamic_lib
)