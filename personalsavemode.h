#ifndef PERSONALSAVEMODE_H
#define PERSONALSAVEMODE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QLabel>
#include <QPalette>
#include <QScrollArea>
#include <QCheckBox>
#include <QProcess>
#include <QDebug>
class personalsavemode : public QWidget
{
    Q_OBJECT
public:
    explicit personalsavemode(QWidget *parent = 0);
    ~personalsavemode();
    void show_tip();

signals:
    void turn_first_menu();
    void personal_sig_send(QString,QString);
public slots:
     void cpu_control_handler();
     void lcd_control_handler();
     void show_checkbox();
     void hide_checkbox();
     void show_spinbox();
     void hide_spinbox();
     void apply_app();
     void checkchange();

private:
    QWidget *top_widget;
    QWidget *center_widget;
    QVBoxLayout *center_layout;
    QLabel *center_label;
    QWidget *foot_widget;
    QVBoxLayout *top_layout;
    QHBoxLayout *foot_layout;
    QVBoxLayout *total_layout;
    QPushButton *return_icon;
    QPushButton *cancel_action;
    QPushButton *apply_action;
    QLabel *common;
    QPushButton *lcd_brightness;
    QLabel *lcd_label;
    QPushButton *wifi_control;
    QLabel *wifi_label;
    QPushButton *bluetooth_control;
    QLabel *bluetooth_label;
    QPushButton *cpu_frequency_control;
    QLabel *cpu_frequency_label;
    QPushButton *back_process_control;
    QLabel *back_process_label;
    QLabel *total_label;
    QScrollArea *scrollArea;
    QCheckBox *performance_check;
    QCheckBox *self_defined_check;
    QCheckBox *saving_check;
    QCheckBox *high_light;
    QCheckBox *middle_light;
    QCheckBox *low_light;
    int cpu_temp;
    int lcd_temp;
    QString lcd_brightness_status;
    QString cpu_frequency_status;
    QProcess *get_setting_status;
};

#endif // PERSONALSAVEMODE_H
