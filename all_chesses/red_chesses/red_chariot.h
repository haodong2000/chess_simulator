#ifndef RED_CHARIOT_H
#define RED_CHARIOT_H

/*****************************************************************
*   File:     red_chariot.h
*   Author:   Haodong LI
*   Usage:    TheUsageOfFile
*   Time:     2021-05-30 -> 20:53:47
*****************************************************************/

#include "Chariot.h"

class red_chariot: public Chariot
{
public:
    red_chariot(int x = 0, int y = 0,
                const QString name = "RChariot", // empty name is illegal
                const bool camp = true, // black is default
                const int number = 1, // 0 is an error number, only 1-5 is legal
                bool alive = true);
};

#endif // RED_CHARIOT_H
