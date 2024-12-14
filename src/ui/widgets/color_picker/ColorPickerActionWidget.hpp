#pragma once

#include <QWidgetAction>

#include "ColorPickerToolButton.hpp"

class ColorPickerActionWidget final : public QWidgetAction {
    Q_OBJECT
    QColorDialog *colorDialog;
    QColor currentColor;

public:
    explicit ColorPickerActionWidget(ColorPickerToolButton *parent);

public slots:
    void setCurrentColor(QColor color);

    void aboutToShow() const;

    void aboutToHide() const;

signals:
    void rejected();

    void colorSelected(QColor color);
};
