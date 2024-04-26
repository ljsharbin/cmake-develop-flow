cmake_minimum_required(VERSION 3.22)

add_library(dyn_core_lib SHARED)

target_sources(dyn_core_lib PRIVATE
    common.h
    function.h
    function.cpp)
