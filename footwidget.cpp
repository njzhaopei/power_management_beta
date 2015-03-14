#include "footwidget.h"

Foot_Widget::Foot_Widget(QWidget *parent) : QWidget(parent)
{
    setFixedSize(420,385);
    QPalette text_palette = palette();
    text_palette.setColor(QPalette::WindowText, QColor(0, 0, 0));
    bottom_label = new QLabel();
    bottom_label->setGeometry(0,0,420,385);
    bottom_label->setStyleSheet("background-color: #fdf5e6");
    bottom_label->setParent(this);
    all_layout = new QVBoxLayout();//for main layout
    quick_save_mode = new QPushButton("一键模式");
    quick_save_mode->setPalette(text_palette);
    quick_save_mode->setFixedHeight(96);
    quick_save_mode->setFlat(true);
    quick_save_mode->setStyleSheet("border: 1px dashed black");
    limited_mode = new QPushButton("极限省电模式");
    limited_mode->setPalette(text_palette);
    limited_mode->setFixedHeight(96);
    limited_mode->setFlat(true);
    limited_mode->setStyleSheet("border: 1px dashed black");
    locked_mode = new QPushButton("锁屏模式");
    limited_mode->setPalette(text_palette);
    locked_mode->setFixedHeight(96);
    locked_mode->setFlat(true);
    locked_mode->setStyleSheet("border: 1px dashed black");
    personal_mode = new QPushButton("个性化模式");
    limited_mode->setPalette(text_palette);
    personal_mode->setFixedHeight(96);
    personal_mode->setFlat(true);
    personal_mode->setStyleSheet("border: 1px dashed black");
    all_layout->addWidget(quick_save_mode);
    all_layout->addWidget(limited_mode);
    all_layout->addWidget(locked_mode);
    all_layout->addWidget(personal_mode);
    all_layout->setSpacing(0);
    all_layout->setMargin(0);
    connect(personal_mode,SIGNAL(clicked()),this,SIGNAL(turn_second_menu()));
    setLayout(all_layout);
}

Foot_Widget::~Foot_Widget()
{

}

