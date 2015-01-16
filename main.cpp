#include "mainwindow.h"
#include "reminder.h"
#include <QApplication>
#include <QVector>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;
    Reminder eyesReminder(NULL, 60000, "Eyes! Relax!");

    QObject::connect(&window, SIGNAL(eyesAlarmTimeChanged(int)),
                     &eyesReminder, SLOT(setTime(int)));

    QObject::connect(&window, SIGNAL(canCreateNewReminder(QString,int)),
                     &eyesReminder, SLOT(createNew(QString, int)));

    //Reminder reminder(NULL, 6 /**60000*/, "shit"); // thats ok

    window.show();
    return a.exec();
}
