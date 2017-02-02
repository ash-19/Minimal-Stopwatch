// CS 3505, A5 - Stopwatch
// Snehashish Mishra
// Contains the implementation of the model used for the stopwatch app

#include "timermodel.h"
#include <QTime>

// Constructor. Sets the required flags.
TimerModel::TimerModel(QObject *parent) : QObject(parent) {
    totalElapsedTime = 0;
    newStart = true;
    wasPaused = false;
    wasRunning = false;
}

// Starts (or pauses or resumes) the timer.
void TimerModel::startOrPauseTimer() {
    // If timing from scratch, reset totalElapsedTime
    if(newStart) {
        totalElapsedTime = 0;
        time.start();
        newStart = false;
        wasPaused = false;
        wasRunning = true;
    }

    // If was paused before, discard the paused time. Resume timing.
    else if(wasPaused) {
        time.start();
        newStart = false;
        wasPaused = false;
        wasRunning = true;
    }

    // Was running before (and clicked pause), get the time accumulated
    // and pause the timing.
    else if(wasRunning) {
        time.start();
        wasPaused = true;
        wasRunning = false;
    }
}

// Resets the timer (used when reset button is pressed)
void TimerModel::stopAndResetTimer() {
    totalElapsedTime = 0;
    newStart = true;
    wasPaused = false;
    wasRunning = false;
}

// Returns the total elapsed time in msec.
int TimerModel::getTotalElapsedTime() {
    if(wasRunning) {
        int current = time.restart();
        totalElapsedTime += current;
    }
    return totalElapsedTime;
}

// Emits a signal to update msec, sec, min labels with needed data.
void TimerModel::emitUpdateSignal() {
    emit(updateMilliSecTime(QString::number((getTotalElapsedTime()/10)%100)));
    emit(updateSecTime(QString::number((getTotalElapsedTime()/1000)%60)));
    emit(updateMinuteTime(QString::number((getTotalElapsedTime()/1000/60)%60)));
};
