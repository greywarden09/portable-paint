#include "ViewMenuActions.hpp"

ViewMenuActions::ViewMenuActions(QWidget *parent): parent(parent) {
}

QAction * ViewMenuActions::zoomInAction() const {
    const auto action = new QAction(tr("Zoom In"), parent);
    action->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Plus));
    return action;
}

QAction * ViewMenuActions::zoomOutAction() const {
    const auto action = new QAction(tr("Zoom Out"), parent);
    action->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Minus));
    return action;
}

QAction * ViewMenuActions::fitToWindowAction() const {
    const auto action = new QAction(tr("Fit to Window"), parent);
    return action;
}

QAction * ViewMenuActions::showGridAction() const {
    const auto action = new QAction(tr("Show Grid"), parent);
    return action;
}
