#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    labelYStep = 150;
    newReminderId = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_setButton_clicked()
{
   newTimeOfEyesAlarm = ui->eyesAlarmTimeEdit->toPlainText();
   if ((!newTimeOfEyesAlarm.isEmpty()) && (newTimeOfEyesAlarm.toInt() != 0) && (newTimeOfEyesAlarm.toInt() < 60)) {
       emit eyesAlarmTimeChanged(newTimeOfEyesAlarm.toInt() * 60000); // *60000 = conversion to minutes
   }
}

void MainWindow::on_addReminderButton_clicked()
{
    newReminderText = ui->newReminderText->toPlainText();
    newReminderTime = ui->newReminderTime->toPlainText().toInt();
    bool disposableReminder = ui->disposableReminder->isChecked();
    // ограничение по времени напоминалки? ( 60 минут? )
    if ((!newReminderText.isEmpty()) && (newReminderTime != 0)) {
        Reminder *reminder = new Reminder(NULL, newReminderTime, newReminderText, disposableReminder);
        QLabel *a = new QLabel(newReminderText, this);
        a->move(20, labelYStep);
        a->show();
        labelYStep += 20;
    }
}
