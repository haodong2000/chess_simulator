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

#include "globalChesses.h"

#include "singleton.h"

class TestChessMove
{
public:
    TestChessMove();
    virtual void LoopMove(int indexMaxIn = 5);
    virtual void turnSwitch(int indexSwitch = 5);
    virtual void testEvaluate();
    virtual void testIsThereOurChess();
    virtual void testWhichChessOnThere();
    virtual void testHorseGenerateMove();
    virtual void testElephantGenerateMove();
    virtual void testGeneralGenerateMove();
    virtual void testSoldierGenerateMove();

};

typedef NormalSingleton< TestChessMove > TestChessMoveIn;

#endif // TESTCHESSMOVE_H
