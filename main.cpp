#include <QApplication>
#include <QtGui>
#include "Counter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Counter counter;
    QTimer newTimer;
    counter.initi();
    QObject::connect(&newTimer, SIGNAL(timeout()),
                     &counter, SLOT(sh()));
    QObject::connect(&counter.trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason reason)),
              &counter, SLOT(iconActivated(QSystemTrayIcon::ActivationReason reason)));

    newTimer.start(600000);
// 600000
    return a.exec();
}
