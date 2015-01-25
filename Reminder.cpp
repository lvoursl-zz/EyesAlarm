#include "reminder.h"

Reminder::Reminder(QWidget *parent, int time, QString text, bool disposable, int id) : QWidget(parent)
{
    if (icon.isVisible() == false) {
        /* if app started first time */
        icon.setIcon(QIcon(":/img/icon.png"));
        icon.setVisible(true);
        icon.show();
        icon.showMessage("eyesAlarm", "Welcome!", icon.Warning, 20000);
    }
    timer.start(time);

    this->text = text;
    this->time = time;
    this->id = id;

    QObject::connect(&timer, SIGNAL(timeout()),
                     this, SLOT(show()));
    if (disposable) {
        QObject::connect(&timer, SIGNAL(timeout()),
                         &timer, SLOT(stop()));
    }
    if (id > 0) {
        QFile dataFile("reminders.json");
        QJsonObject reminder;
        reminder["id"] = id;
        reminder["text"] = text;
        reminder["time"] = time;
        reminder["disposable"] = disposable;
        QJsonDocument saveReminder(reminder);
        if (dataFile.open(QIODevice::WriteOnly | QIODevice::Append)) {
            dataFile.write(saveReminder.toJson());
        }
    }

}

Reminder::~Reminder()
{

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




