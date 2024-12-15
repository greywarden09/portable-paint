#pragma once
#include <qframe.h>
#include <QGroupBox>
#include <QSpinBox>

#include "../../icon_provider/IconProvider.hpp"

class EraserToolbox final : public QGroupBox, public IconProvider {
    Q_OBJECT

    QSpinBox *eraserSize;

public:
    explicit EraserToolbox(QWidget *parent);

signals:
    void eraserSizeChanged(int size) const;
    void updateEraserSize(int size) const;
    void pickedEraserShape(int id, bool selected) const;
    void selectedSquareShapeEraser() const;
    void selectedCircleShapeEraser() const;
};
