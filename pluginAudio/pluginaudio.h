#ifndef PLUGINAUDIO_H
#define PLUGINAUDIO_H

#include <QProcess>
#include <QDebug>

extern "C" {
    int getVolume();
    int getMicro();
    void setVolume(int n, QString valor);
    void setMicro(int n, QString valor);
}

#endif // PLUGINAUDIO_H
