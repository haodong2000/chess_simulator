#ifndef COORDINATE_H
#define COORDINATE_H

/* * * * * * * * * * * * * * * * * * * * *
*   File:     coordinate.h
*   Author:   Haodong LI
*   Usage:    1. transfer the original coordinate value to simple (x, y), like (0, 0) and (2, 3)
*             2. set coordinate of all chesses
*   Time:     2021/05-29
* * * * * * * * * * * * * * * * * * * * * */

#include "SGeoPoint.h"
#include "singleton.h"

class coordinate
{
public:
    coordinate();
    virtual int transferPosX(double originPosX);
    virtual int transferPosY(double originPosY);
    virtual SGeoPoint tranPos(double originPosX, double originPosY);
    virtual double tranRealPosX(SGeoPoint* Pos);
    virtual double tranRealPosY(SGeoPoint* Pos);
    virtual double tranRealPosX(int PosX);
    virtual double tranRealPosY(int PosY);
};

typedef NormalSingleton< coordinate > coordinateIn;

#endif // COORDINATE_H
