#include "mainwindow.h"
#include "reminder.h"
#include <QApplication>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;
    QTimer timer;
    Reminder reminder;
    timer.start(reminder.getEyesAlarmTime());

    QObject::connect(&timer, SIGNAL(timeout()),
                     &reminder, SLOT(show()));
    QObject::connect(&window, SIGNAL(eyesAlarmTimeChanged(int)),
                     &reminder, SLOT(setEyesAlarmTime(int)));
    QObject::connect(&window, SIGNAL(eyesAlarmTimeChanged(int)),
                     &timer, SLOT(start(int)));
    window.show();
    return a.exec();
}
