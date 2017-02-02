// CS 3505, A5 - Stopwatch
// Snehashish Mishra
// Provides the view interface for the stopwatch app

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "timermodel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void on_startButton_clicked();
    void on_resetButton_clicked();
    void startTicking();                // Starts the QTimer and emits a signal every x msec to update the UI

private:
    void updateMSec(QString s);         // Updates the msec label on the stopwatch UI
    void updateSeconds(QString s);      // Updates the seconds label on the stopwatch UI
    void updateMinutes(QString s);      // Updates the minutes label on the stopwatch UI
    QString padIfNeeded(QString s);     // Pads to time to two digits if necessary
    Ui::MainWindow *ui;
    TimerModel *model;
    QTimer *tick;
};

#endif // MAINWINDOW_H
