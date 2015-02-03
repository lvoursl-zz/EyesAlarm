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

    this->y += id * 25;
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
        reminderLabel->setWordWrap(true);
        reminderLabel->setFixedSize(280, 25);
        reminderLabel->move(20, this->y);
        reminderLabel->show();        

        /* button to delete reminder */
        deleteReminderButton = new QPushButton("delete", w);
        deleteReminderButton->move(330, this->y);
        deleteReminderButton->setFixedSize(75, 30);
        deleteReminderButton->show();

        QObject::connect(deleteReminderButton, SIGNAL(clicked()), this, SLOT(deleteLater()));
    }

}

Reminder::~Reminder()
{
    /* thats for ignore eyesReminder */
    if (this->id != -1) {
        delete reminderLabel;
        delete deleteReminderButton;
        emit reminderDeleted(this->id);
    }
}

void Reminder::createIconMenu()
{
    QMenu *iconMenu = new QMenu();
    QAction *quit = new QAction("Quit", this);
    QAction *open = new QAction("Open", this);
    iconMenu->addAction(open);
    iconMenu->addAction(quit);
    QObject::connect(open, SIGNAL(triggered()), this, SLOT(openButtonClicked()));
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

void Reminder::openButtonClicked() {
    qDebug() << "emit";
    emit open(true);
}




