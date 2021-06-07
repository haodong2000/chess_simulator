#include "Advisor.h"

namespace AdvisorPos {
    const int b_up_y = 3;
    const int b_down_y = 5;
    const int b_left_x = 0;
    const int b_right_x = 2;
    const int r_up_y = 3;
    const int r_down_y = 5;
    const int r_left_x = 0 + 7;
    const int r_right_x = 2 + 7;

    const int b_mid_x = 1;
    const int b_mid_y = 4;
    const int r_mid_x = 1 + 7;
    const int r_mid_y = 4;

    QVector<QPair<int, int>> FourPoints = {
        { 1,  1},
        {-1,  1},
        { 1, -1},
        {-1, -1},
    };
}

Advisor::Advisor(int x, int y, QString name, bool camp, int number, bool isAlive):
    Chess(x, y, name, camp, number, isAlive)
{

}

double Advisor::space_value() {
    double countMoveModeNum = 0;
    if(!isAlive()) return 0;
    if(!canChessMove()) return 0;
    if(canChessMove()) countMoveModeNum = chessMoveNum();
    return countMoveModeNum/PARAM::globalEnvironment::maxAdvisorMove;
}

double Advisor::chessMoveNum() {
    bool camp = chessCamp();
    int count = 0;
    switch (camp) {
    case false: // black
        if((getPosX() == AdvisorPos::b_left_x && getPosY() == AdvisorPos::b_up_y) ||
                (getPosX() == AdvisorPos::b_right_x && getPosY() == AdvisorPos::b_up_y) ||
                (getPosX() == AdvisorPos::b_left_x && getPosY() == AdvisorPos::b_down_y) ||
                (getPosX() == AdvisorPos::b_right_x && getPosY() == AdvisorPos::b_down_y)) {
            if(!(GlobalEnvirIn::Instance()->__isThereHasChess(AdvisorPos::b_mid_x, AdvisorPos::b_mid_y)))
                count = 1;
        }
        else if(getPosX() == AdvisorPos::b_mid_x && getPosY() == AdvisorPos::b_mid_y) {
            if(!(GlobalEnvirIn::Instance()->__isThereHasChess(AdvisorPos::b_left_x, AdvisorPos::b_up_y))) count++;
            if(!(GlobalEnvirIn::Instance()->__isThereHasChess(AdvisorPos::b_right_x, AdvisorPos::b_up_y))) count++;
            if(!(GlobalEnvirIn::Instance()->__isThereHasChess(AdvisorPos::b_left_x, AdvisorPos::b_down_y))) count++;
            if(!(GlobalEnvirIn::Instance()->__isThereHasChess(AdvisorPos::b_right_x, AdvisorPos::b_down_y))) count++;
        }
        else qDebug() << "Advisor.cpp canChessMove() Please chack the position of black Advisor!";
        break;
    case true: // red
        if((getPosX() == AdvisorPos::r_left_x && getPosY() == AdvisorPos::r_up_y) ||
                (getPosX() == AdvisorPos::r_right_x && getPosY() == AdvisorPos::r_up_y) ||
                (getPosX() == AdvisorPos::r_left_x && getPosY() == AdvisorPos::r_down_y) ||
                (getPosX() == AdvisorPos::r_right_x && getPosY() == AdvisorPos::r_down_y)) {
            if(!(GlobalEnvirIn::Instance()->__isThereHasChess(AdvisorPos::r_mid_x, AdvisorPos::r_mid_y)))
                count = 1;
        }
        else if(getPosX() == AdvisorPos::r_mid_x && getPosY() == AdvisorPos::r_mid_y) {
            if(!(GlobalEnvirIn::Instance()->__isThereHasChess(AdvisorPos::r_left_x, AdvisorPos::r_up_y))) count++;
            if(!(GlobalEnvirIn::Instance()->__isThereHasChess(AdvisorPos::r_right_x, AdvisorPos::r_up_y))) count++;
            if(!(GlobalEnvirIn::Instance()->__isThereHasChess(AdvisorPos::r_left_x, AdvisorPos::r_down_y))) count++;
            if(!(GlobalEnvirIn::Instance()->__isThereHasChess(AdvisorPos::r_right_x, AdvisorPos::r_down_y))) count++;
        }
        else qDebug() << "Advisor.cpp canChessMove() Please chack the position of red Advisor!";
        break;
    default:
        qDebug() << "Advisor.cpp canChessMove() chessCamp() invalid!";
        break;
    }
    return count;
}

