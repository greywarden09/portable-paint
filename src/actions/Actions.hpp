#pragma once
#include <QWidget>
#include <QActionGroup>
#include <QMessageBox>

#include "../tools/Tools.hpp"
#include "../ui/canvas/Canvas.hpp"
#include "../ui/icon_provider/IconProvider.hpp"
#include "../windows/main_window/MainWindow.hpp"

// ReSharper disable CppDFAMemoryLeak
class Actions final : public QObject {
    Q_OBJECT

    QWidget *parent;

    class FileMenu final : QObject, IconProvider {
        friend class Actions;

        explicit FileMenu(QWidget *parent): parent(parent) {
        }

        [[nodiscard]] QAction *newAction() const {
            const auto action = new QAction(getIcon("new"), tr("New"), parent);
            action->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_N));
            return action;;
        }

        [[nodiscard]] QAction *openAction() const {
            const auto action = new QAction(getIcon("open"), tr("Open"), parent);
            action->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_O));
            return action;
        }

        [[nodiscard]] QAction *saveAction() const {
            const auto action = new QAction(getIcon("save"), tr("Save"), parent);
            action->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_S));
            return action;
        }

        [[nodiscard]] QAction *saveAsAction() const {
            const auto action = new QAction(tr("Save As..."), parent);
            action->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_S));
            return action;
        }

        [[nodiscard]] QAction *printAction() const {
            const auto action = new QAction(getIcon("print"), tr("Print"), parent);
            action->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_P));
            return action;
        }

        [[nodiscard]] QAction *exitAction() const {
            return new QAction(getIcon("exit"), tr("Exit"), parent);
        }

        QWidget *parent;
    } FileMenu;

    class EditMenu final : QObject, IconProvider {
        friend class Actions;

        explicit EditMenu(QWidget *parent): parent(parent) {
        }

        [[nodiscard]] QAction *undoAction() const {
            const auto action = new QAction(getIcon("undo"), tr("Undo"), parent);
            action->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Z));
            return action;
        }

        [[nodiscard]] QAction *redoAction() const {
            const auto action = new QAction(getIcon("redo"), tr("Redo"), parent);
            action->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Y));
            return action;
        }

        [[nodiscard]] QAction *cutAction() const {
            const auto action = new QAction(getIcon("cut"), tr("Cut"), parent);
            action->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_X));
            return action;
        }

        [[nodiscard]] QAction *copyAction() const {
            const auto action = new QAction(getIcon("copy"), tr("Copy"), parent);
            action->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_C));
            return action;
        }

        [[nodiscard]] QAction *pasteAction() const {
            const auto action = new QAction(getIcon("paste"), tr("Paste"), parent);
            action->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_V));
            return action;
        }

        QWidget *parent;
    } EditMenu;

    class ToolsMenu final : QObject, IconProvider {

        friend class Actions;

        explicit ToolsMenu(QWidget *parent, Canvas *canvas): parent(parent),
                                                             canvas(canvas),
                                                             actionGroup(new QActionGroup(parent)) {
        }

        [[nodiscard]] QAction *pencilToolAction() const {
            const auto action = new QAction(getIcon("pencil"), tr("Pencil"), parent);
            action->setData(PENCIL);
            action->setCheckable(true);
            action->setChecked(true);
            actionGroup->addAction(action);
            connect(action, &QAction::triggered, canvas, &Canvas::selectTool);
            return action;
        }

        [[nodiscard]] QAction *brushToolAction() const {
            const auto action = new QAction(getIcon("brush"), tr("Brush"), parent);
            action->setData(BRUSH);
            action->setCheckable(true);
            actionGroup->addAction(action);
            connect(action, &QAction::triggered, canvas, &Canvas::selectTool);
            return action;
        }

        [[nodiscard]] QAction *eraserToolAction() const {
            const auto action = new QAction(getIcon("eraser"), tr("Eraser"), parent);
            action->setData(ERASER);
            action->setCheckable(true);
            actionGroup->addAction(action);
            connect(action, &QAction::triggered, canvas, &Canvas::selectTool);
            return action;
        }

        [[nodiscard]] QAction *lineToolAction() const {
            const auto action = new QAction(getIcon("line"), tr("Line"), parent);
            action->setData(LINE);
            action->setCheckable(true);
            actionGroup->addAction(action);
            connect(action, &QAction::triggered, canvas, &Canvas::selectTool);
            return action;
        }

        [[nodiscard]] QAction *rectangleToolAction() const {
            const auto action = new QAction(getIcon("rectangle"), tr("Rectangle"), parent);
            action->setData(RECTANGLE);
            action->setCheckable(true);
            actionGroup->addAction(action);
            connect(action, &QAction::triggered, canvas, &Canvas::selectTool);
            return action;
        }

        [[nodiscard]] QAction *ellipseToolAction() const {
            const auto action = new QAction(getIcon("ellipse"), tr("Ellipse"), parent);
            action->setData(RECTANGLE);
            action->setCheckable(true);
            actionGroup->addAction(action);
            connect(action, &QAction::triggered, canvas, &Canvas::selectTool);
            return action;
        }

        QWidget *parent;
        Canvas *canvas;
        QActionGroup *actionGroup;
    } ToolsMenu;

    class ViewMenu final : QObject, IconProvider {
        friend class Actions;

        explicit ViewMenu(QWidget *parent): parent(parent) {
        }

        [[nodiscard]] QAction *zoomInAction() const {
            const auto action = new QAction(tr("Zoom In"), parent);
            action->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Plus));
            return action;
        }

        [[nodiscard]] QAction *zoomOutAction() const {
            const auto action = new QAction(tr("Zoom Out"), parent);
            action->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Minus));
            return action;
        }

        [[nodiscard]] QAction *fitToWindowAction() const {
            const auto action = new QAction(tr("Fit to Window"), parent);
            return action;
        }

        [[nodiscard]] QAction *showGridAction() const {
            const auto action = new QAction(tr("Fit to Window"), parent);
            return action;
        }

        QWidget *parent;
    } ViewMenu;

    class ImageMenu final : QObject, IconProvider {
        friend class Actions;

        explicit ImageMenu(QWidget *parent): parent(parent) {
        }

        [[nodiscard]] QAction *resizeAction() const {
            const auto action = new QAction(tr("Resize"), parent);
            return action;
        }

        [[nodiscard]] QAction *cropAction() const {
            const auto action = new QAction(tr("Crop"), parent);
            return action;
        }

        [[nodiscard]] QAction *rotateLeftAction() const {
            const auto action = new QAction(tr("Rotate Left"), parent);
            return action;
        }

        [[nodiscard]] QAction *rotateRightAction() const {
            const auto action = new QAction(tr("Rotate Right"), parent);
            return action;
        }

        [[nodiscard]] QAction *flipHorizontalAction() const {
            const auto action = new QAction(tr("Rotate Left"), parent);
            return action;
        }

        [[nodiscard]] QAction *flipVerticalAction() const {
            const auto action = new QAction(tr("Rotate Left"), parent);
            return action;
        }

        QWidget *parent;
    } ImageMenu;

    class HelpMenu final : QObject, IconProvider {
        friend class Actions;

        explicit HelpMenu(QWidget *parent): parent(parent) {
        }

        [[nodiscard]] QAction *helpTopicsAction() const {
            const auto action = new QAction(tr("Help Topics"), parent);
            return action;
        }

        [[nodiscard]] QAction *aboutAction() const {
            const auto action = new QAction(getIcon("about"), tr("Help Topics"), parent);
            //connect(action, &QAction::triggered, *this, &HelpMenu::showAboutDialog);
            return action;
        }

    public slots:
        void showAboutDialog() {
            QMessageBox aboutBox(parent);
            aboutBox.setWindowTitle(tr("About"));
            aboutBox.setText(
                tr("<h2>PaintApp v1.0</h2>"
                    "<p>Simple and multi-platform painting application.</p>"
                    "<p><b>Author: </b>Marcin Las</p>"
                    "<p><b>License: </b> MIT License</p>"
                    "<p>GitHub: <a href='https://github.com/greywarden09/portable-paint'>github.com/greywarden09/portable-paint</a></p>")
            );
            aboutBox.setIcon(QMessageBox::Information);
            aboutBox.exec();
        }


        QWidget *parent;
    } HelpMenu;

