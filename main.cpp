#include "mainwindow.h"
#include <QApplication>
#include <QThread>
//#include <worker.h>
//#include <battery_detact_thread.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qDebug() << "main thread" << QThread::currentThreadId();
    MainWindow w;
    w.show();
    //h.show();
    return a.exec();
}
