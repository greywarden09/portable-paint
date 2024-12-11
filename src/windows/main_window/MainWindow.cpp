#include "MainWindow.hpp"

#include <QVBoxLayout>
#include <QStatusBar>
#include <QWidget>
#include <QLabel>
#include <QMessageBox>
#include <QToolBar>
#include <QSpinBox>

#include "../../ui/canvas/Canvas.hpp"
#include "../../ui/menu_bar/MenuBar.hpp"

// ReSharper disable CppDFAMemoryLeak
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), cursorPositionLabel(new QLabel("X: 0, Y: 0", this)) {
    resize(800, 600);
    setWindowTitle("Portable Paint");


    const auto centralWidget = new QWidget(this);
    const auto layout = new QVBoxLayout(centralWidget);
    const auto canvas = new Canvas(centralWidget);
    layout->addWidget(canvas);
    setCentralWidget(centralWidget);

    const auto actions = new Actions(this, canvas);
    const auto menuBar = new MenuBar(actions, this);
    setMenuBar(menuBar);


    const auto toolBar = new QToolBar(this);

    toolBar->addSeparator();

    addToolBar(Qt::TopToolBarArea, toolBar);

    const auto statusBar = new QStatusBar(this);
    statusBar->addPermanentWidget(cursorPositionLabel);

    setStatusBar(statusBar);

    connect(canvas, &Canvas::cursorPositionChanged, this, &MainWindow::updateCursorPosition);
    connect(menuBar, &MenuBar::toolSelected, canvas, &Canvas::selectTool);
}

void MainWindow::showAboutDialog() {
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
}

void MainWindow::updateCursorPosition(const QPoint &point) const {
    cursorPositionLabel->setText(QString("X: %1, Y: %2").arg(point.x()).arg(point.y()));
}

// ReSharper enable CppDFAMemoryLeak
