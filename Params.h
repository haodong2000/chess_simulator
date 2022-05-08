#ifndef PARAMS_H
#define PARAMS_H

/* * * * * * * * * * * * * * * * * * * * *
*   File:     Params.h
*   Author:   Haodong LI
*   Usage:    store the params of the project
*   Time:     2021/05-29
* * * * * * * * * * * * * * * * * * * * * */

#include <QDesktopWidget>
#include <QApplication>
#include <unordered_map>
#include <QString>
#include <math.h>

//class Params : public QApplication {
//public:
//    Params(){}
//};

namespace PARAM {

    const int NINE_NINE_NINE = 999;

    const QString HOST = "127.0.0.1";
    const int PORT = 6666;

//    const QString RL_HOST = "10.162.26.114";
    const QString RL_HOST = "127.0.0.1";
    const int RL_PORT = 9999;

    const QString M1_HOST = "192.168.1.49";
    const int M1_PORT = 8082;
    // const QString M1_HOST = HOST;
    // const int M1_PORT = PORT;

    const int START_DEPTH = 3;
//    const int BASIC_DEPTH = 3;
//    const int BEST_EXPONENT = BASIC_DEPTH * 2;
//    const int MAX_SEARCH_NODES = pow(44, BEST_EXPONENT);
    const int MAX_LEVEL = 10;

    const int WHOLE_GAME = 666;

    const int ROUND_NUM_SIMPLE = 30;
    const int ROUND_NUM_MIDDLE = 40;
    const int ROUND_NUM_HARD_1 = 60;
    const int ROUND_NUM_HARD_2 = 30;

    const int ROUND_RANDOM = 10;

