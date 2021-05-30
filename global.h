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

class GlobalEnvironment {
public:
    GlobalEnvironment();
    virtual void __refreshBoard();
    virtual void __printBoard();
    int ** __board;
    char * __chessArray;
    SGeoPoint __black_general;
    SGeoPoint __black_advisor;
    SGeoPoint __black_elephant;
    SGeoPoint __black_horse;
    SGeoPoint __black_chariot;
    SGeoPoint __black_cannon;
    SGeoPoint __black_soldier;
    SGeoPoint __red_general;
    SGeoPoint __red_advisor;
    SGeoPoint __red_elephant;
    SGeoPoint __red_horse;
    SGeoPoint __red_chariot;
    SGeoPoint __red_cannon;
    SGeoPoint __red_soldier;
};

#endif // GLOBAL_H
