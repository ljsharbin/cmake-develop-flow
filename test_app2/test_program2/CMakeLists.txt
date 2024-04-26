cmake_minimum_required(VERSION 3.22)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR}
    COMPONENTS
        Core
        Gui
        Widgets
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(my_second_app)

target_sources(my_second_app PRIVATE
    main.cpp)

target_include_directories(my_second_app PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../../core/test_dynamic_lib
    ${CMAKE_CURRENT_SOURCE_DIR}/../../core/test_static_lib
    ${CMAKE_CURRENT_SOURCE_DIR}/../test_lib2
)

target_link_libraries(my_second_app PRIVATE
    Qt::Core
    Qt::Gui
    Qt::Widgets
    dyn_core_lib
    static_core_lib
    test_lib2)