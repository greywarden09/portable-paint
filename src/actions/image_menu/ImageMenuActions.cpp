#include "ImageMenuActions.hpp"

ImageMenuActions::ImageMenuActions(QWidget *parent): parent(parent) {
}

QAction *ImageMenuActions::resizeAction() const {
    const auto action = new QAction(tr("Resize"), parent);
    return action;
}

QAction *ImageMenuActions::cropAction() const {
    const auto action = new QAction(tr("Crop"), parent);
    return action;
}

QAction *ImageMenuActions::rotateLeftAction() const {
    const auto action = new QAction(tr("Rotate Left"), parent);
    return action;
}

QAction *ImageMenuActions::rotateRightAction() const {
    const auto action = new QAction(tr("Rotate Right"), parent);
    return action;
}

QAction *ImageMenuActions::flipHorizontalAction() const {
    const auto action = new QAction(tr("Rotate Left"), parent);
    return action;
}

QAction *ImageMenuActions::flipVerticalAction() const {
    const auto action = new QAction(tr("Rotate Left"), parent);
    return action;
}
