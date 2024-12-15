#pragma once
#include <qwidget.h>
#include <functional>
#include <QPainter>

#include "EraserShape.hpp"
#include "Tool.hpp"

class Canvas final : public QWidget {
    Q_OBJECT

    unsigned short eraserSize;
    std::vector<QRgb> pixelArray;
    int width;
    int height;
    QPoint lastPoint;
    QRgb colorPrimary;
    Tool selectedTool;
    EraserShape eraserShape;

    std::function<void(const QPoint &)> drawingHandler;

    void drawPixel(const QPoint &point);

    void erasePixel(const QPoint &point);

    void updateEraserSize(const QWheelEvent *event);

    [[nodiscard]] QCursor eraserCursor() const;

    [[nodiscard]] std::vector<QPoint> getAffectedPixels(const QPoint &point) const;

protected:
    void mousePressEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;

    void mouseMoveEvent(QMouseEvent *event) override;

    void paintEvent(QPaintEvent *event) override;

    void wheelEvent(QWheelEvent *event) override;

    void interpolateLine(const QPoint &start, const QPoint &end);

public:
    explicit Canvas(QWidget *parent = nullptr);

public slots:
    void selectTool();

    void colorSelected(QColor color);

    void changeEraserSize(int newSize);

    void setSquareEraserShape();

    void setCircleEraserShape();

signals:
    void cursorPositionChanged(const QPoint &point);

    void eraserSizeChanged(int newSize);
};
