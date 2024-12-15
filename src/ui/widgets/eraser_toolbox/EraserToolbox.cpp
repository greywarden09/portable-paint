#include "EraserToolbox.hpp"

#include <QActionGroup>
#include <qboxlayout.h>
#include <QButtonGroup>
#include <QLabel>
#include <QGroupBox>
#include <QSpinBox>
#include <QPushButton>

#include "../color_picker/ColorPickerToolButton.hpp"

// ReSharper disable CppDFAMemoryLeak
EraserToolbox::EraserToolbox(QWidget *parent): QGroupBox(parent),
                                               eraserSize(new QSpinBox(this)) {
    setContentsMargins(0, -5, 0, -5);
    QWidget::setVisible(false);

    const auto layout = new QHBoxLayout(this);
    layout->setSpacing(6);
    layout->addWidget(new QLabel(tr("Tool size:")));

    eraserSize->setMinimum(1);
    eraserSize->setMaximum(255);
    eraserSize->setValue(10);

    const auto eraserShapeButtonGroup = new QButtonGroup(this);
    eraserShapeButtonGroup->setExclusive(true);

    layout->addWidget(eraserSize);

    const auto squareShapeButton = new QPushButton(getIcon("square"), "", this);
    squareShapeButton->setCheckable(true);
    squareShapeButton->setChecked(true);
    const auto circleShapeButton = new QPushButton(getIcon("circle"), "", this);
    circleShapeButton->setCheckable(true);

    eraserShapeButtonGroup->addButton(squareShapeButton);
    eraserShapeButtonGroup->addButton(circleShapeButton);

    layout->addWidget(new QLabel(tr("Shape:")));

    layout->addWidget(squareShapeButton);
    layout->addWidget(circleShapeButton);

    setLayout(layout);

    connect(eraserSize, &QSpinBox::valueChanged, this, &EraserToolbox::eraserSizeChanged);
    connect(squareShapeButton, &QPushButton::pressed, this, &EraserToolbox::selectedSquareShapeEraser);
    connect(circleShapeButton, &QPushButton::pressed, this, &EraserToolbox::selectedCircleShapeEraser);
    connect(this, &EraserToolbox::updateEraserSize, eraserSize, &QSpinBox::setValue);
}

// ReSharper enable CppDFAMemoryLeak
