#include "Soldier.h"

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

void Soldier::generateMove() {

}
