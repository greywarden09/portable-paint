#include "HelpMenuActions.hpp"

const auto baseAboutMessage = "<h2>PaintApp v1.0</h2>"
        "<p>Simple and multi-platform painting application.</p>"
        "<p><b>Author: </b>Marcin Las</p>"
        "<p><b>License: </b> MIT License</p>"
        "<p>GitHub: <a href='https://github.com/greywarden09/portable-paint'>github.com/greywarden09/portable-paint</a></p>";

HelpMenuActions::HelpMenuActions(QWidget *parent): parent(parent) {
}

QAction *HelpMenuActions::helpTopicsAction() const {
    const auto action = new QAction(tr("Help Topics"), parent);
    return action;
}

QAction *HelpMenuActions::aboutAction() const {
    const auto action = new QAction(getIcon("about"), tr("About"), parent);
    connect(action, &QAction::triggered, this, [this] {
        showAboutDialog();
    });
    return action;
}

void HelpMenuActions::showAboutDialog() const {
    QMessageBox aboutBox(parent);
    aboutBox.setWindowTitle(tr("About"));
    aboutBox.setText(tr(baseAboutMessage));
    aboutBox.setIcon(QMessageBox::Information);
    aboutBox.exec();
}
