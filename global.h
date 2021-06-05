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
#include <string>
#include <QString>
#include <QDebug>
#include <QTimer>
#include <QTime>

#include "singleton.h"
#include "Chess.h"

//#include "allBRChessesInclude.h"

class GlobalEnvironment {
public:
    GlobalEnvironment();
    virtual void __refreshBoard();
    virtual void __printBoard();
    virtual void __printAlive();
    virtual QString __int2QStrName(int name);
    virtual QString __QString2SimpleName(QString originName);
    virtual int __QStr2intName(QString name);
    virtual Chess* __QStrOrInt2Chess(int chessNameSimple, int number);
    virtual Chess* __QStrOrInt2Chess(QString chessNameSimple, int number);
    virtual void __delayMsec(int Msec);
    virtual bool __isThereHasChess(SGeoPoint* Pos);
    virtual bool __isThereHasChess(int PosX, int PosY);
    virtual bool __isChessOnThere(Chess* chess, SGeoPoint* Pos);
    virtual int __BoardEvaluate();
    virtual int __calculateAlive();
    virtual int __isWholeBoardEntire();
    virtual bool __isOtherChessAround(int chessNum, int chessNumber);
    virtual double __countSpaceAround(int chessNum, int chessNumber);
    int ** __board; // result of chess identify, 0-14
                    // 0: empty
                    // 1-7:  black
                    // 8-14: red
    char * __chessArray; // 0-13
};

// extern Qml_Connection* QmlConnect;
extern QObject* object; // control the whole graphic panel

typedef NormalSingleton< GlobalEnvironment > GlobalEnvirIn;

#endif // GLOBAL_H
