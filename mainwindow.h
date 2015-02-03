#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "reminder.h"

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void eyesAlarmTimeChanged(int newTime);
private slots:
    void on_setButton_clicked();
    void on_addReminderButton_clicked();
    void updateReminders(int id);

private:
    Ui::MainWindow *ui;
    QString newTimeOfEyesAlarm;
    QString newReminderText;
    int newReminderTime;
    int newReminderId;
    bool disposableReminder;
    QList<Reminder*> remindersList;

    void closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOW_H
