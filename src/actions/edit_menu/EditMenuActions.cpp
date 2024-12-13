#include "EditMenuActions.hpp"

EditMenuActions::EditMenuActions(QWidget *parent): parent(parent) {
}

QAction *EditMenuActions::undoAction() const {
    const auto action = new QAction(getIcon("undo"), tr("Undo"), parent);
    action->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Z));
    return action;
}

QAction *EditMenuActions::redoAction() const {
    const auto action = new QAction(getIcon("redo"), tr("Redo"), parent);
    action->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Y));
    return action;
}

QAction *EditMenuActions::cutAction() const {
    const auto action = new QAction(getIcon("cut"), tr("Cut"), parent);
    action->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_X));
    return action;
}

QAction *EditMenuActions::copyAction() const {
    const auto action = new QAction(getIcon("copy"), tr("Copy"), parent);
    action->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_C));
    return action;
}

QAction *EditMenuActions::pasteAction() const {
    const auto action = new QAction(getIcon("paste"), tr("Paste"), parent);
    action->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_V));
    return action;
}
