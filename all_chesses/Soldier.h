#ifndef SOLDIER_H
#define SOLDIER_H

/* * * * * * * * * * * * * * * * * * * * *
*   File:     Soldier.h
*   Author:   Haodong LI
*   Usage:    UsageOfFile
*   Time:     2021-05-30
* * * * * * * * * * * * * * * * * * * * * */

#include "Chess.h"
#include "global.h"

class Soldier: public Chess
{
public:
    Soldier(int x = 0, int y = 0,
            const QString name = "Soldier", // empty name is illegal
            const bool camp = false, // black is default
            const int number = 0, // 0 is an error number, only 1-5 is legal
            bool alive = true);
    virtual double space_value(); // 0~100%
    virtual bool canChessMove();
};

#endif // SOLDIER_H
