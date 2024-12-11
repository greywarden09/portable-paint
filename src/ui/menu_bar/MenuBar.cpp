#include "MenuBar.hpp"

#include <QButtonGroup>
#include <QMessageBox>
#include <QAbstractButton>
#include <QActionGroup>

#include "../canvas/Canvas.hpp"

MenuBar::MenuBar(Actions *actions, QWidget *parent)
    : QMenuBar(parent),
      actions(actions),
      fileMenu(addMenu(tr("File"))),
      editMenu(addMenu(tr("Edit"))),
      toolsMenu(addMenu(tr("Tools"))),
      viewMenu(addMenu(tr("View"))),
      imageMenu(addMenu(tr("Image"))),
      helpMenu(addMenu(tr("Help"))) {
    createFileMenu();
    createEditMenu();
    createToolsMenu();
    createViewMenu();
    createImageMenu();
    createHelpMenu();
}

void MenuBar::createFileMenu() {
    fileMenu->addActions({
        actions->newAction,
        actions->openAction,
        actions->saveAction,
        actions->saveAsAction,
        addSeparator(),
        actions->printAction,
        actions->exitAction
    });
}

void MenuBar::createEditMenu() {
    editMenu->addActions({
        actions->undoAction,
        actions->redoAction,
        addSeparator(),
        actions->cutAction,
        actions->copyAction,
        actions->pasteAction
    });
}

void MenuBar::createToolsMenu() {
    toolsMenu->addActions({
        actions->pencilToolAction,
        actions->brushToolAction,
        actions->eraserToolAction,
        addSeparator(),
        actions->lineToolAction,
        actions->rectangleToolAction,
        actions->ellipseToolAction
    });
}

void MenuBar::createViewMenu() {
    viewMenu->addActions({
        actions->zoomInAction,
        actions->zoomOutAction,
        addSeparator(),
        actions->fitToWindowAction,
        actions->showGridAction,
    });
}

void MenuBar::createImageMenu() {
    imageMenu->addActions({
        actions->resizeAction,
        actions->cropAction,
        addSeparator(),
        actions->rotateLeftAction,
        actions->rotateRightAction,
        addSeparator(),
        actions->flipHorizontalAction,
        actions->flipVerticalAction
    });
}

void MenuBar::createHelpMenu() {
    helpMenu->addAction(tr("Help Topics"));
    helpMenu->addSeparator();
    helpMenu->addAction(getIcon("about"), tr("About"));
}
