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

    SGeoPoint* up_up = new SGeoPoint(up_up_x, up_up_y);
    SGeoPoint* left_up = new SGeoPoint(left_up_x, left_up_y);
    SGeoPoint* left_down = new SGeoPoint(left_down_x, left_down_y);
    SGeoPoint* right_up = new SGeoPoint(right_up_x, right_up_y);
    SGeoPoint* right_down = new SGeoPoint(right_down_x, right_down_y);
    SGeoPoint* down_down = new SGeoPoint(down_down_x, down_down_y);
    SGeoPoint* mid = new SGeoPoint(mid_x, mid_y);
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
    const double up_down_pos = 0.5;
    QString chessNameSimple = GlobalEnvirIn::Instance()->__QString2SimpleName(chessName());
    int chessNum = GlobalEnvirIn::Instance()->__QStr2intName(chessNameSimple);
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
    return totalValue/(2.0 * mid_pos);
}

bool Elephant::canChessMove() {
    QString chessNameSimple = GlobalEnvirIn::Instance()->__QString2SimpleName(chessName());
    int chessNum = GlobalEnvirIn::Instance()->__QStr2intName(chessNameSimple);
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
    return false;
}

bool Elephant::canElephantMove(SGeoPoint *start, SGeoPoint *end) {
    const int width = 2;
    const int height = 2;
    if((abs(start->getPosX() - end->getPosX()) != width) || (abs(start->getPosY() - end->getPosY()) != height)) {
        qDebug() << "Elephant.cpp line: 60 canElephantMove() error: invalid move of elephant (2*2)";
        return false;
    }

    return ((GlobalEnvirIn::Instance()->__isThereHasChess(end)) &&
            (GlobalEnvirIn::Instance()->__isThereHasChess((start->getPosX() + end->getPosX())/2, (start->getPosY() + end->getPosY())/2)));
}

void Elephant::generateMove() {

}
