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
    QVector<int> CHESS_COUNT = {
        0, // 0
        0, // "将",
        0, // "士",
        0, // "象",
        0, // "馬",
        0, // "車",
        0, // "砲",
        0, // "卒",
        0, // "帅",
        0, // "仕",
        0, // "相",
        0, // "傌",
        0, // "俥",
        0, // "炮",
        0, // "兵"
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
    std::cout << "-*-*-*-*-*- init_endgame::printVisionBoard() called -*-*-*-*-*-" << std::endl;
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

void init_endgame::allChessesKilled() {
    Ab_gen_1->setAlive(false);
    Ab_adv_1->setAlive(false);
    Ab_adv_2->setAlive(false);
    Ab_can_1->setAlive(false);
    Ab_can_2->setAlive(false);
    Ab_cha_1->setAlive(false);
    Ab_cha_2->setAlive(false);
    Ab_ele_1->setAlive(false);
    Ab_ele_2->setAlive(false);
    Ab_hor_1->setAlive(false);
    Ab_hor_2->setAlive(false);
    Ab_sol_1->setAlive(false);
    Ab_sol_2->setAlive(false);
    Ab_sol_3->setAlive(false);
    Ab_sol_4->setAlive(false);
    Ab_sol_5->setAlive(false);
    Ar_gen_1->setAlive(false);
    Ar_adv_1->setAlive(false);
    Ar_adv_2->setAlive(false);
    Ar_can_1->setAlive(false);
    Ar_can_2->setAlive(false);
    Ar_cha_1->setAlive(false);
    Ar_cha_2->setAlive(false);
    Ar_ele_1->setAlive(false);
    Ar_ele_2->setAlive(false);
    Ar_hor_1->setAlive(false);
    Ar_hor_2->setAlive(false);
    Ar_sol_1->setAlive(false);
    Ar_sol_2->setAlive(false);
    Ar_sol_3->setAlive(false);
    Ar_sol_4->setAlive(false);
    Ar_sol_5->setAlive(false);
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
    allChessesKilled();
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 10; j++) {
            if(initChessBoard[i][j] == 0) continue;
            GlobalInit::CHESS_COUNT[initChessBoard[i][j]] += 1; // count the chess number
            GlobalEnvirIn::Instance()->__QStrOrInt2Chess(initChessBoard[i][j], GlobalInit::CHESS_COUNT[initChessBoard[i][j]])->setAlive(true);
            GlobalEnvirIn::Instance()->__QStrOrInt2Chess(initChessBoard[i][j], GlobalInit::CHESS_COUNT[initChessBoard[i][j]])->setPosX(i);
            GlobalEnvirIn::Instance()->__QStrOrInt2Chess(initChessBoard[i][j], GlobalInit::CHESS_COUNT[initChessBoard[i][j]])->setPosY(j);
        }
    }
    GlobalEnvirIn::Instance()->__printBoard();
    // judge if gameIsOn
    bool gameIsOn = Ab_gen_1->isAlive() && Ar_gen_1->isAlive() && GlobalEnvirIn::Instance()->__isOnlyTwoGeneralsInRow();
    if(gameIsOn == false) qDebug() << "ERROR: init_endgame.cpp function:setInitVisionBoard() line:111 game already end!!!";
    // refresh the chess board (qml canvas)
    for(int num = 1; num <= GlobalInit::CHESS_TABLE::RED_SOLDIER; num++) {
        if(num == GlobalInit::CHESS_TABLE::BLACK_GENERAL || num == GlobalInit::CHESS_TABLE::RED_GENERAL) {
            QmlConnectIn::Instance()->moveChessOnCanvas(num, 1);
        }
        else if(num == GlobalInit::CHESS_TABLE::BLACK_SOLDIER || num == GlobalInit::CHESS_TABLE::RED_SOLDIER) {
            for(int number = 1; number <= 5; number++) {
                if(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(num, number)->isAlive() == false)
                    QmlConnectIn::Instance()->eraseChessOnCanvas(num,  number);
                else
                    QmlConnectIn::Instance()->moveChessOnCanvas(num, number);
            }
        }
        else {
            for(int number = 1; number <= 2; number++) {
                if(GlobalEnvirIn::Instance()->__QStrOrInt2Chess(num, number)->isAlive() == false)
                    QmlConnectIn::Instance()->eraseChessOnCanvas(num,  number);
                else
                    QmlConnectIn::Instance()->moveChessOnCanvas(num, number);
            }
        }
    }
    isVisionBoardDone = true;
    std::cout << "vision generate init chess board done!" << std::endl;
    QmlConnectIn::Instance()->setWhetherVisionDone(isVisionBoardDone);
}

void init_endgame::setInitStrategyBoard(int strategy_mode) {
    // 2021-08-01
    if(strategy_mode < 0 || strategy_mode > PARAM::EndGame::MaxStrategyModeNum) {
        qDebug() << "ERROR: init_endgame.cpp function:setInitStrategyBoard() line:179 strategy_mode inValid!";
        return;
    }
}
