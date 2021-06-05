#include "Elephant.h"

Elephant::Elephant(int x, int y, QString name, bool camp, int number, bool isAlive):
    Chess(x, y, name, camp, number, isAlive)
{

}

double Elephant::space_value() {
    return 0;
}

bool Elephant::canChessMove() {
    return true;
}

