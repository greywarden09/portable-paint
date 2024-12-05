#include "AboutDialog.hpp"

AboutDialog::AboutDialog(QWidget *parent) : QDialog(parent) {
    resize(600, 400);
    setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);
    setWindowTitle("About");
}
