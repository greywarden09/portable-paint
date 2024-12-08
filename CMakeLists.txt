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
        Svg
        LinguistTools
)

add_library(portable_paint_lib
        STATIC
        src/windows/main_window/MainWindow.hpp src/windows/main_window/MainWindow.cpp
        src/ui/icon_provider/IconProvider.hpp src/ui/icon_provider/IconProvider.cpp
        src/ui/menu_bar/MenuBar.hpp src/ui/menu_bar/MenuBar.cpp
        src/ui/canvas/Canvas.hpp src/ui/canvas/Canvas.cpp
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

qt_standard_project_setup(I18N_TRANSLATED_LANGUAGES en pl)
qt_add_translations(TARGETS portable_paint
        TS_FILE_DIR translations)
