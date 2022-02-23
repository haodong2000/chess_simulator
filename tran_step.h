#ifndef TRAN_STEP_H
#define TRAN_STEP_H

#include "global.h"
#include "singleton.h"
#include "Qml_Connection.h"
#include "rl_thread.h"
#include "allBRChessesInclude.h"
#include "globalChesses.h"
#include "chessstep.h"

/*****************************************************************
*   File:     tran_step.h
*   Author:   Haodong LI
*   Usage:    TheUsageOfFile
*   Time:     2022-02-23 -> 20:02:51
*****************************************************************/

extern rl_thread *rl_brain;

class tran_step
{
public:
    tran_step();
    virtual void tranStep2ChessStep();
    virtual bool returnIsStepReady();
    virtual void setIsStepReady(bool curIsStepReady);
public:
    chessStep Step;
    bool isStepReady;
};

typedef NormalSingleton< tran_step > tranStepIn;

#endif // TRAN_STEP_H
