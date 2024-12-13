#pragma once

#include <QWidget>
#include "../../ui/icon_provider/IconProvider.hpp"

class ViewMenuActions final : QObject, IconProvider {
    friend class Actions;

    explicit ViewMenuActions(QWidget *parent): parent(parent) {
    }

    [[nodiscard]] QAction *zoomInAction() const {
        const auto action = new QAction(tr("Zoom In"), parent);
        action->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Plus));
        return action;
    }

    [[nodiscard]] QAction *zoomOutAction() const {
        const auto action = new QAction(tr("Zoom Out"), parent);
        action->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Minus));
        return action;
    }

    [[nodiscard]] QAction *fitToWindowAction() const {
        const auto action = new QAction(tr("Fit to Window"), parent);
        return action;
    }

    [[nodiscard]] QAction *showGridAction() const {
        const auto action = new QAction(tr("Show Grid"), parent);
        return action;
    }

    QWidget *parent;
};