#include "General.h"

General::General(int x, int y, QString name, bool camp, int number, bool isAlive):
    Chess(x, y, name, camp, number, isAlive)
{

}

double General::space_value() {
    return 0;
}

