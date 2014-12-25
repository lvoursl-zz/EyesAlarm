#include "Reminder.h"

Reminder::Reminder(QWidget *parent) :
    QWidget(parent)
{
    icon.setIcon(QIcon("icon1.png"));
    icon.setVisible(true);
    icon.show();
    icon.showMessage("eyesAlarm", "Thanks for using!", icon.Warning, 20000);
    /*QSystemTrayIcon *Icon = new QSystemTrayIcon(QIcon("icon1.png"), this);
    Icon->setVisible(true);
    Icon->show();
    Icon->showMessage("eyesAlarm", "Thanks for using!", Icon->ActivationReasonWarning, 20000);*/
}

void Reminder::show() {
    qDebug()<< "show";
    icon.showMessage("eyesAlarm", "Relax!", icon.Warning, 20000);
}

 void Reminder::iconActivated(QSystemTrayIcon::ActivationReason reason) {
     qDebug()<< "it works";
 }
