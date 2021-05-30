#ifndef BLACK_CHARIOT_H
#define BLACK_CHARIOT_H

/* * * * * * * * * * * * * * * * * * * * *
*   File:     black_chariot.h
*   Author:   Haodong LI
*   Usage:    TheUsageOfFile
*   Time:     2021-05-30
* * * * * * * * * * * * * * * * * * * * * */

#include "Chariot.h"

class black_chariot: public Chariot
{
public:
    black_chariot(int x = 0, int y = 0,
                  const QString name = "BChariot", // empty name is illegal
                  const bool camp = false, // black is default
                  const int number = 1, // 0 is an error number, only 1-5 is legal
                  bool alive = true);
};

#endif // BLACK_CHARIOT_H
