#ifndef REMINDER_H
#define REMINDER_H

#include <QWidget>
#include <QSystemTrayIcon>
#include <QDebug>

class Reminder : public QWidget
{
    Q_OBJECT
public:
    explicit Reminder(QWidget *parent = 0);
    ~Reminder();

private :
    int eyesAlarmTime;
    QString newTime;
    QSystemTrayIcon icon;
signals:

public slots:
    void show();
    int getEyesAlarmTime() const;
    void setEyesAlarmTime(int value);
};

#endif // REMINDER_H
