#include "tittlewidget.h"
#include <QLayout>
#include "QDesktopWidget"
#include "QApplication"
Tittle_Widget::Tittle_Widget(QWidget *parent) :
    QWidget(parent)
{
    id = 0;
    QDesktopWidget  *d=QApplication::desktop();

    current_skin = 4;
    skin_list<<"background-color:#fffafa"<<"background-color:#dc143c"<<"background-color:#ff8c00"<<"background-color:#ffd700"<<"background-color:#3cb371"<<"background-color:#483d8b"<<"background-color:#800000"<<"background-color:#4b0082"<<"background-color:#000000";

    QPalette text_palette = palette();
    text_palette.setColor(QPalette::WindowText, QColor(255, 255, 255));

    top_label = new QLabel();
    top_label->setGeometry(0,0,d->width(),35);
    top_label->setStyleSheet(DEFAULT_SKIN);
    top_label->setParent(this);

    version = new QLabel(" Power Manager 1.0");  //version info
    version->setPalette(text_palette);
    version->setFont(QFont("黑体",10,99,true));

    /*set button for close and minisized the main_widget*/
    btclose = new QPushButton();
    QPixmap close_pic(":/title/button/close.png");
    btclose->setIcon(close_pic);
    btclose->setIconSize(close_pic.size());
    btclose->setFixedSize(close_pic.width()+2,close_pic.height()+2);
    btclose->setFlat(true);

    btmin = new QPushButton();
    QPixmap min_pic(":/title/button/min.png");
    btmin->setIcon(min_pic);
    btmin->setIconSize(min_pic.size());
    btmin->setFixedSize(min_pic.width()+2,min_pic.height()+2);
    btmin->setFlat(true);

    btmax = new QPushButton();
    QPixmap max_pic(":/title/button/max.png");
    btmax->setIcon(max_pic);
    btmax->setIconSize(max_pic.size());
    btmax->setFixedSize(max_pic.width()+2,max_pic.height()+2);
    btmax->setFlat(true);

    btskin = new QPushButton();
    QPixmap skin_pic(":/title/button/skin.png");
    btskin->setIcon(skin_pic);
    btskin->setIconSize(skin_pic.size());
    btskin->setFixedSize(skin_pic.width()+4,skin_pic.height()+4);
    btskin->setFlat(true);

    QHBoxLayout *main_layout = new QHBoxLayout();
    main_layout->addWidget(version,0,Qt::AlignTop);
    main_layout->addStretch();
    main_layout->addWidget(btskin,0,Qt::AlignTop);
//    main_layout->addWidget(btmax,0,Qt::AlignTop);
    main_layout->addWidget(btmin,0,Qt::AlignTop);
    main_layout->addWidget(btclose,0,Qt::AlignTop);

    version->setContentsMargins(0,0,0,0);
    main_layout->setSpacing(0);
    main_layout->setContentsMargins(0,0,3,0);

    connect(btclose,SIGNAL(clicked()),this,SIGNAL(show_close()));
    connect(btmin, SIGNAL(clicked()),this,SIGNAL(show_min()));
    connect(btskin,SIGNAL(clicked()),this,SLOT(change_skin()));


//    QHBoxLayout *logo_layout = new QHBoxLayout();
//    product_name = new QLabel("Shine The Night");  //this label doesn't matter now
//    product_name->setPalette(text_palette);
//    product_name->setFont(QFont(URW_C_FONT,16,QFont::Bold,true));
//    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect();
//    effect->setOffset(8,8);
//    product_name->setGraphicsEffect(effect);

    //实例 QGraphicsOpacityEffect
//    QGraphicsOpacityEffect *o_effect = new QGraphicsOpacityEffect();
//    //设定透明值
//    o_effect->setOpacity(0.5);

//    logo = new QLabel();
//    QPixmap logo_pic(":/picture/button_pic/start");
//    logo->setPixmap(logo_pic.scaled(70,70));
//    logo->setGraphicsEffect(o_effect);

//    logo_layout->addWidget(logo);
//    logo_layout->addWidget(product_name);
//    logo_layout->addStretch();
//    logo_layout->setSpacing(0);
//    logo_layout->setContentsMargins(0,0,5,0);

//    button_layout->addStretch();
//    button_layout->addLayout(logo_layout);
//    button_layout->setSpacing(8);
//    button_layout->setContentsMargins(15, 0, 15, 0);

    QVBoxLayout *all_layout = new QVBoxLayout();

    all_layout->addLayout(main_layout);
//    all_layout->addLayout(button_layout);
    setLayout(all_layout);
    setFixedHeight(35);

     is_move = false;
//      this->setStyleSheet("border:1px solid balck; background-color:blue");

}
Tittle_Widget::~Tittle_Widget()
{

}


void Tittle_Widget::change_skin()
{
    if(current_skin < skin_list.size()-1)
    {
        current_skin++;
    }
    else{
        current_skin = 0;
    }
    top_label->setStyleSheet(skin_list.at(current_skin));
 //   top_label->setStyleSheet("background-color:#000000");
    int current = current_skin;
    emit change_skin(current);
    qDebug() << current_skin+"skin";
}

void Tittle_Widget::mouseDoubleClickEvent(QMouseEvent *)
{
    id++;
    if(id%2 == 1){
    emit showMax();
        qDebug() << "show max";
    }
    else{
        emit showNor();
        qDebug() << "show normal";
    }
}
