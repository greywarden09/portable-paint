#include "FileMenuActions.hpp"

FileMenuActions::FileMenuActions(QWidget *parent): parent(parent) {
}

QAction *FileMenuActions::newAction() const {
    const auto action = new QAction(getIcon("new"), tr("New"), parent);
    action->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_N));
    return action;;
}

QAction *FileMenuActions::openAction() const {
    const auto action = new QAction(getIcon("open"), tr("Open"), parent);
    action->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_O));
    return action;
}

QAction *FileMenuActions::saveAction() const {
    const auto action = new QAction(getIcon("save"), tr("Save"), parent);
    action->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_S));
    return action;
}

QAction *FileMenuActions::saveAsAction() const {
    const auto action = new QAction(tr("Save As..."), parent);
    action->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_S));
    return action;
}

QAction *FileMenuActions::printAction() const {
    const auto action = new QAction(getIcon("print"), tr("Print"), parent);
    action->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_P));
    return action;
}

QAction *FileMenuActions::exitAction() const {
    const auto action = new QAction(getIcon("exit"), tr("Exit"), parent);
    return action;
}
