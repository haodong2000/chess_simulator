#include "Chess.h"

Chess::Chess(int x, int y, QString name, bool camp, int number, bool isAlive):
    SGeoPoint(x, y), _name(name), _redOrBlack(camp), _number(number), _isAlive(isAlive)
{
    // StepList.clear(); // make it empty
    // StepKillList.clear();
    chessStepList.clear(); // make it empty
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

void Chess::printStepList() {
    const int countStep = chessStepList.size();
    if(countStep == 0) {
        qDebug() << "Chess.cpp printStepList() line:50 error:chessStepList is EMPTY!!!";
        return;
    }
    // print every element of the list
    for(int i = 0; i < countStep; i++) {
        std::cout << "=================== <" << i << "> ===================" << std::endl;
        int Num = chessStepList.at(i)._chessNum;
        int Number = chessStepList.at(i)._chessNumber;
        int PosX = chessStepList.at(i)._deltaX;
        int PosY = chessStepList.at(i)._deltaY;
        bool kill = chessStepList.at(i)._isKill;
        int killNum = chessStepList.at(i)._chessKilledNum;
        int killNumber = chessStepList.at(i)._chessKilledNumber;
        std::cout << "Num = \t" << Num << std::endl;
        std::cout << "Number = \t" << Number << std::endl;
        std::cout << "PosX = \t" << PosX << std::endl;
        std::cout << "PosY = \t" << PosY << std::endl;
        std::cout << "kill = \t" << (kill ? "True" : "False") << std::endl;
        std::cout << "killNum = \t" << killNum << std::endl;
        std::cout << "killNumber = \t" << killNumber << std::endl;
    }
}
