#ifndef FOOTWIDGET_H
#define FOOTWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QSplitter>
class Foot_Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Foot_Widget(QWidget *parent = 0);
    ~Foot_Widget();

signals:
    void turn_second_menu();
public slots:

private:
    QLabel *bottom_label;
    QVBoxLayout *all_layout;
    QPushButton *quick_save_mode;
    QLabel *quick_save_label;
    QPushButton *limited_mode;
    QLabel *limited_label;
    QPushButton *locked_mode;
    QLabel *locked_label;
    QPushButton *personal_mode;
    QLabel *personal_label;

};

#endif // FOOTWIDGET_H
