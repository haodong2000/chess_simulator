#ifndef TESTCHESSMOVE_H
#define TESTCHESSMOVE_H

/*****************************************************************
*   File:     TestChessMove.h
*   Author:   Haodong LI
*   Usage:    TestChessMove
*   Time:     2021-06-01 -> 08:27:41
*****************************************************************/

#include <QTimer>
#include <QObject>

#include "singleton.h"

class TestChessMove
{
public:
    TestChessMove();
    virtual void LoopMove(int indexMaxIn = 5);
    virtual void turnSwitch(int indexSwitch = 5);

};

typedef NormalSingleton< TestChessMove > TestChessMoveIn;

#endif // TESTCHESSMOVE_H
