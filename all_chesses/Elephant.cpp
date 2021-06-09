#include "Elephant.h"
#include <QtMath>

namespace ElephantPos {
    const int up_up_x = 2;
    const int up_up_y = 0;
    const int left_up_x = 0;
    const int left_up_y = 2;
    const int left_down_x = 0;
    const int left_down_y = 6;
    const int mid_x = 2;
    const int mid_y = 4;
    const int down_down_x = 2;
    const int down_down_y = 8;
    const int right_up_x = 4;
    const int right_up_y = 2;
    const int right_down_x = 4;
    const int right_down_y = 6;

    const int red_up_up_x = 2 + 5;
    const int red_up_up_y = 0;
    const int red_left_up_x = 0 + 5;
    const int red_left_up_y = 2;
    const int red_left_down_x = 0 + 5;
    const int red_left_down_y = 6;
    const int red_mid_x = 2 + 5;
    const int red_mid_y = 4;
    const int red_down_down_x = 2 + 5;
    const int red_down_down_y = 8;
    const int red_right_up_x = 4 + 5;
    const int red_right_up_y = 2;
    const int red_right_down_x = 4 + 5;
    const int red_right_down_y = 6;

    SGeoPoint* up_up = new SGeoPoint(up_up_x, up_up_y);
    SGeoPoint* left_up = new SGeoPoint(left_up_x, left_up_y);
    SGeoPoint* left_down = new SGeoPoint(left_down_x, left_down_y);
    SGeoPoint* right_up = new SGeoPoint(right_up_x, right_up_y);
    SGeoPoint* right_down = new SGeoPoint(right_down_x, right_down_y);
    SGeoPoint* down_down = new SGeoPoint(down_down_x, down_down_y);
    SGeoPoint* mid = new SGeoPoint(mid_x, mid_y);

    SGeoPoint* red_up_up = new SGeoPoint(red_up_up_x, red_up_up_y);
    SGeoPoint* red_left_up = new SGeoPoint(red_left_up_x, red_left_up_y);
    SGeoPoint* red_left_down = new SGeoPoint(red_left_down_x, red_left_down_y);
    SGeoPoint* red_right_up = new SGeoPoint(red_right_up_x, red_right_up_y);
    SGeoPoint* red_right_down = new SGeoPoint(red_right_down_x, red_right_down_y);
    SGeoPoint* red_down_down = new SGeoPoint(red_down_down_x, red_down_down_y);
    SGeoPoint* red_mid = new SGeoPoint(red_mid_x, red_mid_y);
}

Elephant::Elephant(int x, int y, QString name, bool camp, int number, bool isAlive):
    Chess(x, y, name, camp, number, isAlive)
{

}

