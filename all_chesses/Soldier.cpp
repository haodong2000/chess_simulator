#include "Soldier.h"

namespace SoldierPos {
    QVector<QPair<int, int>> Our = {
        {1, 0},
    };
    QVector<QPair<int, int>> Enemy = {
        {1,  0},
        {0,  1},
        {0, -1}
    };
    QVector<QPair<int, int>> redOur = {
        {-1, 0},
    };
    QVector<QPair<int, int>> redEnemy = {
        {-1, 0},
        {0,  1},
        {0, -1}
    };
}

Soldier::Soldier(int x, int y, QString name, bool camp, int number, bool isAlive):
    Chess(x, y, name, camp, number, isAlive)
{

}

double Soldier::space_value() {
    if(!isAlive()) return 0;
    if(!canChessMove()) return 0;
    QString chessNameSimple = GlobalEnvirIn::Instance()->__QString2SimpleName(chessName());
    int chessNum = GlobalEnvirIn::Instance()->__QStr2intName(chessNameSimple);
    SGeoPoint* up = new SGeoPoint(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosX(),
                                  GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosY() - 1);
    SGeoPoint* down = new SGeoPoint(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosX(),
                                  GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosY() + 1);
    int enemy_delta = chessCamp() ? -1 : 1;
    SGeoPoint* enemy = new SGeoPoint(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosX() + enemy_delta,
                                  GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosY());
    if(GlobalEnvirIn::Instance()->__isPosInBoard(up) && (!GlobalEnvirIn::Instance()->__isThereHasChess(up))) return 0.75;
    if(GlobalEnvirIn::Instance()->__isPosInBoard(down) && (!GlobalEnvirIn::Instance()->__isThereHasChess(down))) return 0.75;
    if(GlobalEnvirIn::Instance()->__isPosInBoard(enemy) && (!GlobalEnvirIn::Instance()->__isThereHasChess(enemy))) return 1.25;
    return 0;
}

bool Soldier::canChessMove() {
    QString chessNameSimple = GlobalEnvirIn::Instance()->__QString2SimpleName(chessName());
    int chessNum = GlobalEnvirIn::Instance()->__QStr2intName(chessNameSimple);
    SGeoPoint* up = new SGeoPoint(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosX(),
                                  GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosY() - 1);
    SGeoPoint* down = new SGeoPoint(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosX(),
                                  GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosY() + 1);
    int enemy_delta = chessCamp() ? -1 : 1;
    SGeoPoint* enemy = new SGeoPoint(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosX() + enemy_delta,
                                  GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosY());
    if(GlobalEnvirIn::Instance()->__isPosInBoard(up) && (!GlobalEnvirIn::Instance()->__isThereHasChess(up))) return true;
    if(GlobalEnvirIn::Instance()->__isPosInBoard(down) && (!GlobalEnvirIn::Instance()->__isThereHasChess(down))) return true;
    if(GlobalEnvirIn::Instance()->__isPosInBoard(enemy) && (!GlobalEnvirIn::Instance()->__isThereHasChess(enemy))) return true;
    return false;
}

bool Soldier::canSoldierMoveOrKill(SGeoPoint *start, SGeoPoint *end) {
    QString chessNameSimple = GlobalEnvirIn::Instance()->__QString2SimpleName(chessName());
    int chessNum = GlobalEnvirIn::Instance()->__QStr2intName(chessNameSimple);
    bool redOrBlack = (chessNum >= 8); // true is red and false is black

    if((abs(start->getPosX() - end->getPosX()) + abs(start->getPosY() - end->getPosY()) != 1) ||
            (redOrBlack  && (start->getPosX() < end->getPosX())) ||
            (!redOrBlack && (start->getPosX() > end->getPosX())) ||
            (redOrBlack  && (start->getPosX() == end->getPosX()) && (start->getPosX() >= PARAM::globalEnvironment::middleRed)) ||
            (!redOrBlack && (start->getPosX() == end->getPosX()) && (start->getPosX() <= PARAM::globalEnvironment::middleBlack))) {
        qDebug() << "Soldier.cpp line:59 canSoldierMoveOrKill() error:Soldier step illegal!!!";
        return false;
    }

    if(!GlobalEnvirIn::Instance()->__isPosInBoard(end)) {
        qDebug() << "Soldier.cpp line:76 canSoldierMoveOrKill() error: end pos out of poundary";
        return false;
    }

    if(!GlobalEnvirIn::Instance()->__isThereHasOurChess(chessCamp(), end)) return true;
    return false;
}

