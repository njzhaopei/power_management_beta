#include "mainwidget.h"
#include <QLayout>
#include "QDesktopWidget"
#include "QApplication"
Main_Widget::Main_Widget(QWidget *parent) :
    QWidget(parent)
{
    setFixedSize(420,260);
    main_label = new QLabel();
    main_label->setGeometry(0,0,420,260);
    main_label->setStyleSheet(DEFAULT_SKIN);
    main_label->setParent(this);
    left_widget = new QWidget();
    right_widget = new QWidget();
    //set text
    QPalette text_palette = palette();
    text_palette.setColor(QPalette::WindowText, QColor(255, 255, 255));
    //set pix
    QPixmap batterypic("://battery/low_battery");
    remain_battery = new QLabel("剩余电量");
    remain_battery->setPalette(text_palette);
    remain_battery->setFont(QFont("黑体",0,80,true));
    remain_battery_value = new QLabel("12%");
    get_info = new QProcess;
    get_battery_info();
    battery_label = new QPushButton();
    battery_label->setFixedSize(210,250);
    battery_label->setIcon(batterypic);
    battery_label->setIconSize(QSize(210,250));
    battery_label->setFlat(true);
    battery_label->setParent(left_widget);
    remain_time = new QLabel("剩余时间");
    remain_time->setPalette(text_palette);
    remain_time->setFont(QFont("黑体",0,80,true));
    remain_time_value = new QLabel("5小时20分");
    right_layout = new QVBoxLayout;// for right widget
    right_layout->addWidget(remain_battery);
    right_layout->addWidget(remain_battery_value);
    right_layout->addWidget(remain_time);
    right_layout->addWidget(remain_time_value);
    right_widget->setLayout(right_layout);
    main_layout = new QHBoxLayout;
    main_layout->addWidget(left_widget);
    main_layout->addWidget(right_widget);
    work = new worker();
//    connect(get_info,SIGNAL(readyRead()),this,SLOT(readOutput()));
    connect(get_info,SIGNAL(finished(int,QProcess::ExitStatus)),this,SLOT(readOutput()));
    connect(work,SIGNAL(refresh_right_widget()),this,SLOT(do_refresh()),Qt::DirectConnection);
    qDebug() << "main_widget thread" << QThread::currentThreadId();
    setLayout(main_layout);
}
Main_Widget::~Main_Widget()
{

}
void Main_Widget::get_battery_info()
{
    do_shell("bash ./battery/battery_info.sh");
}
void Main_Widget::do_shell(QString e)
{
    get_info->start(e);
    qDebug() << "start";
}
void Main_Widget::readOutput()
{
    battery_info +=get_info->readAll();
    qDebug() <<battery_info;
    battery_label->setToolTip(battery_info);
    battery_label->setStyleSheet("QToolTip{border:1px solid #ec6a95;background:#F0F8FF;color:grey; }");
}

void Main_Widget::do_refresh()
{
    //clear all mask, reset the label
    qDebug() << "_______________________start charging_____________________________";
    qDebug() << "8888888888888888888888888888888888888888";
    if(work->state == "charging"){
        remain_battery->clearMask();
        remain_battery->setText("剩余电量");
        remain_battery_value->clearMask();
        remain_battery_value->setText(work->percentage);
        remain_time->clearMask();
        remain_time->setText("time to full");
        remain_time_value->clearMask();
        remain_time_value->setText(work->totaltime);
    }
    if(work->state == "discharging"){
        remain_battery->clearMask();
        remain_battery->setText("剩余电量");
        remain_battery_value->clearMask();
        remain_battery_value->setText(work->percentage);
        remain_time->clearMask();
        remain_time->setText("time to lack");
        remain_time_value->clearMask();
        remain_time_value->setText(work->totaltime);
    }
}
