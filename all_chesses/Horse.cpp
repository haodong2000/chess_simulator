#include "Horse.h"
#include <QVector>

namespace HorsePos {
    const SGeoPoint* two_one = new SGeoPoint(2, 1);
    const SGeoPoint* one_two = new SGeoPoint(1, 2);
    QVector<QPair<int, int>> EightPoints = {
        { 2,  1},
        {-2,  1},
        { 2, -1},
        {-2, -1},
        { 1,  2},
        {-1,  2},
        { 1, -2},
        {-1, -2}
    };
}

Horse::Horse(int x, int y, QString name, bool camp, int number, bool isAlive):
    Chess(x, y, name, camp, number, isAlive)
{

}

double Horse::space_value() {
    if(!isAlive()) return 0;
    if(!canChessMove()) return 0;

    const double enemyDirection = 1.5;
    const double enemyOnYDirection = 1.25;
    const double ourOnYDirection = 0.75;
    const double ourDirection = 0.5;
    double totalValue = 0;
    double maxValue = 1.5*2 + 1.25*2 + 0.75*2 + 0.5*2;

    QString chessNameSimple = GlobalEnvirIn::Instance()->__QString2SimpleName(chessName());
    int chessNum = GlobalEnvirIn::Instance()->__QStr2intName(chessNameSimple);
    SGeoPoint* curPos = new SGeoPoint(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosX(),
                                      GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosY());

    // four directions, eight points
    for(int index = 0; index < 8; index++) {
        SGeoPoint* finalPos = new SGeoPoint(curPos->getPosX() + HorsePos::EightPoints.at(index).first,
                                            curPos->getPosY() + HorsePos::EightPoints.at(index).second);
        if(canHorseMove(curPos, finalPos)) {
            if(abs(HorsePos::EightPoints.at(index).first) == 1) {
                if(chessCamp()) { // true is red
                    if(HorsePos::EightPoints.at(index).first > 0) totalValue += ourOnYDirection;
                    else totalValue += enemyOnYDirection;
                }
                else { // false is black
                    if(HorsePos::EightPoints.at(index).first > 0) totalValue += enemyOnYDirection;
                    else totalValue += ourOnYDirection;
                }
            }
            else if(abs(HorsePos::EightPoints.at(index).first) == 2) {
                if(chessCamp()) { // true is red
                    if(HorsePos::EightPoints.at(index).first > 0) totalValue += ourDirection;
                    else totalValue += enemyDirection;
                }
                else { // false is black
                    if(HorsePos::EightPoints.at(index).first > 0) totalValue += enemyDirection;
                    else totalValue += ourDirection;
                }
            }
            else {
                qDebug() << "Horse.cpp space_value() line:45  error: Horse move invalid! first must 1, -1, 2, -2!";
                delete curPos;
                delete finalPos;
                return 0;
            }
        }
        delete finalPos;
    }
    delete curPos;
    return totalValue/maxValue;
}

bool Horse::canChessMove() {
    QString chessNameSimple = GlobalEnvirIn::Instance()->__QString2SimpleName(chessName());
    int chessNum = GlobalEnvirIn::Instance()->__QStr2intName(chessNameSimple);
    SGeoPoint* curPos = new SGeoPoint(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosX(),
                                      GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosY());
    for(int index = 0; index < 8; index++) {
        SGeoPoint* finalPos = new SGeoPoint(curPos->getPosX() + HorsePos::EightPoints.at(index).first,
                                            curPos->getPosY() + HorsePos::EightPoints.at(index).second);
        if(canHorseMove(curPos, finalPos)) {
            delete curPos;
            delete finalPos;
            return true;
        }
    }
    delete curPos;
    return false;
}

