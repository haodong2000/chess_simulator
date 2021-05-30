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
            QString name = "General", // empty name is illegal
            bool camp = false, // black is default
            int number = 0, // 0 is an error number, only 1-5 is legal
            bool alive = true);
};

#endif // GENERAL_H
