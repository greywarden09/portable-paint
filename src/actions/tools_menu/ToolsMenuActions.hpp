#pragma once

#include "../../ui/canvas/Tool.hpp"
#include "../../ui/icon_provider/IconProvider.hpp"
#include "../../ui/canvas/Canvas.hpp"

class ToolsMenuActions final : QObject, IconProvider {
    Q_OBJECT
    friend class Actions;

    explicit ToolsMenuActions(QWidget *parent, Canvas *canvas);

    [[nodiscard]] QAction *pencilToolAction() const;

    [[nodiscard]] QAction *brushToolAction() const;

    [[nodiscard]] QAction *eraserToolAction() const;

    [[nodiscard]] QAction *lineToolAction() const;

    [[nodiscard]] QAction *rectangleToolAction() const;

    [[nodiscard]] QAction *ellipseToolAction() const;

    QWidget *parent;
    Canvas *canvas;
    QActionGroup *actionGroup;
signals:
    void selectTool(Tool tool) const;
};
