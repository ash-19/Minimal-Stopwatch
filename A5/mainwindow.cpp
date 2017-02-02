// CS 3505, A5 - Stopwatch
// Snehashish Mishra
// Contains the implementation of the view for the stopwatch app

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>

// Mainwindow constructor. Also includes the connections between view and model via
// siganl, slot mechanism.
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new TimerModel();
    tick = new QTimer(this);

    // Connections
    connect(ui->startButton, &QPushButton::clicked, model, &TimerModel::startOrPauseTimer);
    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::startTicking);
    connect(ui->resetButton, &QPushButton::clicked, model, &TimerModel::stopAndResetTimer);
    connect(model, &TimerModel::updateMilliSecTime, this, &MainWindow::updateMSec);
    connect(model, &TimerModel::updateSecTime, this, &MainWindow::updateSeconds);
    connect(model, &TimerModel::updateMinuteTime, this, &MainWindow::updateMinutes);
    connect(tick, &QTimer::timeout, model, &TimerModel::emitUpdateSignal);
}

// Destructor
MainWindow::~MainWindow()
{
    delete ui;
    delete model;
    delete tick;
}

// Starts the QTimer to emit a signal for UI update
void MainWindow::startTicking() {
    tick->start(10);
}

// Updates the msec label on the stopwatch UI
void MainWindow::updateMSec(QString s) {
    ui->msecLabel->setText(padIfNeeded(s));
}

// Updates the seconds label on the stopwatch UI
void MainWindow::updateSeconds(QString s) {
    ui->secLabel->setText(padIfNeeded(s));
}

// Updates the minutes label on the stopwatch UI
void MainWindow::updateMinutes(QString s) {
    ui->minutesLabel->setText(padIfNeeded(s));
}

// Pads the time to two digits if necessary
QString MainWindow::padIfNeeded(QString s) {
    if(s.length() < 2) {
        return "0" + s;
    }
    return s;
}

// What to do when the start/pause/resume button is clicked
void MainWindow::on_startButton_clicked()
{
    if(ui->startButton->text() == "PAUSE") {
        ui->startButton->setText("RESUME");
    }
    else {
        ui->startButton->setText("PAUSE");
    }

}

// What to do when the reset button is clicked
void MainWindow::on_resetButton_clicked()
{
    ui->startButton->setText("START");
    ui->msecLabel->setText(QString("00"));
    ui->secLabel->setText(QString("00"));
    ui->minutesLabel->setText(QString("00"));
    model = new TimerModel();
    tick = new QTimer(this);
}
