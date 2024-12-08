#pragma once

#include <QLabel>
#include <QMainWindow>

class MainWindow final : public QMainWindow {
    Q_OBJECT
    QLabel *cursorPositionLabel;

private slots:
    void updateCursorPosition(const QPoint &point) const;

public:
    explicit MainWindow(QWidget *parent = nullptr);
};
