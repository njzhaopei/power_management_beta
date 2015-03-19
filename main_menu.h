#ifndef MAIN_MENU_H
#define MAIN_MENU_H


#include <QObject>
#include <QMenu>
#include <QLabel>
#include <QLayout>
#include <QAction>
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QWidgetAction>


class Main_Menu : public QMenu
{
    Q_OBJECT
public:
    explicit Main_Menu(QWidget *parent = 0);

signals:
    void show_widget();
    void hide_widget();
    void show_min();
    void close_widget();


public slots:

private:
    void createActions();

private:
    QAction *exit;
    QAction *restore;
    QAction *hide;
    QAction *min;
    QWidgetAction *myWidgetActiontop;
    QWidgetAction *myWidgetActionbto;

    QWidget *myWidgettop;
    QWidget *myWidgetbto;
    QVBoxLayout *mylayouttop;
    QVBoxLayout *mylayoutbto;

};

#endif // MAIN_MENU_H