bool Horse::canHorseMove(SGeoPoint* start, SGeoPoint* end) {
    if(!((abs(start->getPosX() - end->getPosX()) == 2 && abs(start->getPosY() - end->getPosY()) == 1) ||
            (abs(start->getPosX() - end->getPosX()) == 1 && abs(start->getPosY() - end->getPosY()) == 2))) {
        qDebug() << "Horse.cpp canHorseMove() line:23 error: horse move invalid! 2*1 or 1*2!";
        return false;
    }

    if((!GlobalEnvirIn::Instance()->__isPosInBoard(start)) || (!GlobalEnvirIn::Instance()->__isPosInBoard(end))) return false;

    if(abs(start->getPosX() - end->getPosX()) == 2) {
        if(GlobalEnvirIn::Instance()->__isThereHasChess((start->getPosX() + end->getPosX())/2, start->getPosY())) return false;
        else if(GlobalEnvirIn::Instance()->__isThereHasChess(end)) return false;
        else return true;
    }
    if(abs(start->getPosY() - end->getPosY()) == 2) {
        if(GlobalEnvirIn::Instance()->__isThereHasChess(start->getPosY(), (start->getPosY() + end->getPosY())/2)) return false;
        else if(GlobalEnvirIn::Instance()->__isThereHasChess(end)) return false;
        else return true;
    }
    return false;
}

bool Horse::canHorseMoveOrKill(SGeoPoint *start, SGeoPoint *end) {
    if(!((abs(start->getPosX() - end->getPosX()) == 2 && abs(start->getPosY() - end->getPosY()) == 1) ||
            (abs(start->getPosX() - end->getPosX()) == 1 && abs(start->getPosY() - end->getPosY()) == 2))) {
        qDebug() << "Horse.cpp canHorseMove() line:23 error: horse move invalid! 2*1 or 1*2!";
        return false;
    }

    if((!GlobalEnvirIn::Instance()->__isPosInBoard(start)) || (!GlobalEnvirIn::Instance()->__isPosInBoard(end))) return false;

    if(abs(start->getPosX() - end->getPosX()) == 2) {
        if(GlobalEnvirIn::Instance()->__isThereHasChess((start->getPosX() + end->getPosX())/2, start->getPosY())) return false;
        else if(GlobalEnvirIn::Instance()->__isThereHasOurChess(chessCamp(), end)) return false;
        else return true;
    }
    if(abs(start->getPosY() - end->getPosY()) == 2) {
        if(GlobalEnvirIn::Instance()->__isThereHasChess(start->getPosX(), (start->getPosY() + end->getPosY())/2)) return false;
        else if(GlobalEnvirIn::Instance()->__isThereHasOurChess(chessCamp(), end)) return false;
        else return true;
    }
    return false;
}

void Horse::generateMove() {
    chessStepList.clear();  // api: chessStepList.append(chessStep(1, 1, false, 0 ,0));
    SchessStepList.clear();
    if(!isAlive()) return;
    QString chessNameSimple = GlobalEnvirIn::Instance()->__QString2SimpleName(chessName());
    int chessNum = GlobalEnvirIn::Instance()->__QStr2intName(chessNameSimple);
    const int indexNumber = HorsePos::EightPoints.size();
    SGeoPoint* curPos = new SGeoPoint(getPosX(), getPosY());
    for(int index = 0; index < indexNumber; index++) {
        SGeoPoint* finalPos = new SGeoPoint(curPos->getPosX() + HorsePos::EightPoints.at(index).first,
                                            curPos->getPosY() + HorsePos::EightPoints.at(index).second);
        if(canHorseMoveOrKill(curPos, finalPos)) { // append new step
            bool kill = GlobalEnvirIn::Instance()->__isThereHasChess(finalPos);
            int chessKilledNum = -1;
            int chessKilledNumber = -1;
            if(kill) {
                QString chessKilledName = GlobalEnvirIn::Instance()->__QString2SimpleName(GlobalEnvirIn::Instance()->__whichChessOnThere(finalPos)->chessName());
                chessKilledNum = GlobalEnvirIn::Instance()->__QStr2intName(chessKilledName);
                chessKilledNumber = GlobalEnvirIn::Instance()->__whichChessOnThere(finalPos)->chessNumber();
            }
            chessStep tempStep(chessNum, chessNumber(), chessCamp(), finalPos->getPosX(), finalPos->getPosY(), kill, chessKilledNum, chessKilledNumber);
            chessStepList.append(tempStep);
        }
        delete finalPos;
    }
    delete curPos;
    tranStarStepList();
}
