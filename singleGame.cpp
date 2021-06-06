#include "singleGame.h"

singleGame::singleGame()
{
    chessStep = new Step(-1, -1, false, 0, 0, false);
    _level = 4; // initialization
}

void singleGame::setLevel(int level) {
    _level = level;
}

int singleGame::getLevel() {
    return _level;
}
