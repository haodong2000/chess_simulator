#include "Advisor.h"

Advisor::Advisor(int x, int y, QString name, bool camp, int number, bool isAlive):
    Chess(x, y, name, camp, number, isAlive)
{

}

double Advisor::space_value() {
    return 0;
}
