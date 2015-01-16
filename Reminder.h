#ifndef REMINDER_H
#define REMINDER_H

#include <QWidget>
#include <QSystemTrayIcon>
#include <QDebug>
#include <QTimer>

class Reminder : public QWidget
{
    Q_OBJECT
public:
    explicit Reminder(QWidget *parent = 0, int time = 0, QString text = "");
    ~Reminder();

private :
    QString newTime;
    QSystemTrayIcon icon;
    QString text;
    QTimer timer;
    int time;
signals:

public slots:
    void show(QString text = "Relax");
    int getTime() const;
    void setTime(int value);
    void createNew(QString text, int time);
};


#endif // REMINDER_H
