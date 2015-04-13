#include "mainwidget.h"
#include <QLayout>
#include "QDesktopWidget"
#include "QApplication"
Main_Widget::Main_Widget(QWidget *parent) :
    QWidget(parent)
{
    setFixedSize(420,260);
    QPixmap batterypic("://battery_state/low");
    QPainter painter(this);
    painter.drawPixmap(0,0,128,128,batterypic);
    batterypic = batterypic.scaled(batterypic.width()*1.5,batterypic.height()*1.5,Qt::KeepAspectRatio);
    painter.drawPixmap(210,250,batterypic);
    main_label = new QLabel();
    main_label->setGeometry(0,0,420,260);
    main_label->setStyleSheet(DEFAULT_SKIN);
    main_label->setParent(this);
    left_widget = new QWidget();
    right_widget = new QWidget();
    right_widget->setAttribute(Qt::WA_DeleteOnClose);
    //set text
    QPalette text_palette = palette();
    text_palette.setColor(QPalette::WindowText, QColor(255, 255, 255));
    //set pix

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
    //进行connect前必须实例化
    child_t = new battery_detact_thread();
//    connect(get_info,SIGNAL(readyRead()),this,SLOT(readOutput()));
    connect(get_info,SIGNAL(finished(int,QProcess::ExitStatus)),this,SLOT(readOutput()));
    connect(child_t,SIGNAL(refresh_widget_signal(QString,QString,QString)),this,SLOT(do_refresh(QString,QString,QString)));
    qDebug() << "main_widget thread" << QThread::currentThreadId();
    child_t->start();
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

void Main_Widget::do_refresh(QString state,QString totaltime,QString percentage)
{
    //clear all mask, reset the label
    int index;
    bool ok;
    qDebug() << "_______________________start charging_____________________________";
    qDebug() << "8888888888888888888888888888888888888888";
    if(state == "charging"){
        remain_battery->clearMask();
        remain_battery->setText("剩余电量");
        remain_battery_value->clearMask();
        remain_battery_value->setText(percentage);
        index = percentage.lastIndexOf("%");
        per_to_int = (percentage.mid(0,index)).toInt(&ok,10);
        if(per_to_int >= 25)
            change_battery_pic();
        remain_time->clearMask();
        remain_time->setText("充满时间还剩");
        remain_time_value->clearMask();
        remain_time_value->setText(totaltime);
    }
    if(state == "discharging"){
        remain_battery->clearMask();
        remain_battery->setText("剩余电量");
        remain_battery_value->clearMask();
        remain_battery_value->setText(percentage);
        index = percentage.lastIndexOf("%");
        per_to_int = (percentage.mid(0,index)).toInt(&ok,10);
        if(per_to_int >= 25)
            change_battery_pic();
        remain_time->clearMask();
        remain_time->setText("用完时间还剩");
        remain_time_value->clearMask();
        remain_time_value->setText(totaltime);
    }
}
void Main_Widget::change_battery_pic()
{
    if(per_to_int >= 25 && per_to_int <= 50)
        {
            QPixmap mid_battery("://battery_state/middle");
            QPainter painter(this);
            painter.drawPixmap(0,0,128,128,mid_battery);
            mid_battery = mid_battery.scaled(mid_battery.width()*1.5,mid_battery.height()*1.5,Qt::KeepAspectRatio);
            painter.drawPixmap(210,250,mid_battery);
            battery_label->clearMask();
            battery_label->setIcon(mid_battery);
         }
    if(per_to_int > 50 && per_to_int <= 95)
        {
            QPixmap high_battery("://battery_state/high");
            QPainter painter(this);
            painter.drawPixmap(0,0,128,128,high_battery);
            high_battery = high_battery.scaled(high_battery.width()*1.5,high_battery.height()*1.5,Qt::KeepAspectRatio);
            painter.drawPixmap(210,250,high_battery);
            battery_label->clearMask();
            battery_label->setIcon(high_battery);
            }
    if(per_to_int > 95 && per_to_int <= 100)
        {
            QPixmap full_battery("://battery_state/full");
            QPainter painter(this);
            painter.drawPixmap(0,0,128,128,full_battery);
            full_battery = full_battery.scaled(full_battery.width()*1.5,full_battery.height()*1.5,Qt::KeepAspectRatio);
            painter.drawPixmap(210,250,full_battery);
            battery_label->clearMask();
            battery_label->setIcon(full_battery);

            }
}
