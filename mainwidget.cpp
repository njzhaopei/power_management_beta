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
    QPalette text_palette = palette();
    text_palette.setColor(QPalette::WindowText, QColor(255, 255, 255));
    remain_battery = new QLabel("剩余电量");
    remain_battery->setPalette(text_palette);
    remain_battery->setFont(QFont("黑体",0,80,true));
    remain_battery_value = new QLabel("12%");
    battery_label = new QLabel("电池");
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
    setLayout(main_layout);
}
Main_Widget::~Main_Widget()
{

}