double Elephant::space_value() {
    if(!isAlive()) return 0;
    if(!canChessMove()) return 0;
    double totalValue = 0;
    const double mid_pos = 2.0;
    const double left_pos = 1.5;
    const double right_pos = 1.0;
    const double red_left_pos = 1.0;
    const double red_right_pos = 1.5;
    const double up_down_pos = 0.5;
    QString chessNameSimple = GlobalEnvirIn::Instance()->__QString2SimpleName(chessName());
    int chessNum = GlobalEnvirIn::Instance()->__QStr2intName(chessNameSimple);
    bool redOrBlack = (chessNum >= 8);
    if(redOrBlack) {
        if(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosX() == ElephantPos::red_mid_x &&
                GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosY() == ElephantPos::red_mid_y) {
            // there are four possible steps
            if(canElephantMove(ElephantPos::red_mid, ElephantPos::red_left_up)) totalValue += mid_pos;
            if(canElephantMove(ElephantPos::red_mid, ElephantPos::red_left_down)) totalValue += mid_pos;
            if(canElephantMove(ElephantPos::red_mid, ElephantPos::red_right_up)) totalValue += mid_pos;
            if(canElephantMove(ElephantPos::red_mid, ElephantPos::red_right_down)) totalValue += mid_pos;
            return totalValue/(4.0 * mid_pos);
        }
        if(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosX() == ElephantPos::red_up_up_x &&
                GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosY() == ElephantPos::red_up_up_y) {
            if(canElephantMove(ElephantPos::red_up_up, ElephantPos::red_left_up)) totalValue += up_down_pos;
            if(canElephantMove(ElephantPos::red_up_up, ElephantPos::red_right_up)) totalValue += up_down_pos;
        }
        if(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosX() == ElephantPos::red_down_down_x &&
                GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosY() == ElephantPos::red_down_down_y) {
            if(canElephantMove(ElephantPos::red_down_down, ElephantPos::red_left_down)) totalValue += up_down_pos;
            if(canElephantMove(ElephantPos::red_down_down, ElephantPos::red_right_down)) totalValue += up_down_pos;
        }
        if(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosX() == ElephantPos::red_left_up_x &&
                GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosY() == ElephantPos::red_left_up_y) {
            if(canElephantMove(ElephantPos::red_left_up, ElephantPos::red_up_up)) totalValue += red_left_pos;
            if(canElephantMove(ElephantPos::red_left_up, ElephantPos::red_mid)) totalValue += red_left_pos;
        }
        if(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosX() == ElephantPos::red_left_down_x &&
                GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosY() == ElephantPos::red_left_down_y) {
            if(canElephantMove(ElephantPos::red_left_down, ElephantPos::red_mid)) totalValue += red_left_pos;
            if(canElephantMove(ElephantPos::red_left_down, ElephantPos::red_down_down)) totalValue += red_left_pos;
        }
        if(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosX() == ElephantPos::red_right_up_x &&
                GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosY() == ElephantPos::red_right_up_y) {
            if(canElephantMove(ElephantPos::red_right_up, ElephantPos::red_up_up)) totalValue += red_right_pos;
            if(canElephantMove(ElephantPos::red_right_up, ElephantPos::red_mid)) totalValue += red_right_pos;
        }
        if(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosX() == ElephantPos::red_right_down_x &&
                GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosY() == ElephantPos::red_right_down_y) {
            if(canElephantMove(ElephantPos::red_right_down, ElephantPos::red_mid)) totalValue += red_right_pos;
            if(canElephantMove(ElephantPos::red_right_down, ElephantPos::red_down_down)) totalValue += red_right_pos;
        }
    }
    else {
        if(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosX() == ElephantPos::mid_x &&
                GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosY() == ElephantPos::mid_y) {
            // there are four possible steps
            if(canElephantMove(ElephantPos::mid, ElephantPos::left_up)) totalValue += mid_pos;
            if(canElephantMove(ElephantPos::mid, ElephantPos::left_down)) totalValue += mid_pos;
            if(canElephantMove(ElephantPos::mid, ElephantPos::right_up)) totalValue += mid_pos;
            if(canElephantMove(ElephantPos::mid, ElephantPos::right_down)) totalValue += mid_pos;
            return totalValue/(4.0 * mid_pos);
        }
        if(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosX() == ElephantPos::up_up_x &&
                GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosY() == ElephantPos::up_up_y) {
            if(canElephantMove(ElephantPos::up_up, ElephantPos::left_up)) totalValue += up_down_pos;
            if(canElephantMove(ElephantPos::up_up, ElephantPos::right_up)) totalValue += up_down_pos;
        }
        if(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosX() == ElephantPos::down_down_x &&
                GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosY() == ElephantPos::down_down_y) {
            if(canElephantMove(ElephantPos::down_down, ElephantPos::left_down)) totalValue += up_down_pos;
            if(canElephantMove(ElephantPos::down_down, ElephantPos::right_down)) totalValue += up_down_pos;
        }
        if(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosX() == ElephantPos::left_up_x &&
                GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosY() == ElephantPos::left_up_y) {
            if(canElephantMove(ElephantPos::left_up, ElephantPos::up_up)) totalValue += left_pos;
            if(canElephantMove(ElephantPos::left_up, ElephantPos::mid)) totalValue += left_pos;
        }
        if(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosX() == ElephantPos::left_down_x &&
                GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosY() == ElephantPos::left_down_y) {
            if(canElephantMove(ElephantPos::left_down, ElephantPos::mid)) totalValue += left_pos;
            if(canElephantMove(ElephantPos::left_down, ElephantPos::down_down)) totalValue += left_pos;
        }
        if(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosX() == ElephantPos::right_up_x &&
                GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosY() == ElephantPos::right_up_y) {
            if(canElephantMove(ElephantPos::right_up, ElephantPos::up_up)) totalValue += right_pos;
            if(canElephantMove(ElephantPos::right_up, ElephantPos::mid)) totalValue += right_pos;
        }
        if(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosX() == ElephantPos::right_down_x &&
                GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosY() == ElephantPos::right_down_y) {
            if(canElephantMove(ElephantPos::right_down, ElephantPos::mid)) totalValue += right_pos;
            if(canElephantMove(ElephantPos::right_down, ElephantPos::down_down)) totalValue += right_pos;
        }
    }
    return totalValue/(4.0 * mid_pos);
}

