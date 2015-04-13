#include "personalsavemode.h"

personalsavemode::personalsavemode(QWidget *parent) : QWidget(parent)
{
    QPalette text_palette = palette();
    lcd_temp = 0;
    cpu_temp = 0;
    text_palette.setColor(QPalette::WindowText, QColor(0, 0, 0));
    top_widget = new QWidget();
    top_widget->setAttribute(Qt::WA_DeleteOnClose);
    top_widget->setFixedSize(420,40);
    top_layout = new QVBoxLayout;
    return_icon = new QPushButton();//second menu to return to first menu
    QPixmap return_pic(":/secondmenu/tittle/return.ico");
    return_icon->setIcon(return_pic);
    return_icon->setIconSize(QSize(35, 38));
    return_icon->setFixedSize(35,38);
    return_icon->setFlat(true);
    common = new QLabel("常用设置");
    top_layout->addWidget(return_icon,0,Qt::AlignLeft | Qt::AlignTop);
    top_layout->addWidget(common,0,Qt::AlignCenter);

    center_label = new QLabel();
    center_label->setStyleSheet("background-color: #fdf5e6");
    //top_layout->addStretch();
    top_layout->setMargin(0);
    top_layout->setSpacing(0);
    top_widget->setLayout(top_layout);
    center_widget = new QWidget();//for setting ways
    center_widget->setAttribute(Qt::WA_DeleteOnClose);
    center_widget->setFixedSize(420,555);
    center_label->setParent(center_widget);
    QHBoxLayout *lcd_temp = new QHBoxLayout;
    lcd_brightness = new QPushButton("屏幕亮度");
    QFont font = lcd_brightness->font();
    high_light = new QCheckBox("高亮");
    middle_light = new QCheckBox("中亮");
    low_light = new QCheckBox("低亮");
    font.setPointSize(16);
    lcd_brightness->setFont(font);
    //lcd_brightness->setPalette(text_palette);
    //lcd_brightness->setFont(QFont("黑体",0,80,false));
    lcd_brightness->setFixedHeight(111);
    lcd_brightness->setFixedWidth(400);
    lcd_brightness->setFlat(true);
    lcd_label = new QLabel("未开启>");
    lcd_temp->setMargin(0);
    lcd_temp->setSpacing(0);
    lcd_brightness->setLayout(lcd_temp);
    QHBoxLayout *wifi_temp = new QHBoxLayout;
    wifi_control = new QPushButton("wifi");
    wifi_control->setFont(font);
    wifi_control->setFixedHeight(111);
    wifi_control->setFixedWidth(400);
    wifi_control->setFlat(true);
    wifi_label = new QLabel("未开启>");
    wifi_label->setPalette(text_palette);
    wifi_label->setFont(QFont("黑体",0,80,true));
    wifi_temp->addWidget(wifi_label,0,Qt::AlignRight);
    wifi_temp->setSpacing(0);
    wifi_temp->setMargin(0);
    wifi_control->setLayout(wifi_temp);
    QHBoxLayout *blue_temp = new QHBoxLayout;
    bluetooth_control = new QPushButton("蓝牙");
    bluetooth_control->setFont(font);
//    bluetooth_control->setPalette(text_palette);
//    bluetooth_control->setFont(QFont("黑体",0,80,false));
    bluetooth_control->setFixedHeight(111);
    bluetooth_control->setFixedWidth(400);
    bluetooth_control->setFlat(true);
    bluetooth_label = new QLabel("未开启>");
    bluetooth_label->setPalette(text_palette);
    bluetooth_label->setFont(QFont("黑体",0,80,true));
    blue_temp->addWidget(bluetooth_label,0,Qt::AlignRight);
    blue_temp->setSpacing(0);
    blue_temp->setMargin(0);
    bluetooth_control->setLayout(blue_temp);
    QHBoxLayout *cpu_temp = new QHBoxLayout;
   // QVBoxLayout *cpu_temp1 = new QVBoxLayout;
    cpu_frequency_control = new QPushButton("cpu频率控制");
    cpu_frequency_control->setFont(font);
//    cpu_frequency_control->setPalette(text_palette);
//    cpu_frequency_control->setFont(QFont("黑体",0,80,false));
    cpu_frequency_control->setFixedHeight(111);//normal size 111, 221px
    cpu_frequency_control->setFixedWidth(400);
    performance_check = new QCheckBox("性能模式频率");
    performance_check->setFixedHeight(55);
    self_defined_check = new QCheckBox("自定义模式频率");
    self_defined_check->setFixedHeight(55);
    saving_check = new QCheckBox("节能模式频率");
    saving_check->setFixedHeight(55);
    cpu_frequency_control->setFlat(true);
    cpu_frequency_label = new QLabel("未扩展>");
    cpu_frequency_label->setFont(QFont("黑体",0,80,true));
    cpu_frequency_label->setPalette(text_palette);
    cpu_temp->addWidget(cpu_frequency_label,0,Qt::AlignRight);
    cpu_temp->setSpacing(0);
    cpu_temp->setMargin(0);
//    cpu_temp1->addLayout(cpu_temp);
//    cpu_temp1->addWidget(performance_check);
//    cpu_temp1->addWidget(saving_check);
    cpu_frequency_control->setLayout(cpu_temp);
    QHBoxLayout *back_temp = new QHBoxLayout;
    back_process_control = new QPushButton("后台进程");
    back_process_control->setFont(font);
//    back_process_control->setPalette(text_palette);
//    back_process_control->setFont(QFont("黑体",0,100,false));
    back_process_control->setFixedHeight(111);
    back_process_control->setFixedWidth(400);
    back_process_control->setFlat(true);
    back_process_label = new QLabel("未扩展>");
    back_process_label->setFont(QFont("黑体",0,80,true));
    back_process_label->setPalette(text_palette);
    back_temp->addWidget(back_process_label,0,Qt::AlignRight);
    back_temp->setSpacing(0);
    back_temp->setMargin(0);
    back_process_control->setLayout(back_temp);
    scrollArea = new QScrollArea(center_widget);
//    scrollArea->setAlignment(Qt::AlignLeft);
//    scrollArea->setParent(center_widget);
    scrollArea->setFixedSize(420,555);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    center_layout = new QVBoxLayout;
    center_layout->addWidget(lcd_brightness);
    center_layout->addWidget(high_light,0,Qt::AlignCenter);
    center_layout->addWidget(middle_light,0,Qt::AlignCenter);
    center_layout->addWidget(low_light,0,Qt::AlignCenter);
    center_layout->addWidget(wifi_control);
    center_layout->addWidget(bluetooth_control);
    center_layout->addWidget(cpu_frequency_control);
    center_layout->addWidget(performance_check,0,Qt::AlignCenter);
    center_layout->addWidget(self_defined_check,0,Qt::AlignCenter);
    center_layout->addWidget(saving_check,0,Qt::AlignCenter);
    center_layout->addWidget(back_process_control);
    center_layout->setSpacing(0);
    center_layout->setMargin(0);
    center_widget->setLayout(center_layout);
    scrollArea->setWidget(center_label);
    foot_widget = new QWidget();
    foot_widget->setAttribute(Qt::WA_DeleteOnClose);
    foot_widget->setFixedSize(420,50);
    cancel_action = new QPushButton("取消");
    cancel_action->setFlat(true);
    apply_action = new QPushButton("应用");
    apply_action->setFlat(true);
    foot_layout = new QHBoxLayout;
    foot_layout->addStretch(1);
    foot_layout->addWidget(cancel_action);
    foot_layout->addStretch(1);
    foot_layout->addWidget(apply_action);
    foot_layout->addStretch(1);
    foot_layout->setMargin(0);
    foot_widget->setLayout(foot_layout);
    total_layout = new QVBoxLayout;
    total_layout->addWidget(top_widget);
    total_layout->addWidget(center_widget);
    total_layout->addWidget(foot_widget);
    total_layout->setMargin(0);
    total_layout->setSpacing(0);
    performance_check->hide();
    saving_check->hide();
    self_defined_check->hide();
    high_light->hide();
    middle_light->hide();
    low_light->hide();
    total_label = new QLabel();
    connect(self_defined_check,SIGNAL(clicked()),this,SLOT(checkchange()));
    connect(performance_check,SIGNAL(clicked()),this,SLOT(checkchange()));
    connect(saving_check,SIGNAL(clicked()),this,SLOT(checkchange()));
    connect(high_light,SIGNAL(clicked()),this,SLOT(checkchange()));
    connect(middle_light,SIGNAL(clicked()),this,SLOT(checkchange()));
    connect(low_light,SIGNAL(clicked()),this,SLOT(checkchange()));
    connect(cancel_action,SIGNAL(clicked()),this,SIGNAL(turn_first_menu()));
    connect(return_icon,SIGNAL(clicked()),this,SIGNAL(turn_first_menu()));
    connect(apply_action,SIGNAL(clicked()),this,SLOT(apply_app()));
    connect(lcd_brightness,SIGNAL(clicked()),this,SLOT(lcd_control_handler()));
    connect(cpu_frequency_control,SIGNAL(clicked()),this,SLOT(cpu_control_handler()));
    total_label->setStyleSheet("background-color: #fdf5e6");
    total_label->setParent(this);
    setLayout(total_layout);

}

