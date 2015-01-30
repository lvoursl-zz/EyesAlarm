#ifndef REMINDER_H
#define REMINDER_H

#include <QMainWindow>
#include <QWidget>
#include <QSystemTrayIcon>
#include <QDebug>
#include <QTimer>
#include <QMenu>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDate>
#include <QTime>
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>

static QSystemTrayIcon icon;
static int labelYstep = 150;

class Reminder : public QWidget
{
    Q_OBJECT
public:
    explicit Reminder(int time, QString text, bool disposable, int id,
                      QMainWindow *w, QWidget *parent = 0);
    ~Reminder();
    void createIconMenu();

    QLabel *getReminderLabel() const;
    void setReminderLabel(QLabel *value);

    QPushButton *getDeleteReminderButton() const;
    void setDeleteReminderButton(QPushButton *value);

    int getY() const;
    void setY(int value);

    int getId() const;
    void setId(int value);

private :
    QString newTime;
    QString text;
    QTimer timer;
    int time;
    int id;
    int y;
    bool disposable;

    QLabel *reminderLabel;
    QPushButton *deleteReminderButton;
signals:
    void quit();
    void reminderDeleted(int id);
public slots:
    void show(QString text = "Relax");
    int getTime() const;
    void setTime(int value);
    void quitButtonClicked();
};


#endif // REMINDER_H