bool Advisor::canChessMove() {
    bool camp = chessCamp();
    switch (camp) {
    case false: // black
        if((getPosX() == AdvisorPos::b_left_x && getPosY() == AdvisorPos::b_up_y) ||
                (getPosX() == AdvisorPos::b_right_x && getPosY() == AdvisorPos::b_up_y) ||
                (getPosX() == AdvisorPos::b_left_x && getPosY() == AdvisorPos::b_down_y) ||
                (getPosX() == AdvisorPos::b_right_x && getPosY() == AdvisorPos::b_down_y))
            return !(GlobalEnvirIn::Instance()->__isThereHasChess(AdvisorPos::b_mid_x, AdvisorPos::b_mid_y));
        else if(getPosX() == AdvisorPos::b_mid_x && getPosY() == AdvisorPos::b_mid_y) {
            bool retCanMove = (GlobalEnvirIn::Instance()->__isThereHasChess(AdvisorPos::b_left_x, AdvisorPos::b_up_y) &&
                               GlobalEnvirIn::Instance()->__isThereHasChess(AdvisorPos::b_right_x, AdvisorPos::b_up_y) &&
                               GlobalEnvirIn::Instance()->__isThereHasChess(AdvisorPos::b_left_x, AdvisorPos::b_down_y) &&
                               GlobalEnvirIn::Instance()->__isThereHasChess(AdvisorPos::b_right_x, AdvisorPos::b_down_y));
            return !retCanMove;
        }
        else qDebug() << "Advisor.cpp canChessMove() Please chack the position of black Advisor!";
        break;
    case true: // red
        if((getPosX() == AdvisorPos::r_left_x && getPosY() == AdvisorPos::r_up_y) ||
                (getPosX() == AdvisorPos::r_right_x && getPosY() == AdvisorPos::r_up_y) ||
                (getPosX() == AdvisorPos::r_left_x && getPosY() == AdvisorPos::r_down_y) ||
                (getPosX() == AdvisorPos::r_right_x && getPosY() == AdvisorPos::r_down_y))
            return !(GlobalEnvirIn::Instance()->__isThereHasChess(AdvisorPos::r_mid_x, AdvisorPos::r_mid_y));
        else if(getPosX() == AdvisorPos::r_mid_x && getPosY() == AdvisorPos::r_mid_y) {
            bool retCanMove = (GlobalEnvirIn::Instance()->__isThereHasChess(AdvisorPos::r_left_x, AdvisorPos::r_up_y) &&
                               GlobalEnvirIn::Instance()->__isThereHasChess(AdvisorPos::r_right_x, AdvisorPos::r_up_y) &&
                               GlobalEnvirIn::Instance()->__isThereHasChess(AdvisorPos::r_left_x, AdvisorPos::r_down_y) &&
                               GlobalEnvirIn::Instance()->__isThereHasChess(AdvisorPos::r_right_x, AdvisorPos::r_down_y));
            return !retCanMove;
        }
        else qDebug() << "Advisor.cpp canChessMove() Please chack the position of red Advisor!";
        break;
    default:
        qDebug() << "Advisor.cpp canChessMove() chessCamp() invalid!";
        break;
    }
    return true;
}

