#pragma once

#include <QWidget>
#include <QAction>
#include "../ui/icon_provider/IconProvider.hpp"

class FileMenu final : QObject, IconProvider {
    friend class Actions;

    explicit FileMenu(QWidget *parent): parent(parent) {
    }

    [[nodiscard]] QAction *newAction() const {
        const auto action = new QAction(getIcon("new"), tr("New"), parent);
        action->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_N));
        return action;;
    }

    [[nodiscard]] QAction *openAction() const {
        const auto action = new QAction(getIcon("open"), tr("Open"), parent);
        action->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_O));
        return action;
    }

    [[nodiscard]] QAction *saveAction() const {
        const auto action = new QAction(getIcon("save"), tr("Save"), parent);
        action->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_S));
        return action;
    }

    [[nodiscard]] QAction *saveAsAction() const {
        const auto action = new QAction(tr("Save As..."), parent);
        action->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_S));
        return action;
    }

    [[nodiscard]] QAction *printAction() const {
        const auto action = new QAction(getIcon("print"), tr("Print"), parent);
        action->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_P));
        return action;
    }

    [[nodiscard]] QAction *exitAction() const {
        return new QAction(getIcon("exit"), tr("Exit"), parent);
    }

    QWidget *parent;
};