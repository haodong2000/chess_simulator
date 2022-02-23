#include "rl_thread.h"

namespace Global_RL {
    enum CHESS_ALL_TABLE { // all chesses
        BLACK_1_GENERAL = 1,

        BLACK_1_ADVISOR,
        BLACK_2_ADVISOR,

        BLACK_1_ELEPHANT,
        BLACK_2_ELEPHANT,

        BLACK_1_HORSE,
        BLACK_2_HORSE,

        BLACK_1_CHARIOT,
        BLACK_2_CHARIOT,

        BLACK_1_CANNON,
        BLACK_2_CANNON,

        BLACK_1_SOLDIER,
        BLACK_2_SOLDIER,
        BLACK_3_SOLDIER,
        BLACK_4_SOLDIER,
        BLACK_5_SOLDIER,

        RED_1_GENERAL,
        RED_1_ADVISOR,
        RED_2_ADVISOR,

        RED_1_ELEPHANT,
        RED_2_ELEPHANT,

        RED_1_HORSE,
        RED_2_HORSE,

        RED_1_CHARIOT,
        RED_2_CHARIOT,

        RED_1_CANNON,
        RED_2_CANNON,

        RED_1_SOLDIER,
        RED_2_SOLDIER,
        RED_3_SOLDIER,
        RED_4_SOLDIER,
        RED_5_SOLDIER,
    };

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

    enum WHOLE_BOARD {
        INIT_BOARD = 1,
        GOING_BOARD,
        END_BOARD,
        FINAL_BOARD
    };

