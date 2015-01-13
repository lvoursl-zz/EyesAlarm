#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
    // ограничение по времени? ( 60 минут? )
    if ((!newReminderText.isEmpty()) && (newReminderTime != 0)) {
        qDebug() << newReminderText << " " << newReminderTime;
    }
}
