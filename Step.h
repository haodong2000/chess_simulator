#ifndef STEP_H
#define STEP_H

/*****************************************************************
*   File:     Step.h
*   Author:   Haodong LI
*   Usage:    Step class to generate next step of the chess board
*   Time:     2021-06-03 -> 12:29:35
*****************************************************************/

#include "global.h"
#include "SGeoPoint.h"
#include "coordinate.h"
#include "globalChesses.h"

#include <QString>

class Step
{
public:
    Step(int ChessNum, bool camp,
         int DeltaX, int DeltaY,
         bool Kill = false, int ChessKilledNum = -1);

    virtual int getStepX();
    virtual int getStepY();
    virtual int getStepDeltaX();
    virtual int getStepDeltaY();

    virtual void setStepX(int PosX);
    virtual void setStepY(int PosY);
    virtual void setStepDeltaX(int PosDeltaX);
    virtual void setStepDeltaY(int PosDeltaY);

    virtual void executeStep();

private:
    SGeoPoint* __StepMove; // TODO, no use currently
    SGeoPoint* __StepDeltaMove;
    int __ChessNum;
    QString __CHessName;
    bool __ChessCamp; // false is black and true is red
    bool __isKill;
    int __ChessKilledNum; // -1 means no killed
    QString __ChessKilledName;
};

typedef NormalSingleton< Step > StepIn;

#endif // STEP_H
