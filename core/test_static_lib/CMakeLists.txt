cmake_minimum_required(VERSION 3.22)

add_library(static_core_lib STATIC)

target_sources(static_core_lib PRIVATE
    function_static.h
    function_static.cpp)
