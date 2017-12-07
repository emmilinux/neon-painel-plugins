#include "plugincolor.h"


QString changeDatail(int hue, QString n)
{
    QColor color;
    color = color.fromHsl(hue, 255, 115, 255);
    return color.name();
}
