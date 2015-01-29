#include "mainwindow.h"
#include "reminder.h"
#include <QApplication>
#include <QVector>
#include <QMenu>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;
    Reminder eyesReminder(NULL, 3, "Eyes! Relax!", false, 0);

    QObject::connect(&window, SIGNAL(eyesAlarmTimeChanged(int)),
                     &eyesReminder, SLOT(setTime(int)));

    QObject::connect(&eyesReminder, SIGNAL(quit()), &a, SLOT(quit()));

    eyesReminder.createIconMenu();
    window.setFixedSize(436, 280);
    window.setWindowIcon(QIcon(":/img/icon.png"));
    window.show();
    return a.exec();
}
