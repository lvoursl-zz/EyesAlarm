#include "reminder.h"

Reminder::Reminder(QWidget *parent, int time, QString text, bool disposable) : QWidget(parent)
{
    icon.setIcon(QIcon("icon1.png"));
    icon.setVisible(true);
    icon.showMessage("eyesAlarm", text, icon.Warning, 20000);
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





