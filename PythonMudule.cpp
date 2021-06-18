#include "PythonMudule.h"

namespace GlobalPython {
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

    const int randomRange = 250;
}

PythonMudule::PythonMudule(QString N):name(N),step(0, 0, false, 0, 0),step_str(""),isValid(false),count(1),received(true)
{
    qDebug() << this->name << "hello world";

    __visionBoard = new int*[10];
    for(int i = 0; i < 10; i++) {
        __visionBoard[i] = new int[10];
    }
}

void PythonMudule::run() {
//    while(true) {
//        std::cout << "test" << std::endl;
//        __delayMsec(1000);
//    }
    client->connectToHost(PARAM::HOST, PARAM::PORT);
    if(client->waitForConnected(10000)) {
        qDebug() << this->name << " Connected!";
    }
    else {
        qDebug() << this->name << " Connection Failed!!!";
    }
    connect(client, SIGNAL(readyRead()), this, SLOT(client_read_data()));
    connect(client, SIGNAL(disconnected()), this, SLOT(client_disconnect()));
    QString data = "connection test, hello pycharm!";
    if(client->write(data.toLatin1(), data.length()) == -1) {
        qDebug() << "PythonMudule.cpp line:15 PythonMudule() write failed!";
    }
    while(true) {
        __delayMsec(5000);
        if(received) {
            QString request = "Chess Step Request  ->  " + QString::number(count);
            if(client->write(request.toLatin1(), request.length()) == -1) {
                qDebug() << "PythonMudule.cpp line:26 run() write failed!";
            }
            std::cout << request.toStdString() << std::endl;
            received = false;
        }
        if(isValid) vision_step();
    }
}

void PythonMudule::vision_step() {
    // TODO
    // return the chessStep if chess moved
}

void PythonMudule::__QString2Board(QString origin_message) {
    int size = origin_message.size();
    int board_size = QString("").size();
    int chess_size = QString("b_gen_04, ").size();
    int count_chess = (size - board_size)/chess_size;
    QVector<QString> vision_chess;
    vision_chess.clear();
    for(int index = 0; index < count_chess; index++) {
        QString each_chess = origin_message.section(",", index, index).trimmed();
        vision_chess.append(each_chess);
        // std::cout << each_chess.toStdString() << std::endl;
    }
    int count = vision_chess.size();
    // std::cout << "chesses from vision, count = " << count << std::endl;
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 10; j++) {
            __visionBoard[i][j] = 0;
        }
    }
    for (int index = 0; index < count; index++) {
        QString chess_str = vision_chess.at(index).left(6);
        int PosX = vision_chess.at(index).mid(6, 1).toInt();
        int PosY = vision_chess.at(index).right(1).toInt();
        __visionBoard[PosX][PosY] = __QStr2intName(chess_str);
        // std::cout << chess_str.toStdString() << " " << PosX << " " << PosY << std::endl;
    }
    __printVisionBoard();
}

void PythonMudule::__printVisionBoard() {
    std::cout << "PythonMudule::__printVisionBoard() called" << std::endl;
    for(int i = 0; i < 9; i++) {
        std::cout << "[";
        for(int j = 0; j < 10; j++) {
            std::cout << " ";
            // QByteArray QStr2Char(GlobalPython::CHESS_TABLE.at(__board[i][j] - 1).toStdString().data());
            std::cout << GlobalPython::CHESS_TABLE.at(__visionBoard[i][j]).toStdString();
            if(j != 4) std::cout << " ";
            else std::cout << " |";
        }
        std::cout << "]\t" << std::endl;
    }
}

int PythonMudule::__QStr2intName(QString name) {
    // GlobalPython::Chess_Qstr2Int_simple.find(name);
    std::unordered_map<QString, int>::iterator it;
    for(it = GlobalPython::Chess_Qstr2Int_simple.begin();
        it != GlobalPython::Chess_Qstr2Int_simple.end(); it++) {
        int tempInt = it->second;
        QString tempStr = it->first;
        if(name.compare(tempStr) == 0) break;
    }
    if(it == GlobalPython::Chess_Qstr2Int_simple.end()) {
        qDebug() << "PythonMudule.cpp __QStr2intName(QString name) line: 272 -> error: name(QString) invalid!";
        return -1;
    }
    return GlobalPython::Chess_Qstr2Int_simple[name];
}

void PythonMudule::__delayMsec(int Msec) {
    QTime dieTime = QTime::currentTime().addMSecs(Msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void PythonMudule::client_read_data() {
    char msg[1024] = {0};
    client->read(msg, 1024);
    QString msg_qstr = "";
    if(strlen(msg) > 0) {
        msg_qstr = msg;
        count++;
        qDebug() << count << " communications";
        qDebug() << "client reveive: " << msg_qstr;
        if(count > 1) __QString2Board(msg_qstr);
        received = true;
    }
    else {
        qDebug() << "PythonMudule.cpp line:58 client_read_data() receive message from server error!";
    }
    // TODO:
    // add chessStep generator, if the info is valid
    step_msg_check(msg_qstr);
}

void PythonMudule::client_disconnect() {
    qDebug() << this->name << " Connection Closed!";
}

void PythonMudule::step_msg_check(QString recv) {
    // TODO
    // if valid, refresh step_str
}

void PythonMudule::setReceived(bool recv) {
    received = recv;
}
