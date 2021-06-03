#include "Step.h"

/*****************************************************************
*   File:     Step.cpp
*   Author:   Haodong LI
*   Usage:    TheUsageOfFile
*   Time:     2021-06-03 -> 12:29:29
*****************************************************************/

Step::Step(int ChessNum, int ChessNumber, bool camp,
           int DeltaX, int DeltaY,
           bool Kill, int ChessKilledNum, int ChessKilledNumber):
    __ChessNum(ChessNum), __ChessNumber(ChessNumber), __ChessCamp(camp),
    __isKill(Kill), __ChessKilledNum(ChessKilledNum), __CHessKilledNumber(ChessKilledNumber)
{
    __StepDeltaMove = new SGeoPoint(DeltaX, DeltaY);
    if(Kill) { // if kill happened
        GlobalEnvirIn::Instance()->__QStrOrInt2Chess(__ChessKilledNum, __CHessKilledNumber)->setAlive(false);
    }
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

void Step::executeStep() {
    object->setProperty(
                (GlobalEnvirIn::Instance()->__int2QStrName(__ChessNum) +
                 QString::number(__ChessNumber) +
                 QString("_posX")).toLatin1(),
                 coordinateIn::Instance()->tranRealPosX(
                    GlobalEnvirIn::Instance()->__QStrOrInt2Chess(__ChessNum, __ChessNumber)->getPosX() +
                    __StepDeltaMove->getPosX()));
    object->setProperty(
                (GlobalEnvirIn::Instance()->__int2QStrName(__ChessNum) +
                 QString::number(__ChessNumber) +
                 QString("_posY")).toLatin1(),
                coordinateIn::Instance()->tranRealPosX(
                    GlobalEnvirIn::Instance()->__QStrOrInt2Chess(__ChessNum, __ChessNumber)->getPosY() +
                    __StepDeltaMove->getPosY()));
    if(__isKill) {
        object->setProperty(
                    (GlobalEnvirIn::Instance()->__int2QStrName(__ChessKilledNum) +
                     QString::number(__CHessKilledNumber) +
                     QString("_alive")).toLatin1(), false);
    }
}
