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
    bool kill = GlobalEnvirIn::Instance()->__isThereHasChess(tar_x, tar_y);
    int k_num = 0;
    if(kill) {
        QString k_num_name = GlobalEnvirIn::Instance()->__whichChessOnThere(tar_x, tar_y)->chessName();
        k_num = GlobalEnvirIn::Instance()->__QStr2intName(GlobalEnvirIn::Instance()->__QString2SimpleName(k_num_name));
    }
    else {
        k_num = rl_brain->tranChessStep_RL.kill_num;
    }
    std::cout << "-*-*-*- tranStep2ChessStep -> " << chessNum << " "
              << pos_x << " " << pos_y << " " << tar_x << " " << tar_y << " "
              << kill << " " << k_num << "\n==========CAO=========" << std::endl;
    Step._chessNum = chessNum;
//    std::cout << Ab_gen_1->getPosX() << " " << Ab_gen_1->getPosY() << "  ==  " << pos_x << " " << pos_y << std::endl;
    Step._chessNumber = GlobalEnvirIn::Instance()->__whichChessOnThere(pos_x, pos_y)->chessNumber();
    Step._deltaX = tar_x; // no delta bur target!
    Step._deltaY = tar_y;
    Step._isKill = kill;
    if(kill) {
        Step._chessKilledNum = k_num;
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
