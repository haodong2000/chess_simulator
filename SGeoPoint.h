#ifndef SGEOPOINT_H
#define SGEOPOINT_H

/* * * * * * * * * * * * * * * * * * * * *
*   File:     sgeopoint.h
*   Author:   Haodong LI
*   Usage:    the (x, y) mudule
*   Time:     2021-05-29
* * * * * * * * * * * * * * * * * * * * * */

class SGeoPoint
{
public:
    SGeoPoint(int x = 0, int y = 0);
    void setPosX(int PosX);
    void setPosY(int PosY);
    int getPosX();
    int getPosY();

private:
    int _x;
    int _y;
};

#endif // SGEOPOINT_H
