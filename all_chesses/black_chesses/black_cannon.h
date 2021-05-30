#ifndef BLACK_CANNON_H
#define BLACK_CANNON_H

/* * * * * * * * * * * * * * * * * * * * *
*   File:     black_cannon.h
*   Author:   Haodong LI
*   Usage:    TheUsageOfFile
*   Time:     2021-05-30
* * * * * * * * * * * * * * * * * * * * * */

#include "Cannon.h"

class black_cannon: public Cannon
{
public:
    black_cannon(int x = 0, int y = 0,
                 QString name = "BCannon", // empty name is illegal
                 bool camp = false, // black is default
                 int number = 1, // 0 is an error number, only 1-5 is legal
                 bool alive = true);
};

#endif // BLACK_CANNON_H
