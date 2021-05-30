#ifndef RED_ADVISOR_H
#define RED_ADVISOR_H

/*****************************************************************
*   File:     red_advisor.h
*   Author:   Haodong LI
*   Usage:    TheUsageOfFile
*   Time:     2021-05-30 -> 20:52:37
*****************************************************************/

#include "Advisor.h"

class red_advisor: public Advisor
{
public:
    red_advisor(int x = 0, int y = 0,
                QString name = "Advisor", // empty name is illegal
                bool camp = true, // black is default
                int number = 1, // 0 is an error number, only 1-5 is legal
                bool alive = true);
};

#endif // RED_ADVISOR_H
