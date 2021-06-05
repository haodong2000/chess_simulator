#include "Soldier.h"

Soldier::Soldier(int x, int y, QString name, bool camp, int number, bool isAlive):
    Chess(x, y, name, camp, number, isAlive)
{

}

double Soldier::space_value() {
    return 0;
}

bool Soldier::canChessMove() {
    return true;
}

void Soldier::generateMove() {

}
