#include "ToolBar.hpp"

#include "../../actions/Actions.hpp"
#include "../widgets/color_picker/ColorPickerToolButton.hpp"
#include "../widgets/eraser_toolbox/EraserToolbox.hpp"

ToolBar::ToolBar(Actions *actions, QWidget *parent) : QToolBar(parent),
                                                      actions(actions),
                                                      colorPickerToolButton(
                                                          new ColorPickerToolButton(this)) {
    setIconSize(QSize(32, 32));
    const auto eraserToolBox = new EraserToolbox(this);

    addAction(actions->pencilToolAction);
    addAction(actions->brushToolAction);
    addAction(actions->eraserToolAction);
    addSeparator();
    addWidget(colorPickerToolButton);
    addSeparator();
    this->eraserToolboxAction = addWidget(eraserToolBox);

    connect(actions->eraserToolAction, &QAction::toggled, this, &ToolBar::toggleEraserToolbox);
    connect(eraserToolBox, &EraserToolbox::eraserSizeChanged, this, &ToolBar::eraserSizeChanged);
    connect(eraserToolBox, &EraserToolbox::selectedSquareShapeEraser, this, &ToolBar::selectedSquareShapeEraser);
    connect(eraserToolBox, &EraserToolbox::selectedCircleShapeEraser, this, &ToolBar::selectedCircleShapeEraser);
    connect(this, &ToolBar::eraserSizeChanged, eraserToolBox, &EraserToolbox::updateEraserSize);
    connect(colorPickerToolButton, &ColorPickerToolButton::colorSelected, this, &ToolBar::colorSelected);
}

void ToolBar::toggleEraserToolbox(const bool eraserActive) const {
    this->eraserToolboxAction->setVisible(eraserActive);
}
