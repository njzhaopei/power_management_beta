#include "main_menu.h"

Main_Menu::Main_Menu(QWidget *parent) :
    QMenu(parent)
{
    this->createActions();

}


void Main_Menu::createActions()
{
    exit = new QAction(this);
    exit->setText("退出");
    restore = new QAction(this);
    restore->setText("恢复");
    hide = new QAction(this);
    hide->setText("隐藏");
    min = new QAction(this);
    min->setText("最小化");
 //   turnPage = new QAction (this);
//    feedback = new QAction(this);
    myWidgetActiontop = new QWidgetAction(this);
    myWidgetActionbto =new QWidgetAction(this);
    myWidgettop = new QWidget();
    myWidgetbto = new QWidget();

    QLabel *lab_top = new QLabel(myWidgettop);
    QLabel *lab_bto = new QLabel(myWidgetbto);
    mylayouttop = new QVBoxLayout();
    mylayoutbto = new QVBoxLayout();
    lab_top->setGeometry(0,0,200,300);
    lab_bto->setGeometry(0,0,200,300);

    lab_top->setStyleSheet("background-color:#27ae64");
    lab_bto->setStyleSheet("background-color:#27ae64");


    myWidgettop->setLayout(mylayouttop);
    myWidgetActiontop->setDefaultWidget(myWidgettop);
    myWidgetbto->setLayout(mylayoutbto);
    myWidgetActionbto->setDefaultWidget(myWidgetbto);




    this->addAction(myWidgetActiontop);
    this->addAction(restore);
    this->addSeparator();
    this->addAction(hide);
    this->addSeparator();
    this->addAction(min);
    this->addSeparator();
    this->addAction(exit);
    this->addAction(myWidgetActionbto);




    //恢复
    connect(restore,SIGNAL(triggered()),this,SIGNAL(show_widget()));
    //退出
    connect(exit,SIGNAL(triggered()),this,SIGNAL(close_widget()));
    //隐藏
    connect(hide,SIGNAL(triggered()),this,SIGNAL(hide_widget()));
    //最小化
    connect(min,SIGNAL(triggered()),this,SIGNAL(show_min()));

}

