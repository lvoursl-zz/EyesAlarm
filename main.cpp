#include "mainwindow.h"
#include "reminder.h"
#include <QApplication>
#include <QVector>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;
    Reminder eyesReminder(NULL, 60000, "Eyes! Relax!", false); // 60000 - 1 mimute

    QObject::connect(&window, SIGNAL(eyesAlarmTimeChanged(int)),
                     &eyesReminder, SLOT(setTime(int)));

    window.show();
    window.setFixedSize(436, 280);
    return a.exec();
}
