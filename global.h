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
#include <QtGlobal>

#include "singleton.h"
#include "Chess.h"

//#include "allBRChessesInclude.h"

class GlobalEnvironment {
public:
    GlobalEnvironment();
    virtual void __refreshBoard();
    virtual void __printBoard();
    virtual void __printAlive();
    virtual void __QString2Board(QString origin_message);
    virtual void __printVisionBoard();
    virtual QString __int2QStrName(int name);
    virtual QString __QString2SimpleName(QString originName);
    virtual int __QStr2intName(QString name);
    virtual Chess* __QStrOrInt2Chess(int chessNameSimple, int number);
    virtual Chess* __QStrOrInt2Chess(QString chessNameSimple, int number);
    virtual void __delayMsec(int Msec);
    virtual bool __isPosInBoard(SGeoPoint* Pos);
    virtual bool __isPosInBoard(int PosX, int PosY);
    virtual bool __isThereHasChess(SGeoPoint* Pos);
    virtual bool __isThereHasChess(int PosX, int PosY);
    virtual bool __isThereHasOurChess(bool camp, SGeoPoint* Pos); // false is black and true is red
    virtual bool __isThereHasOurChess(bool camp, int PosX, int PosY);
    virtual Chess* __whichChessOnThere(SGeoPoint* Pos);
    virtual Chess* __whichChessOnThere(int PosX, int PosY);
    virtual bool __isChessOnThere(Chess* chess, SGeoPoint* Pos);
    virtual void __killThisChess(int killNum, int killNumber);
    virtual void __fakeKillThisChess(int killNum, int killNumber);
    virtual void __setGameTurn(bool whosTurn);
    virtual bool __isHumanStepValid(chessStep step);
    virtual void __refershPosValueUnit();
    virtual int __BoardEvaluate();
    virtual int __calculateBlackSpaceValue();
    virtual int __calculateRedSpaceValue();
    virtual int __calculateBlackChessValue();
    virtual int __calculateRedChessValue();
    virtual int __calculateBlackPosValue();
    virtual int __calculateRedPosValue();
    virtual int __boardValueBlackUnit(int x, int y);
    virtual int __boardValueRedUnit(int x, int y);
    virtual int __calculateAlive();
    virtual int __isWholeBoardEntire();
    virtual bool __isOtherChessAround(int chessNum, int chessNumber);
    virtual double __countSpaceAround(int chessNum, int chessNumber);
    virtual int __countChessInPath(SGeoPoint* start, SGeoPoint* end);
    virtual int __generateRandomNumber(int maxNumber);
    virtual bool __isOnlyTwoGeneralsInRow();
    int ** __board; // result of chess identify, 0-14
                    // 0: empty
                    // 1-7:  black
                    // 8-14: red
    int ** __visionBoard;
    int ** __boardValueBlack;
    int ** __boardValueRed;
    char * __chessArray; // 0-13
};

extern bool __curTurn;
// extern Qml_Connection* QmlConnect;
extern QObject* object; // control the whole graphic panel
extern int SEARCH_DEPTH;
extern int STRATEGY_MODE;
// extern int M_human_index;
extern int ** Main_chessBoard;
extern bool Is_Game_Start;
extern bool Is_Game_No_Play;
extern bool Is_CIMC_EndGame;
extern int BASIC_DEPTH;
extern int BEST_EXPONENT;
extern int MAX_SEARCH_NODES;
extern int CHESS_PLAY_MODE;

typedef NormalSingleton< GlobalEnvironment > GlobalEnvirIn;

#endif // GLOBAL_H
