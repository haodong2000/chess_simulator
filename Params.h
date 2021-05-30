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
