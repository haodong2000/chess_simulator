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
//  new api
    QmlConnectIn::Instance()->changeChessPos(__ChessNum, __ChessNumber, __ChessCamp, __StepDeltaMove->getPosX(), __StepDeltaMove->getPosY());
//  old api
//    object->setProperty((GlobalEnvirIn::Instance()->__int2QStrName(__ChessNum) + QString::number(__ChessNumber) + QString("_posX")).toLatin1(),
//                 coordinateIn::Instance()->tranRealPosX(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(__ChessNum, __ChessNumber)->getPosX() + __StepDeltaMove->getPosX()));
//    object->setProperty((GlobalEnvirIn::Instance()->__int2QStrName(__ChessNum) + QString::number(__ChessNumber) + QString("_posY")).toLatin1(),
//                coordinateIn::Instance()->tranRealPosX(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(__ChessNum, __ChessNumber)->getPosY() + __StepDeltaMove->getPosY()));
    if(__isKill) {
        GlobalEnvirIn::Instance()->__QStrOrInt2Chess(__ChessKilledNum, __CHessKilledNumber)->setAlive(false);
        object->setProperty(
                    (GlobalEnvirIn::Instance()->__int2QStrName(__ChessKilledNum) +
                     QString::number(__CHessKilledNumber) +
                     QString("_alive")).toLatin1(), false);
    }
}

void Step::setChessNum(int chessNum) {
    __ChessNum = chessNum;
    __CHessName = GlobalEnvirIn::Instance()->__int2QStrName(chessNum);
}

void Step::setChessNumber(int chessNumber) {
    __ChessNumber = chessNumber;
}

bool Step::getChessCamp() {
    return __ChessCamp;
}

void Step::setKill(bool kill) {
    __isKill = kill;
}

void Step::setChessKilledNum(int chessKilledNum) {
    __ChessKilledNum = chessKilledNum;
    __ChessKilledName = GlobalEnvirIn::Instance()->__int2QStrName(chessKilledNum);
}

void Step::setChessKilledNumber(int chessKilledNumber) {
    __CHessKilledNumber = chessKilledNumber;
}

int Step::getChessNum() {
    return __ChessNum;
}

int Step::getChessNumber() {
    return __ChessNumber;
}

bool Step::getKill() {
    return __isKill;
}

int Step::getChessKilledNum() {
    return __ChessKilledNum;
}

int Step::getChessKilledNumber() {
    return __CHessKilledNumber;
}

void Step::displayStep() {
    // QmlConnectIn::Instance()->changeChessPos(__ChessNum, __ChessNumber, __ChessCamp, __StepDeltaMove->getPosX(), __StepDeltaMove->getPosY());
    int Num = this->getChessNum();
    int Number = this->getChessNumber();
    int PosX =  this->getStepDeltaX();
    int PosY =  this->getStepDeltaY();
    bool kill = this->getKill();
    QString killString = kill ? "True" : "False";
    int killNum = -1;
    int killNumber = -1;
    if(kill) {
        killNum = this->getChessKilledNum();
        killNumber = this->getChessKilledNumber();
    }
    std::cout << "Num\t = " << Num << std::endl;
    std::cout << "Number\t = " << Number << std::endl;
    std::cout << "Name\t = " << GlobalEnvirIn::Instance()->__int2QStrName(Num).toStdString() << std::endl;
    std::cout << "PosX\t = " << PosX << std::endl;
    std::cout << "PosY\t = " << PosY << std::endl;
    std::cout << "kill\t = " << killString.toStdString() << std::endl;
    if(kill) {
        std::cout << "k_Num\t = " << killNum << std::endl;
        std::cout << "k_Number\t = " << killNumber << std::endl;
        std::cout << "k_Name\t = " << GlobalEnvirIn::Instance()->__int2QStrName(killNum).toStdString() << std::endl;
    }
}
