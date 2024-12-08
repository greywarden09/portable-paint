#pragma once
#include <qwidget.h>

class Canvas final : public QWidget {
    Q_OBJECT

    std::vector<QRgb> pixelArray;
    int width;
    int height;
    QPoint lastPoint;

    enum SelectedTool {
        PENCIL,
        BRUSH,
        ERASER,
        LINE,
        RECTANGLE,
        ELLIPSE
    } selectedTool;

    void drawPixel(const QPoint &point);

protected:
    void mousePressEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;

    void mouseMoveEvent(QMouseEvent *event) override;

    void paintEvent(QPaintEvent *event) override;

    void interpolateLine(const QPoint &start, const QPoint &end);

public:
    explicit Canvas(QWidget *parent = nullptr);

public slots:
    void selectTool(const int &tool);

signals:
    void cursorPositionChanged(const QPoint &point);
};
