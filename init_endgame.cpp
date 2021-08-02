#include "init_endgame.h"

namespace GlobalInit {
    enum CHESS_TABLE {
        BLACK_GENERAL = 1,
        BLACK_ADVISOR,
        BLACK_ELEPHANT,
        BLACK_HORSE,
        BLACK_CHARIOT,
        BLACK_CANNON,
        BLACK_SOLDIER,
        RED_GENERAL,
        RED_ADVISOR,
        RED_ELEPHANT,
        RED_HORSE,
        RED_CHARIOT,
        RED_CANNON,
        RED_SOLDIER,
    };
    QVector<QString> CHESS_TABLE = {
        "一", // 0
        "将",
        "士",
        "象",
        "馬",
        "車",
        "砲",
        "卒",
        "帅",
        "仕",
        "相",
        "傌",
        "俥",
        "炮",
        "兵"
    };
}

init_endgame::init_endgame()
{
    isEndGameMode = true;
    isVisionBoardDone = false;
    initChessBoard = new int*[10];
    for(int i = 0; i < 10; i++) {
        initChessBoard[i] = new int[10];
    }
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 10; j++) {
            initChessBoard[i][j] = 0;
        }
    }
}

void init_endgame::printVisionBoard() {
    std::cout << "init_endgame::printVisionBoard() called -*-*-*-*-*-" << std::endl;
    for(int i = 0; i < 9; i++) {
        std::cout << "[";
        for(int j = 0; j < 10; j++) {
            std::cout << " ";
            std::cout << GlobalInit::CHESS_TABLE.at(initChessBoard[i][j]).toStdString();
            if(j != 4) std::cout << " ";
            else std::cout << " |";
        }
        std::cout << "]\t" << std::endl;
    }
}

void init_endgame::setInitVisionBoard() {
    // 2021-08-01
    QmlConnectIn::Instance()->setEndGameMode(isEndGameMode);
    QmlConnectIn::Instance()->setWhetherVisionDone(isVisionBoardDone);
    std::cout << "start vision detecting chess board..." << std::endl;
    // wait until isVisionBoardAtLeastOnce = true
    while (vision->python_vision->isVisionBoardAtLeastOnce == false);
    GlobalEnvirIn::Instance()->__delayMsec(5);
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 10; j++) {
            initChessBoard[i][j] = vision->python_vision->__visionBoard[i][j];
        }
    }
    printVisionBoard();
    // change the properties of chesses

    // refresh the chess board (qml canvas)

    isVisionBoardDone = true;
    std::cout << "vision generate init chess board done!" << std::endl;
    QmlConnectIn::Instance()->setWhetherVisionDone(isVisionBoardDone);
}
