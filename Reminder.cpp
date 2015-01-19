#include "reminder.h"

Reminder::Reminder(QWidget *parent, int time, QString text, bool disposable) : QWidget(parent)
{
    if (icon.isVisible() == false) {
        /* if started first time */
        icon.setIcon(QIcon(":/img/icon.png"));
        icon.setVisible(true);
        icon.show();
        icon.showMessage("eyesAlarm", "Welcome!", icon.Warning, 20000);
    }
    timer.start(time);
    this->text = text;
    this->time = time;
    QObject::connect(&timer, SIGNAL(timeout()),
                     this, SLOT(show()));
    if (disposable) {
        QObject::connect(&timer, SIGNAL(timeout()),
                         &timer, SLOT(stop()));
    }
    qDebug() << this->text << this->time << " constructor" << disposable;
}

Reminder::~Reminder()
{

}
int Reminder::getTime() const
{
    return time;
}

void Reminder::setTime(int value)
{
    time = value;
    timer.start(time);
    qDebug() << value;
}

void Reminder::show(QString text) {
    icon.showMessage("eyesAlarm", this->text, icon.Warning, 20000);
}





