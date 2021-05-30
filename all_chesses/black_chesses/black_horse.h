#ifndef BLACK_HORSE_H
#define BLACK_HORSE_H

/* * * * * * * * * * * * * * * * * * * * *
*   File:     black_horse.h
*   Author:   Haodong LI
*   Usage:    TheUsageOfFile
*   Time:     2021-05-30
* * * * * * * * * * * * * * * * * * * * * */

#include "Horse.h"

class black_horse: public Horse
{
public:
    black_horse(int x = 0, int y = 0,
                const QString name = "BHorse", // empty name is illegal
                const bool camp = false, // black is default
                const int number = 1, // 0 is an error number, only 1-5 is legal
                bool alive = true);
};

#endif // BLACK_HORSE_H
