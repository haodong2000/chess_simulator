#ifndef RED_CANNON_H
#define RED_CANNON_H

/*****************************************************************
*   File:     red_cannon.h
*   Author:   Haodong LI
*   Usage:    TheUsageOfFile
*   Time:     2021-05-30 -> 20:53:12
*****************************************************************/

#include "Cannon.h"

class red_cannon: public Cannon
{
public:
    red_cannon(int x = 0, int y = 0,
               QString name = "Cannon", // empty name is illegal
               bool camp = true, // black is default
               int number = 1, // 0 is an error number, only 1-5 is legal
               bool alive = true);
};

#endif // RED_CANNON_H
