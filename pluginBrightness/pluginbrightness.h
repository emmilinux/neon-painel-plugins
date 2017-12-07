#ifndef PLUGINBRIGHTNESS_H
#define PLUGINBRIGHTNESS_H

#include <QDebug>

#include <X11/Xatom.h>
#include <X11/Xlib.h>
#include <X11/extensions/Xrandr.h>

extern "C" void setBrightness(double bright);
extern "C" double getBrightness();

#endif // PLUGINBRIGHTNESS_H
