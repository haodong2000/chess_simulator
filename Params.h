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
        const QDesktopWidget* desktopWidget = QApplication::desktop();
        const QRect clientRect = desktopWidget->availableGeometry();
        const double screenWidth = clientRect.width();
        const double screenHeight = clientRect.height();

//        const double screenWidth = 100;
//        const double screenHeight = 100;

        // important parameters, never change
        const double devicePixelRatio  = 100;
        const int screenAvaliableWidth  = (screenHeight *2.0)/15.0;
        const int screenAvaliableHeight = screenHeight/9.0;
        const double cubeSizeWidth = (screenAvaliableHeight * 2.0)/15.0;
        const double cubeSizeHeight = screenAvaliableHeight/9.0;
    }

    namespace chessPos {
        // all the coordinate info of all chesses
        const double chessSize  =  globalEnvironment::cubeSizeWidth * 0.45;
        namespace black {
            namespace General {
                double x = globalEnvironment::cubeSizeWidth/2.0 - chessSize/2.0;
                double y = globalEnvironment::cubeSizeHeight * 4.5 - chessSize/2.0;
            }
            namespace Advisor_1 {
                double x = globalEnvironment::cubeSizeWidth/2.0 - chessSize/2.0;
                double y = globalEnvironment::cubeSizeHeight * 3.5 - chessSize/2.0;
            }
            namespace Advisor_2 {
                double x = globalEnvironment::cubeSizeWidth/2.0 - chessSize/2.0;
                double y = globalEnvironment::cubeSizeHeight * 5.5 - chessSize/2.0;
            }
        }
        namespace red {
            namespace General {
                double x = globalEnvironment::cubeSizeWidth * 9.5 - chessSize/2.0;
                double y = globalEnvironment::cubeSizeWidth * 9.5 - chessSize/2.0;
            }
            namespace Advisor_1 {
                double x = globalEnvironment::cubeSizeWidth * 9.5 - chessSize/2.0;
                double y = globalEnvironment::cubeSizeHeight * 3.5 - chessSize/2.0;
            }
            namespace Advisor_2 {
                double x = globalEnvironment::cubeSizeWidth * 9.5 - chessSize/2.0;
                double y = globalEnvironment::cubeSizeHeight * 5.5 - chessSize/2.0;
            }
        }
    }

}


#endif // PARAMS_H
