#include "pluginbrightness.h"


void setBrightness(double bright)
{
    Display *display = XOpenDisplay(NULL);
    static Atom backlight = XInternAtom (display, "Backlight", True);
    int screen = 0, o = 0;
    //Window root = RootWindow(display, screen);
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

    value = bright * (max - min) + min;

    XRRChangeOutputProperty(display, output, backlight, XA_INTEGER,
                            32, PropModeReplace, (unsigned char *) &value, 1);

    XFlush(display);
    //XSync(display, False);
}

double getBrightness()
{
    Display *display = XOpenDisplay(NULL);
    static Atom backlight = XInternAtom (display, "Backlight", True);
    int screen = 0, o = 0;
    //Window root = RootWindow(display, screen);
    Window root = DefaultRootWindow(display);
    XRRScreenResources *resources = XRRGetScreenResources(display, root);
    RROutput output = resources->outputs[o];
    XRRPropertyInfo *info = XRRQueryOutputProperty(display, output, backlight);
    double min, max;
    long value;

    qDebug() << info->values;

    XFree(info);

    return 1.0;
}
