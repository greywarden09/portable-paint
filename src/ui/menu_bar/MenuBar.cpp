#include "MenuBar.hpp"

#include <QIcon>
#include <QFile>
#include <QStyle>
#include <QFileDialog>

#include "../../windows/about/AboutDialog.hpp"

MenuBar::MenuBar(QWidget *parent)
    : QMenuBar(parent) {
    createFileMenu();
    createEditMenu();
    createToolsMenu();
    createViewMenu();
    createImageMenu();
    createHelpMenu();
}

void MenuBar::createFileMenu() {
    fileMenu = addMenu("File");

    newAction = fileMenu->addAction(QIcon(":/resources/new.svg"), "New", QKeyCombination(Qt::CTRL | Qt::Key_N));
    openAction = fileMenu->addAction(QIcon(":/resources/open.svg"), "Open", QKeyCombination(Qt::CTRL | Qt::Key_O));
    saveAction = fileMenu->addAction(QIcon(":/resources/save.svg"), "Save", QKeyCombination(Qt::CTRL | Qt::Key_S));
    saveAction = fileMenu->addAction("Save As...", QKeyCombination(Qt::CTRL | Qt::SHIFT | Qt::Key_S));
    fileMenu->addSeparator();
    fileMenu->addAction(QIcon(":/resources/print.svg"), "Print", QKeyCombination(Qt::CTRL | Qt::Key_P));
    exitAction = fileMenu->addAction(QIcon(":/resources/exit.svg"), "Exit");

    connect(openAction, &QAction::triggered, this, [this] {
        QString selfilter = tr("JPEG (*.jpg *.jpeg)");
        QString fileName = QFileDialog::getOpenFileName(
            this,
            "Open file",
            ".",
            tr("All files (*.*);;JPEG (*.jpg *.jpeg);;PNG (*.png)"),
            &selfilter
        );
    });
}

void MenuBar::createEditMenu() {
    editMenu = addMenu("Edit");

    undoAction = editMenu->addAction(QIcon(":/resources/undo.svg"), "Undo");
    redoAction = editMenu->addAction(QIcon(":/resources/redo.svg"), "Redo");
    editMenu->addSeparator();
    cutAction = editMenu->addAction(QIcon(":/resources/cut.svg"), "Cut", QKeyCombination(Qt::CTRL | Qt::Key_X));
    copyAction = editMenu->addAction(QIcon(":/resources/copy.svg"), "Copy", QKeyCombination(Qt::CTRL | Qt::Key_C));
    pasteAction = editMenu->addAction(QIcon(":/resources/paste.svg"), "Paste", QKeyCombination(Qt::CTRL | Qt::Key_V));
}

void MenuBar::createToolsMenu() {
    toolsMenu = addMenu("Tools");

    pencilToolAction = toolsMenu->addAction(QIcon(":/resources/pencil.svg"), "Pencil");
    pencilToolAction->setCheckable(true);
    brushToolAction = toolsMenu->addAction(QIcon(":/resources/brush.svg"), "Brush");
    brushToolAction->setCheckable(true);
    eraserToolAction = toolsMenu->addAction(QIcon(":/resources/eraser.svg"), "Eraser");
    eraserToolAction->setCheckable(true);

    toolsMenu->addSeparator();
    lineToolAction = toolsMenu->addAction(QIcon(":/resources/line.svg"), "Line");
    rectangleToolAction = toolsMenu->addAction(QIcon(":/resources/rectangle.svg"), "Rectangle");
    ellipseToolAction = toolsMenu->addAction(QIcon(":/resources/circle.svg"), "Ellipse");
}

void MenuBar::createViewMenu() {
    viewMenu = addMenu("View");

    zoomInAction = viewMenu->addAction("Zoom In");
    zoomOutAction = viewMenu->addAction("Zoom Out");
    viewMenu->addSeparator();
    fitToWindowAction = viewMenu->addAction("Fit to Window");
    showGridAction = viewMenu->addAction("Show Grid");
}

void MenuBar::createImageMenu() {
    imageMenu = addMenu("Image");

    imageMenu->addAction("Resize");
    imageMenu->addAction("Crop");
    imageMenu->addSeparator();
    imageMenu->addAction("Rotate Left");
    imageMenu->addAction("Rotate Right");
    imageMenu->addSeparator();
    imageMenu->addAction("Flip Horizontal");
    imageMenu->addAction("Flip Vertical");
}

void MenuBar::createHelpMenu() {
    helpMenu = addMenu("Help");

    helpTopicsAction = helpMenu->addAction("Help Topics");
    helpMenu->addSeparator();
    aboutAction = helpMenu->addAction(QIcon(":/resources/about.svg"), "About");

    connect(aboutAction, &QAction::triggered, this, [this]() {
        AboutDialog dialog(this);
        dialog.exec();
    });
}

QAction *MenuBar::getNewAction() const { return newAction; }
QAction *MenuBar::getOpenAction() const { return openAction; }
QAction *MenuBar::getSaveAction() const { return saveAction; }
QAction *MenuBar::getExitAction() const { return exitAction; }
