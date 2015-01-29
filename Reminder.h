#ifndef REMINDER_H
#define REMINDER_H

#include <QWidget>
#include <QSystemTrayIcon>
#include <QDebug>
#include <QTimer>
#include <QMenu>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDate>
#include <QTime>

static QSystemTrayIcon icon;

class Reminder : public QWidget
{
    Q_OBJECT
public:
    explicit Reminder(QWidget *parent = 0, int time = 0, QString text = "", bool disposable = true, int id = 0);
    ~Reminder();
    void createIconMenu();

private :
    QString newTime;
    QString text;
    QTimer timer;
    int time;
    int id;
    bool disposable;
signals:
    void quit();
public slots:
    void show(QString text = "Relax");
    int getTime() const;
    void setTime(int value);
    void quitButtonClicked();
};


#endif // REMINDER_H
