#include "ColorPickerActionWidget.hpp"

#include "ColorPickerToolButton.hpp"

ColorPickerActionWidget::ColorPickerActionWidget(ColorPickerToolButton *parent)
    : QWidgetAction(parent),
      colorDialog(new QColorDialog(parent)) {
    colorDialog->setWindowFlags(Qt::Widget);
    colorDialog->setOptions(QColorDialog::DontUseNativeDialog);

    connect(colorDialog, &QColorDialog::colorSelected, this, &ColorPickerActionWidget::colorSelected);
    connect(colorDialog, &QColorDialog::rejected, this, &ColorPickerActionWidget::rejected);

    setDefaultWidget(colorDialog);
}

void ColorPickerActionWidget::aboutToShow() const {
    colorDialog->setCurrentColor(currentColor);
    colorDialog->show();
}

void ColorPickerActionWidget::aboutToHide() const {
    colorDialog->hide();
}

void ColorPickerActionWidget::setCurrentColor(const QColor color) {
    this->currentColor = color;
}
