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
    QPushButton *limited_mode;
    QPushButton *locked_mode;
    QPushButton *personal_mode;

};

#endif // FOOTWIDGET_H
