#include "Chariot.h"

Chariot::Chariot(int x, int y, QString name, bool camp, int number, bool isAlive):
    Chess(x, y, name, camp, number, isAlive)
{

}

double Chariot::space_value() {
    return 0;
}

