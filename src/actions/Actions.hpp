#pragma once
#include <QWidget>

#include "edit_menu/EditMenuActions.hpp"
#include "file_menu/FileMenuActions.hpp"
#include "help_menu/HelpMenuActions.hpp"
#include "image_menu/ImageMenuActions.hpp"
#include "tools_menu/ToolsMenuActions.hpp"
#include "view_menu/ViewMenuActions.hpp"
#include "../ui/canvas/Canvas.hpp"

// ReSharper disable CppDFAMemoryLeak
class Actions final : public QObject {
    Q_OBJECT

    QWidget *parent;
    FileMenuActions *fileMenuActions;
    EditMenuActions *editMenuActions;
    ToolsMenuActions *toolsMenuActions;
    ViewMenuActions *viewMenuActions;
    ImageMenuActions *imageMenuActions;
    HelpMenuActions *helpMenuActions;


public:
    explicit Actions(QWidget *parent, Canvas *canvas): parent(parent),
                                                       fileMenuActions(new FileMenuActions(parent)),
                                                       editMenuActions(new EditMenuActions(parent)),
                                                       toolsMenuActions(new ToolsMenuActions(parent, canvas)),
                                                       viewMenuActions(new ViewMenuActions(parent)),
                                                       imageMenuActions(new ImageMenuActions(parent)),
                                                       helpMenuActions(new HelpMenuActions(parent)) {
    }

    QAction *newAction = fileMenuActions->newAction();
    QAction *openAction = fileMenuActions->openAction();
    QAction *saveAction = fileMenuActions->saveAction();
    QAction *saveAsAction = fileMenuActions->saveAsAction();
    QAction *printAction = fileMenuActions->printAction();
    QAction *exitAction = fileMenuActions->exitAction();

    QAction *undoAction = editMenuActions->undoAction();
    QAction *redoAction = editMenuActions->redoAction();
    QAction *cutAction = editMenuActions->cutAction();
    QAction *copyAction = editMenuActions->copyAction();
    QAction *pasteAction = editMenuActions->pasteAction();

    QAction *pencilToolAction = toolsMenuActions->pencilToolAction();
    QAction *brushToolAction = toolsMenuActions->brushToolAction();
    QAction *eraserToolAction = toolsMenuActions->eraserToolAction();
    QAction *lineToolAction = toolsMenuActions->lineToolAction();
    QAction *rectangleToolAction = toolsMenuActions->rectangleToolAction();
    QAction *ellipseToolAction = toolsMenuActions->ellipseToolAction();

    QAction *zoomInAction = viewMenuActions->zoomInAction();
    QAction *zoomOutAction = viewMenuActions->zoomOutAction();
    QAction *fitToWindowAction = viewMenuActions->fitToWindowAction();
    QAction *showGridAction = viewMenuActions->showGridAction();

    QAction *resizeAction = imageMenuActions->resizeAction();
    QAction *cropAction = imageMenuActions->cropAction();
    QAction *rotateLeftAction = imageMenuActions->rotateLeftAction();
    QAction *rotateRightAction = imageMenuActions->rotateRightAction();
    QAction *flipHorizontalAction = imageMenuActions->flipHorizontalAction();
    QAction *flipVerticalAction = imageMenuActions->flipVerticalAction();

    QAction* helpTopicsAction = helpMenuActions->helpTopicsAction();
    QAction* aboutAction = helpMenuActions->aboutAction();
};

// ReSharper restore CppDFAMemoryLeak
