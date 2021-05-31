#ifndef GLOBAL_H
#define GLOBAL_H

/* * * * * * * * * * * * * * * * * * * * *
*   File:     global.h
*   Author:   Haodong LI
*   Usage:    global include files
*   Time:     2021-05-30
* * * * * * * * * * * * * * * * * * * * * */

#include "Params.h"
#include "SGeoPoint.h"
#include <QObject>
#include <QVector>
#include <iostream>
#include <string.h>
#include <QString>
#include <QDebug>

#include "singleton.h"
#include "Qml_Connection.h"

class GlobalEnvironment {
public:
    GlobalEnvironment();
    virtual void __refreshBoard();
    virtual void __printBoard();
    int ** __board; // result of chess identify, 0-14
                    // 0: empty
                    // 1-7:  black
                    // 8-14: red
    char * __chessArray; // 0-13
    Qml_Connection QmlConnect;
};

typedef NormalSingleton< GlobalEnvironment > GlobalEnvirIn;

#endif // GLOBAL_H
