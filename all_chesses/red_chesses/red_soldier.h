#ifndef RED_SOLDIER_H
#define RED_SOLDIER_H

/*****************************************************************
*   File:     red_soldier.h
*   Author:   Haodong LI
*   Usage:    TheUsageOfFile
*   Time:     2021-05-30 -> 21:04:35
*****************************************************************/

#include "Soldier.h"

class red_soldier: public Soldier
{
public:
    red_soldier(int x = 0, int y = 0,
                QString name = "RSoldier", // empty name is illegal
                bool camp = true, // black is default
                int number = 1, // 0 is an error number, only 1-5 is legal
                bool alive = true);
};

#endif // RED_SOLDIER_H
