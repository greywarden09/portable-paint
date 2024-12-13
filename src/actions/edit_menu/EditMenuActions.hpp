#pragma once

#include <QWidget>
#include "../../ui/icon_provider/IconProvider.hpp"

class EditMenuActions final : QObject, IconProvider {
    Q_OBJECT

    friend class Actions;

    explicit EditMenuActions(QWidget *parent);

    [[nodiscard]] QAction *undoAction() const;

    [[nodiscard]] QAction *redoAction() const;

    [[nodiscard]] QAction *cutAction() const;

    [[nodiscard]] QAction *copyAction() const;

    [[nodiscard]] QAction *pasteAction() const;

    QWidget *parent;
};
