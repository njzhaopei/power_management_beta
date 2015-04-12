#include "authenticate.h"

authenticate::authenticate(QWidget *parent) : QWidget(parent)
{
        QPixmap close_pic(":/title/button/close.png");
        t_widget = new QWidget();
        QHBoxLayout *t_layout = new QHBoxLayout;
        QPushButton *close_authen = new QPushButton("");
        close_authen->setIcon(close_pic);
        close_authen->setIconSize(close_pic.size());
        close_authen->setFixedSize(close_pic.width()+2,close_pic.height()+2);
        close_authen->setFlat(true);
        close_authen->setFixedSize(30,30);
        t_layout->addWidget(close_authen,0,Qt::AlignRight);
        t_layout->setSpacing(0);
        t_layout->setMargin(0);
        t_widget->setLayout(t_layout);
        t_widget->setFixedSize(400,40);

        m_widget = new QWidget();
        m_widget->setAttribute(Qt::WA_DeleteOnClose);
        f_widget = new QWidget();

        authen_tittle = new QLabel("验证");
        authen_tittle->setFixedHeight(50);
        authen_passwd = new QLabel("登录密码");
        apply_button = new QPushButton("确定");
        cancel_button = new QPushButton("取消");
        passwd_edit = new QLineEdit();
        passwd_edit->setEchoMode(QLineEdit::Password);
        passwd_layout = new QHBoxLayout;
        action_layout = new QHBoxLayout;
        passwd_layout->addWidget(authen_passwd);
        passwd_layout->addWidget(passwd_edit);

        m_widget->setLayout(passwd_layout);
        m_widget->setFixedSize(400,55);
        action_layout->addWidget(apply_button);
        action_layout->addWidget(cancel_button);

        f_widget->setLayout(action_layout);
        f_widget->setFixedSize(400,55);
        main_layout = new QVBoxLayout;
        main_layout->addWidget(t_widget);
        main_layout->addWidget(authen_tittle,0,Qt::AlignCenter);
        main_layout->addWidget(m_widget);
        main_layout->addWidget(f_widget);
        main_layout->setSpacing(0);
        main_layout->setMargin(0);
        setLayout(main_layout);
        connect(apply_button,SIGNAL(clicked()),this,SIGNAL(passwd_ready()));
        setFixedSize(400,200);
        setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
}

authenticate::~authenticate()
{

}