personalsavemode::~personalsavemode()
{

}

void personalsavemode::show_tip(){
    QMessageBox::information(0,"确定应用","你确定要应用节电选项吗？Ok");
}
void personalsavemode::cpu_control_handler()
{
    cpu_temp ++;
    if(cpu_temp%2 == 1){
        cpu_frequency_label->clearMask();
        cpu_frequency_label->setText("扩展>");
        show_checkbox();
    }
    if(cpu_temp%2 == 0){
        cpu_frequency_label->clearMask();
        cpu_frequency_label->setText("未扩展>");
        hide_checkbox();
    }
}
void personalsavemode::show_checkbox()
{
    performance_check->show();
    saving_check->show();
    self_defined_check->show();

}
void personalsavemode::hide_checkbox()
{
    performance_check->hide();
    saving_check->hide();
    self_defined_check->hide();
}
void personalsavemode::lcd_control_handler()
{
    lcd_temp++;
    if(lcd_temp%2 == 1){
        lcd_label->clearMask();
        lcd_label->setText("展开");
        show_spinbox();
    }
    if(lcd_temp%2 == 0){
       lcd_label->clearMask();
       lcd_label->setText("未展开");
       hide_spinbox();
    }
}
void personalsavemode::show_spinbox()
{
    high_light->show();
    middle_light->show();
    low_light->show();
}
void personalsavemode::hide_spinbox()
{
    high_light->hide();
    middle_light->hide();
    low_light->hide();
}
void personalsavemode::apply_app()
{
    show_tip();
    qDebug() << "send perosnal sig" << lcd_brightness_status << cpu_frequency_status;
    emit personal_sig_send(lcd_brightness_status,cpu_frequency_status);
    //QString info = "bash -c \"echo \""+authen->passwd_edit->text()+"\"| sudo -S bash ./settings/quick_mode.sh";
    //get_setting_status->start("bash ./settings/battery_state.sh "+lcd_brightness_status+" "+cpu_frequency_status+"");
    //QMessageBox::information(0,"确定应用","应用成功");
}
void personalsavemode::checkchange()
{
    if (sender() == performance_check)
        {
            performance_check->setChecked(true);
            self_defined_check->setChecked(false);
            saving_check->setChecked(false);
            cpu_frequency_status = "cpuperformance";
        }
    if (sender() == self_defined_check)
        {
            self_defined_check->setChecked(true);
            performance_check->setChecked(false);
            saving_check->setChecked(false);
            cpu_frequency_status = "cpuselfdefined";
        }
    if (sender() == saving_check)
        {
            saving_check->setChecked(true);
            performance_check->setChecked(false);
            self_defined_check->setChecked(false);
            cpu_frequency_status = "cpupowersave";
        }
    if (sender() == high_light)
        {
            high_light->setChecked(true);
            middle_light->setChecked(false);
            low_light->setChecked(false);
            lcd_brightness_status = "high";
        }
    if (sender() == middle_light)
        {
            middle_light->setChecked(true);
            high_light->setChecked(false);
            low_light->setChecked(false);
            lcd_brightness_status = "middle";
        }
    if (sender() == low_light)
        {
            low_light->setChecked(true);
            high_light->setChecked(false);
            middle_light->setChecked(false);
            lcd_brightness_status = "low";
        }
}
