// CS 3505, A5 - Stopwatch
// Snehashish Mishra
// Provides the model interface for the stopwatch app

#ifndef TIMERMODEL_H
#define TIMERMODEL_H

#include <QObject>
#include <QTime>

class TimerModel : public QObject
{
    Q_OBJECT

private:
    QTime time;                   // Object to measure and manipulate time
    int totalElapsedTime;
    bool newStart;                // New measurement or resuming old one?
    bool wasPaused;               // Was the stopwatch paused before or was it running
    bool wasRunning;              // Was the stopwatch running before or was it paused

public:
    explicit TimerModel(QObject *parent = 0);
    void startOrPauseTimer();      // Starts (or pauses or resumes) the timer.
    void stopAndResetTimer();      // Resets the timer (used when reset button is pressed)

private:
    int getTotalElapsedTime();

signals:
    void updateMilliSecTime(QString elapsedTime);
    void updateSecTime(QString elapsedTime);
    void updateMinuteTime(QString elapsedTime);

public slots:
    void emitUpdateSignal();
};

#endif // TIMERMODEL_H
