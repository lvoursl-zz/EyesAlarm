#include "remined.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Remined w;
    w.show();

    return a.exec();
}
