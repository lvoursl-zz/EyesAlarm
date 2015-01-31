#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /* thats for taken last id from json file */
    QFile remindersFile("reminders.json");
    if (remindersFile.open(QIODevice::ReadOnly)) {
        // сделать отдельный фаил, где хранится ИД, и здесь читать из него значение, затем присваивая его newReminderId
        QByteArray remindersData = remindersFile.readAll();
        QJsonDocument remindersInJSON(QJsonDocument::fromJson(remindersData));
        QJsonObject remindersObject = remindersInJSON.object();
        QJsonArray remindersArray = remindersObject["id"].toArray();
        //qDebug() << remindersInJSON.array();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_setButton_clicked()
{
   newTimeOfEyesAlarm = ui->eyesAlarmTimeEdit->toPlainText();
   if ((!newTimeOfEyesAlarm.isEmpty()) && (newTimeOfEyesAlarm.toInt() > 0) && (newTimeOfEyesAlarm.toInt() < 60)) {
       // writing for file
       QFile eyesAlarmTimeFile("eyesalarm.txt");
       if (eyesAlarmTimeFile.open(QIODevice::ReadWrite)) {
           QTextStream eyesAlarmTimeStream(&eyesAlarmTimeFile);
           eyesAlarmTimeFile.resize("eyesalarm.txt", 0);
           eyesAlarmTimeStream << newTimeOfEyesAlarm.toInt();
           eyesAlarmTimeFile.close();
       }
       emit eyesAlarmTimeChanged(newTimeOfEyesAlarm.toInt() * 60000);
   }
}

void MainWindow::on_addReminderButton_clicked()
{
    newReminderText = ui->newReminderText->toPlainText();
    newReminderTime = ui->newReminderTime->toPlainText().toInt();
    bool disposableReminder = ui->disposableReminder->isChecked();
    newReminderId = remindersList.length();

    if ((!newReminderText.isEmpty()) && (newReminderTime > 0) && (newReminderTime < 241)) {
        Reminder *reminder = new Reminder(newReminderTime, newReminderText,
                                          disposableReminder, newReminderId, this);
        remindersList.push_back(reminder);
        QObject::connect(reminder, SIGNAL(reminderDeleted(int)), this, SLOT(updateReminders(int)));
    }
}

void MainWindow::updateReminders(int id)
{
    qDebug() << "id:" << id;
    qDebug() << "length: " << remindersList.length();
    remindersList.removeAt(id);
    Reminder *r;
    for (int i = id; i < remindersList.length(); i++) {
        r = remindersList.at(i);
        r->setId(i);
        r->getReminderLabel()->move(20, r->getY() - 25);
        r->getDeleteReminderButton()->move(330, r->getY() - 25);
        r->setY(r->getY() - 25);
    }

}



