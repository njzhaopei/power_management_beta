#include "personalsavemode.h"

personalsavemode::personalsavemode(QWidget *parent) : QWidget(parent)
{
    top_widget = new QWidget();
    top_widget->setFixedSize(420,40);
    top_layout = new QVBoxLayout();
    return_icon = new QPushButton();//second menu to return to first menu
    QPixmap return_pic(":/secondmenu/tittle/return.ico");
    return_icon->setIcon(return_pic);
    return_icon->setIconSize(QSize(35, 38));
    return_icon->setFixedSize(35,38);
    return_icon->setFlat(true);
    top_layout->addWidget(return_icon,0,Qt::AlignLeft | Qt::AlignTop);
    top_layout->addStretch();
    top_layout->setMargin(0);
    top_layout->setSpacing(0);
    top_widget->setLayout(top_layout);
    center_widget = new QWidget();//for setting ways
    center_widget->setFixedSize(420,555);

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
    connect(cancel_action,SIGNAL(clicked()),this,SIGNAL(turn_first_menu()));
    connect(return_icon,SIGNAL(clicked()),this,SIGNAL(turn_first_menu()));
    setLayout(total_layout);

}

personalsavemode::~personalsavemode()
{

}

