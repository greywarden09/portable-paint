cmake_minimum_required(VERSION 3.31)
project(portable_paint)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(Python3_EXECUTABLE python3)

set(Qt6_DIR /usr/local/Qt-6.8.1/lib/cmake/Qt6)

find_package(Qt6
        REQUIRED
        COMPONENTS
        Core
        Gui
        Widgets
        Svg)

add_library(portable_paint_lib
        STATIC
        src/windows/main_window/MainWindow.hpp src/windows/main_window/MainWindow.cpp
        src/windows/about/AboutDialog.hpp src/windows/about/AboutDialog.cpp
        src/ui/menu_bar/MenuBar.hpp src/ui/menu_bar/MenuBar.cpp
        resources.qrc
)

add_executable(portable_paint src/main.cpp resources.qrc)

target_link_libraries(
        portable_paint_lib
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        Qt::Svg
)

target_link_libraries(portable_paint
        portable_paint_lib
)

