#include "tran_step.h"

/*****************************************************************
*   File:     tran_step.cpp
*   Author:   Haodong LI
*   Usage:    TheUsageOfFile
*   Time:     2022-02-23 -> 20:05:39
*****************************************************************/

tran_step::tran_step():Step(-1, -1, false,- 1, -1), isStepReady(false) { }

void tran_step::tranStep2ChessStep() {
    while (rl_brain->retuanIsTranStepReady() == false) {
        GlobalEnvirIn::Instance()->__delayMsec(10);
    }
    int chessNum = rl_brain->tranChessStep_RL.chessNum;
    int pos_y = rl_brain->tranChessStep_RL.pos_x;
    int pos_x = rl_brain->tranChessStep_RL.pos_y;
    int tar_y = rl_brain->tranChessStep_RL.tar_x;
    int tar_x = rl_brain->tranChessStep_RL.tar_y;
    Step._chessNum = chessNum;
    Step._chessNumber = GlobalEnvirIn::Instance()->__whichChessOnThere(pos_x, pos_y)->chessNumber();
    Step._deltaX = tar_x; // no delta bur target!
    Step._deltaY = tar_y;
    Step._isKill = GlobalEnvirIn::Instance()->__isThereHasChess(tar_x, tar_y);
//    std::cout << Step._chessNum << " " << Step._chessNumber << " " << Step._deltaX << " " << Step._deltaY << std::endl;
    if(Step._isKill) {
        Step._chessKilledNum = GlobalEnvirIn::Instance()->__QStr2intName(
                    GlobalEnvirIn::Instance()->__QString2SimpleName(
                        GlobalEnvirIn::Instance()->__whichChessOnThere(tar_x, tar_y)->chessName()));
        Step._chessKilledNumber = GlobalEnvirIn::Instance()->__whichChessOnThere(tar_x, tar_y)->chessNumber();
    }
    rl_brain->setIsTranStepReady(false);
    isStepReady = true;
}

bool tran_step::returnIsStepReady() {
    return isStepReady;
}

void tran_step::setIsStepReady(bool curIsStepReady) {
    isStepReady = curIsStepReady;
}
