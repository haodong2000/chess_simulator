#include "rl_thread.h"

rl_thread::rl_thread():MP_count(0), MP_received(true) {
    qDebug() << " hello world (RL)";
}

rl_thread::rl_thread(QString name):MP_count(0), MP_received(true) {
    qDebug() << name << " hello world (RL)";
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
        __delayMsec(500);
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
        }
        else {
            qDebug() << "rl_thread.cpp line:50 run() receive message from server error!";
        }
        if(MP_received) {
            QString request = "RL Brain Request  ->  " + QString::number(MP_count);
            if(client->write(request.toLatin1(), request.length()) == -1) {
                qDebug() << "rl_thread.cpp line:55 run() write failed!";
            }
            std::cout << request.toStdString() << std::endl;
            MP_received = false;
        }
    }
}
