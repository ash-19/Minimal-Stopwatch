// CS 3505, A5 - Stopwatch
// Snehashish Mishra
// Gets things running

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
