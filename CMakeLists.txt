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
        src/actions/Actions.hpp
        src/actions/file_menu/FileMenuActions.hpp src/actions/file_menu/FileMenuActions.cpp
        src/actions/edit_menu/EditMenuActions.hpp src/actions/edit_menu/EditMenuActions.cpp
        src/actions/tools_menu/ToolsMenuActions.hpp src/actions/tools_menu/ToolsMenuActions.cpp
        src/actions/view_menu/ViewMenuActions.hpp src/actions/view_menu/ViewMenuActions.cpp
        src/actions/image_menu/ImageMenuActions.hpp src/actions/image_menu/ImageMenuActions.cpp
        src/actions/help_menu/HelpMenuActions.hpp src/actions/help_menu/HelpMenuActions.cpp
        src/ui/canvas/Tool.hpp
        src/ui/canvas/EraserShape.hpp
        src/windows/main_window/MainWindow.hpp src/windows/main_window/MainWindow.cpp
        src/ui/icon_provider/IconProvider.hpp src/ui/icon_provider/IconProvider.cpp
        src/ui/menu_bar/MenuBar.hpp src/ui/menu_bar/MenuBar.cpp
        src/ui/canvas/Canvas.hpp src/ui/canvas/Canvas.cpp
        src/ui/tool_bar/ToolBar.hpp src/ui/tool_bar/ToolBar.cpp
        src/ui/widgets/color_picker/ColorPickerToolButton.hpp src/ui/widgets/color_picker/ColorPickerToolButton.cpp
        src/ui/widgets/color_picker/ColorPickerActionWidget.hpp src/ui/widgets/color_picker/ColorPickerActionWidget.cpp
        src/ui/widgets/eraser_toolbox/EraserToolbox.hpp src/ui/widgets/eraser_toolbox/EraserToolbox.cpp
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
