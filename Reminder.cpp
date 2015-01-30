#include "reminder.h"

Reminder::Reminder(int time, QString text,
                   bool disposable, int id, QMainWindow *w, QWidget *parent) : QWidget(parent)
{
    if (icon.isVisible() == false) {
        /* if app started first time */
        icon.setIcon(QIcon(":/img/icon.png"));
        icon.setVisible(true);
        icon.show();
        icon.showMessage("eyesAlarm", "Welcome!", icon.Warning, 20000);
    }

    //QDate d;
    //QTime t;
    //d.setDate(getTime());
    //qDebug() << d.currentDate() << t.currentTime();

    this->text = text;
    this->time = time * 60000;
    this->id = id;
    this->disposable = disposable;

    timer.start(this->time);

    QObject::connect(&timer, SIGNAL(timeout()),
                     this, SLOT(show()));

    /* automatic deleting disposable reminder */
    if (disposable) {
        QObject::connect(&timer, SIGNAL(timeout()),
                         &timer, SLOT(stop()));
        QObject::connect(&timer, SIGNAL(timeout()),
                         this, SLOT(deleteLater()));
    }

    if (id > -1) {
        /* label with reminder text */
        QString labelText = text + ";   remind time:  " + QString::number(time) + " (minutes)";
        reminderLabel = new QLabel(labelText, w);
        reminderLabel->setFixedSize(400, 25);
        reminderLabel->move(20, labelYstep);
        reminderLabel->show();

        /* button to delete reminder */
        deleteReminderButton = new QPushButton("delete", w);
        deleteReminderButton->move(330, labelYstep);
        deleteReminderButton->setFixedSize(75, 30);
        deleteReminderButton->show();

        this->y = labelYstep;

        QObject::connect(deleteReminderButton, SIGNAL(clicked()), this, SLOT(deleteLater()));

        labelYstep += 25;
        /* save reminder to json file */
  /*      QFile dataFile("reminders.json");
        QJsonObject reminder;
        reminder["id"] = this->id;
        reminder["text"] = this->text;
        reminder["time"] = this->time;
        reminder["disposable"] = this->disposable;
        QJsonDocument saveReminder(reminder);
        if (dataFile.open(QIODevice::WriteOnly | QIODevice::Append)) {
            dataFile.write(saveReminder.toJson());
        }*/
    }

}

Reminder::~Reminder()
{
    qDebug() << "i am here";
    reminderLabel->deleteLater();
    deleteReminderButton->deleteLater();
    emit reminderDeleted(this->id);
}

void Reminder::createIconMenu()
{
    QMenu *iconMenu = new QMenu();
    QAction *quit = new QAction("Quit", this);
    iconMenu->addSeparator();
    iconMenu->addAction(quit);
    QObject::connect(quit, SIGNAL(triggered()), this, SLOT(quitButtonClicked()));
    icon.setContextMenu(iconMenu);
}
QLabel *Reminder::getReminderLabel() const
{
    return reminderLabel;
}

void Reminder::setReminderLabel(QLabel *value)
{
    reminderLabel = value;
}
QPushButton *Reminder::getDeleteReminderButton() const
{
    return deleteReminderButton;
}

void Reminder::setDeleteReminderButton(QPushButton *value)
{
    deleteReminderButton = value;
}
int Reminder::getY() const
{
    return y;
}

void Reminder::setY(int value)
{
    y = value;
}
int Reminder::getId() const
{
    return id;
}

void Reminder::setId(int value)
{
    id = value;
}





int Reminder::getTime() const
{
    return time;
}

void Reminder::setTime(int value)
{
    time = value;
    timer.start(time);
    qDebug() << value;
}

void Reminder::show(QString text) {
    icon.showMessage("eyesAlarm", this->text, icon.Warning, 20000);
}

void Reminder::quitButtonClicked() {
    emit quit();
}




