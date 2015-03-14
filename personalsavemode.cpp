#include "personalsavemode.h"

personalsavemode::personalsavemode(QWidget *parent) : QWidget(parent)
{
    top_widget = new QWidget();
    top_widget->setFixedSize(420,35);
    top_layout = new QVBoxLayout();
    return_icon = new QPushButton();//second menu to return to first menu
    QPixmap return_pic(":/title/button/close.png");
    return_icon->setIcon(return_pic);
    return_icon->setIconSize(return_pic.size());
    return_icon->setFixedSize(30,30);
    return_icon->setFlat(true);
    top_layout->addWidget(return_icon,0,Qt::AlignLeft);
    top_widget->setLayout(top_layout);
    center_widget = new QWidget();//for setting ways
    center_widget->setFixedSize(420,595);

    foot_widget = new QWidget();
    foot_widget->setFixedSize(420,50);
    cancel_action = new QPushButton("取消");
    apply_action = new QPushButton("确认");
    foot_layout = new QHBoxLayout();
    foot_layout->addStretch(1);
    foot_layout->addWidget(cancel_action);
    foot_layout->addStretch(1);
    foot_layout->addWidget(apply_action);
    foot_layout->addStretch(1);
    foot_layout->setMargin(0);
    foot_widget->setLayout(foot_layout);
    total_layout = new QVBoxLayout();
    total_layout->addWidget(top_widget);
    total_layout->addWidget(center_widget);
    total_layout->addWidget(foot_widget);
    setLayout(total_layout);
}

personalsavemode::~personalsavemode()
{

}

