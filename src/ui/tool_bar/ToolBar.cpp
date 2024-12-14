#include "ToolBar.hpp"

#include "../../actions/Actions.hpp"
#include "../widgets/color_picker/ColorPickerToolButton.hpp"

ToolBar::ToolBar(Actions *actions, QWidget *parent) : QToolBar(parent),
                                                      actions(actions),
                                                      colorPickerToolButton(new ColorPickerToolButton(this)) {
    addAction(actions->pencilToolAction);
    addAction(actions->brushToolAction);
    addAction(actions->eraserToolAction);
    addSeparator();
    addWidget(colorPickerToolButton);

    connect(colorPickerToolButton, &ColorPickerToolButton::colorSelected, this, &ToolBar::colorSelected);
}
