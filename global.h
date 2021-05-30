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
    SGeoPoint __black_general;  // 1 - 1
    SGeoPoint __black_advisor;  // 2 - 1
    SGeoPoint __black_elephant; // 3 - 1
    SGeoPoint __black_horse;    // 4 - 1
    SGeoPoint __black_chariot;  // 5 - 1
    SGeoPoint __black_cannon;   // 6 - 1
    SGeoPoint __black_soldier;  // 7 - 1
    SGeoPoint __red_general;    // 8 - 1
    SGeoPoint __red_advisor;    // 9 - 1
    SGeoPoint __red_elephant;   // 10 - 1
    SGeoPoint __red_horse;      // 11 - 1
    SGeoPoint __red_chariot;    // 12 - 1
    SGeoPoint __red_cannon;     // 13 - 1
    SGeoPoint __red_soldier;    // 14 - 1
};

#endif // GLOBAL_H
