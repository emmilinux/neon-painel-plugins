#ifndef PLUGINDISPLAY_H
#define PLUGINDISPLAY_H

#include <QProcess>
#include <QDebug>
#include <QX11Info>

#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <X11/Xutil.h>


extern "C" void displayChange(int d, QString n);
extern "C" int displayLength();
extern "C" void setMoreDisplay(int num, QString n);

#endif // PLUGINDISPLAY_H
