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
    virtual ~SGeoPoint() {};
    virtual void setPosX(int PosX);
    virtual void setPosY(int PosY);
    virtual int getPosX();
    virtual int getPosY();

private:
    int _x;
    int _y;
};

#endif // SGEOPOINT_H