void Soldier::generateMove() {
    // api: chessStepList.append(chessStep(1, 1, false, 0 ,0));
    QString chessNameSimple = GlobalEnvirIn::Instance()->__QString2SimpleName(chessName());
    int chessNum = GlobalEnvirIn::Instance()->__QStr2intName(chessNameSimple);
    bool redOrBlack = (chessNum >= 8); // true is red and false is black
    SGeoPoint* start = new SGeoPoint(getPosX(), getPosY());

    if(redOrBlack) {
        if(getPosX() >= PARAM::globalEnvironment::middleRed) {
            int count = SoldierPos::redOur.size();
            for(int index = 0; index < count; index++) {
                SGeoPoint* end = new SGeoPoint(start->getPosX() + SoldierPos::redOur.at(index).first, start->getPosY() + SoldierPos::redOur.at(index).second);
                if(canSoldierMoveOrKill(start, end)) {
                    int chessKillNum = -1;
                    int chessKillNumber = -1;
                    bool kill = GlobalEnvirIn::Instance()->__isThereHasChess(end);
                    if(kill) {
                        QString killName = GlobalEnvirIn::Instance()->__QString2SimpleName(GlobalEnvirIn::Instance()->__whichChessOnThere(end)->chessName());
                        chessKillNum = GlobalEnvirIn::Instance()->__QStr2intName(killName);
                        chessKillNumber = GlobalEnvirIn::Instance()->__whichChessOnThere(end)->chessNumber();
                    }
                    chessStep tempStep(chessNum, chessNumber(), chessCamp(), getPosX() + SoldierPos::redOur.at(index).first, getPosY() + SoldierPos::redOur.at(index).second, kill, chessKillNum, chessKillNumber);
                    chessStepList.append(tempStep);
                }
            }
        }
        else {
            int count = SoldierPos::redEnemy.size();
            for(int index = 0; index < count; index++) {
                SGeoPoint* end = new SGeoPoint(start->getPosX() + SoldierPos::redEnemy.at(index).first, start->getPosY() + SoldierPos::redEnemy.at(index).second);
                if(canSoldierMoveOrKill(start, end)) {
                    int chessKillNum = -1;
                    int chessKillNumber = -1;
                    bool kill = GlobalEnvirIn::Instance()->__isThereHasChess(end);
                    if(kill) {
                        QString killName = GlobalEnvirIn::Instance()->__QString2SimpleName(GlobalEnvirIn::Instance()->__whichChessOnThere(end)->chessName());
                        chessKillNum = GlobalEnvirIn::Instance()->__QStr2intName(killName);
                        chessKillNumber = GlobalEnvirIn::Instance()->__whichChessOnThere(end)->chessNumber();
                    }
                    chessStep tempStep(chessNum, chessNumber(), chessCamp(), getPosX() + SoldierPos::redEnemy.at(index).first, getPosY() + SoldierPos::redEnemy.at(index).second, kill, chessKillNum, chessKillNumber);
                    chessStepList.append(tempStep);
                }
            }
        }
    }
    else {
        if(getPosX() <= PARAM::globalEnvironment::middleBlack) {
            int count = SoldierPos::Our.size();
            for(int index = 0; index < count; index++) {
                SGeoPoint* end = new SGeoPoint(start->getPosX() + SoldierPos::Our.at(index).first, start->getPosY() + SoldierPos::Our.at(index).second);
                if(canSoldierMoveOrKill(start, end)) {
                    int chessKillNum = -1;
                    int chessKillNumber = -1;
                    bool kill = GlobalEnvirIn::Instance()->__isThereHasChess(end);
                    if(kill) {
                        QString killName = GlobalEnvirIn::Instance()->__QString2SimpleName(GlobalEnvirIn::Instance()->__whichChessOnThere(end)->chessName());
                        chessKillNum = GlobalEnvirIn::Instance()->__QStr2intName(killName);
                        chessKillNumber = GlobalEnvirIn::Instance()->__whichChessOnThere(end)->chessNumber();
                    }
                    chessStep tempStep(chessNum, chessNumber(), chessCamp(), getPosX() + SoldierPos::Our.at(index).first, getPosY() + SoldierPos::Our.at(index).second, kill, chessKillNum, chessKillNumber);
                    chessStepList.append(tempStep);
                }
            }
        }
        else {
            int count = SoldierPos::Enemy.size();
            for(int index = 0; index < count; index++) {
                SGeoPoint* end = new SGeoPoint(start->getPosX() + SoldierPos::Enemy.at(index).first, start->getPosY() + SoldierPos::Enemy.at(index).second);
                if(canSoldierMoveOrKill(start, end)) {
                    int chessKillNum = -1;
                    int chessKillNumber = -1;
                    bool kill = GlobalEnvirIn::Instance()->__isThereHasChess(end);
                    if(kill) {
                        QString killName = GlobalEnvirIn::Instance()->__QString2SimpleName(GlobalEnvirIn::Instance()->__whichChessOnThere(end)->chessName());
                        chessKillNum = GlobalEnvirIn::Instance()->__QStr2intName(killName);
                        chessKillNumber = GlobalEnvirIn::Instance()->__whichChessOnThere(end)->chessNumber();
                    }
                    chessStep tempStep(chessNum, chessNumber(), chessCamp(), getPosX() + SoldierPos::Enemy.at(index).first, getPosY() + SoldierPos::Enemy.at(index).second, kill, chessKillNum, chessKillNumber);
                    chessStepList.append(tempStep);
                }
            }
        }
    }
}
