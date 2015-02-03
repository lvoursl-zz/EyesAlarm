#ifndef REMINDER_H
#define REMINDER_H

#include <QMainWindow>
#include <QWidget>
#include <QSystemTrayIcon>
#include <QDebug>
#include <QTimer>
#include <QMenu>
#include <QFile>
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QCloseEvent>

static QSystemTrayIcon icon;
const int widgetsYsize = 50;

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
    int y = 150;
    bool disposable;
    QLabel *reminderLabel;
    QPushButton *deleteReminderButton;
signals:
    void quit();
    void open(bool);
    void reminderDeleted(int id);
public slots:
    void show(QString text = "Relax");
    int getTime() const;
    void setTime(int value);
    void quitButtonClicked();
    void openButtonClicked();
};


#endif // REMINDER_H
