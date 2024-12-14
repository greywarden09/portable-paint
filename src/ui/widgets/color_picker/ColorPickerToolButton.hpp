#pragma once

#include <QColorDialog>
#include <QToolButton>

#include "../../icon_provider/IconProvider.hpp"

class ColorPickerToolButton final : public QToolButton, protected IconProvider {
    Q_OBJECT
    QMenu *menu;
    QColorDialog *colorDialog;
    QColor currentColor;

private slots:
    void onColorDialogAction();

    void setCurrentColor(QColor color);

public:
    explicit ColorPickerToolButton(QWidget *parent);

signals:
    void colorSelected(QColor color);
    void rejected();
};
