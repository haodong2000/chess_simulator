#ifndef STARTGUI_H
#define STARTGUI_H

#include <QObject>
#include <QString>
#include <QTimer>
#include <global.h>

/* * * * * * * * * * * * * * * * * * * * *
*   File:     StartGui.h
*   Author:   Haodong LI
*   Usage:    UsageOfFile
*   Time:     2021-10-23
* * * * * * * * * * * * * * * * * * * * * */

class StartGui : public QObject
{
    Q_OBJECT

    // 使用 MEMBER 关键字
    Q_PROPERTY(int age MEMBER m_nAge NOTIFY ageChanged)
    Q_PROPERTY(QString difficulty MEMBER m_strDifficulty NOTIFY difficultyChanged)
    Q_PROPERTY(int int_difficulty MEMBER m_intDifficulty NOTIFY int_difficultyChanged)
    Q_PROPERTY(QString mode MEMBER m_strMode NOTIFY modeChanged)
    Q_PROPERTY(int int_mode MEMBER m_intMode NOTIFY int_modeChanged)
    Q_PROPERTY(QString end MEMBER m_strEnd NOTIFY endChanged)
    Q_PROPERTY(QString manual MEMBER m_strManual NOTIFY manualChanged)
    Q_PROPERTY(QString back MEMBER m_strBack NOTIFY backChanged)

public:
    explicit StartGui(QObject *parent = nullptr);

    Q_INVOKABLE void exitGameFunc();
    void testFunc();

public slots:
    void startGameFunc();

private:
    void getCurrentTime();

signals:
    void ageChanged();
    void difficultyChanged(const QString &newDifficulty);
    void int_difficultyChanged(const int &newIntDifficulty);
    void modeChanged(const QString &newMode);
    void int_modeChanged(const int &newIntMode);
    void endChanged(const QString &newEnd);
    void manualChanged(const QString &newManual);
    void backChanged(const QString &newBack);

    void refreshTime(const QString time);
private:
    QString m_strDifficulty;
    QString m_strMode;
    QString m_strEnd;
    QString m_strManual;
    QString m_strBack;
    int m_nAge;
    int m_intDifficulty;
    int m_intMode;

    QTimer m_timer;
};


#endif // STARTGUI_H
