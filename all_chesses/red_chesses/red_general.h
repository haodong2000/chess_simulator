#ifndef RED_GENERAL_H
#define RED_GENERAL_H

/* * * * * * * * * * * * * * * * * * * * *
*   File:     red_general.h
*   Author:   Haodong LI
*   Usage:    TheUsageOfFile
*   Time:     2021-05-30
* * * * * * * * * * * * * * * * * * * * * */

#include "../General.h"

class red_general: General
{
public:
    red_general(int x = 0, int y = 0,
                QString name = "RGeneral", // empty name is illegal
                bool camp = true, // black is default
                int number = 1, // 0 is an error number, only 1-5 is legal
                bool alive = true);
};

#endif // RED_GENERAL_H
