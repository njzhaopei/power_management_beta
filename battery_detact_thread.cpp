#include "battery_detact_thread.h"

battery_detact_thread::battery_detact_thread()
{
    get_battery_time = new QProcess;
}

battery_detact_thread::~battery_detact_thread()
{

}

void battery_detact_thread::run()
{
    //timer.moveToThread(this);
    QTimer timer;
    worker work;
    connect(&timer,SIGNAL(timeout()),&work,SLOT(onTimeout()),Qt::AutoConnection);
    timer.start(1000);
    exec();
}

