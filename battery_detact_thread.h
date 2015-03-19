#ifndef BATTERY_DETACT_THREAD_H
#define BATTERY_DETACT_THREAD_H
#include <QThread>
#include <QTimer>
#include <QProcess>
#include <worker.h>
#include <QDebug>
class battery_detact_thread : public  QThread
{
public:
    battery_detact_thread();
    ~battery_detact_thread();
private:
    void run();
    QProcess *get_battery_time;
};

#endif // BATTERY_DETACT_THREAD_H
