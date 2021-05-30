#ifndef ADVISOR_H
#define ADVISOR_H

/* * * * * * * * * * * * * * * * * * * * *
*   File:     Advisor.h
*   Author:   Haodong LI
*   Usage:    UsageOfFile
*   Time:     2021-05-30
* * * * * * * * * * * * * * * * * * * * * */

#include "Chess.h"
#include "global.h"

class Advisor: public Chess
{
public:
    Advisor(int x = 0, int y = 0,
            const QString name = "Advisor", // empty name is illegal
            const bool camp = false, // black is default
            const int number = 0, // 0 is an error number, only 1-5 is legal
            bool alive = true);
};

#endif // ADVISOR_H
