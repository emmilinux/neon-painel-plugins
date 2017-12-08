#ifndef PLUGINBRIGHTNESS_H
#define PLUGINBRIGHTNESS_H

#include <QDebug>
#include <QFile>
#include <QFileInfoList>
#include <QDir>

#include <X11/Xatom.h>
#include <X11/Xlib.h>
#include <X11/extensions/Xrandr.h>

extern "C" void setBrightness(int bright);
extern "C" int getBrightness();
extern "C" int maxBrightness();

#endif // PLUGINBRIGHTNESS_H
