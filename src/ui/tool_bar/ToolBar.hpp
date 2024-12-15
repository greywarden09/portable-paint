#pragma once
#include <QToolBar>
#include "../../actions/Actions.hpp"
#include "../widgets/color_picker/ColorPickerToolButton.hpp"

class ToolBar final : public QToolBar {
    Q_OBJECT
    Actions *actions;
    ColorPickerToolButton *colorPickerToolButton;
    QAction *eraserToolboxAction;

public:
    explicit ToolBar(Actions *actions, QWidget *parent);

public slots:
    void toggleEraserToolbox(bool eraserActive) const;

signals:
    void colorSelected(QColor color);
    void eraserSizeChanged(int size);
    void selectedSquareShapeEraser();
};
