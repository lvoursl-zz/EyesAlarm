#include "reminder.h"

Reminder::Reminder(QWidget *parent) : QWidget(parent)
{
    eyesAlarmTime = 600000; // 10 min
    icon.setIcon(QIcon("icon1.png"));
    icon.setVisible(true);
    icon.show();
    icon.showMessage("eyesAlarm", "Thanks for using!", icon.Warning, 20000);
}

Reminder::~Reminder()
{

}
int Reminder::getEyesAlarmTime() const
{
    return eyesAlarmTime;
}

void Reminder::setEyesAlarmTime(int value)
{
    eyesAlarmTime = value;
}


void Reminder::show() {
    qDebug()<< "show" << eyesAlarmTime;
    icon.showMessage("eyesAlarm", "Relax!", icon.Warning, 20000);
}




