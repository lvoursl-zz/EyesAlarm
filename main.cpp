#include "Reminder.h"
#include <QApplication>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Reminder reminder;
    QTimer timer;

    QObject::connect(&timer, SIGNAL(timeout()),
                     &reminder, SLOT(show()));
  /*  QObject::connect(&reminder.icon, SIGNAL(activated(QSystemTrayIcon::ActivationReason reason)),
              &reminder, SLOT(iconActivated(QSystemTrayIcon::ActivationReason reason)));
*/
    timer.start(600000);

    return a.exec();
}
