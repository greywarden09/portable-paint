#pragma once

#include <QWidget>
#include <QAction>
#include "../../ui/icon_provider/IconProvider.hpp"

class FileMenuActions final : QObject, IconProvider {
    Q_OBJECT
    friend class Actions;

    explicit FileMenuActions(QWidget *parent);

    [[nodiscard]] QAction *newAction() const;

    [[nodiscard]] QAction *openAction() const;

    [[nodiscard]] QAction *saveAction() const;

    [[nodiscard]] QAction *saveAsAction() const;

    [[nodiscard]] QAction *printAction() const;

    [[nodiscard]] QAction *exitAction() const;

    QWidget *parent;
};