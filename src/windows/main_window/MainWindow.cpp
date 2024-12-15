#include "MainWindow.hpp"

#include <QVBoxLayout>
#include <QStatusBar>
#include <QWidget>
#include <QLabel>
#include <QMessageBox>
#include <QToolBar>

#include "../../actions/Actions.hpp"
#include "../../ui/menu_bar/MenuBar.hpp"
#include "../../ui/tool_bar/ToolBar.hpp"

// ReSharper disable CppDFAMemoryLeak
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          centralWidget(new QWidget(this)),
                                          canvas(new Canvas(this)),
                                          cursorPositionLabel(new QLabel("X: 0, Y: 0", this)) {
    resize(800, 600);
    setWindowTitle("Portable Paint");

    const auto layout = new QGridLayout(centralWidget);
    layout->addWidget(canvas, 0, 0, 10, 10, Qt::AlignTop | Qt::AlignLeft);
    setCentralWidget(centralWidget);

    const auto actions = new Actions(this, canvas);
    const auto menuBar = new MenuBar(actions, this);
    setMenuBar(menuBar);

    const auto toolBar = new ToolBar(actions, this);

    addToolBar(Qt::TopToolBarArea, toolBar);

    const auto statusBar = new QStatusBar(this);
    statusBar->addPermanentWidget(cursorPositionLabel);

    setStatusBar(statusBar);

    connect(canvas, &Canvas::cursorPositionChanged, this, &MainWindow::updateCursorPosition);
    connect(canvas, &Canvas::eraserSizeChanged, toolBar, &ToolBar::eraserSizeChanged);
    connect(toolBar, &ToolBar::selectedSquareShapeEraser, canvas, &Canvas::setSquareEraserShape);
    connect(toolBar, &ToolBar::selectedCircleShapeEraser, canvas, &Canvas::setCircleEraserShape);
    connect(toolBar, &ToolBar::eraserSizeChanged, canvas, &Canvas::changeEraserSize);
    connect(toolBar, &ToolBar::colorSelected, canvas, &Canvas::colorSelected);
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
