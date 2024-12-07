#include <QApplication>
#include <QTranslator>

#include "windows/main_window/MainWindow.hpp"

int main(int argc, char **argv) {
    QApplication a(argc, argv);

    QTranslator translator;
    if (translator.load(QLocale(), "portable_paint", "_")) {
        QApplication::installTranslator(&translator);
    }

    MainWindow mainWindow;
    mainWindow.show();
    return QApplication::exec();
}
