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

#include "singleGame.h"

class TestChessMove
{
public:
    TestChessMove();
    virtual void LoopMove(int indexMaxIn = 5);
    virtual void turnSwitch(int indexSwitch = 5);
    virtual void testEvaluate();
    virtual void testIsThereOurChess();
    virtual void testWhichChessOnThere();

    virtual void testMemory();

    virtual void testHorseGenerateMove();
    virtual void testElephantGenerateMove();
    virtual void testGeneralGenerateMove();
    virtual void testSoldierGenerateMove();
    virtual void testAdvisorGenerateMove();
    virtual void testChariotGenerateMove();
    virtual void testCannonGenerateMove();

    virtual void S_HorseGenerateMove(); // NO TEST
    virtual void S_ElephantGenerateMove(); // NO TEST
    virtual void S_GeneralGenerateMove(); // NO TEST
    virtual void S_SoldierGenerateMove(); // NO TEST
    virtual void S_AdvisorGenerateMove(); // NO TEST
    virtual void S_ChariotGenerateMove(); // NO TEST
    virtual void S_CannonGenerateMove(); // NO TEST

    virtual void testQVectorAdding();

    virtual void testDisplayAllPossibleMoves();
    virtual void S_DisplayAllPossibleMoves();

    virtual void test_Ar_hor_2_isAlive();

    virtual void testChessing();
    virtual void testChessingNew();

    virtual void testWin();
};

typedef NormalSingleton< TestChessMove > TestChessMoveIn;

#endif // TESTCHESSMOVE_H
