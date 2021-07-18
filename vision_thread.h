#ifndef VISION_THREAD_H
#define VISION_THREAD_H

#include <QThread>
#include <PythonMudule.h>

/* * * * * * * * * * * * * * * * * * * * *
*   File:     vision_thread.h
*   Author:   Haodong LI
*   Usage:    build a new thread, avoid creating object in father thread
*   Time:     2021-07-18
* * * * * * * * * * * * * * * * * * * * * */

class vision_thread: public QThread
{
public:
    vision_thread();
    void run();
public:
    QString name;
};

#endif // VISION_THREAD_H
