#include "plugincolor.h"


QString changeDatail(int hue, QString light)
{
    QColor color;
    //115
    color = color.fromHsl(hue, 255, light.toInt(), 255);
    return color.name();
}
