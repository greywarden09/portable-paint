#include "IconProvider.hpp"

#include <QApplication>
#include <QFile>
#include <QSvgRenderer>
#include <QPainter>
#include <qpalette.h>

QIcon IconProvider::renderIcon(const QString &iconPath, const QColor &color) {
    QSvgRenderer renderer(iconPath);
    if (!renderer.isValid()) {
        return {};
    }

    const QSize size = renderer.defaultSize().isValid() ? renderer.defaultSize() : QSize(100, 100);
    QPixmap pixmap(size);
    pixmap.fill(Qt::transparent);

    QPainter painter(&pixmap);
    renderer.render(&painter);
    painter.end();

    QPixmap coloredPixmap(size);
    coloredPixmap.fill(Qt::transparent);

    QPainter colorPainter(&coloredPixmap);
    colorPainter.setCompositionMode(QPainter::CompositionMode_Source);
    colorPainter.fillRect(coloredPixmap.rect(), color);
    colorPainter.setCompositionMode(QPainter::CompositionMode_DestinationIn);
    colorPainter.drawPixmap(0, 0, pixmap);
    colorPainter.end();

    return {coloredPixmap};
}

IconProvider::IconProvider() {
    currentColor = QApplication::palette().color(QPalette::WindowText);;
}

QIcon IconProvider::getIcon(const QString &iconName) const {
    const auto iconPath = ":/resources/" + iconName + ".svg";
    if (!QFile::exists(iconPath)) {
        return {};
    }
    return renderIcon(iconPath, currentColor);
}
