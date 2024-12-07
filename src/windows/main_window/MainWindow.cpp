#include "MainWindow.hpp"
#include <QToolBar>
#include <QStatusBar>
#include <qwidget.h>
#include <QStyle>
#include <QLabel>

#include "../../ui/menu_bar/MenuBar.hpp"

// ReSharper disable CppDFAMemoryLeak
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    resize(800, 600);
    setWindowTitle("Portable Paint");
    resize(800, 600);

    const auto menuBar = new MenuBar(this);
    setMenuBar(menuBar);

    const auto statusBar = new QStatusBar(this);
    const auto cursorPositionLabel = new QLabel("X: 0, Y: 0", this);
    statusBar->addPermanentWidget(cursorPositionLabel);

    setStatusBar(statusBar);
}

MainWindow::~MainWindow() = default;

// ReSharper enable CppDFAMemoryLeak