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
    // api: chessStepList.append(chessStep(1, 1, false, 0 ,0));
}
