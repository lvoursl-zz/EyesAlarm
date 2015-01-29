#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    labelYStep = 150;

    // thats for taken last id from json file
    /*QFile remindersFile("reminders.json");
    QByteArray remindersData = remindersFile.readAll();
    QJsonDocument remindersInJSON(QJsonDocument::fromJson(remindersData));*/

    newReminderId = 1;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_setButton_clicked()
{
   newTimeOfEyesAlarm = ui->eyesAlarmTimeEdit->toPlainText();
   if ((!newTimeOfEyesAlarm.isEmpty()) && (newTimeOfEyesAlarm.toInt() > 0) && (newTimeOfEyesAlarm.toInt() < 60)) {
       emit eyesAlarmTimeChanged(newTimeOfEyesAlarm.toInt());
   }
}

void MainWindow::on_addReminderButton_clicked()
{
    newReminderText = ui->newReminderText->toPlainText();
    newReminderTime = ui->newReminderTime->toPlainText().toInt();
    bool disposableReminder = ui->disposableReminder->isChecked();

    if ((!newReminderText.isEmpty()) && (newReminderTime > 0)) {
        Reminder *reminder = new Reminder(NULL, newReminderTime, newReminderText, disposableReminder, newReminderId);
        newReminderId++;
        QString labelText = newReminderText + ";   remind time: " + ui->newReminderTime->toPlainText() + " (minutes)";
        QLabel *a = new QLabel(labelText, this);
        a->setFixedSize(400, 25);
        a->move(20, labelYStep);
        a->show();
        labelYStep += 25;
    }
}