    namespace EndGame {
        const QVector<QPair<QString, QPair<int, int>>> MeiHuaPu {
            {"b_gen_", qMakePair<int, int>(0, 4)},
            {"b_ele_", qMakePair<int, int>(0, 2)},
            {"b_adv_", qMakePair<int, int>(0, 3)},
            {"b_adv_", qMakePair<int, int>(0, 5)},
            {"b_ele_", qMakePair<int, int>(0, 6)},

            {"b_hor_", qMakePair<int, int>(2, 2)},
            {"b_can_", qMakePair<int, int>(2, 4)},
            {"b_can_", qMakePair<int, int>(2, 7)},
            {"b_cha_", qMakePair<int, int>(2, 8)},

            {"b_sol_", qMakePair<int, int>(3, 0)},
            {"b_sol_", qMakePair<int, int>(3, 2)},
            {"b_hor_", qMakePair<int, int>(3, 4)},
            {"r_cha_", qMakePair<int, int>(3, 6)},
            {"b_sol_", qMakePair<int, int>(3, 8)},

            {"b_sol_", qMakePair<int, int>(5, 4)},

            {"r_sol_", qMakePair<int, int>(6, 0)},
            {"r_sol_", qMakePair<int, int>(6, 2)},
            {"r_sol_", qMakePair<int, int>(6, 4)},
            {"r_sol_", qMakePair<int, int>(6, 6)},
            {"r_sol_", qMakePair<int, int>(6, 8)},

            {"r_hor_", qMakePair<int, int>(7, 2)},
            {"r_can_", qMakePair<int, int>(7, 4)},
            {"r_can_", qMakePair<int, int>(7, 6)},
            {"r_hor_", qMakePair<int, int>(7, 8)},

            {"r_adv_", qMakePair<int, int>(8, 4)},
            {"b_cha_", qMakePair<int, int>(8, 5)},

            {"r_ele_", qMakePair<int, int>(9, 2)},
            {"r_adv_", qMakePair<int, int>(9, 3)},
            {"r_gen_", qMakePair<int, int>(9, 4)},
            {"r_ele_", qMakePair<int, int>(9, 6)},
            {"r_cha_", qMakePair<int, int>(9, 8)}
        };
        const QVector<QPair<QString, QPair<int, int>>> JuZhongMi {
            {"b_gen_", qMakePair<int, int>(0, 4)},
            {"b_ele_", qMakePair<int, int>(0, 2)},
            {"b_adv_", qMakePair<int, int>(0, 3)},
            {"b_adv_", qMakePair<int, int>(0, 5)},
            {"b_ele_", qMakePair<int, int>(0, 6)},

            {"b_cha_", qMakePair<int, int>(1, 3)},

            {"b_hor_", qMakePair<int, int>(2, 2)},
            {"b_can_", qMakePair<int, int>(2, 4)},
            {"b_can_", qMakePair<int, int>(2, 7)},

            {"b_sol_", qMakePair<int, int>(3, 0)},
            {"r_cha_", qMakePair<int, int>(3, 2)},
            {"b_sol_", qMakePair<int, int>(3, 4)},
            {"b_sol_", qMakePair<int, int>(3, 6)},

            {"r_sol_", qMakePair<int, int>(4, 2)},
            {"b_hor_", qMakePair<int, int>(4, 7)},
            {"b_sol_", qMakePair<int, int>(4, 8)},

            {"r_sol_", qMakePair<int, int>(6, 0)},
            {"r_sol_", qMakePair<int, int>(6, 4)},
            {"r_sol_", qMakePair<int, int>(6, 6)},
            {"r_sol_", qMakePair<int, int>(6, 8)},

            {"r_hor_", qMakePair<int, int>(7, 2)},
            {"r_can_", qMakePair<int, int>(7, 4)},
            {"r_can_", qMakePair<int, int>(7, 5)},
            {"r_hor_", qMakePair<int, int>(7, 8)},

            {"r_adv_", qMakePair<int, int>(8, 4)},
            {"b_cha_", qMakePair<int, int>(8, 5)},

            {"r_ele_", qMakePair<int, int>(9, 2)},
            {"r_gen_", qMakePair<int, int>(9, 4)},
            {"r_adv_", qMakePair<int, int>(9, 5)},
            {"r_ele_", qMakePair<int, int>(9, 6)},
            {"r_cha_", qMakePair<int, int>(9, 8)},
        };
        const QVector<QPair<QString, QPair<int, int>>> MengRuShenJi {
            {"b_ele_", qMakePair<int, int>(0, 2)},
            {"b_adv_", qMakePair<int, int>(0, 5)},

            {"b_adv_", qMakePair<int, int>(2, 3)},
            {"b_gen_", qMakePair<int, int>(2, 5)},

            {"r_cha_", qMakePair<int, int>(3, 1)},
            {"r_hor_", qMakePair<int, int>(3, 2)},
            {"r_hor_", qMakePair<int, int>(3, 6)},

            {"r_can_", qMakePair<int, int>(4, 4)},
            {"b_ele_", qMakePair<int, int>(4, 6)},

            {"r_cha_", qMakePair<int, int>(5, 1)},

            {"r_can_", qMakePair<int, int>(7, 1)},
            {"b_hor_", qMakePair<int, int>(7, 6)},

            {"b_cha_", qMakePair<int, int>(8, 3)},
            {"r_adv_", qMakePair<int, int>(8, 4)},
            {"b_cha_", qMakePair<int, int>(8, 5)},

            {"r_gen_", qMakePair<int, int>(9, 4)},
            {"b_can_", qMakePair<int, int>(9, 8)},
        };
        const QVector<QPair<QString, QPair<int, int>>> HuYaJi {
            {"b_gen_", qMakePair<int, int>(0, 3)},
            {"r_sol_", qMakePair<int, int>(0, 7)},

            {"b_cha_", qMakePair<int, int>(1, 3)},
            {"r_sol_", qMakePair<int, int>(1, 4)},

            {"r_can_", qMakePair<int, int>(2, 1)},
            {"r_sol_", qMakePair<int, int>(2, 2)},
            {"b_cha_", qMakePair<int, int>(2, 3)},
            {"r_sol_", qMakePair<int, int>(2, 6)},
            {"r_sol_", qMakePair<int, int>(2, 7)},

            {"r_can_", qMakePair<int, int>(3, 1)},

            {"b_sol_", qMakePair<int, int>(7, 4)},

            {"b_sol_", qMakePair<int, int>(8, 3)},
            {"b_sol_", qMakePair<int, int>(8, 4)},
            {"b_sol_", qMakePair<int, int>(8, 7)},

            {"b_sol_", qMakePair<int, int>(9, 0)},
            {"r_cha_", qMakePair<int, int>(9, 1)},
            {"r_gen_", qMakePair<int, int>(9, 5)},
            {"r_ele_", qMakePair<int, int>(9, 6)},
        };
        const QVector<QPair<QString, QPair<int, int>>> TaoLueYuanJi {
            {"b_gen_", qMakePair<int, int>(0, 3)},
            {"b_adv_", qMakePair<int, int>(0, 5)},
            {"b_ele_", qMakePair<int, int>(0, 6)},

            {"b_adv_", qMakePair<int, int>(1, 4)},
            {"r_sol_", qMakePair<int, int>(1, 5)},

            {"b_ele_", qMakePair<int, int>(2, 4)},

            {"r_can_", qMakePair<int, int>(3, 1)},
            {"r_sol_", qMakePair<int, int>(3, 3)},

            {"b_hor_", qMakePair<int, int>(6, 0)},

            {"r_ele_", qMakePair<int, int>(7, 4)},
            {"b_cha_", qMakePair<int, int>(7, 5)},

            {"r_can_", qMakePair<int, int>(8, 2)},
            {"b_sol_", qMakePair<int, int>(8, 4)},
            {"b_sol_", qMakePair<int, int>(8, 5)},

            {"r_cha_", qMakePair<int, int>(9, 1)},
            {"r_gen_", qMakePair<int, int>(9, 3)},
        };
        const QVector<QPair<QString, QPair<int, int>>> YuanShenHaiKuo {
            {"b_gen_", qMakePair<int, int>(0, 3)},
            {"b_can_", qMakePair<int, int>(0, 5)},

            {"r_sol_", qMakePair<int, int>(1, 4)},
            {"r_sol_", qMakePair<int, int>(1, 5)},

            {"b_cha_", qMakePair<int, int>(2, 3)},
            {"b_ele_", qMakePair<int, int>(2, 8)},

            {"b_ele_", qMakePair<int, int>(4, 2)},
            {"b_hor_", qMakePair<int, int>(4, 6)},

            {"r_can_", qMakePair<int, int>(5, 0)},
            {"r_sol_", qMakePair<int, int>(5, 2)},
            {"b_cha_", qMakePair<int, int>(5, 3)},
            {"r_sol_", qMakePair<int, int>(5, 6)},

            {"r_cha_", qMakePair<int, int>(6, 1)},

            {"b_sol_", qMakePair<int, int>(7, 5)},

            {"b_sol_", qMakePair<int, int>(8, 4)},

            {"r_cha_", qMakePair<int, int>(9, 0)},
            {"r_ele_", qMakePair<int, int>(9, 2)},
            {"r_gen_", qMakePair<int, int>(9, 5)},
            {"r_ele_", qMakePair<int, int>(9, 6)},
        };
        const QVector<QPair<QString, QPair<int, int>>> MiJinBaoLue {
            {"r_can_", qMakePair<int, int>(0, 2)},
            {"b_gen_", qMakePair<int, int>(0, 4)},
            {"b_can_", qMakePair<int, int>(0, 6)},

            {"r_cha_", qMakePair<int, int>(1, 2)},
            {"b_cha_", qMakePair<int, int>(1, 6)},

            {"r_hor_", qMakePair<int, int>(4, 4)},

            {"r_cha_", qMakePair<int, int>(5, 3)},
            {"b_sol_", qMakePair<int, int>(5, 5)},

            {"b_cha_", qMakePair<int, int>(6, 4)},

            {"r_can_", qMakePair<int, int>(7, 3)},
            {"r_gen_", qMakePair<int, int>(7, 5)},

            {"b_hor_", qMakePair<int, int>(9, 3)},
            {"b_hor_", qMakePair<int, int>(9, 5)},
        };
        const QVector<QVector<QPair<QString, QPair<int, int>>>> ChessStrategies = {
            MeiHuaPu, // index = 0
            JuZhongMi,
            MengRuShenJi,
            HuYaJi,
            TaoLueYuanJi,
            YuanShenHaiKuo,
            MiJinBaoLue
        };
        const int MaxStrategyModeNum = ChessStrategies.size() - 1;
    }

