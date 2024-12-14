#pragma once
#include <QToolBar>
#include "../../actions/Actions.hpp"
#include "../widgets/color_picker/ColorPickerToolButton.hpp"

class ToolBar final : public QToolBar {
    Q_OBJECT
    Actions *actions;
    ColorPickerToolButton *colorPickerToolButton;

public:
    explicit ToolBar(Actions *actions, QWidget *parent);

signals:
    void colorSelected(QColor color);
};
