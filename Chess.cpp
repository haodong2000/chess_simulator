#include "Chess.h"

Chess::Chess(int x, int y, QString name, bool camp, int number, bool isAlive):
    SGeoPoint(x, y), _name(name), _redOrBlack(camp), _number(number), _isAlive(isAlive)
{
    StepList.clear(); // make it empty
    StepKillList.clear();
    _spaceValue = 0;
}

bool Chess::isAlive() {
    return _isAlive;
}

void Chess::setAlive(bool isAliveNow) {
    _isAlive = isAliveNow;
}

bool Chess::canKill() {
    return _canKill;
}

bool Chess::canMove() {
    return _canMove;
}

bool Chess::chessCamp() {
    // false is black
    // true is red
    return _redOrBlack;
}

QString Chess::chessName() {
    return _name;
}

int Chess::chessNumber() {
    return _number;
}

void Chess::setSpaceValue(double value) {
    _spaceValue = value;
}

double Chess::getSpaceValue() {
    return _spaceValue;
}

double Chess::space_value() {

}