    namespace globalEnvironment {

        // get available desktop size
//        const QDesktopWidget* desktopWidget = QApplication::desktop();
//        const QRect clientRect = desktopWidget->availableGeometry();
//        const double screenAvaliableWidth = clientRect.width();
//        const double screenAvaliableHeight = clientRect.height();

//        const double screenWidth = 100;
//        const double screenHeight = 100;

        // important parameters, never change
        // const double devicePixelRatio  = 100;
        const double screenAvaliableWidth = 1920;
        const double screenAvaliableHeight = 1080;
        const double cubeSizeWidth = (screenAvaliableHeight * 2.0)/15.0;
        const double cubeSizeHeight = screenAvaliableHeight/10.0;

        // TODO
        const int initChessCount = 32;
        const int goingChessCount = 24;
        const int endChessCount = 16;
        const int finalChessCount = 8;

        // board scale
        const int maxAxisOfX = 9;
        const int maxAxisOfY = 8;
        const int middleBlack = 4;
        const int middleRed = 5;

        // chess move number
        const double maxAdvisorMove = 4;

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
    }

    namespace chessNameMap {
        const std::unordered_map<QString, int> Chess_Qstr2Int_simple {
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

        const std::unordered_map<int, QString> Chess_Int2Qstr_simple {
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
    }

    namespace chessInitPos {
        // all the coordinate info of all chesses
        const double chessSize  =  globalEnvironment::cubeSizeWidth * 0.625;
        namespace black {
            namespace General {
                const double x = globalEnvironment::cubeSizeWidth/2.0 - chessSize/2.0;
                const double y = globalEnvironment::cubeSizeHeight * 4.5 - chessSize/2.0;
            }
            namespace Advisor_1 {
                const double x = globalEnvironment::cubeSizeWidth/2.0 - chessSize/2.0;
                const double y = globalEnvironment::cubeSizeHeight * 3.5 - chessSize/2.0;
            }
            namespace Advisor_2 {
                const double x = globalEnvironment::cubeSizeWidth/2.0 - chessSize/2.0;
                const double y = globalEnvironment::cubeSizeHeight * 5.5 - chessSize/2.0;
            }
            namespace Elephant_1 {
                const double x = globalEnvironment::cubeSizeWidth/2.0 - chessSize/2.0;
                const double y = globalEnvironment::cubeSizeHeight * 2.5 - chessSize/2.0;
            }
            namespace Elephant_2 {
                const double x = globalEnvironment::cubeSizeWidth/2.0 - chessSize/2.0;
                const double y = globalEnvironment::cubeSizeHeight * 6.5 - chessSize/2.0;
            }
            namespace Horse_1 {
                const double x = globalEnvironment::cubeSizeWidth/2.0 - chessSize/2.0;
                const double y = globalEnvironment::cubeSizeHeight * 1.5 - chessSize/2.0;
            }
            namespace Horse_2 {
                const double x = globalEnvironment::cubeSizeWidth/2.0 - chessSize/2.0;
                const double y = globalEnvironment::cubeSizeHeight * 7.5 - chessSize/2.0;
            }
            namespace Chariot_1 {
                const double x = globalEnvironment::cubeSizeWidth/2.0 - chessSize/2.0;
                const double y = globalEnvironment::cubeSizeHeight/2.0 - chessSize/2.0;
            }
            namespace Chariot_2 {
                const double x = globalEnvironment::cubeSizeWidth/2.0 - chessSize/2.0;
                const double y = globalEnvironment::cubeSizeHeight * 8.5 - chessSize/2.0;
            }
            namespace Cannon_1 {
                const double x = globalEnvironment::cubeSizeWidth * 2.5 - chessSize/2.0;
                const double y = globalEnvironment::cubeSizeHeight * 1.5 - chessSize/2.0;
            }
            namespace Cannon_2 {
                const double x = globalEnvironment::cubeSizeWidth * 2.5 - chessSize/2.0;
                const double y = globalEnvironment::cubeSizeHeight * 7.5 - chessSize/2.0;
            }
            namespace Soldier_1 {
                const double x = globalEnvironment::cubeSizeWidth * 3.5 - chessSize/2.0;
                const double y = globalEnvironment::cubeSizeHeight/2.0 - chessSize/2.0;
            }
            namespace Soldier_2 {
                const double x = globalEnvironment::cubeSizeWidth * 3.5 - chessSize/2.0;
                const double y = globalEnvironment::cubeSizeHeight * 2.5 - chessSize/2.0;
            }
            namespace Soldier_3 {
                const double x = globalEnvironment::cubeSizeWidth * 3.5 - chessSize/2.0;
                const double y = globalEnvironment::cubeSizeHeight * 4.5 - chessSize/2.0;
            }
            namespace Soldier_4 {
                const double x = globalEnvironment::cubeSizeWidth * 3.5 - chessSize/2.0;
                const double y = globalEnvironment::cubeSizeHeight * 6.5 - chessSize/2.0;
            }
            namespace Soldier_5 {
                const double x = globalEnvironment::cubeSizeWidth * 3.5 - chessSize/2.0;
                const double y = globalEnvironment::cubeSizeHeight * 8.5 - chessSize/2.0;
            }
        }
        namespace red {
            namespace General {
                const double x = globalEnvironment::cubeSizeWidth * 9.5 - chessSize/2.0;
                const double y = globalEnvironment::cubeSizeWidth * 9.5 - chessSize/2.0;
            }
            namespace Advisor_1 {
                const double x = globalEnvironment::cubeSizeWidth * 9.5 - chessSize/2.0;
                const double y = globalEnvironment::cubeSizeHeight * 3.5 - chessSize/2.0;
            }
            namespace Advisor_2 {
                const double x = globalEnvironment::cubeSizeWidth * 9.5 - chessSize/2.0;
                const double y = globalEnvironment::cubeSizeHeight * 5.5 - chessSize/2.0;
            }
            namespace Elephant_1 {
                const double x = globalEnvironment::cubeSizeWidth * 9.5 - chessSize/2.0;
                const double y = globalEnvironment::cubeSizeHeight * 2.5 - chessSize/2.0;
            }
            namespace Elephant_2 {
                const double x = globalEnvironment::cubeSizeWidth * 9.5 - chessSize/2.0;
                const double y = globalEnvironment::cubeSizeHeight * 6.5 - chessSize/2.0;
            }
            namespace Horse_1 {
                const double x = globalEnvironment::cubeSizeWidth * 9.5 - chessSize/2.0;
                const double y = globalEnvironment::cubeSizeHeight * 1.5 - chessSize/2.0;
            }
            namespace Horse_2 {
                const double x = globalEnvironment::cubeSizeWidth * 9.5 - chessSize/2.0;
                const double y = globalEnvironment::cubeSizeHeight * 7.5 - chessSize/2.0;
            }
            namespace Chariot_1 {
                const double x = globalEnvironment::cubeSizeWidth * 9.5 - chessSize/2.0;
                const double y = globalEnvironment::cubeSizeHeight/2.0 - chessSize/2.0;
            }
            namespace Chariot_2 {
                const double x = globalEnvironment::cubeSizeWidth * 9.5 - chessSize/2.0;
                const double y = globalEnvironment::cubeSizeHeight * 8.5 - chessSize/2.0;
            }
            namespace Cannon_1 {
                const double x = globalEnvironment::cubeSizeWidth * 7.5 - chessSize/2.0;
                const double y = globalEnvironment::cubeSizeHeight * 1.5 - chessSize/2.0;
            }
            namespace Cannon_2 {
                const double x = globalEnvironment::cubeSizeWidth * 7.5 - chessSize/2.0;
                const double y = globalEnvironment::cubeSizeHeight * 7.5 - chessSize/2.0;
            }
            namespace Soldier_1 {
                const double x = globalEnvironment::cubeSizeWidth * 6.5 - chessSize/2.0;
                const double y = globalEnvironment::cubeSizeHeight/2.0 - chessSize/2.0;
            }
            namespace Soldier_2 {
                const double x = globalEnvironment::cubeSizeWidth * 6.5 - chessSize/2.0;
                const double y = globalEnvironment::cubeSizeHeight * 2.5 - chessSize/2.0;
            }
            namespace Soldier_3 {
                const double x = globalEnvironment::cubeSizeWidth * 6.5 - chessSize/2.0;
                const double y = globalEnvironment::cubeSizeHeight * 4.5 - chessSize/2.0;
            }
            namespace Soldier_4 {
                const double x = globalEnvironment::cubeSizeWidth * 6.5 - chessSize/2.0;
                const double y = globalEnvironment::cubeSizeHeight * 6.5 - chessSize/2.0;
            }
            namespace Soldier_5 {
                const double x = globalEnvironment::cubeSizeWidth * 6.5 - chessSize/2.0;
                const double y = globalEnvironment::cubeSizeHeight * 8.5 - chessSize/2.0;
            }
        }
    }

}


#endif // PARAMS_H
