#ifndef QML_CONNECTION_H
#define QML_CONNECTION_H

/*****************************************************************
*   File:     Qml_Connection.h
*   Author:   Haodong LI
*   Usage:    connect with qml file to change the position of chesses
*   Time:     2021-05-31 -> 13:59:25
*****************************************************************/

#include <QQuickItem>
#include <QObject>
#include <QQuickItem>
#include <QWidget>

class Qml_Connection: public QObject
{
    Q_OBJECT
public:
    Qml_Connection();
};

#endif // QML_CONNECTION_H
