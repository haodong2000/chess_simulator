#ifndef PARAMS_H
#define PARAMS_H

/* * * * * * * * * * * * * * * * * * * * *
*   File:     Params.h
*   Author:   Haodong LI
*   Usage:    store the params of the project
*   Time:     2021/05-29
* * * * * * * * * * * * * * * * * * * * * */

#include <QScreen>
#include <QGuiApplication>

namespace globalEnvironment {
    // get the avaliable geometry space of client screen
    QRect screenRect = QGuiApplication::primaryScreen()->availableGeometry();

    // important parameters, never change
    const double devicePixelRatio  = QGuiApplication::primaryScreen()->devicePixelRatio();
    const int screenAvaliableWidth  = screenRect.width();
    const int screenAvaliableHeight = screenRect.height();
    const double cubeSizeWidth = (screenAvaliableHeight * 2.0)/15.0;
    const double cubeSizeHeight = screenAvaliableHeight/9.0;
}

namespace chessPos {
    // all the coordinate info of all chesses
    double chessSize  =  globalEnvironment::cubeSizeWidth * 0.45;
    namespace black {
        namespace General {
            double x = globalEnvironment::cubeSizeWidth/2.0 - chessSize/2.0;
            double y = globalEnvironment::cubeSizeHeight * 4.5 - chessSize/2.0;
        }
    }
    namespace red {
        namespace General {
            double x = globalEnvironment::cubeSizeWidth * 9.5 - chessSize/2.0;
            double y = globalEnvironment::cubeSizeWidth * 9.5 - chessSize/2.0;
        }
    }
}

#endif // PARAMS_H
