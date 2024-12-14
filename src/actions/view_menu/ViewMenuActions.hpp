#pragma once

#include <QWidget>
#include "../../ui/icon_provider/IconProvider.hpp"

class ViewMenuActions final : QObject, IconProvider {
    Q_OBJECT
    friend class Actions;

    explicit ViewMenuActions(QWidget *parent);

    [[nodiscard]] QAction *zoomInAction() const;

    [[nodiscard]] QAction *zoomOutAction() const;

    [[nodiscard]] QAction *fitToWindowAction() const;

    [[nodiscard]] QAction *showGridAction() const;

    QWidget *parent;
};