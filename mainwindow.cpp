#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDesktopWidget"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->setFixedSize(420,680);
    //this->setFixedSize(900,500);
    QWidget * widget = new QWidget () ;
    tittle = new Tittle_Widget();
    QWidget *tempwidget = new QWidget();
    QWidget *personalwidget = new personalsavemode();
    stack = new QStackedWidget();
    temp_layout = new QVBoxLayout();
    center = new Main_Widget();
    foot = new Foot_Widget();
    main_layout = new QVBoxLayout();
//    main_layout->addWidget(tittle,0,Qt::AlignTop);
    temp_layout->addWidget(center);
    temp_layout->addWidget(foot);
    temp_layout->setMargin(0);
    temp_layout->setSpacing(0);
    tempwidget->setLayout(temp_layout);
    stack->addWidget(tempwidget);
    stack->addWidget(personalwidget);
    center->setStyleSheet("border:1px dashed black;");//for border
    main_layout->addWidget(tittle);
    main_layout->addWidget(stack);
//    tittle->setStyleSheet("border:1px dashed black;");
    main_layout->setMargin(0);
    main_layout->setSpacing(0);
//    this->setContentsMargins(0, 0, SHADOW_WIDTH, SHADOW_WIDTH);
    connect(tittle,SIGNAL(show_close()),this,SLOT(close()));//close all widgets
    connect(foot,SIGNAL(turn_second_menu()),this,SLOT(turnpage()));
    connect(tittle,SIGNAL(show_min()),this,SLOT(showMinimized()));
    connect(tittle,SIGNAL(showMax()),this,SLOT(showMaximized()));
    connect(tittle,SIGNAL(showNor()),this,SLOT(showNormal()));
    widget->setLayout(main_layout);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::turnpage()
{
    stack->setCurrentIndex(1);
}
