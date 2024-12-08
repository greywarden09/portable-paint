#include "MainWindow.hpp"

#include <QVBoxLayout>
#include <QStatusBar>
#include <QWidget>
#include <QLabel>
#include <QToolBar>
#include <QSpinBox>
#include <QStackedWidget>

#include "../../ui/canvas/Canvas.hpp"
#include "../../ui/menu_bar/MenuBar.hpp"

// ReSharper disable CppDFAMemoryLeak
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), cursorPositionLabel(new QLabel("X: 0, Y: 0",this)) {
    resize(800, 600);
    setWindowTitle("Portable Paint");

    const auto menuBar = new MenuBar(this);
    setMenuBar(menuBar);

    const auto centralWidget = new QWidget(this);
    const auto layout = new QVBoxLayout(centralWidget);
    const auto canvas = new Canvas(centralWidget);
    layout->addWidget(canvas);
    setCentralWidget(centralWidget);

    const auto toolBar = new QToolBar(this);

    toolBar->addAction(menuBar->getPencilToolAction());
    toolBar->addAction(menuBar->getBrushToolAction());
    toolBar->addAction(menuBar->getEraserToolAction());

    toolBar->addSeparator();

    toolBar->addAction(menuBar->getLineToolAction());
    toolBar->addAction(menuBar->getRectangleToolAction());
    toolBar->addAction(menuBar->getEllipseToolAction());

    toolBar->addSeparator();

    addToolBar(Qt::TopToolBarArea, toolBar);

    const auto statusBar = new QStatusBar(this);
    statusBar->addPermanentWidget(cursorPositionLabel);

    setStatusBar(statusBar);

    connect(canvas, &Canvas::cursorPositionChanged, this, &MainWindow::updateCursorPosition);
    connect(menuBar, &MenuBar::toolSelected, canvas, &Canvas::selectTool);
}

void MainWindow::updateCursorPosition(const QPoint &point) const {
    cursorPositionLabel->setText(QString("X: %1, Y: %2").arg(point.x()).arg(point.y()));
}



// ReSharper enable CppDFAMemoryLeak