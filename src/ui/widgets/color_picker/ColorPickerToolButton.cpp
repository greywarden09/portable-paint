#include "ColorPickerToolButton.hpp"
#include <QMenu>

#include "ColorPickerActionWidget.hpp"

// ReSharper disable CppDFAMemoryLeak
ColorPickerToolButton::ColorPickerToolButton(QWidget *parent): QToolButton(parent),
                                                               menu(new QMenu(this)),
                                                               colorDialog(new QColorDialog(this)),
                                                               currentColor(QColor(0, 0, 0)) {
    const auto colorPickerActionWidget = new ColorPickerActionWidget(this);
    menu->addAction(colorPickerActionWidget);
    setPopupMode(MenuButtonPopup);

    setMenu(menu);

    auto *colorDialogAction = new QAction(this);
    setDefaultAction(colorDialogAction);

    connect(colorDialogAction, &QAction::triggered, this, &ColorPickerToolButton::onColorDialogAction);
    connect(colorDialog, &QColorDialog::colorSelected, colorPickerActionWidget,
            &ColorPickerActionWidget::setCurrentColor);
    connect(colorPickerActionWidget, &ColorPickerActionWidget::colorSelected, this, &ColorPickerToolButton::setCurrentColor);

    connect(colorPickerActionWidget, &ColorPickerActionWidget::colorSelected, menu, &QMenu::hide);
    connect(colorPickerActionWidget, &ColorPickerActionWidget::rejected, menu, &QMenu::hide);

    connect(menu, &QMenu::aboutToShow, colorPickerActionWidget, &ColorPickerActionWidget::aboutToShow);
    connect(menu, &QMenu::aboutToHide, colorPickerActionWidget, &ColorPickerActionWidget::aboutToHide);

    connect(colorDialog, &QColorDialog::colorSelected, this, &ColorPickerToolButton::colorSelected);
    connect(colorPickerActionWidget, &ColorPickerActionWidget::colorSelected, this, &ColorPickerToolButton::colorSelected);

    setIcon(getIcon("palette"));
}

void ColorPickerToolButton::onColorDialogAction() {
    colorDialog->setWindowFlags(Qt::SubWindow | Qt::Dialog);
    colorDialog->setOption(QColorDialog::DontUseNativeDialog, false);
    colorDialog->setCurrentColor(currentColor);
    if (colorDialog->exec() == QColorDialog::Accepted) {
        setCurrentColor(colorDialog->currentColor());
    }
}

void ColorPickerToolButton::setCurrentColor(const QColor color) {
    this->currentColor = color;
}

// ReSharper enable CppDFAMemoryLeak
