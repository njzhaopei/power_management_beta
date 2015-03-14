#ifndef MAINWIDGET
#define MAIN_WIDGET
#include <QWidget>
#include <QLabel>
#include "common.h"
#include "QLabel"
#include  "QVBoxLayout"
class Main_Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Main_Widget(QWidget *parent = 0);
    ~Main_Widget();
private:
    QLabel *main_label;
    QLabel *battery_label;//for battery pic
    QLabel *remain_battery; // left battery tip
    QLabel *remain_battery_value;//left battery
    QWidget *left_widget;// left widget
    QWidget *right_widget;// right widget
    QLabel *remain_time;
    QLabel *remain_time_value;
    QVBoxLayout *right_layout;
    QHBoxLayout *main_layout;
};

#endif // MAINWIDGET
