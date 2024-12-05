#pragma once

#include <QMenuBar>
#include <QObject>

class MenuBar final : public QMenuBar {
    Q_OBJECT

public:
    explicit MenuBar(QWidget *parent = nullptr);

    QAction *getNewAction() const;

    QAction *getOpenAction() const;

    QAction *getSaveAction() const;

    QAction *getExitAction() const;

private:
    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *toolsMenu;
    QMenu *viewMenu;
    QMenu *imageMenu;
    QMenu *helpMenu;

    QAction *newAction{};
    QAction *openAction{};
    QAction *saveAction{};
    QAction *exitAction{};

    QAction *undoAction{};
    QAction *redoAction{};
    QAction *cutAction{};
    QAction *copyAction{};
    QAction *pasteAction{};
    QAction *clearAction{};

    QAction *brushToolAction{};
    QAction *eraserToolAction{};
    QAction *lineToolAction{};
    QAction *rectangleToolAction{};
    QAction *ellipseToolAction{};

    QAction *zoomInAction{};
    QAction *zoomOutAction{};
    QAction *fitToWindowAction{};
    QAction *showGridAction{};

    QAction *helpTopicsAction{};
    QAction *aboutAction{};
    QAction * pencilToolAction{};

    void createFileMenu();

    void createEditMenu();

    void createToolsMenu();

    void createViewMenu();

    void createImageMenu();

    void createHelpMenu();
};

