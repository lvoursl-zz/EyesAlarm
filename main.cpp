#include "mainwindow.h"
#include "reminder.h"
#include <QApplication>
#include <QVector>
#include <QMenu>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;
    Reminder eyesReminder(NULL, 60000, "Eyes! Relax!", false); // 60000 - 1 mimute
    QMenu *menu = new QMenu();
    QString aa = "aaa";
    menu->addAction(aa);
    icon.setContextMenu(menu);

    QObject::connect(&window, SIGNAL(eyesAlarmTimeChanged(int)),
                     &eyesReminder, SLOT(setTime(int)));

    window.setFixedSize(436, 280);
    window.setWindowIcon(QIcon(":/img/icon.png"));
    window.show();
    return a.exec();
}
