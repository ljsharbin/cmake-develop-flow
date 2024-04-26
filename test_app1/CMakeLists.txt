cmake_minimum_required(VERSION 3.22)
project(test_app VERSION 0.1.0 LANGUAGES C CXX)

add_subdirectory(../core/test_dynamic_lib test_dynamic_lib)
add_subdirectory(../core/test_static_lib test_static_lib)
add_subdirectory(test_lib1)
add_subdirectory(test_program1)