void Advisor::generateMove() {
    chessStepList.clear();  // api: chessStepList.append(chessStep(1, 1, false, 0 ,0));
    if(!isAlive()) return;
    QString chessNameSimple = GlobalEnvirIn::Instance()->__QString2SimpleName(chessName());
    int chessNum = GlobalEnvirIn::Instance()->__QStr2intName(chessNameSimple);
    SGeoPoint* start = new SGeoPoint(getPosX(), getPosY());
    const int count = AdvisorPos::FourPoints.size();
    for(int index = 0; index < count; index++) {
        SGeoPoint* end = new SGeoPoint(getPosX() + AdvisorPos::FourPoints.at(index).first, getPosY() + AdvisorPos::FourPoints.at(index).second);
        if(basicAdvisorMoveCondition(start, end) && canAdvisorMove(start, end)) {
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
    }
}

bool Advisor::basicAdvisorMoveCondition(SGeoPoint *start, SGeoPoint *end) {
    if(!(GlobalEnvirIn::Instance()->__isPosInBoard(start) && GlobalEnvirIn::Instance()->__isPosInBoard(end))) {
        return false;
    }

    if(chessCamp()) {
        if(!(isInRedArea(start) && isInRedArea(end))) {
            return false;
        }
    }
    else {
        if(!(isInBlackArea(start) && isInBlackArea(end))) {
            return false;
        }
    }
    return true;
}

bool Advisor::canAdvisorMove(SGeoPoint *start, SGeoPoint *end) {
    if(!(GlobalEnvirIn::Instance()->__isPosInBoard(start) && GlobalEnvirIn::Instance()->__isPosInBoard(end))) {
        qDebug() << "Advisor.cpp line:141 canAdvisorMove() error:start or end out of boundary!";
        return false;
    }

    if(chessCamp()) {
        if(!(isInRedArea(start) && isInRedArea(end))) {
            qDebug() << "Advisor.cpp line:128 canAdvisorMove() error:RED out of 9 Pavilion";
            return false;
        }
    }
    else {
        if(!(isInBlackArea(start) && isInBlackArea(end))) {
            qDebug() << "Advisor.cpp line:128 canAdvisorMove() error:BLACK out of 9 Pavilion";
            return false;
        }
    }

    if(!advisorRule(start, end)) {
        qDebug() << "Advisor.cpp line:146 canAdvisorMove() error:advisor move must 1*1 1*-1 -1*1 -1*-1 !";
        return false;
    }

    return !GlobalEnvirIn::Instance()->__isThereHasOurChess(chessCamp(), end);
}

bool Advisor::advisorRule(SGeoPoint *start, SGeoPoint *end) {
    return ((abs(start->getPosX() - end->getPosX())) == 1 &&
            (abs(start->getPosY() - end->getPosY())) == 1);
}

bool Advisor::isInRedArea(SGeoPoint *Pos) {
    if((Pos->getPosX() == AdvisorPos::r_mid_x && Pos->getPosY() == AdvisorPos::r_mid_y) ||
            (Pos->getPosX() == AdvisorPos::r_left_x && Pos->getPosY() == AdvisorPos::r_up_y) ||
            (Pos->getPosX() == AdvisorPos::r_left_x && Pos->getPosY() == AdvisorPos::r_down_y) ||
            (Pos->getPosX() == AdvisorPos::r_right_x && Pos->getPosY() == AdvisorPos::r_up_y) ||
            (Pos->getPosX() == AdvisorPos::r_right_x && Pos->getPosY() == AdvisorPos::r_down_y)) return true;
    return false;
}

bool Advisor::isInBlackArea(SGeoPoint *Pos) {
    if((Pos->getPosX() == AdvisorPos::b_mid_x && Pos->getPosY() == AdvisorPos::b_mid_y) ||
            (Pos->getPosX() == AdvisorPos::b_left_x && Pos->getPosY() == AdvisorPos::b_up_y) ||
            (Pos->getPosX() == AdvisorPos::b_left_x && Pos->getPosY() == AdvisorPos::b_down_y) ||
            (Pos->getPosX() == AdvisorPos::b_right_x && Pos->getPosY() == AdvisorPos::b_up_y) ||
            (Pos->getPosX() == AdvisorPos::b_right_x && Pos->getPosY() == AdvisorPos::b_down_y)) return true;
    return false;
    return false;
}
