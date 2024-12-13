#include "ToolsMenuActions.hpp"
#include <QActionGroup>

ToolsMenuActions::ToolsMenuActions(QWidget *parent, Canvas *canvas): parent(parent),
                                                                     canvas(canvas),
                                                                     actionGroup(new QActionGroup(parent)) {
}

QAction *ToolsMenuActions::pencilToolAction() const {
    const auto action = new QAction(getIcon("pencil"), tr("Pencil"), parent);
    action->setData(PENCIL);
    action->setCheckable(true);
    action->setChecked(true);
    actionGroup->addAction(action);
    connect(action, &QAction::triggered, canvas, &Canvas::selectTool);
    return action;
}

QAction *ToolsMenuActions::brushToolAction() const {
    const auto action = new QAction(getIcon("brush"), tr("Brush"), parent);
    action->setData(QVariant(BRUSH));
    action->setCheckable(true);
    actionGroup->addAction(action);
    connect(action, &QAction::triggered, canvas, &Canvas::selectTool);
    return action;
}

QAction *ToolsMenuActions::eraserToolAction() const {
    const auto action = new QAction(getIcon("eraser"), tr("Eraser"), parent);
    action->setData(ERASER);
    action->setCheckable(true);
    actionGroup->addAction(action);
    connect(action, &QAction::triggered, canvas, &Canvas::selectTool);
    return action;
}

QAction *ToolsMenuActions::lineToolAction() const {
    const auto action = new QAction(getIcon("line"), tr("Line"), parent);
    action->setData(LINE);
    action->setCheckable(true);
    actionGroup->addAction(action);
    connect(action, &QAction::triggered, canvas, [this] { emit selectTool(LINE); });
    return action;
}

QAction *ToolsMenuActions::rectangleToolAction() const {
    const auto action = new QAction(getIcon("rectangle"), tr("Rectangle"), parent);
    action->setData(RECTANGLE);
    action->setCheckable(true);
    actionGroup->addAction(action);
    connect(action, &QAction::triggered, canvas, [this] { emit selectTool(RECTANGLE); });
    return action;
}

QAction *ToolsMenuActions::ellipseToolAction() const {
    const auto action = new QAction(getIcon("ellipse"), tr("Ellipse"), parent);
    action->setData(ELLIPSE);
    action->setCheckable(true);
    actionGroup->addAction(action);
    connect(action, &QAction::triggered, canvas, [this] { emit selectTool(ELLIPSE); });
    return action;
}
