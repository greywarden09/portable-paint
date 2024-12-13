#pragma once
#include <qwidget.h>
#include <QPainter>

#include "Tool.hpp"

class Canvas final : public QWidget {
    Q_OBJECT

    std::vector<QRgb> pixelArray;
    int width;
    int height;
    QPoint lastPoint;
    QRgb colorPrimary;
    QRgb colorSecondary;
    Tool selectedTool;
    int eraserSize = 10;

    std::function<void(const QPoint&)> drawingHandler;

    //void draw(const QPoint &point);
    void drawPixel(const QPoint &point);
    void erasePixel(const QPoint &point);

    [[nodiscard]] QCursor eraserCursor() const;
    [[nodiscard]] std::vector<QPoint> getAffectedPixels(const QPoint &point) const;

protected:
    void mousePressEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;

    void mouseMoveEvent(QMouseEvent *event) override;

    void paintEvent(QPaintEvent *event) override;

    void interpolateLine(const QPoint &start, const QPoint &end);

public:
    explicit Canvas(QWidget *parent = nullptr);

public slots:
    void selectTool();

signals:
    void cursorPositionChanged(const QPoint &point);
};


