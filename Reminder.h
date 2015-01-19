#ifndef REMINDER_H
#define REMINDER_H

#include <QWidget>
#include <QSystemTrayIcon>
#include <QDebug>
#include <QTimer>

static QSystemTrayIcon icon;

class Reminder : public QWidget
{
    Q_OBJECT
public:
    explicit Reminder(QWidget *parent = 0, int time = 0, QString text = "", bool disposable = true);
    ~Reminder();

private :
    QString newTime;
    QString text;
    QTimer timer;
    int time;
    int id;
    bool disposable;
signals:

public slots:
    void show(QString text = "Relax");
    int getTime() const;
    void setTime(int value);
};


#endif // REMINDER_H
