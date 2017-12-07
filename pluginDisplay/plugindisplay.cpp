#include "plugindisplay.h"


void displayChange(int go, QString n)
{
    Display *display = QX11Info::display();
    Window root = DefaultRootWindow(display);
    XEvent xev;
    Atom wm_state  =  XInternAtom(display, "_NET_CURRENT_DESKTOP", False);

    memset(&xev, 0, sizeof(xev));
    xev.type = ClientMessage;
    xev.xclient.window = root;
    xev.xclient.message_type = wm_state;
    xev.xclient.format = 32;
    xev.xclient.data.l[0] = go;
    xev.xclient.data.l[1] = CurrentTime;

    XSendEvent(display, root, False, SubstructureNotifyMask, &xev);

    XFlush(display);
}

int displayLength()
{
    QProcess process;
    process.start("xfconf-query -c xfwm4 -p /general/workspace_count");
    process.waitForFinished();
    QString size = process.readLine().replace("\n", "");
    process.close();

    return size.toInt();
}

void setMoreDisplay(int num, QString n)
{
    Display *display = QX11Info::display();
    Window root = DefaultRootWindow(display);
    XEvent xev;
    Atom wm_state  =  XInternAtom(display, "_NET_NUMBER_OF_DESKTOPS", False);

    memset(&xev, 0, sizeof(xev));
    xev.type = ClientMessage;
    xev.xclient.window = root;
    xev.xclient.message_type = wm_state;
    xev.xclient.format = 32;
    xev.xclient.data.l[0] = num;
    xev.xclient.data.l[1] = CurrentTime;

    XSendEvent(display, root, False, SubstructureNotifyMask, &xev);

    XFlush(display);
}
