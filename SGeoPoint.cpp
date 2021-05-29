#include "SGeoPoint.h"

SGeoPoint::SGeoPoint(int x, int y): _x(x), _y(y)
{

}

void SGeoPoint::setPosX(int PosX){
    _x = PosX;
}

void SGeoPoint::setPosY(int PosY) {
    _y = PosY;
}

int SGeoPoint::getPosX() {
    return _x;
}

int SGeoPoint::getPosY() {
    return _y;
}
