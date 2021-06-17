#include "PythonMudule.h"

PythonMudule::PythonMudule(QString N):name(N)
{

}

void PythonMudule::run() {
    qDebug() << this->name << "hello world";
    for(int i = 0; i < 10; i++)
    {
        qDebug() << "====================    " << this->name << " -> " << i << "    ====================";
    }
}
