#include "mainwindow.h"
#include "reminder.h"
#include <QApplication>
#include <QVector>
#include <QMenu>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;
    QFile eyesAlarmTimeFile("eyesalarm.txt");
    QTextStream eyesAlarmTimeStream(&eyesAlarmTimeFile);
    int eyesAlarmTimeInFile;

    if (eyesAlarmTimeFile.open(QIODevice::ReadWrite)) {
        eyesAlarmTimeStream >> eyesAlarmTimeInFile;
        eyesAlarmTimeFile.close();
    }

    Reminder eyesReminder(eyesAlarmTimeInFile, "Eyes! Relax!", false, -1, &window);

    QObject::connect(&window, SIGNAL(eyesAlarmTimeChanged(int)),
                     &eyesReminder, SLOT(setTime(int)));

    QObject::connect(&eyesReminder, SIGNAL(quit()), &a, SLOT(quit()));

    eyesReminder.createIconMenu();
    window.setFixedSize(436, 280);
    window.setWindowIcon(QIcon(":/img/icon.png"));
    window.show();
    return a.exec();
}
