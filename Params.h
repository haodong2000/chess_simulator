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

//class Params : public QApplication {
//public:
//    Params(){}
//};

namespace PARAM {

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
        const double chessSize  =  globalEnvironment::cubeSizeWidth * 0.45;
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