bool Elephant::canChessMove() {
    QString chessNameSimple = GlobalEnvirIn::Instance()->__QString2SimpleName(chessName());
    int chessNum = GlobalEnvirIn::Instance()->__QStr2intName(chessNameSimple);
    bool redOrBlack = (chessNum >= 8);
    if(redOrBlack) {
        if(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosX() == ElephantPos::red_mid_x &&
                GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosY() == ElephantPos::red_mid_y) {
            // there are four possible steps
            if(canElephantMove(ElephantPos::red_mid, ElephantPos::red_left_up)) return true;
            if(canElephantMove(ElephantPos::red_mid, ElephantPos::red_left_down)) return true;
            if(canElephantMove(ElephantPos::red_mid, ElephantPos::red_right_up)) return true;
            if(canElephantMove(ElephantPos::red_mid, ElephantPos::red_right_down)) return true;
        }
        if(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosX() == ElephantPos::red_up_up_x &&
                GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosY() == ElephantPos::red_up_up_y) {
            if(canElephantMove(ElephantPos::red_up_up, ElephantPos::red_left_up)) return true;
            if(canElephantMove(ElephantPos::red_up_up, ElephantPos::red_right_up)) return true;
        }
        if(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosX() == ElephantPos::red_down_down_x &&
                GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosY() == ElephantPos::red_down_down_y) {
            if(canElephantMove(ElephantPos::red_down_down, ElephantPos::red_left_down)) return true;
            if(canElephantMove(ElephantPos::red_down_down, ElephantPos::red_right_down)) return true;
        }
        if(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosX() == ElephantPos::red_left_up_x &&
                GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosY() == ElephantPos::red_left_up_y) {
            if(canElephantMove(ElephantPos::red_left_up, ElephantPos::red_up_up)) return true;
            if(canElephantMove(ElephantPos::red_left_up, ElephantPos::red_mid)) return true;
        }
        if(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosX() == ElephantPos::red_left_down_x &&
                GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosY() == ElephantPos::red_left_down_y) {
            if(canElephantMove(ElephantPos::red_left_down, ElephantPos::red_mid)) return true;
            if(canElephantMove(ElephantPos::red_left_down, ElephantPos::red_down_down)) return true;
        }
        if(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosX() == ElephantPos::red_right_up_x &&
                GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosY() == ElephantPos::red_right_up_y) {
            if(canElephantMove(ElephantPos::red_right_up, ElephantPos::red_up_up)) return true;
            if(canElephantMove(ElephantPos::red_right_up, ElephantPos::red_mid)) return true;
        }
        if(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosX() == ElephantPos::red_right_down_x &&
                GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosY() == ElephantPos::red_right_down_y) {
            if(canElephantMove(ElephantPos::red_right_down, ElephantPos::red_mid)) return true;
            if(canElephantMove(ElephantPos::red_right_down, ElephantPos::red_down_down)) return true;
        }
    }
    else {
        if(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosX() == ElephantPos::mid_x &&
                GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosY() == ElephantPos::mid_y) {
            // there are four possible steps
            if(canElephantMove(ElephantPos::mid, ElephantPos::left_up)) return true;
            if(canElephantMove(ElephantPos::mid, ElephantPos::left_down)) return true;
            if(canElephantMove(ElephantPos::mid, ElephantPos::right_up)) return true;
            if(canElephantMove(ElephantPos::mid, ElephantPos::right_down)) return true;
        }
        if(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosX() == ElephantPos::up_up_x &&
                GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosY() == ElephantPos::up_up_y) {
            if(canElephantMove(ElephantPos::up_up, ElephantPos::left_up)) return true;
            if(canElephantMove(ElephantPos::up_up, ElephantPos::right_up)) return true;
        }
        if(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosX() == ElephantPos::down_down_x &&
                GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosY() == ElephantPos::down_down_y) {
            if(canElephantMove(ElephantPos::down_down, ElephantPos::left_down)) return true;
            if(canElephantMove(ElephantPos::down_down, ElephantPos::right_down)) return true;
        }
        if(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosX() == ElephantPos::left_up_x &&
                GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosY() == ElephantPos::left_up_y) {
            if(canElephantMove(ElephantPos::left_up, ElephantPos::up_up)) return true;
            if(canElephantMove(ElephantPos::left_up, ElephantPos::mid)) return true;
        }
        if(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosX() == ElephantPos::left_down_x &&
                GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosY() == ElephantPos::left_down_y) {
            if(canElephantMove(ElephantPos::left_down, ElephantPos::mid)) return true;
            if(canElephantMove(ElephantPos::left_down, ElephantPos::down_down)) return true;
        }
        if(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosX() == ElephantPos::right_up_x &&
                GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosY() == ElephantPos::right_up_y) {
            if(canElephantMove(ElephantPos::right_up, ElephantPos::up_up)) return true;
            if(canElephantMove(ElephantPos::right_up, ElephantPos::mid)) return true;
        }
        if(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosX() == ElephantPos::right_down_x &&
                GlobalEnvirIn::Instance()->__QStrOrInt2Chess(chessNum, chessNumber())->getPosY() == ElephantPos::right_down_y) {
            if(canElephantMove(ElephantPos::right_down, ElephantPos::mid)) return true;
            if(canElephantMove(ElephantPos::right_down, ElephantPos::down_down)) return true;
        }
    }
    return false;
}

bool Elephant::canElephantMove(SGeoPoint *start, SGeoPoint *end) {
    const int width = 2;
    const int height = 2;
    if((abs(start->getPosX() - end->getPosX()) != width) || (abs(start->getPosY() - end->getPosY()) != height)) {
        qDebug() << "Elephant.cpp line: 60 canElephantMove() error: invalid move of elephant (2*2)";
        return false;
    }

    return ((!GlobalEnvirIn::Instance()->__isThereHasChess(end)) &&
            (!GlobalEnvirIn::Instance()->__isThereHasChess((start->getPosX() + end->getPosX())/2, (start->getPosY() + end->getPosY())/2)));
}

bool Elephant::canElephantMoveOrKill(SGeoPoint *start, SGeoPoint *end) {
    const int width = 2;
    const int height = 2;
    if((abs(start->getPosX() - end->getPosX()) != width) || (abs(start->getPosY() - end->getPosY()) != height)) {
        qDebug() << "Elephant.cpp line: 60 canElephantMove() error: invalid move of elephant (2*2)";
        return false;
    }

    return (((!GlobalEnvirIn::Instance()->__isThereHasChess(end)) || (!GlobalEnvirIn::Instance()->__isThereHasOurChess(chessCamp(), end))) &&
            (!GlobalEnvirIn::Instance()->__isThereHasChess((start->getPosX() + end->getPosX())/2, (start->getPosY() + end->getPosY())/2)));
}

