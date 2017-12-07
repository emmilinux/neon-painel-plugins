#include "pluginaudio.h"


int getVolume()
{
    QProcess *process = new QProcess();
    process->start("amixer get Master");
    process->waitForFinished();
    QString result = process->readAll();
    result = result.split("%]")[0].split("[")[1];
    process->close();
    return result.toInt();
}

int getMicro()
{
    QProcess *process = new QProcess();
    process->start("amixer get Capture");
    process->waitForFinished();
    QString result = process->readAll();
    result = result.split("%]")[0].split("[")[1];
    process->close();
    return result.toInt();
}

void setVolume(int n, QString valor)
{
    QProcess process;
    valor = valor.append("%");
    process.start("amixer set Master " + valor);
    process.waitForFinished();
    process.close();
}

void setMicro(int n, QString valor)
{
    QProcess process;
    valor = valor.append("%");
    process.start("amixer set Capture " + valor);
    process.waitForFinished();
    process.close();
}
