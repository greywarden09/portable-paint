#include "MenuBar.hpp"

#include <QButtonGroup>
#include <QMessageBox>
#include <QAbstractButton>
#include <QList>

MenuBar::MenuBar(QWidget *parent)
    : QMenuBar(parent),
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
    newAction = fileMenu->addAction(getIcon("new"), tr("New"), QKeyCombination(Qt::CTRL | Qt::Key_N));
    openAction = fileMenu->addAction(getIcon("open"), tr("Open"), QKeyCombination(Qt::CTRL | Qt::Key_O));
    saveAction = fileMenu->addAction(getIcon("save"), tr("Save"), QKeyCombination(Qt::CTRL | Qt::Key_S));
    saveAsAction = fileMenu->addAction(tr("Save As..."), QKeyCombination(Qt::CTRL | Qt::SHIFT | Qt::Key_S));
    fileMenu->addSeparator();
    fileMenu->addAction(getIcon("print"), tr("Print"), QKeyCombination(Qt::CTRL | Qt::Key_P));
    exitAction = fileMenu->addAction(getIcon("exit"), tr("Exit"));
}

void MenuBar::createEditMenu() {
    undoAction = editMenu->addAction(getIcon("undo"), tr("Undo"), QKeyCombination(Qt::CTRL | Qt::Key_Z));
    redoAction = editMenu->addAction(getIcon("redo"), tr("Redo"), QKeyCombination(Qt::CTRL | Qt::Key_Y));
    editMenu->addSeparator();
    cutAction = editMenu->addAction(getIcon("cut"), tr("Cut"), QKeyCombination(Qt::CTRL | Qt::Key_X));
    copyAction = editMenu->addAction(getIcon("copy"), tr("Copy"), QKeyCombination(Qt::CTRL | Qt::Key_C));
    pasteAction = editMenu->addAction(getIcon("paste"), tr("Paste"), QKeyCombination(Qt::CTRL | Qt::Key_V));
}

void MenuBar::createToolsMenu() {
    pencilToolAction = toolsMenu->addAction(getIcon("pencil"), tr("Pencil"));
    brushToolAction = toolsMenu->addAction(getIcon("brush"), tr("Brush"));
    eraserToolAction = toolsMenu->addAction(getIcon("eraser"), tr("Eraser"));

    toolsMenu->addSeparator();

    lineToolAction = toolsMenu->addAction(getIcon("line"), tr("Line"));
    rectangleToolAction = toolsMenu->addAction(getIcon("rectangle"), tr("Rectangle"));
    ellipseToolAction = toolsMenu->addAction(getIcon("circle"), tr("Ellipse"));

    auto actions = std::vector{
        pencilToolAction,
        brushToolAction,
        eraserToolAction,
        lineToolAction,
        rectangleToolAction,
        ellipseToolAction
    };

    actions[selectedTool]->setChecked(true);

    for (int i = 0; i < actions.size(); ++i) {
        QAction *action = actions[i];
        action->setCheckable(true);
        connect(action, &QAction::triggered, this, [i, this, actions]() {
            if (i == selectedTool) {
                actions[i]->setChecked(true);
                return;
            }
            actions[selectedTool]->setChecked(false);
            selectedTool = i;
            actions[selectedTool]->setChecked(true);
            emit toolSelected(selectedTool);
        });
    }
}

void MenuBar::createViewMenu() {
    zoomInAction = viewMenu->addAction(tr("Zoom In"));
    zoomOutAction = viewMenu->addAction(tr("Zoom Out"));
    viewMenu->addSeparator();
    fitToWindowAction = viewMenu->addAction(tr("Fit to Window"));
    showGridAction = viewMenu->addAction(tr("Show Grid"));
}

void MenuBar::createImageMenu() {
    imageMenu->addAction(tr("Resize"));
    imageMenu->addAction(tr("Crop"));
    imageMenu->addSeparator();
    imageMenu->addAction(tr("Rotate Left"));
    imageMenu->addAction(tr("Rotate Right"));
    imageMenu->addSeparator();
    imageMenu->addAction(tr("Flip Horizontal"));
    imageMenu->addAction(tr("Flip Vertical"));
}

void MenuBar::createHelpMenu() {
    helpTopicsAction = helpMenu->addAction(tr("Help Topics"));
    helpMenu->addSeparator();
    aboutAction = helpMenu->addAction(getIcon("about"), tr("About"));

    connect(aboutAction, &QAction::triggered, this, [this] {
        QMessageBox aboutBox(this);
        aboutBox.setWindowTitle(tr("About"));
        aboutBox.setText(
            tr("<h2>PaintApp v1.0</h2>"
                "<p>Simple and multi-platform painting application.</p>"
                "<p><b>Author: </b>Marcin Las</p>"
                "<p><b>License: </b> MIT License</p>"
                "<p>GitHub: <a href='https://github.com/greywarden09/portable-paint'>github.com/greywarden09/portable-paint</a></p>")
        );
        aboutBox.setIcon(QMessageBox::Information);
        aboutBox.exec();
    });
}

QAction *MenuBar::getNewAction() const { return newAction; }
QAction *MenuBar::getOpenAction() const { return openAction; }
QAction *MenuBar::getSaveAction() const { return saveAction; }
QAction *MenuBar::getExitAction() const { return exitAction; }
QAction *MenuBar::getPencilToolAction() const { return pencilToolAction; }
QAction *MenuBar::getBrushToolAction() const { return brushToolAction; }
QAction *MenuBar::getEraserToolAction() const { return eraserToolAction; }
QAction *MenuBar::getLineToolAction() const { return lineToolAction; }
QAction *MenuBar::getRectangleToolAction() const { return rectangleToolAction; }
QAction *MenuBar::getEllipseToolAction() const { return ellipseToolAction; }
