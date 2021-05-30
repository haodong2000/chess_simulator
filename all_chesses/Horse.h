#ifndef HORSE_H
#define HORSE_H

/* * * * * * * * * * * * * * * * * * * * *
*   File:     Horse.h
*   Author:   Haodong LI
*   Usage:    UsageOfFile
*   Time:     2021-05-30
* * * * * * * * * * * * * * * * * * * * * */

#include "Chess.h"
#include "global.h"

class Horse: public Chess
{
public:
    Horse(int x = 0, int y = 0,
          QString name = "Horse", // empty name is illegal
          bool camp = false, // black is default
          int number = 0, // 0 is an error number, only 1-5 is legal
          bool alive = true);
};

#endif // HORSE_H
