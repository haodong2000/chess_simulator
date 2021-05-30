#ifndef BLACK_GENERAL_H
#define BLACK_GENERAL_H

/* * * * * * * * * * * * * * * * * * * * *
*   File:     black_general.h
*   Author:   Haodong LI
*   Usage:    UsageOfFile
*   Time:     2021-05-30
* * * * * * * * * * * * * * * * * * * * * */

#include "../General.h"

class black_General: public General
{
public:
    black_General(int x = 0, int y = 0,
                  QString name = "General", // empty name is illegal
                  bool camp = false, // black is default
                  int number = 1, // 0 is an error number, only 1-5 is legal
                  bool alive = true);
};

#endif // BLACK_GENERAL_H
