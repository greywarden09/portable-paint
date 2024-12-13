#pragma once

#include <QWidget>
#include "../../ui/icon_provider/IconProvider.hpp"

class ImageMenuActions final : QObject, IconProvider {
    Q_OBJECT

    friend class Actions;

    explicit ImageMenuActions(QWidget *parent);

    [[nodiscard]] QAction *resizeAction() const;

    [[nodiscard]] QAction *cropAction() const;

    [[nodiscard]] QAction *rotateLeftAction() const;

    [[nodiscard]] QAction *rotateRightAction() const;

    [[nodiscard]] QAction *flipHorizontalAction() const;

    [[nodiscard]] QAction *flipVerticalAction() const;

    QWidget *parent;
};
