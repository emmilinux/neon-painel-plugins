#include "pluginbrightness.h"


void setBrightness(int bright)
{
    Display *display = XOpenDisplay(NULL);
    static Atom backlight = XInternAtom (display, "Backlight", True);
    int screen = 0, o = 0;
    Window root = DefaultRootWindow(display);
    XRRScreenResources *resources = XRRGetScreenResources(display, root);
    RROutput output = resources->outputs[o];
    XRRPropertyInfo *info = XRRQueryOutputProperty(display, output, backlight);
    double min, max;
    long value;

    min = info->values[0];
    max = info->values[1];
    XFree(info);
    XRRFreeScreenResources(resources);

    bright = (bright * max) / 100;

    value = QString::number(bright).toInt();

    XRRChangeOutputProperty(display, output, backlight, XA_INTEGER,
                            32, PropModeReplace, (unsigned char *) &value, 1);

    XFlush(display);
}

int getBrightness()
{
    QString path = "/sys/class/backlight/";
    QDir dir(path);
    QFileInfoList infolist = dir.entryInfoList(QDir::Dirs | QDir::NoDot | QDir::NoDotAndDotDot);

    QFile f(path + infolist.at(0).fileName() + "/brightness");

    if(f.open(QFile::ReadOnly))
    {
        return f.readLine().replace("\n", "").toInt();
    }
    else
    {
        return 0;
    }
}

int maxBrightness()
{
    QString path = "/sys/class/backlight/";
    QDir dir(path);
    QFileInfoList infolist = dir.entryInfoList(QDir::Dirs | QDir::NoDot | QDir::NoDotAndDotDot);

    QFile f(path + infolist.at(0).fileName() + "/max_brightness");

    if(f.open(QFile::ReadOnly))
    {
        return f.readLine().replace("\n", "").toInt();
    }
    else
    {
        return 0;
    }
}
