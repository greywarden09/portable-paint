#include "Canvas.hpp"
#include <QMouseEvent>
#include <QImage>
#include <QPainter>
#include <QVariant>

#include "../../windows/main_window/MainWindow.hpp"
#include "../menu_bar/MenuBar.hpp"

Canvas::Canvas(QWidget *parent): QWidget(parent),
                                 width(512),
                                 height(400),
                                 selectedTool(PENCIL),
                                 colorPrimary(qRgb(255, 0, 0)),
                                 colorSecondary(qRgb(255, 255, 255)) {
    setFixedSize(width, height);
    QPalette palette;
    palette.setColor(QPalette::Window, Qt::white);
    setAutoFillBackground(true);
    setPalette(palette);

    drawingHandler = [this](const QPoint &pos) {
        drawPixel(pos);
    };

    pixelArray.resize(width * height, qRgba(0, 0, 0, 0));
    setMouseTracking(true);
}

QCursor Canvas::eraserCursor() const {
    QPixmap pixmap(eraserSize, eraserSize);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(Qt::black);
    painter.setBrush(Qt::white);
    painter.drawRect(0, 0, eraserSize, eraserSize);
    painter.end();

    return QCursor(pixmap);
}

std::vector<QPoint> Canvas::getAffectedPixels(const QPoint &point) const {
    std::vector<QPoint> result;
    const auto halfSize = eraserSize / 2;
    const auto startX = point.x() - halfSize;
    const auto startY = point.y() - halfSize;
    const auto endX = point.x() + halfSize;
    const auto endY = point.y() + halfSize;

    for (auto y = startY; y <= endY; ++y) {
        for (int x = startX; x <= endX; ++x) {
            result.emplace_back(x, y);
        }
    }

    return result;
}

void Canvas::selectTool() {
    const auto action = qobject_cast<QAction *>(sender());
    const auto tool = static_cast<Tool>(action->data().toInt());
    this->selectedTool = tool;
    switch (tool) {
        case ERASER:
            drawingHandler = [this](const QPoint &pos) {
                erasePixel(pos);
            };
            setCursor(eraserCursor());
            break;
        default:
            unsetCursor();
    }
}

/*void Canvas::rotateRight() {
    std::vector<QRgb> rotatedImage(pixelArray.size());

    const auto newWidth = height;
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            const auto srcIndex = row * width + col;
            const auto destIndex = col * newWidth + (height - row - 1);
            rotatedImage[destIndex] = pixelArray[srcIndex];
        }
    }
    pixelArray = std::move(rotatedImage);
    std::swap(width, height);

    update();
}

void Canvas::rotateLeft() {
    std::vector<QRgb> rotatedImage(pixelArray.size());

    const auto newWidth = height;
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            const auto srcIndex = row * width + col;
            const auto destIndex = (width - col - 1) * newWidth + row;
            rotatedImage[destIndex] = pixelArray[srcIndex];
        }
    }
    pixelArray = std::move(rotatedImage);
    std::swap(width, height);

    update();
}*/

void Canvas::drawPixel(const QPoint &point) {
    const auto x = point.x();
    const auto y = point.y();
    const auto componentWidth = this->width;
    const auto componentHeight = this->height;

    if (x >= 0 && x < componentWidth && y >= 0 && y < componentHeight) {
        pixelArray[y * componentWidth + x] = colorPrimary;
        update(QRect(point, QSize(1, 1)));
    }
}

void Canvas::erasePixel(const QPoint &point) {
    auto pixels = getAffectedPixels(point);

    for (const auto &pixel: pixels) {
        const auto x = pixel.x();
        const auto y = pixel.y();
        if (x >= 0 && x < this->width && y >= 0 && y < this->height) {
            pixelArray[y * this->width + x] = qRgba(0, 0, 0, 0);
        }
    }
    update(QRect(point.x() - eraserSize / 2, point.y() - eraserSize / 2, eraserSize, eraserSize));
}

void Canvas::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        lastPoint = event->pos();
        drawingHandler(event->pos());
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
    emit cursorPositionChanged(event->pos());
}

void Canvas::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    const QImage image(reinterpret_cast<uchar *>(pixelArray.data()), width, height, QImage::Format_ARGB32);
    painter.drawImage(0, 0, image);
}

void Canvas::interpolateLine(const QPoint &start, const QPoint &end) {
    if (start == QPoint(-1, -1)) {
        drawingHandler(end);
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
        drawingHandler(QPoint(static_cast<int>(x), static_cast<int>(y)));
    }
}
