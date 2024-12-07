#pragma once
#include <QIcon>


class IconProvider {
    static QIcon renderIcon(const QString &iconPath, const QColor &color);

    QColor currentColor;

public:
    IconProvider();

    QIcon getIcon(const QString &iconName) const;
};
