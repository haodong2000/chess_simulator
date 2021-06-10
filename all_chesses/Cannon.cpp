#include "Cannon.h"

Cannon::Cannon(int x, int y, QString name, bool camp, int number, bool isAlive):
    Chess(x, y, name, camp, number, isAlive)
{

}

double Cannon::space_value() {
    return GlobalEnvirIn::Instance()->__countSpaceAround(GlobalEnvirIn::Instance()->__QStr2intName(GlobalEnvirIn::Instance()->__QString2SimpleName(chessName())),
                                                         chessNumber());
}

bool Cannon::canChessMove() {
    bool retMove;
    if(GlobalEnvirIn::Instance()->__isOtherChessAround(GlobalEnvirIn::Instance()->__QStr2intName(GlobalEnvirIn::Instance()->__QString2SimpleName(chessName())),
                                                       chessNumber())) retMove = false;
    else retMove = true;
    return retMove;
}

void Cannon::generateMove() {
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
        if(canCannonMoveOrKill(start, end)) {
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
        if(canCannonMoveOrKill(start, end)) {
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
    // tranStarStepList();
}

bool Cannon::canCannonMoveOrKill(SGeoPoint* start, SGeoPoint* end) {
    if((!GlobalEnvirIn::Instance()->__isPosInBoard(start)) || (!GlobalEnvirIn::Instance()->__isPosInBoard(end))) {
        qDebug() << "Cannon.cpp line:26 canCannonMoveOrKill() error:start or end out of boundary";
        return false;
    }

    if(!((start->getPosX() == end->getPosX()) || (start->getPosY() == end->getPosY()))) {
        qDebug() << "Cannon.cpp line:32 canCannonMoveOrKill() error:cannon move must in straight line!";
        return false;
    }

    // 1. end is empty and count_chess_in_path = 0, kill = false
    // 2. end is enemy and count_chess_in_path = 1, kill = true

    if(GlobalEnvirIn::Instance()->__countChessInPath(start, end) == 0 &&
            !GlobalEnvirIn::Instance()->__isThereHasChess(end)) return true;

    if(GlobalEnvirIn::Instance()->__countChessInPath(start, end) == 1 &&
            (GlobalEnvirIn::Instance()->__isThereHasChess(end) &&
             !GlobalEnvirIn::Instance()->__isThereHasOurChess(chessCamp(), end))) return true;

    return false;
}
