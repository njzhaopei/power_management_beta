#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDesktopWidget"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->setFixedSize(420,680);
    //this->setFixedSize(900,500);
    this->setWindowIcon(QIcon(":/app/syslogo/battery"));
//    menu = new QMenu(this);
    createActions();
    create_trayiconMenu();
    mytrayIcon = new QSystemTrayIcon(this);
    mytrayIcon->setIcon(QIcon(":/app/syslogo/battery"));
    mytrayIcon->show();
    mytrayIcon->setToolTip("We will help you save the power");
    mytrayIcon->showMessage("Tray","Tray Manager",QSystemTrayIcon::Information,10000);
    mytrayIcon->setContextMenu(trayiconMenu);
    widget = new QWidget () ;
    tittle = new Tittle_Widget();
    QWidget *tempwidget = new QWidget();
    personalwidget = new personalsavemode();
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
    connect(tittle,SIGNAL(show_close()),this,SLOT(hide()));//close all widgets
    connect(foot,SIGNAL(turn_second_menu()),this,SLOT(turn_second_page()));
    connect(personalwidget,SIGNAL(turn_first_menu()),this,SLOT(turn_main_page()));
    connect(tittle,SIGNAL(show_min()),this,SLOT(showmin()));
    connect(tittle,SIGNAL(showMax()),this,SLOT(showMaximized()));
    connect(tittle,SIGNAL(showNor()),this,SLOT(showNormal()));
    connect(action_show,SIGNAL(triggered()),this,SLOT(showNormal()));
    connect(action_quit,SIGNAL(triggered()),this,SLOT(closeAll()));
    connect(action_minimize,SIGNAL(triggered()),this,SLOT(showMinimized()));
    //activate app
    connect(mytrayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(iconIsActived(QSystemTrayIcon::ActivationReason)));
    widget->setLayout(main_layout);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::turn_second_page()
{
    stack->setCurrentIndex(1);
}
void MainWindow::turn_main_page()
{
    qDebug() << "clicked";
    stack->setCurrentIndex(0);
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_DragPosition = event->globalPos() - this->pos();
        event->accept();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() && Qt::LeftButton) {
        move(event->globalPos() - m_DragPosition);
        event->accept();
    }
}
void MainWindow::createActions()
{
    //create tray items
    action_show = new QAction(this);
    action_quit = new QAction(this);
    action_help = new QAction(this);
    action_minimize = new QAction(this);
    //set text content
    action_show->setText("恢复");
    action_quit->setText("退出");
    action_help->setText("帮助");
    action_minimize->setText("最小化");


}
void MainWindow::iconIsActived(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason)
    {
        //点击托盘图标之后松开
    case QSystemTrayIcon::Trigger:
        {
            //show_widget();

            break;
        }
        //双击托盘图标
    case QSystemTrayIcon::DoubleClick:
        {
            //show_widget();
        //showNormal();

            break;
        }
    default:
        break;
    }
}
void MainWindow::showmin()
{
    qDebug() << "show min" ;\
    showMinimized();
}

void MainWindow::show_widget()
{

    this->showNormal();
    this->raise();
    this->activateWindow();
}
//点击最小化按钮隐藏界面
void MainWindow::changeEvent(QEvent *e)
{
if((e->type()==QEvent::WindowStateChange)&&this->isMinimized())
{
//    QTimer::singleShot(100, this, SLOT(hide()));
  this->hide();
}
}
//create menu
void MainWindow::create_trayiconMenu()
{
    trayiconMenu = new QMenu(this);
    trayiconMenu->setStyleSheet("background-color: #ec6a95;");
    trayiconMenu->addAction(action_show);
    trayiconMenu->addSeparator();
    trayiconMenu->addAction(action_help);
    trayiconMenu->addSeparator();
    trayiconMenu->addAction(action_minimize);
    trayiconMenu->addSeparator();
    trayiconMenu->addAction(action_quit);
    trayiconMenu->addSeparator();
}

void MainWindow::closeAll()
{
    delete tittle;
    delete center;
    delete foot;
    this->close();
    mytrayIcon->hide();
}
//close to systemtrayicon
void MainWindow::closeEvent(QCloseEvent *e)
{
    if((e->type()==QEvent::WindowStateChange)&&this->close())
    {
        this->hide();
    }
}
