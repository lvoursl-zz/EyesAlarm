#include "mainwindow.h"
#include "reminder.h"
#include <QApplication>
#include <QVector>
#include <QMenu>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;

    /* for restore time, that user set to eyesReminder */
    QFile eyesAlarmTimeFile("eyesalarm.txt");
    QTextStream eyesAlarmTimeStream(&eyesAlarmTimeFile);
    int eyesAlarmTimeInFile = 1;

    if (eyesAlarmTimeFile.open(QIODevice::ReadWrite)) {
        eyesAlarmTimeStream >> eyesAlarmTimeInFile;
        eyesAlarmTimeFile.close();
    }

    Reminder eyesReminder(eyesAlarmTimeInFile, "Eyes! Relax!", false, -1, &window);

    QObject::connect(&window, SIGNAL(eyesAlarmTimeChanged(int)),
                     &eyesReminder, SLOT(setTime(int)));

    QObject::connect(&eyesReminder, SIGNAL(quit()), &a, SLOT(quit()));
    QObject::connect(&eyesReminder, SIGNAL(open(bool)), &window, SLOT(showNormal()));

    eyesReminder.createIconMenu();
    window.setFixedSize(436, 280);
    window.setWindowIcon(QIcon(":/img/icon.png"));
    window.setWindowTitle("eyesAlarm");
    window.show();
    return a.exec();
}
