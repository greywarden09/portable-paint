#pragma once

#include <QLabel>
#include <QMainWindow>

#include "../../ui/canvas/Canvas.hpp"

class MainWindow final : public QMainWindow {
    Q_OBJECT
    QWidget *centralWidget;
    Canvas *canvas;
    QLabel *cursorPositionLabel;

private slots:
    void updateCursorPosition(const QPoint &point) const;

public:
    explicit MainWindow(QWidget *parent = nullptr);

public slots:
    void showAboutDialog();
};
