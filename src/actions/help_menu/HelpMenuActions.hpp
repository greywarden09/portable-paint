#pragma once

#include <QMessageBox>
#include "../../ui/icon_provider/IconProvider.hpp"

class HelpMenuActions final : QObject, IconProvider {
    friend class Actions;

    QWidget *parent;

    explicit HelpMenuActions(QWidget *parent);

    [[nodiscard]] QAction *helpTopicsAction() const;

    [[nodiscard]] QAction *aboutAction() const;

    void showAboutDialog() const;
};
