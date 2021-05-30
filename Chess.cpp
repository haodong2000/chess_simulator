#include "Chess.h"

Chess::Chess(int x, int y, QString name, bool camp, int number):
    SGeoPoint(x, y), _name(name), _redOrBlack(camp), _number(number)
{

}
