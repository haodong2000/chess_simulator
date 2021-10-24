#ifndef STARTGUI_H
#define STARTGUI_H

#include <QObject>
#include <QString>
#include <QTimer>
#include <global.h>

class StartGui : public QObject
{
    Q_OBJECT

    // 使用 MEMBER 关键字
    Q_PROPERTY(int age MEMBER m_nAge NOTIFY ageChanged)
    Q_PROPERTY(QString name MEMBER m_strName NOTIFY nameChanged)

public:
    explicit StartGui(QObject *parent = nullptr);

    Q_INVOKABLE void exitGameFunc();
    void testFunc03();

public slots:
    void startGameFunc();

private:
    void getCurrentTime();

signals:
    void ageChanged();
    void nameChanged(const QString &newName);

    //普通信号
    void refreshTime(const QString time);
private:
    QString m_strName;
    int m_nAge;

    QTimer m_timer;
};


#endif // STARTGUI_H
