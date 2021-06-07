#ifndef GENERAL_H
#define GENERAL_H

/* * * * * * * * * * * * * * * * * * * * *
*   File:     General.h
*   Author:   Haodong LI
*   Usage:    UsageOfFile
*   Time:     2021-05-30
* * * * * * * * * * * * * * * * * * * * * */

#include "Chess.h"
#include "global.h"

class General: public Chess
{
public:
    General(int x = 0, int y = 0,
            const QString name = "General", // empty name is illegal
            const bool camp = false, // black is default
            const int number = 0, // 0 is an error number, only 1-5 is legal
            bool alive = true);
    virtual double space_value(); // 0~100%
    virtual bool canChessMove();
    virtual void generateMove();
    virtual bool canGeneralMoveOrKill(SGeoPoint* start, SGeoPoint* end);
    virtual bool generalInPavilion(SGeoPoint* Pos);
};

#endif // GENERAL_H
