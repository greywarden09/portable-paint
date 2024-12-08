#include "Canvas.hpp"
#include <QMouseEvent>
#include <QImage>
#include <QPainter>

#include "../../windows/main_window/MainWindow.hpp"
#include "../menu_bar/MenuBar.hpp"

Canvas::Canvas(QWidget *parent): QWidget(parent),
                                 width(512),
                                 height(512),
                                 selectedTool(PENCIL) {
    pixelArray.resize(width * height, qRgb(255, 255, 255));
    setMouseTracking(true);
}

void Canvas::selectTool(const int &tool) {
    this->selectedTool = static_cast<SelectedTool>(tool);
}

void Canvas::drawPixel(const QPoint &point) {
    const auto x = point.x();
    const auto y = point.y();
    const auto componentWidth = this->width;
    const auto componentHeight = this->height;

    if (x >= 0 && x < componentWidth && y >= 0 && y < componentHeight) {
        pixelArray[y * componentWidth + x] = qRgb(0, 0, 0);
        update(QRect(point, QSize(1, 1)));
    }
}

void Canvas::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        lastPoint = event->pos();
        drawPixel(event->pos());
    }
}

void Canvas::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        lastPoint = QPoint(-1, -1);
    }
}

void Canvas::mouseMoveEvent(QMouseEvent *event) {
    if (event->buttons() & Qt::LeftButton) {
        interpolateLine(lastPoint, event->pos());
        lastPoint = event->pos();
    }
    if (event->pos().x() <= this->width && event->pos().y() <= this->height) {
        emit cursorPositionChanged(event->pos());
    }
}

void Canvas::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    const QImage image(reinterpret_cast<uchar *>(pixelArray.data()), width, height, QImage::Format_ARGB32);
    painter.drawImage(0, 0, image);
}

void Canvas::interpolateLine(const QPoint &start, const QPoint &end) {
    if (start == QPoint(-1, -1)) {
        drawPixel(end);
        return;
    }

    const auto startX = static_cast<float>(start.x());
    const auto startY = static_cast<float>(start.y());
    const auto endX = static_cast<float>(end.x());
    const auto endY = static_cast<float>(end.y());

    auto dx = std::abs(endX - startX);
    auto dy = std::abs(endY - startY);
    auto steps = static_cast<int>(std::max(dx, dy));

    for (int i = 0; i <= steps; ++i) {
        float t = static_cast<float>(i) / static_cast<float>(steps);
        auto x = startX + t * (endX - startX);
        auto y = startY + t * (endY - startY);
        drawPixel(QPoint(static_cast<int>(x), static_cast<int>(y)));
    }
}