    std::unordered_map<int, int> CHESS_VALUE = {
        {CHESS_TABLE::BLACK_GENERAL , 2*1000},
        {CHESS_TABLE::BLACK_ADVISOR , 2*200},
        {CHESS_TABLE::BLACK_ELEPHANT, 2*175},
        {CHESS_TABLE::BLACK_HORSE   , 2*400},
        {CHESS_TABLE::BLACK_CHARIOT , 2*600},
        {CHESS_TABLE::BLACK_CANNON  , 2*400},
        {CHESS_TABLE::BLACK_SOLDIER , 2*150},
        {CHESS_TABLE::RED_GENERAL , 2*1000},
        {CHESS_TABLE::RED_ADVISOR , 2*200},
        {CHESS_TABLE::RED_ELEPHANT, 2*175},
        {CHESS_TABLE::RED_HORSE   , 2*400},
        {CHESS_TABLE::RED_CHARIOT , 2*600},
        {CHESS_TABLE::RED_CANNON  , 2*400},
        {CHESS_TABLE::RED_SOLDIER , 2*150}
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

    std::unordered_map<QString, int> Chess_Qstr2Int {
        {"BGeneral",  1},
        {"BAdvisor",  2},
        {"BElephant", 3},
        {"BHorse",    4},
        {"BChariot",  5},
        {"BCannon",   6},
        {"BSoldier",  7},
        {"RGeneral",  1 + 7},
        {"RAdvisor",  2 + 7},
        {"RElephant", 3 + 7},
        {"RHorse",    4 + 7},
        {"RChariot",  5 + 7},
        {"RCannon",   6 + 7},
        {"RSoldier",  7 + 7},
    };

    std::unordered_map<int, QString> Chess_Int2Qstr {
        {1,  "BGeneral"},
        {2,  "BAdvisor"},
        {3,  "BElephant"},
        {4,  "BHorse"},
        {5,  "BChariot"},
        {6,  "BCannon"},
        {7,  "BSoldier"},
        {8,  "RGeneral"},
        {9,  "RAdvisor"},
        {10, "RElephant"},
        {11, "RHorse"},
        {12, "RChariot"},
        {13, "RCannon"},
        {14, "RSoldier"},
    };

    std::unordered_map<QString, int> Chess_Qstr2Int_simple {
        {"b_gen_", 1},
        {"b_adv_", 2},
        {"b_ele_", 3},
        {"b_hor_", 4},
        {"b_cha_", 5},
        {"b_can_", 6},
        {"b_sol_", 7},
        {"r_gen_", 1 + 7},
        {"r_adv_", 2 + 7},
        {"r_ele_", 3 + 7},
        {"r_hor_", 4 + 7},
        {"r_cha_", 5 + 7},
        {"r_can_", 6 + 7},
        {"r_sol_", 7 + 7},
    };

    std::unordered_map<int, QString> Chess_Int2Qstr_simple {
        {1,  "b_gen_"},
        {2,  "b_adv_"},
        {3,  "b_ele_"},
        {4,  "b_hor_"},
        {5,  "b_cha_"},
        {6,  "b_can_"},
        {7,  "b_sol_"},
        {8,  "r_gen_"},
        {9,  "r_adv_"},
        {10, "r_ele_"},
        {11, "r_hor_"},
        {12, "r_cha_"},
        {13, "r_can_"},
        {14, "r_sol_"},
    };

    const bool rl_debug = false;
}

rl_thread::rl_thread():MP_count(0), MP_received(true), RL_sent(0), last_TURN_COUNT(-1) {
    qDebug() << " hello world (RL)";
    currentChessBoard = new int*[10];
    for(int i = 0; i < 10; i++) {
        currentChessBoard[i] = new int[10];
    }
}

rl_thread::rl_thread(QString name):MP_count(0), MP_received(true), RL_sent(0), last_TURN_COUNT(-1) {
    qDebug() << name << " hello world (RL)";
    currentChessBoard = new int*[10];
    for(int i = 0; i < 10; i++) {
        currentChessBoard[i] = new int[10];
    }
}

void rl_thread::__delayMsec(int Msec) {
    QTime dieTime = QTime::currentTime().addMSecs(Msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void rl_thread::run() {
    client->connectToHost(PARAM::RL_HOST, PARAM::RL_PORT);
    if(client->waitForConnected(10000)) {
        qDebug() << this->name << " Connected! (RL)";
    }
    else {
        qDebug() << this->name << " Connection Failed!!!";
    }
    // connect(client, SIGNAL(readyRead()), this, SLOT(client_read_data()));
    connect(client, SIGNAL(disconnected()), this, SLOT(client_disconnect()));
    QString data = "connection test, hello pycharm! (RL)";
    if(client->write(data.toLatin1(), data.length()) == -1) {
        qDebug() << "rl_thread.cpp line:23 run() write failed!";
    }
    // exit
//    QString exit_data = "exit";
//    if(client->write(exit_data.toLatin1(), exit_data.length()) == -1) {
//        qDebug() << "rl_thread.cpp line:28 run() write failed!";
//    }
    while(true) {
        __delayMsec(10);
        // @TODO
        // no time delay between sending and receiving
        char msg[1024] = {0};
        client->read(msg, 1024);
        QString msg_qstr = "";
        if(strlen(msg) > 0) {
            msg_qstr = msg;
            MP_count++;
            qDebug() << MP_count << " communications";
            qDebug() << "client reveive: " << msg_qstr;
//            if(MP_count > 1) __QString2Board(msg_qstr);
            MP_received = true;
            // DEBUG, to pretend the robot finishes its turn
//            if(MP_count > 1){
//                CURRENT_TURN = true;
//            }
        }
        else {
            // qDebug() << "rl_thread.cpp line:50 run() receive message from server error!";
        }
        if(MP_received) {
            // @TODO
            // 1. generate request from current chessboard once the board has been changed (human-turn finished)
            // 2. time delay comes from the time needed for human-turn to finish
            while(!(last_TURN_COUNT != TURN_COUNT && TURN_COUNT - last_TURN_COUNT > 1)) {
                __delayMsec(10);
            }
            // TURN_COUNT = last_TURN_COUNT + 2
            RL_sent = 0;
            last_TURN_COUNT = TURN_COUNT;

            if(Global_RL::rl_debug) {
                std::cout << "CURRENT_TURN       -> " << CURRENT_TURN << std::endl;
                std::cout << "TURN_COUNT         -> " << TURN_COUNT << std::endl;
                std::cout << "last_TURN_COUNT    -> " << last_TURN_COUNT << std::endl;
                std::cout << "RL_sent            -> " << RL_sent << std::endl;
            }

//            while(CURRENT_TURN == false || TURN_COUNT < 1 || RL_sent != 0) {
//                __delayMsec(10);
//            }
            QString request = "RL Brain Request  ->  " + QString::number(MP_count) +
                    " -> CURRENT_TURN " + QString::number((CURRENT_TURN == true ? 1 : 0)) +
                    " -> TURN_COUNT " + QString::number(TURN_COUNT) +
                    " -> last_TURN_COUNT " + QString::number(last_TURN_COUNT);
            request = generateRequest();
            if(client->write(request.toLatin1(), request.length()) == -1) {
                qDebug() << "rl_thread.cpp line:55 run() write failed!";
            }
            else {
                RL_sent++;
            }
            std::cout << request.toStdString() << std::endl;
            MP_received = false;
        }
    }
}

void rl_thread::__displayCurrentChessBoard() {
    std::cout << "rl_thread::__displayCurrentChessBoard() called" << std::endl;
    for(int i = 0; i < 9; i++) {
        std::cout << "[";
        for(int j = 0; j < 10; j++) {
            std::cout << " ";
            std::cout << Global_RL::CHESS_TABLE.at(currentChessBoard[i][j]).toStdString();
            if(j != 4) std::cout << " ";
            else std::cout << " |";
        }
        std::cout << "]\t" << std::endl;
    }
}

QString rl_thread::generateRequest() {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 10; j++) {
            currentChessBoard[i][j] = Main_chessBoard[j][i];
        }
    }
    __displayCurrentChessBoard();
    return "testtesttest";
}
