#ifndef PYTHONMUDULE_H
#define PYTHONMUDULE_H

#include <QThread>
#include <QString>
#include <QDebug>

#include "Chess.h"

class PythonMudule: public QThread
{
public:
    PythonMudule(QString N = "default_name");
    void run() override;

private:
    QString name;
};

#endif // PYTHONMUDULE_H
