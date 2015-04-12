#ifndef AUTHENTICATE_H
#define AUTHENTICATE_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
class authenticate : public QWidget
{
    Q_OBJECT
public:
    explicit authenticate(QWidget *parent = 0);
    ~authenticate();
public:
    QLabel *authen_tittle;
    QLabel *authen_passwd;
    QLineEdit *passwd_edit;
    QPushButton *apply_button;
    QPushButton *cancel_button;
    QHBoxLayout *passwd_layout;
    QHBoxLayout *action_layout;
    QVBoxLayout *main_layout;
    QWidget *m_widget;
    QWidget *f_widget;
    QWidget *t_widget;
    //QPushButton *close_authen;

signals:
    void passwd_ready();
public slots:


};

#endif // AUTHENTICATE_H
