#include "authenticate.h"

authenticate::authenticate(QWidget *parent) : QWidget(parent)
{
        authen_tittle = new QLabel("验证");
        authen_passwd = new QLabel("登录密码");
        apply_button = new QPushButton("确定");
        cancel_button = new QPushButton("取消");
        passwd_edit = new QLineEdit();
        passwd_edit->setEchoMode(QLineEdit::Password);
        passwd_layout = new QHBoxLayout;
        action_layout = new QHBoxLayout;
        passwd_layout->addWidget(authen_passwd);
        passwd_layout->addWidget(passwd_edit);
        action_layout->addWidget(apply_button);
        action_layout->addWidget(cancel_button);
        main_layout = new QVBoxLayout;
        main_layout->addWidget(authen_tittle,0,Qt::AlignCenter | Qt::AlignTop);
        main_layout->addLayout(passwd_layout);
        main_layout->addLayout(action_layout);
        setLayout(main_layout);
        connect(apply_button,SIGNAL(clicked()),this,SIGNAL(passwd_ready()));
        setFixedSize(400,200);
}

authenticate::~authenticate()
{

}

