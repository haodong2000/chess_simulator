#include "General.h"

namespace GeneralPos {
    SGeoPoint* zero_one = new SGeoPoint(0, 1);
    SGeoPoint* one_zero = new SGeoPoint(1, 0);
    QVector<QPair<int, int>> FourPoints = {
        { 1, 0},
        {-1, 0},
        {0,  1},
        {0, -1},
    };
    const int red_left = 7;
    const int red_right = 9;
    const int red_up = 3;
    const int red_down = 5;
    const int left = 0;
    const int right = 2;
    const int up = 3;
    const int down = 5;
}

General::General(int x, int y, QString name, bool camp, int number, bool isAlive):
    Chess(x, y, name, camp, number, isAlive)
{

}

double General::space_value() {
    if(!isAlive()) return 0;
    return 1.0; // is alive, return 100%
}

bool General::canChessMove() {
    bool retMove;
    if(GlobalEnvirIn::Instance()->__isOtherChessAround(GlobalEnvirIn::Instance()->__QStr2intName(GlobalEnvirIn::Instance()->__QString2SimpleName(chessName())),
                                                       chessNumber())) retMove = false;
    else retMove = true;
    return retMove;
}

void General::generateMove() {
    chessStepList.clear();  // api: chessStepList.append(chessStep(1, 1, false, 0 ,0));
    if(!isAlive()) return;
    QString chessNameSimple = GlobalEnvirIn::Instance()->__QString2SimpleName(chessName());
    int chessNum = GlobalEnvirIn::Instance()->__QStr2intName(chessNameSimple);
    const int FourDirection = 4;
    SGeoPoint* start = new SGeoPoint(getPosX(), getPosY());
    for(int index = 0; index < FourDirection; index++) {
        SGeoPoint* end = new SGeoPoint(getPosX() + GeneralPos::FourPoints.at(index).first, getPosY() + GeneralPos::FourPoints.at(index).second);
        if(!GlobalEnvirIn::Instance()->__isPosInBoard(end)) continue;
        if((generalInPavilion(start) && generalInPavilion(end)) && canGeneralMoveOrKill(start, end)) {
            int chessKillNum = -1;
            int chessKillNumber = -1;
            bool kill = GlobalEnvirIn::Instance()->__isThereHasChess(end);
            if(kill) {
                QString killName = GlobalEnvirIn::Instance()->__QString2SimpleName(GlobalEnvirIn::Instance()->__whichChessOnThere(end)->chessName());
                chessKillNum = GlobalEnvirIn::Instance()->__QStr2intName(killName);
                chessKillNumber = GlobalEnvirIn::Instance()->__whichChessOnThere(end)->chessNumber();
            }
            chessStep tempStep(chessNum, chessNumber(), chessCamp(), getPosX() + GeneralPos::FourPoints.at(index).first, getPosY() + GeneralPos::FourPoints.at(index).second, kill, chessKillNum, chessKillNumber);
            chessStepList.append(tempStep);
        }
    }
    tranStarStepList();
}

bool General::canGeneralMoveOrKill(SGeoPoint *start, SGeoPoint *end) {
    if((!GlobalEnvirIn::Instance()->__isPosInBoard(start)) || (!GlobalEnvirIn::Instance()->__isPosInBoard(end))) {
        qDebug() << "General.cpp line:42 canGeneralMoveOrKill() error:General move out of boundary !!!";
        return false;
    }

    if(!((abs(start->getPosX() - end->getPosX()) == GeneralPos::one_zero->getPosX() && abs(start->getPosY() - end->getPosY()) == GeneralPos::one_zero->getPosY()) ||
            (abs(start->getPosX() - end->getPosX()) == GeneralPos::zero_one->getPosX() && abs(start->getPosY() - end->getPosY()) == GeneralPos::zero_one->getPosY()))) {
        qDebug() << "General.cpp line:38 canGeneralMoveOrKill() error:General move must 1*0 0*1 -1*0 0*-1 !!!";
        return false;
    }

    if(!(generalInPavilion(start) && generalInPavilion(end))) {
        qDebug() << "General.cpp line78 canGeneralMoveOrKill() error:General start or end out of 9 Pavilion!";
        return false;
    }

    if(GlobalEnvirIn::Instance()->__isThereHasOurChess(chessCamp(), end)) return false;

    return true;
}

bool General::generalInPavilion(SGeoPoint *Pos) {
    bool camp = chessCamp();
    if(camp) { // red
        if(Pos->getPosX() < GeneralPos::red_left || Pos->getPosX() > GeneralPos::red_right) return false;
        if(Pos->getPosY() < GeneralPos::red_up || Pos->getPosY() > GeneralPos::red_down) return false;
    }
    else { // black
        if(Pos->getPosX() < GeneralPos::left || Pos->getPosX() > GeneralPos::right) return false;
        if(Pos->getPosY() < GeneralPos::up || Pos->getPosY() > GeneralPos::down) return false;
    }
    return true;
}
