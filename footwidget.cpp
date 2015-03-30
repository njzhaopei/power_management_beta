#include "footwidget.h"

Foot_Widget::Foot_Widget(QWidget *parent) : QWidget(parent)
{
    setFixedSize(420,385);
    mutex = true;
    quick_time = 0;
    limit_time = 0;
    lock_time = 0;
    QPalette text_palette = palette();
    QPixmap switch_off("://foot/switch/off1");
    text_palette.setColor(QPalette::WindowText, QColor(0, 0, 0));
    bottom_label = new QLabel();
    bottom_label->setGeometry(0,0,420,385);
    bottom_label->setStyleSheet("background-color: #fdf5e6");
    bottom_label->setParent(this);
    all_layout = new QVBoxLayout;//for main layout
    QHBoxLayout *temp1 = new QHBoxLayout;
    quick_save_label = new QLabel();
    quick_save_mode = new QPushButton("一键模式");
    quick_save_label->setPixmap(switch_off);
    quick_save_label->setScaledContents(true);
    quick_save_label->setFixedSize(90,50);
    temp1->addWidget(quick_save_label,0,Qt::AlignRight);
    temp1->setSpacing(0);
    temp1->setMargin(0);
    quick_save_mode->setLayout(temp1);
    quick_save_mode->setPalette(text_palette);
    quick_save_mode->setFixedHeight(96);
    quick_save_mode->setFlat(true);
    quick_save_mode->setStyleSheet("border: 0.5px solid white");
    QHBoxLayout *temp2 = new QHBoxLayout;
    limited_label = new QLabel();
    limited_label->setPixmap(switch_off);
    limited_label->setScaledContents(true);
    limited_label->setFixedSize(90,50);
    temp2->addWidget(limited_label,0,Qt::AlignRight);
    temp2->setSpacing(0);
    temp2->setMargin(0);
    limited_mode = new QPushButton("极限省电模式");
    limited_mode->setPalette(text_palette);
    limited_mode->setFixedHeight(96);
    limited_mode->setFlat(true);
    limited_mode->setStyleSheet("border: 0.5px solid white");
    limited_mode->setLayout(temp2);
    QHBoxLayout *temp3 = new QHBoxLayout;
    locked_label = new QLabel();
    locked_label->setPixmap(switch_off);
    locked_label->setScaledContents(true);
    locked_label->setFixedSize(90,50);
    temp3->addWidget(locked_label,0,Qt::AlignRight);
    temp3->setSpacing(0);
    temp3->setMargin(0);
    locked_mode = new QPushButton("锁屏模式");
    locked_mode->setPalette(text_palette);
    locked_mode->setFixedHeight(96);
    locked_mode->setFlat(true);
    locked_mode->setStyleSheet("border: 0.5px solid white");
    locked_mode->setLayout(temp3);
    QHBoxLayout *temp4 = new QHBoxLayout;
    personal_label = new QLabel();
    personal_label->setPixmap(switch_off);
    personal_label->setScaledContents(true);
    personal_label->setFixedSize(90,50);
    temp4->addWidget(personal_label,0,Qt::AlignRight);
    temp4->setSpacing(0);
    temp4->setMargin(0);
    personal_mode = new QPushButton("个性化模式");
    personal_mode->setPalette(text_palette);
    personal_mode->setFixedHeight(96);
    personal_mode->setFlat(true);
    personal_mode->setStyleSheet("border: 0.5px solid white");
    personal_mode->setLayout(temp4);
    all_layout->addWidget(quick_save_mode);
    all_layout->addWidget(limited_mode);
    all_layout->addWidget(locked_mode);
    all_layout->addWidget(personal_mode);
    all_layout->setSpacing(0);
    all_layout->setMargin(0);
    connect(quick_save_mode,SIGNAL(clicked()),this,SLOT(quick_change_state()));
    connect(limited_mode,SIGNAL(clicked()),this,SLOT(limited_change_state()));
    connect(locked_mode,SIGNAL(clicked()),this,SLOT(locked_change_state()));
    connect(personal_mode,SIGNAL(clicked()),this,SIGNAL(turn_second_menu()));//cancel action connect to second page
    setLayout(all_layout);
}

Foot_Widget::~Foot_Widget()
{

}
void Foot_Widget::quick_change_state()
{
    quick_time++;
    if(mutex == true && (quick_time%2 == 1)){
        QPixmap switch_on("://foot/switch/on1");
        set_animation();
        quick_save_label->clearMask();
        quick_save_label->setPixmap(switch_on);
        mutex = false;
    }
    if(mutex == false && (quick_time%2 == 0)){
         QPixmap switch_off("://foot/switch/off1");
        set_animation();
        quick_save_label->clearMask();
        quick_save_label->setPixmap(switch_off);
        mutex =  true;
    }
}
void Foot_Widget::limited_change_state()
{
    limit_time++;
    if(mutex == true && (limit_time%2 == 1)){
        QPixmap switch_on("://foot/switch/on1");
        set_animation();
        limited_label->clearMask();
        limited_label->setPixmap(switch_on);
        mutex = false;
    }
    if(mutex == false && (limit_time%2 == 0)){
         QPixmap switch_off("://foot/switch/off1");
        set_animation();
        limited_label->clearMask();
        limited_label->setPixmap(switch_off);
        mutex =  true;
    }
}
void Foot_Widget::locked_change_state()
{
    lock_time++;
    if(mutex == true && (lock_time%2 == 1)){
        QPixmap switch_on("://foot/switch/on1");
        set_animation();
        locked_label->clearMask();
        locked_label->setPixmap(switch_on);
        mutex = false;
    }
    if(mutex == false && (lock_time%2 == 0)){
         QPixmap switch_off("://foot/switch/off1");
        set_animation();
        locked_label->clearMask();
        locked_label->setPixmap(switch_off);
        mutex =  true;
    }
}
//set animation
void Foot_Widget::set_animation()
{
    qDebug() << "set animation";
}
