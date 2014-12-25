#ifndef REMINDER_H
#define REMINDER_H

#include <QWidget>
#include <QSystemTrayIcon>
#include <QDebug>
#include <QIcon>

class Reminder : public QWidget
{
    Q_OBJECT
public:
    explicit Reminder(QWidget *parent = 0);

    QSystemTrayIcon icon;
signals:
    void activated(QSystemTrayIcon::ActivationReason reason);
public slots:
    void show();
    void iconActivated(QSystemTrayIcon::ActivationReason reason);
};

#endif // REMINDER_H
