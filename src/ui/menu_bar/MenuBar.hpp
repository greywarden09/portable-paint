#pragma once

#include <QMenuBar>
#include <QObject>

#include "../../actions/Actions.hpp"
#include "../icon_provider/IconProvider.hpp"

class MenuBar final : public QMenuBar, IconProvider {
    Q_OBJECT
    Actions *actions;

    QMenu *fileMenu{};
    QMenu *editMenu{};
    QMenu *toolsMenu{};
    QMenu *viewMenu{};
    QMenu *imageMenu{};
    QMenu *helpMenu{};

    void createFileMenu();

    void createEditMenu();

    void createToolsMenu();

    void createViewMenu();

    void createImageMenu();

    void createHelpMenu();

public:
    explicit MenuBar(Actions *actions, QWidget *parent = nullptr);

signals:
    void toolSelected(const int &tool);
};
