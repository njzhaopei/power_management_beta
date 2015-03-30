#include "mainwindow.h"
#include <QApplication>
#include <QThread>
//#include <worker.h>
//#include <battery_detact_thread.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qDebug() << "main thread" << QThread::currentThreadId();
   // QThread t;
    //QTimer timer;
//    battery_detact_thread t;
//    worker work;
//    //QObject::connect(&timer,SIGNAL(timeout()),&work,SLOT(onTimeout()));
//    //timer.start(1000);
//    work.moveToThread(&t);
//    t.start();
    MainWindow w;
    w.show();

    return a.exec();
}
