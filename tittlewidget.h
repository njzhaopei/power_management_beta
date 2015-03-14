#ifndef TITLEWIDGET
#define TITLEWIDGET
#include <QWidget>
#include <QPushButton>
#include <QLayout>
#include <QLabel>
#include <QSignalMapper>
#include <QDebug>
#include <QGraphicsOpacityEffect>
#include <common.h>

class Tittle_Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Tittle_Widget(QWidget *parent = 0);
    ~Tittle_Widget();

signals:
    void show_close();
    void show_min();
    void showMax();
    void showNor();
    void change_skin(int current);


private:
    QPoint press_point;//鼠标按下去的点
    bool is_move;
    QPushButton *btclose;
    QPushButton *btmin;
    QPushButton *btskin;
    QPushButton *btmax;
    QLabel *top_label;
    QLabel *top_label_pre;

    void mouseDoubleClickEvent(QMouseEvent *);
    QLabel *version;
    QLabel *logo;
    QLabel *product_name;
    QStringList skin_list;
    int current_skin;
    int id;
public slots:
    void change_skin();
};
#endif // TITLEWIDGET

