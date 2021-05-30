#ifndef BLACK_ADVISOR_H
#define BLACK_ADVISOR_H

/* * * * * * * * * * * * * * * * * * * * *
*   File:     black_advisor.h
*   Author:   Haodong LI
*   Usage:    TheUsageOfFile
*   Time:     2021-05-30
* * * * * * * * * * * * * * * * * * * * * */

#include "Advisor.h"

class black_advisor: public Advisor
{
public:
    black_advisor(int x = 0, int y = 0,
                  QString name = "Advisor", // empty name is illegal
                  bool camp = false, // black is default
                  int number = 1, // 0 is an error number, only 1-5 is legal
                  bool alive = true);
};

#endif // BLACK_ADVISOR_H
