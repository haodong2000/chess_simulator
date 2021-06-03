#include "Step.h"

/*****************************************************************
*   File:     Step.cpp
*   Author:   Haodong LI
*   Usage:    TheUsageOfFile
*   Time:     2021-06-03 -> 12:29:29
*****************************************************************/

Step::Step(int ChessNum, bool camp,
           int DeltaX, int DeltaY,
           bool Kill, int ChessKilledNum):
    __ChessNum(ChessNum), __ChessCamp(camp), __isKill(Kill), __ChessKilledNum(ChessKilledNum)
{
    __StepDeltaMove = new SGeoPoint(DeltaX, DeltaY);
}

int Step::getStepX() {
    return __StepMove->getPosX();
}

int Step::getStepY() {
    return __StepMove->getPosY();
}

void Step::setStepX(int PosX) {
    __StepMove->setPosX(PosX);
}

void Step::setStepY(int PosY) {
    __StepMove->setPosY(PosY);
}

int Step::getStepDeltaX() {
    return __StepDeltaMove->getPosX();
}

int Step::getStepDeltaY() {
    return __StepDeltaMove->getPosY();
}

void Step::setStepDeltaX(int PosDeltaX) {
    __StepDeltaMove->setPosX(PosDeltaX);
}

void Step::setStepDeltaY(int PosDeltaY) {
    __StepDeltaMove->setPosY(PosDeltaY);
}
