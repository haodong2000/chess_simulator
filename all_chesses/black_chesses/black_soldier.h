#ifndef BLACK_SOLDIER_H
#define BLACK_SOLDIER_H

/* * * * * * * * * * * * * * * * * * * * *
*   File:     black_soldier.h
*   Author:   Haodong LI
*   Usage:    TheUsageOfFile
*   Time:     2021-05-30
* * * * * * * * * * * * * * * * * * * * * */

#include "Soldier.h"

class black_soldier: public Soldier
{
public:
    black_soldier(int x = 0, int y = 0,
                  QString name = "BSoldier", // empty name is illegal
                  bool camp = false, // black is default
                  int number = 1, // 0 is an error number, only 1-5 is legal
                  bool alive = true);
};

#endif // BLACK_SOLDIER_H
