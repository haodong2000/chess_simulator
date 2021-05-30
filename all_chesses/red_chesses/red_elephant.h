#ifndef RED_ELEPHANT_H
#define RED_ELEPHANT_H

/*****************************************************************
*   File:     red_elephant.h
*   Author:   Haodong LI
*   Usage:    TheUsageOfFile
*   Time:     2021-05-30 -> 21:01:59
*****************************************************************/

#include "Elephant.h"

class red_elephant: public Elephant
{
public:
    red_elephant(int x = 0, int y = 0,
                 const QString name = "RElephant", // empty name is illegal
                 const bool camp = true, // black is default
                 const int number = 1, // 0 is an error number, only 1-5 is legal
                 bool alive = true);
};

#endif // RED_ELEPHANT_H
