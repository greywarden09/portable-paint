#include <QApplication>

#include "windows/main_window/MainWindow.hpp"


int main(int argc, char **argv) {
    QApplication a(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    return QApplication::exec();
}