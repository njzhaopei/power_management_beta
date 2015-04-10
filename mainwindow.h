#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tittlewidget.h"
#include "footwidget.h"
#include "mainwidget.h"
#include "personalsavemode.h"
#include <QVBoxLayout>
#include <QStackedWidget>
#include <footwidget.h>
#include <QMouseEvent>
#include <QAction>
#include <QSystemTrayIcon>
#include "main_menu.h"
#include "authenticate.h"
#include <QProcess>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent*);
    void changeEvent(QEvent *e);
    void closeEvent(QCloseEvent *e);
    void create_trayiconMenu();
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    QProcess *process;
    QProcess *recovery_process;
    Tittle_Widget *tittle;
    QVBoxLayout *main_layout;
    QVBoxLayout *temp_layout;//for center widget && foot widget
    Main_Widget *center;
    Foot_Widget *foot;
    QWidget *personalwidget;
    QStackedWidget *stack;
    QPoint m_DragPosition;
    void createActions();
    void show_widget();
    QAction *action_show;
    QAction *action_quit;
    QAction *action_help;
    QAction *action_minimize;
    QSystemTrayIcon *mytrayIcon;
    Main_Menu *menu;
    QMenu *trayiconMenu;
    QWidget *widget;
    authenticate *authen;
    int state;
private slots:
    void turn_second_page();
    void turn_main_page();
    void iconIsActived(QSystemTrayIcon::ActivationReason reason);
    void showmin();
    void closeAll();
    void quick_sig_handler();
    void limited_sig_handler();
    void locked_sig_handler();
    void do_handle();
    void recovery_state();
};

#endif // MAINWINDOW_H
