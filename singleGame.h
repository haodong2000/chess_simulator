#ifndef SINGLEGAME_H
#define SINGLEGAME_H

/*****************************************************************
*   File:     singleGame.h
*   Author:   Haodong LI
*   Usage:    alpha-beta
*   Time:     2021-06-06 -> 14:25:53
*****************************************************************/

#include "Step.h"
#include "global.h"
#include "globalChesses.h"

class singleGame
{
public:
    singleGame();
    Step* chessStep;
};

typedef NormalSingleton< singleGame > singleGameIn;

#endif // SINGLEGAME_H