void Elephant::generateMove() {
    chessStepList.clear();  // api: chessStepList.append(chessStep(1, 1, false, 0 ,0));
    if(!isAlive()) return;
    QString chessNameSimple = GlobalEnvirIn::Instance()->__QString2SimpleName(chessName());
    int Num = GlobalEnvirIn::Instance()->__QStr2intName(chessNameSimple);
    int Number = chessNumber();
    bool kill = false;
    bool redOrBlack = (Num >= 8);
    if(redOrBlack) {
        if(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(Num, chessNumber())->getPosX() == ElephantPos::red_mid_x &&
                GlobalEnvirIn::Instance()->__QStrOrInt2Chess(Num, chessNumber())->getPosY() == ElephantPos::red_mid_y) {
            // there are four possible steps
            if(canElephantMoveOrKill(ElephantPos::red_mid, ElephantPos::red_left_up)) {
                kill = GlobalEnvirIn::Instance()->__isThereHasChess(ElephantPos::red_left_up);
                int killNum = -1;
                int killNumber = -1;
                if(kill) {
                    QString killName = GlobalEnvirIn::Instance()->__QString2SimpleName(GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::red_left_up)->chessName());
                    killNum = GlobalEnvirIn::Instance()->__QStr2intName(killName);
                    killNumber = GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::red_left_up)->chessNumber();
                }
                chessStep tempStep(Num, Number, redOrBlack, ElephantPos::red_left_up->getPosX(), ElephantPos::red_left_up->getPosY(), kill, killNum, killNumber);
                chessStepList.append(tempStep);
            }
            if(canElephantMoveOrKill(ElephantPos::red_mid, ElephantPos::red_left_down)) {
                kill = GlobalEnvirIn::Instance()->__isThereHasChess(ElephantPos::red_left_down);
                int killNum = -1;
                int killNumber = -1;
                if(kill) {
                    QString killName = GlobalEnvirIn::Instance()->__QString2SimpleName(GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::red_left_down)->chessName());
                    killNum = GlobalEnvirIn::Instance()->__QStr2intName(killName);
                    killNumber = GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::red_left_down)->chessNumber();
                }
                chessStep tempStep(Num, Number, redOrBlack, ElephantPos::red_left_down->getPosX(), ElephantPos::red_left_down->getPosY(), kill, killNum, killNumber);
                chessStepList.append(tempStep);
            }
            if(canElephantMoveOrKill(ElephantPos::red_mid, ElephantPos::red_right_up)) {
                kill = GlobalEnvirIn::Instance()->__isThereHasChess(ElephantPos::red_right_up);
                int killNum = -1;
                int killNumber = -1;
                if(kill) {
                    QString killName = GlobalEnvirIn::Instance()->__QString2SimpleName(GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::red_right_up)->chessName());
                    killNum = GlobalEnvirIn::Instance()->__QStr2intName(killName);
                    killNumber = GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::red_right_up)->chessNumber();
                }
                chessStep tempStep(Num, Number, redOrBlack, ElephantPos::red_right_up->getPosX(), ElephantPos::red_right_up->getPosY(), kill, killNum, killNumber);
                chessStepList.append(tempStep);
            }
            if(canElephantMoveOrKill(ElephantPos::red_mid, ElephantPos::red_right_down)) {
                kill = GlobalEnvirIn::Instance()->__isThereHasChess(ElephantPos::red_right_down);
                int killNum = -1;
                int killNumber = -1;
                if(kill) {
                    QString killName = GlobalEnvirIn::Instance()->__QString2SimpleName(GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::red_right_down)->chessName());
                    killNum = GlobalEnvirIn::Instance()->__QStr2intName(killName);
                    killNumber = GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::red_right_down)->chessNumber();
                }
                chessStep tempStep(Num, Number, redOrBlack, ElephantPos::red_right_down->getPosX(), ElephantPos::red_right_down->getPosY(), kill, killNum, killNumber);
                chessStepList.append(tempStep);
            }
        }
        if(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(Num, chessNumber())->getPosX() == ElephantPos::red_up_up_x &&
                GlobalEnvirIn::Instance()->__QStrOrInt2Chess(Num, chessNumber())->getPosY() == ElephantPos::red_up_up_y) {
            if(canElephantMoveOrKill(ElephantPos::red_up_up, ElephantPos::red_left_up)) {
                kill = GlobalEnvirIn::Instance()->__isThereHasChess(ElephantPos::red_left_up);
                int killNum = -1;
                int killNumber = -1;
                if(kill) {
                    QString killName = GlobalEnvirIn::Instance()->__QString2SimpleName(GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::red_left_up)->chessName());
                    killNum = GlobalEnvirIn::Instance()->__QStr2intName(killName);
                    killNumber = GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::red_left_up)->chessNumber();
                }
                chessStep tempStep(Num, Number, redOrBlack, ElephantPos::red_left_up->getPosX(), ElephantPos::red_left_up->getPosY(), kill, killNum, killNumber);
                chessStepList.append(tempStep);
            }
            if(canElephantMoveOrKill(ElephantPos::red_up_up, ElephantPos::red_right_up)) {
                kill = GlobalEnvirIn::Instance()->__isThereHasChess(ElephantPos::red_right_up);
                int killNum = -1;
                int killNumber = -1;
                if(kill) {
                    QString killName = GlobalEnvirIn::Instance()->__QString2SimpleName(GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::red_right_up)->chessName());
                    killNum = GlobalEnvirIn::Instance()->__QStr2intName(killName);
                    killNumber = GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::red_right_up)->chessNumber();
                }
                chessStep tempStep(Num, Number, redOrBlack, ElephantPos::red_right_up->getPosX(), ElephantPos::red_right_up->getPosY(), kill, killNum, killNumber);
                chessStepList.append(tempStep);
            }
        }
        if(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(Num, chessNumber())->getPosX() == ElephantPos::red_down_down_x &&
                GlobalEnvirIn::Instance()->__QStrOrInt2Chess(Num, chessNumber())->getPosY() == ElephantPos::red_down_down_y) {
            if(canElephantMoveOrKill(ElephantPos::red_down_down, ElephantPos::red_left_down)) {
                kill = GlobalEnvirIn::Instance()->__isThereHasChess(ElephantPos::red_left_down);
                int killNum = -1;
                int killNumber = -1;
                if(kill) {
                    QString killName = GlobalEnvirIn::Instance()->__QString2SimpleName(GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::red_left_down)->chessName());
                    killNum = GlobalEnvirIn::Instance()->__QStr2intName(killName);
                    killNumber = GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::red_left_down)->chessNumber();
                }
                chessStep tempStep(Num, Number, redOrBlack, ElephantPos::red_left_down->getPosX(), ElephantPos::red_left_down->getPosY(), kill, killNum, killNumber);
                chessStepList.append(tempStep);
            }
            if(canElephantMoveOrKill(ElephantPos::red_down_down, ElephantPos::red_right_down)) {
                kill = GlobalEnvirIn::Instance()->__isThereHasChess(ElephantPos::red_right_down);
                int killNum = -1;
                int killNumber = -1;
                if(kill) {
                    QString killName = GlobalEnvirIn::Instance()->__QString2SimpleName(GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::red_right_down)->chessName());
                    killNum = GlobalEnvirIn::Instance()->__QStr2intName(killName);
                    killNumber = GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::red_right_down)->chessNumber();
                }
                chessStep tempStep(Num, Number, redOrBlack, ElephantPos::red_right_down->getPosX(), ElephantPos::red_right_down->getPosY(), kill, killNum, killNumber);
                chessStepList.append(tempStep);
            }
        }
        if(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(Num, chessNumber())->getPosX() == ElephantPos::red_left_up_x &&
                GlobalEnvirIn::Instance()->__QStrOrInt2Chess(Num, chessNumber())->getPosY() == ElephantPos::red_left_up_y) {
            if(canElephantMoveOrKill(ElephantPos::red_left_up, ElephantPos::red_up_up)) {
                kill = GlobalEnvirIn::Instance()->__isThereHasChess(ElephantPos::red_up_up);
                int killNum = -1;
                int killNumber = -1;
                if(kill) {
                    QString killName = GlobalEnvirIn::Instance()->__QString2SimpleName(GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::red_up_up)->chessName());
                    killNum = GlobalEnvirIn::Instance()->__QStr2intName(killName);
                    killNumber = GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::red_up_up)->chessNumber();
                }
                chessStep tempStep(Num, Number, redOrBlack, ElephantPos::red_up_up->getPosX(), ElephantPos::red_up_up->getPosY(), kill, killNum, killNumber);
                chessStepList.append(tempStep);
            }
            if(canElephantMoveOrKill(ElephantPos::red_left_up, ElephantPos::red_mid)) {
                kill = GlobalEnvirIn::Instance()->__isThereHasChess(ElephantPos::red_mid);
                int killNum = -1;
                int killNumber = -1;
                if(kill) {
                    QString killName = GlobalEnvirIn::Instance()->__QString2SimpleName(GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::red_mid)->chessName());
                    killNum = GlobalEnvirIn::Instance()->__QStr2intName(killName);
                    killNumber = GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::red_mid)->chessNumber();
                }
                chessStep tempStep(Num, Number, redOrBlack, ElephantPos::red_mid->getPosX(), ElephantPos::red_mid->getPosY(), kill, killNum, killNumber);
                chessStepList.append(tempStep);
            }
        }
        if(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(Num, chessNumber())->getPosX() == ElephantPos::red_left_down_x &&
                GlobalEnvirIn::Instance()->__QStrOrInt2Chess(Num, chessNumber())->getPosY() == ElephantPos::red_left_down_y) {
            if(canElephantMoveOrKill(ElephantPos::red_left_down, ElephantPos::red_mid)) {
                kill = GlobalEnvirIn::Instance()->__isThereHasChess(ElephantPos::red_mid);
                int killNum = -1;
                int killNumber = -1;
                if(kill) {
                    QString killName = GlobalEnvirIn::Instance()->__QString2SimpleName(GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::red_mid)->chessName());
                    killNum = GlobalEnvirIn::Instance()->__QStr2intName(killName);
                    killNumber = GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::red_mid)->chessNumber();
                }
                chessStep tempStep(Num, Number, redOrBlack, ElephantPos::red_mid->getPosX(), ElephantPos::red_mid->getPosY(), kill, killNum, killNumber);
                chessStepList.append(tempStep);
            }
            if(canElephantMoveOrKill(ElephantPos::red_left_down, ElephantPos::red_down_down)) {
                kill = GlobalEnvirIn::Instance()->__isThereHasChess(ElephantPos::red_down_down);
                int killNum = -1;
                int killNumber = -1;
                if(kill) {
                    QString killName = GlobalEnvirIn::Instance()->__QString2SimpleName(GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::red_down_down)->chessName());
                    killNum = GlobalEnvirIn::Instance()->__QStr2intName(killName);
                    killNumber = GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::red_down_down)->chessNumber();
                }
                chessStep tempStep(Num, Number, redOrBlack, ElephantPos::red_down_down->getPosX(), ElephantPos::red_down_down->getPosY(), kill, killNum, killNumber);
                chessStepList.append(tempStep);
            }
        }
        if(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(Num, chessNumber())->getPosX() == ElephantPos::red_right_up_x &&
                GlobalEnvirIn::Instance()->__QStrOrInt2Chess(Num, chessNumber())->getPosY() == ElephantPos::red_right_up_y) {
            if(canElephantMoveOrKill(ElephantPos::red_right_up, ElephantPos::red_up_up)) {
                kill = GlobalEnvirIn::Instance()->__isThereHasChess(ElephantPos::red_up_up);
                int killNum = -1;
                int killNumber = -1;
                if(kill) {
                    QString killName = GlobalEnvirIn::Instance()->__QString2SimpleName(GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::red_up_up)->chessName());
                    killNum = GlobalEnvirIn::Instance()->__QStr2intName(killName);
                    killNumber = GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::red_up_up)->chessNumber();
                }
                chessStep tempStep(Num, Number, redOrBlack, ElephantPos::red_up_up->getPosX(), ElephantPos::red_up_up->getPosY(), kill, killNum, killNumber);
                chessStepList.append(tempStep);
            }
            if(canElephantMoveOrKill(ElephantPos::red_right_up, ElephantPos::red_mid)) {
                kill = GlobalEnvirIn::Instance()->__isThereHasChess(ElephantPos::red_mid);
                int killNum = -1;
                int killNumber = -1;
                if(kill) {
                    QString killName = GlobalEnvirIn::Instance()->__QString2SimpleName(GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::red_mid)->chessName());
                    killNum = GlobalEnvirIn::Instance()->__QStr2intName(killName);
                    killNumber = GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::red_mid)->chessNumber();
                }
                chessStep tempStep(Num, Number, redOrBlack, ElephantPos::red_mid->getPosX(), ElephantPos::red_mid->getPosY(), kill, killNum, killNumber);
                chessStepList.append(tempStep);
            }
        }
        if(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(Num, chessNumber())->getPosX() == ElephantPos::red_right_down_x &&
                GlobalEnvirIn::Instance()->__QStrOrInt2Chess(Num, chessNumber())->getPosY() == ElephantPos::red_right_down_y) {
            if(canElephantMoveOrKill(ElephantPos::red_right_down, ElephantPos::red_mid)) {
                kill = GlobalEnvirIn::Instance()->__isThereHasChess(ElephantPos::red_mid);
                int killNum = -1;
                int killNumber = -1;
                if(kill) {
                    QString killName = GlobalEnvirIn::Instance()->__QString2SimpleName(GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::red_mid)->chessName());
                    killNum = GlobalEnvirIn::Instance()->__QStr2intName(killName);
                    killNumber = GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::red_mid)->chessNumber();
                }
                chessStep tempStep(Num, Number, redOrBlack, ElephantPos::red_mid->getPosX(), ElephantPos::red_mid->getPosY(), kill, killNum, killNumber);
                chessStepList.append(tempStep);
            }
            if(canElephantMoveOrKill(ElephantPos::red_right_down, ElephantPos::red_down_down)) {
                kill = GlobalEnvirIn::Instance()->__isThereHasChess(ElephantPos::red_down_down);
                int killNum = -1;
                int killNumber = -1;
                if(kill) {
                    QString killName = GlobalEnvirIn::Instance()->__QString2SimpleName(GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::red_down_down)->chessName());
                    killNum = GlobalEnvirIn::Instance()->__QStr2intName(killName);
                    killNumber = GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::red_down_down)->chessNumber();
                }
                chessStep tempStep(Num, Number, redOrBlack, ElephantPos::red_down_down->getPosX(), ElephantPos::red_down_down->getPosY(), kill, killNum, killNumber);
                chessStepList.append(tempStep);
            }
        }
    }
    else {
        if(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(Num, chessNumber())->getPosX() == ElephantPos::mid_x &&
                GlobalEnvirIn::Instance()->__QStrOrInt2Chess(Num, chessNumber())->getPosY() == ElephantPos::mid_y) {
            // there are four possible steps
            if(canElephantMoveOrKill(ElephantPos::mid, ElephantPos::left_up)) {
                kill = GlobalEnvirIn::Instance()->__isThereHasChess(ElephantPos::left_up);
                int killNum = -1;
                int killNumber = -1;
                if(kill) {
                    QString killName = GlobalEnvirIn::Instance()->__QString2SimpleName(GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::left_up)->chessName());
                    killNum = GlobalEnvirIn::Instance()->__QStr2intName(killName);
                    killNumber = GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::left_up)->chessNumber();
                }
                chessStep tempStep(Num, Number, redOrBlack, ElephantPos::left_up->getPosX(), ElephantPos::left_up->getPosY(), kill, killNum, killNumber);
                chessStepList.append(tempStep);
            }
            if(canElephantMoveOrKill(ElephantPos::mid, ElephantPos::left_down)) {
                kill = GlobalEnvirIn::Instance()->__isThereHasChess(ElephantPos::left_down);
                int killNum = -1;
                int killNumber = -1;
                if(kill) {
                    QString killName = GlobalEnvirIn::Instance()->__QString2SimpleName(GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::left_down)->chessName());
                    killNum = GlobalEnvirIn::Instance()->__QStr2intName(killName);
                    killNumber = GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::left_down)->chessNumber();
                }
                chessStep tempStep(Num, Number, redOrBlack, ElephantPos::left_down->getPosX(), ElephantPos::left_down->getPosY(), kill, killNum, killNumber);
                chessStepList.append(tempStep);
            }
            if(canElephantMoveOrKill(ElephantPos::mid, ElephantPos::right_up)) {
                kill = GlobalEnvirIn::Instance()->__isThereHasChess(ElephantPos::right_up);
                int killNum = -1;
                int killNumber = -1;
                if(kill) {
                    QString killName = GlobalEnvirIn::Instance()->__QString2SimpleName(GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::right_up)->chessName());
                    killNum = GlobalEnvirIn::Instance()->__QStr2intName(killName);
                    killNumber = GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::right_up)->chessNumber();
                }
                chessStep tempStep(Num, Number, redOrBlack, ElephantPos::right_up->getPosX(), ElephantPos::right_up->getPosY(), kill, killNum, killNumber);
                chessStepList.append(tempStep);
            }
            if(canElephantMoveOrKill(ElephantPos::mid, ElephantPos::right_down)) {
                kill = GlobalEnvirIn::Instance()->__isThereHasChess(ElephantPos::right_down);
                int killNum = -1;
                int killNumber = -1;
                if(kill) {
                    QString killName = GlobalEnvirIn::Instance()->__QString2SimpleName(GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::right_down)->chessName());
                    killNum = GlobalEnvirIn::Instance()->__QStr2intName(killName);
                    killNumber = GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::right_down)->chessNumber();
                }
                chessStep tempStep(Num, Number, redOrBlack, ElephantPos::right_down->getPosX(), ElephantPos::right_down->getPosY(), kill, killNum, killNumber);
                chessStepList.append(tempStep);
            }
        }
        if(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(Num, chessNumber())->getPosX() == ElephantPos::up_up_x &&
                GlobalEnvirIn::Instance()->__QStrOrInt2Chess(Num, chessNumber())->getPosY() == ElephantPos::up_up_y) {
            if(canElephantMoveOrKill(ElephantPos::up_up, ElephantPos::left_up)) {
                kill = GlobalEnvirIn::Instance()->__isThereHasChess(ElephantPos::left_up);
                int killNum = -1;
                int killNumber = -1;
                if(kill) {
                    QString killName = GlobalEnvirIn::Instance()->__QString2SimpleName(GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::left_up)->chessName());
                    killNum = GlobalEnvirIn::Instance()->__QStr2intName(killName);
                    killNumber = GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::left_up)->chessNumber();
                }
                chessStep tempStep(Num, Number, redOrBlack, ElephantPos::left_up->getPosX(), ElephantPos::left_up->getPosY(), kill, killNum, killNumber);
                chessStepList.append(tempStep);
            }
            if(canElephantMoveOrKill(ElephantPos::up_up, ElephantPos::right_up)) {
                kill = GlobalEnvirIn::Instance()->__isThereHasChess(ElephantPos::right_up);
                int killNum = -1;
                int killNumber = -1;
                if(kill) {
                    QString killName = GlobalEnvirIn::Instance()->__QString2SimpleName(GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::right_up)->chessName());
                    killNum = GlobalEnvirIn::Instance()->__QStr2intName(killName);
                    killNumber = GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::right_up)->chessNumber();
                }
                chessStep tempStep(Num, Number, redOrBlack, ElephantPos::right_up->getPosX(), ElephantPos::right_up->getPosY(), kill, killNum, killNumber);
                chessStepList.append(tempStep);
            }
        }
        if(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(Num, chessNumber())->getPosX() == ElephantPos::down_down_x &&
                GlobalEnvirIn::Instance()->__QStrOrInt2Chess(Num, chessNumber())->getPosY() == ElephantPos::down_down_y) {
            if(canElephantMoveOrKill(ElephantPos::down_down, ElephantPos::left_down)) {
                kill = GlobalEnvirIn::Instance()->__isThereHasChess(ElephantPos::left_down);
                int killNum = -1;
                int killNumber = -1;
                if(kill) {
                    QString killName = GlobalEnvirIn::Instance()->__QString2SimpleName(GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::left_down)->chessName());
                    killNum = GlobalEnvirIn::Instance()->__QStr2intName(killName);
                    killNumber = GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::left_down)->chessNumber();
                }
                chessStep tempStep(Num, Number, redOrBlack, ElephantPos::left_down->getPosX(), ElephantPos::left_down->getPosY(), kill, killNum, killNumber);
                chessStepList.append(tempStep);
            }
            if(canElephantMoveOrKill(ElephantPos::down_down, ElephantPos::right_down)) {
                kill = GlobalEnvirIn::Instance()->__isThereHasChess(ElephantPos::right_down);
                int killNum = -1;
                int killNumber = -1;
                if(kill) {
                    QString killName = GlobalEnvirIn::Instance()->__QString2SimpleName(GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::right_down)->chessName());
                    killNum = GlobalEnvirIn::Instance()->__QStr2intName(killName);
                    killNumber = GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::right_down)->chessNumber();
                }
                chessStep tempStep(Num, Number, redOrBlack, ElephantPos::right_down->getPosX(), ElephantPos::right_down->getPosY(), kill, killNum, killNumber);
                chessStepList.append(tempStep);
            }
        }
        if(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(Num, chessNumber())->getPosX() == ElephantPos::left_up_x &&
                GlobalEnvirIn::Instance()->__QStrOrInt2Chess(Num, chessNumber())->getPosY() == ElephantPos::left_up_y) {
            if(canElephantMoveOrKill(ElephantPos::left_up, ElephantPos::up_up)) {
                kill = GlobalEnvirIn::Instance()->__isThereHasChess(ElephantPos::up_up);
                int killNum = -1;
                int killNumber = -1;
                if(kill) {
                    QString killName = GlobalEnvirIn::Instance()->__QString2SimpleName(GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::up_up)->chessName());
                    killNum = GlobalEnvirIn::Instance()->__QStr2intName(killName);
                    killNumber = GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::up_up)->chessNumber();
                }
                chessStep tempStep(Num, Number, redOrBlack, ElephantPos::up_up->getPosX(), ElephantPos::up_up->getPosY(), kill, killNum, killNumber);
                chessStepList.append(tempStep);
            }
            if(canElephantMoveOrKill(ElephantPos::left_up, ElephantPos::mid)) {
                kill = GlobalEnvirIn::Instance()->__isThereHasChess(ElephantPos::mid);
                int killNum = -1;
                int killNumber = -1;
                if(kill) {
                    QString killName = GlobalEnvirIn::Instance()->__QString2SimpleName(GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::mid)->chessName());
                    killNum = GlobalEnvirIn::Instance()->__QStr2intName(killName);
                    killNumber = GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::mid)->chessNumber();
                }
                chessStep tempStep(Num, Number, redOrBlack, ElephantPos::mid->getPosX(), ElephantPos::mid->getPosY(), kill, killNum, killNumber);
                chessStepList.append(tempStep);
            }
        }
        if(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(Num, chessNumber())->getPosX() == ElephantPos::left_down_x &&
                GlobalEnvirIn::Instance()->__QStrOrInt2Chess(Num, chessNumber())->getPosY() == ElephantPos::left_down_y) {
            if(canElephantMoveOrKill(ElephantPos::left_down, ElephantPos::mid)) {
                kill = GlobalEnvirIn::Instance()->__isThereHasChess(ElephantPos::mid);
                int killNum = -1;
                int killNumber = -1;
                if(kill) {
                    QString killName = GlobalEnvirIn::Instance()->__QString2SimpleName(GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::mid)->chessName());
                    killNum = GlobalEnvirIn::Instance()->__QStr2intName(killName);
                    killNumber = GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::mid)->chessNumber();
                }
                chessStep tempStep(Num, Number, redOrBlack, ElephantPos::mid->getPosX(), ElephantPos::mid->getPosY(), kill, killNum, killNumber);
                chessStepList.append(tempStep);
            }
            if(canElephantMoveOrKill(ElephantPos::left_down, ElephantPos::down_down)) {
                kill = GlobalEnvirIn::Instance()->__isThereHasChess(ElephantPos::down_down);
                int killNum = -1;
                int killNumber = -1;
                if(kill) {
                    QString killName = GlobalEnvirIn::Instance()->__QString2SimpleName(GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::down_down)->chessName());
                    killNum = GlobalEnvirIn::Instance()->__QStr2intName(killName);
                    killNumber = GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::down_down)->chessNumber();
                }
                chessStep tempStep(Num, Number, redOrBlack, ElephantPos::down_down->getPosX(), ElephantPos::down_down->getPosY(), kill, killNum, killNumber);
                chessStepList.append(tempStep);
            }
        }
        if(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(Num, chessNumber())->getPosX() == ElephantPos::right_up_x &&
                GlobalEnvirIn::Instance()->__QStrOrInt2Chess(Num, chessNumber())->getPosY() == ElephantPos::right_up_y) {
            if(canElephantMoveOrKill(ElephantPos::right_up, ElephantPos::up_up)) {
                kill = GlobalEnvirIn::Instance()->__isThereHasChess(ElephantPos::up_up);
                int killNum = -1;
                int killNumber = -1;
                if(kill) {
                    QString killName = GlobalEnvirIn::Instance()->__QString2SimpleName(GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::up_up)->chessName());
                    killNum = GlobalEnvirIn::Instance()->__QStr2intName(killName);
                    killNumber = GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::up_up)->chessNumber();
                }
                chessStep tempStep(Num, Number, redOrBlack, ElephantPos::up_up->getPosX(), ElephantPos::up_up->getPosY(), kill, killNum, killNumber);
                chessStepList.append(tempStep);
            }
            if(canElephantMoveOrKill(ElephantPos::right_up, ElephantPos::mid)) {
                kill = GlobalEnvirIn::Instance()->__isThereHasChess(ElephantPos::mid);
                int killNum = -1;
                int killNumber = -1;
                if(kill) {
                    QString killName = GlobalEnvirIn::Instance()->__QString2SimpleName(GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::mid)->chessName());
                    killNum = GlobalEnvirIn::Instance()->__QStr2intName(killName);
                    killNumber = GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::mid)->chessNumber();
                }
                chessStep tempStep(Num, Number, redOrBlack, ElephantPos::mid->getPosX(), ElephantPos::mid->getPosY(), kill, killNum, killNumber);
                chessStepList.append(tempStep);
            }
        }
        if(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(Num, chessNumber())->getPosX() == ElephantPos::right_down_x &&
                GlobalEnvirIn::Instance()->__QStrOrInt2Chess(Num, chessNumber())->getPosY() == ElephantPos::right_down_y) {
            if(canElephantMoveOrKill(ElephantPos::right_down, ElephantPos::mid)) {
                kill = GlobalEnvirIn::Instance()->__isThereHasChess(ElephantPos::mid);
                int killNum = -1;
                int killNumber = -1;
                if(kill) {
                    QString killName = GlobalEnvirIn::Instance()->__QString2SimpleName(GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::mid)->chessName());
                    killNum = GlobalEnvirIn::Instance()->__QStr2intName(killName);
                    killNumber = GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::mid)->chessNumber();
                }
                chessStep tempStep(Num, Number, redOrBlack, ElephantPos::mid->getPosX(), ElephantPos::mid->getPosY(), kill, killNum, killNumber);
                chessStepList.append(tempStep);
            }
            if(canElephantMoveOrKill(ElephantPos::right_down, ElephantPos::down_down)) {
                kill = GlobalEnvirIn::Instance()->__isThereHasChess(ElephantPos::down_down);
                int killNum = -1;
                int killNumber = -1;
                if(kill) {
                    QString killName = GlobalEnvirIn::Instance()->__QString2SimpleName(GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::down_down)->chessName());
                    killNum = GlobalEnvirIn::Instance()->__QStr2intName(killName);
                    killNumber = GlobalEnvirIn::Instance()->__whichChessOnThere(ElephantPos::down_down)->chessNumber();
                }
                chessStep tempStep(Num, Number, redOrBlack, ElephantPos::down_down->getPosX(), ElephantPos::down_down->getPosY(), kill, killNum, killNumber);
                chessStepList.append(tempStep);
            }
        }
    }
    tranStarStepList();
}
