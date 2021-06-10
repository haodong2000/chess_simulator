#include "Chariot.h"

Chariot::Chariot(int x, int y, QString name, bool camp, int number, bool isAlive):
    Chess(x, y, name, camp, number, isAlive)
{

}

double Chariot::space_value() {
    return GlobalEnvirIn::Instance()->__countSpaceAround(GlobalEnvirIn::Instance()->__QStr2intName(GlobalEnvirIn::Instance()->__QString2SimpleName(chessName())),
                                                         chessNumber());
}

bool Chariot::canChessMove() {
    bool retMove;
    if(GlobalEnvirIn::Instance()->__isOtherChessAround(GlobalEnvirIn::Instance()->__QStr2intName(GlobalEnvirIn::Instance()->__QString2SimpleName(chessName())),
                                                       chessNumber())) retMove = false;
    else retMove = true;
    return retMove;
}

void Chariot::generateMove() {
    SchessStepList.clear();
    chessStepList.clear();  // api: chessStepList.append(chessStep(1, 1, false, 0 ,0));
    if(!isAlive()) return;
    QString chessNameSimple = GlobalEnvirIn::Instance()->__QString2SimpleName(chessName());
    int chessNum = GlobalEnvirIn::Instance()->__QStr2intName(chessNameSimple);
    SGeoPoint* start = new SGeoPoint(getPosX(), getPosY());
    // width scale
    for(int index = 0; index <= PARAM::globalEnvironment::maxAxisOfX; index++) {
        if(index == getPosX()) continue;
        SGeoPoint* end = new SGeoPoint(index, getPosY());
        if(canChariotMoveOrKill(start, end)) {
            int chessKillNum = -1;
            int chessKillNumber = -1;
            bool kill = GlobalEnvirIn::Instance()->__isThereHasChess(end);
            if(kill) {
                QString killName = GlobalEnvirIn::Instance()->__QString2SimpleName(GlobalEnvirIn::Instance()->__whichChessOnThere(end)->chessName());
                chessKillNum = GlobalEnvirIn::Instance()->__QStr2intName(killName);
                chessKillNumber = GlobalEnvirIn::Instance()->__whichChessOnThere(end)->chessNumber();
            }
            chessStep tempStep(chessNum, chessNumber(), chessCamp(), end->getPosX(), end->getPosY(), kill, chessKillNum, chessKillNumber);
            chessStepList.append(tempStep);
        }
        delete end;
    }
    // height scale
    for(int index = 0; index <= PARAM::globalEnvironment::maxAxisOfY; index++) {
        if(index == getPosY()) continue;
        SGeoPoint* end = new SGeoPoint(getPosX(), index);
        if(canChariotMoveOrKill(start, end)) {
            int chessKillNum = -1;
            int chessKillNumber = -1;
            bool kill = GlobalEnvirIn::Instance()->__isThereHasChess(end);
            if(kill) {
                QString killName = GlobalEnvirIn::Instance()->__QString2SimpleName(GlobalEnvirIn::Instance()->__whichChessOnThere(end)->chessName());
                chessKillNum = GlobalEnvirIn::Instance()->__QStr2intName(killName);
                chessKillNumber = GlobalEnvirIn::Instance()->__whichChessOnThere(end)->chessNumber();
            }
            chessStep tempStep(chessNum, chessNumber(), chessCamp(), end->getPosX(), end->getPosY(), kill, chessKillNum, chessKillNumber);
            chessStepList.append(tempStep);
        }
        delete end;
    }
    delete start;
    tranStarStepList();
}

bool Chariot::canChariotMoveOrKill(SGeoPoint *start, SGeoPoint *end) {
    if((!GlobalEnvirIn::Instance()->__isPosInBoard(start)) || (!GlobalEnvirIn::Instance()->__isPosInBoard(end))) {
        qDebug() << "Chariot.cpp line:26 canChariotMoveOrKill() error:start or end out of boundary";
        return false;
    }

    if(!((start->getPosX() == end->getPosX()) || (start->getPosY() == end->getPosY()))) {
        qDebug() << "Chariot.cpp line:32 canChariotMoveOrKill() error:chariot move must in straight line!";
        return false;
    }

    if(start->getPosX() - end->getPosX() == 0) {
        for(int index = qMin(start->getPosY(), end->getPosY()) + 1; index < qMax(start->getPosY(), end->getPosY()); index++) {
            SGeoPoint* middle = new SGeoPoint(start->getPosX(), index);
            if(GlobalEnvirIn::Instance()->__isThereHasChess(middle)) {
                delete middle;
                return false;
            }
            delete middle;
        }
    }
    if(start->getPosY() - end->getPosY() == 0) {
        for(int index = qMin(start->getPosX(), end->getPosX()) + 1; index < qMax(start->getPosX(), end->getPosX()); index++) {
            SGeoPoint* middle = new SGeoPoint(index, start->getPosY());
            if(GlobalEnvirIn::Instance()->__isThereHasChess(middle)) {
                delete middle;
                return false;
            }
            delete middle;
        }
    }
    return !GlobalEnvirIn::Instance()->__isThereHasOurChess(chessCamp(), end);
}
