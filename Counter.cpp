#include "Counter.h"

Counter::Counter() : QObject() { }

void Counter::sh() {
    trayIcon.showMessage("Eyes!", "Please, relax!", trayIcon.Warning, 20000);
    trayIcon.setVisible(true);
}

void Counter::iconActivated(QSystemTrayIcon::ActivationReason reason) {
    qDebug() << "work!";
}

void Counter::initi() {
    trayIcon.setVisible(true);
    trayIcon.setIcon(QIcon("icon.png"));
    trayIcon.showMessage("Eyes!", "Thanks for using!", trayIcon.Warning, 20000);
}

