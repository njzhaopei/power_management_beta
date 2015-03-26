#ifndef PERSONALSAVEMODE_H
#define PERSONALSAVEMODE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QMessageBox>
class personalsavemode : public QWidget
{
    Q_OBJECT
public:
    explicit personalsavemode(QWidget *parent = 0);
    ~personalsavemode();

signals:
    void turn_first_menu();
public slots:
     void show_tip();
private:
    QWidget *top_widget;
    QWidget *center_widget;
    QWidget *foot_widget;
    QVBoxLayout *top_layout;
    QHBoxLayout *foot_layout;
    QVBoxLayout *total_layout;
    QPushButton *return_icon;
    QPushButton *cancel_action;
    QPushButton *apply_action;

};

#endif // PERSONALSAVEMODE_H
