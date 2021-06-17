#include "PythonMudule.h"

PythonMudule::PythonMudule(QString N):name(N),step(0, 0, false, 0, 0),step_str(""),isValid(false)
{
    qDebug() << this->name << "hello world";
    client->connectToHost(PARAM::HOST, PARAM::PORT);
    if(client->waitForConnected(10000)) {
        qDebug() << this->name << " Connected!";
    }
    else {
        qDebug() << this->name << " Connection Failed!!!";
    }
    QString data = "connection test, hello pycharm!";
    if(client->write(data.toLatin1(), data.length()) == -1) {
        qDebug() << "PythonMudule.cpp line:15 PythonMudule() write failed!";
    }
    connect(client, SIGNAL(readyRead()), this, SLOT(client_read_data()));
    connect(client, SIGNAL(disconnected()), this, SLOT(client_disconnect()));
}

void PythonMudule::run() {
    while(true) {
        GlobalEnvirIn::Instance()->__delayMsec(500);
        QString request = "Chess Step Request";
        if(client->write(request.toLatin1(), request.length()) == -1) {
            qDebug() << "PythonMudule.cpp line:26 run() write failed!";
        }
        if(isValid) vision_step();
    }
}

void PythonMudule::vision_step() {
    // TODO
    // return the chessStep if chess moved
}

void PythonMudule::client_read_data() {
    char msg[1024] = {0};
    client->read(msg, 1024);
    QString msg_qstr = "";
    if(strlen(msg) > 0) {
        msg_qstr = msg;
        qDebug() << "client reveive: " << msg_qstr;
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
