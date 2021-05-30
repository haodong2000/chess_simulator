#include "Chess.h"

Chess::Chess(int x, int y, QString name, bool camp, int number, bool isAlive):
    SGeoPoint(x, y), _name(name), _redOrBlack(camp), _number(number), _isAlive(isAlive)
{

}

bool Chess::isAlive() {
    return _isAlive;
}
