#include "worker.h"

worker::worker()
{

}

worker::~worker()
{

}

void  worker::onTimeout(){
      qDebug() << "From work thread"<< QThread::currentThreadId();
    get_battery_time = new QProcess;
    //connect(get_battery_time,SIGNAL(finished(int,QProcess::ExitStatus)),this,SLOT(do_others(int,QProcess::ExitStatus)));
   connect(get_battery_time,SIGNAL(readyRead()),this,SLOT(readOutput()));
    get_battery_time->start("bash ./battery/battery_state.sh");
    //get_battery_time->waitForFinished();
}
void worker::readOutput()
{

    QString tempinfo;
    qDebug() << "------------";
    tempinfo+= get_battery_time->readAll();
    parse_batterytime_info(tempinfo);
    //qDebug() << battery_time_info << "end"<<temp_info;
    qDebug() << "------------";
    set_battery_label();
    //parse_batterytime_info();
}
//void worker::do_others(int,QProcess::ExitStatus exitstatus)
//{
//   qDebug() << "hhhhhhhhhhhhh";
//   if(exitstatus == QProcess::NormalExit)
//        parse_batterytime_info();
//}
void worker::parse_batterytime_info(QString info)
{
    qDebug() << info;
    qDebug() <<"******************";
    int index = info.lastIndexOf('#');
    int index1 = info.lastIndexOf('?');
    int index2 = info.lastIndexOf('!');
    state = info.mid(0,index);
    totaltime = info.mid(index+1,index1-index-1);
    percentage = info.mid(index1+1,index2-index1-1);
    qDebug() << state <<"|||||||"<< totaltime <<"||||||||"<< percentage;
    qDebug() <<"******************";
    //qDebug() << "------------------\n";
}
void worker::set_battery_label()
{
    if(state == "charging"){
        qDebug() << "battery was charging";
    }
    emit refresh_right_widget();
    qDebug() << "refresh widget";
}