public:
    explicit Actions(QWidget *parent, Canvas *canvas): parent(parent),
                                                       FileMenu(parent),
                                                       EditMenu(parent),
                                                       ToolsMenu(parent, canvas),
                                                       ViewMenu(parent),
                                                       ImageMenu(parent),
                                                       HelpMenu(parent) {
    }

    QAction *newAction = FileMenu.newAction();
    QAction *openAction = FileMenu.openAction();
    QAction *saveAction = FileMenu.saveAction();
    QAction *saveAsAction = FileMenu.saveAsAction();
    QAction *printAction = FileMenu.printAction();
    QAction *exitAction = FileMenu.exitAction();

    QAction *undoAction = EditMenu.undoAction();
    QAction *redoAction = EditMenu.redoAction();
    QAction *cutAction = EditMenu.cutAction();
    QAction *copyAction = EditMenu.copyAction();
    QAction *pasteAction = EditMenu.pasteAction();

    QAction *pencilToolAction = ToolsMenu.pencilToolAction();
    QAction *brushToolAction = ToolsMenu.brushToolAction();
    QAction *eraserToolAction = ToolsMenu.eraserToolAction();
    QAction *lineToolAction = ToolsMenu.lineToolAction();
    QAction *rectangleToolAction = ToolsMenu.rectangleToolAction();
    QAction *ellipseToolAction = ToolsMenu.ellipseToolAction();

    QAction *zoomInAction = ViewMenu.zoomInAction();
    QAction *zoomOutAction = ViewMenu.zoomOutAction();
    QAction *fitToWindowAction = ViewMenu.fitToWindowAction();
    QAction *showGridAction = ViewMenu.showGridAction();

    QAction *resizeAction = ImageMenu.resizeAction();
    QAction *cropAction = ImageMenu.cropAction();
    QAction *rotateLeftAction = ImageMenu.rotateLeftAction();
    QAction *rotateRightAction = ImageMenu.rotateRightAction();
    QAction *flipHorizontalAction = ImageMenu.flipHorizontalAction();
    QAction *flipVerticalAction = ImageMenu.flipVerticalAction();
};

// ReSharper restore CppDFAMemoryLeak
