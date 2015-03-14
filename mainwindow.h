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
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Tittle_Widget *tittle;
    QVBoxLayout *main_layout;
    QVBoxLayout *temp_layout;//for center widget && foot widget
    Main_Widget *center;
    Foot_Widget *foot;
    QStackedWidget *stack;

private slots:
    void turnpage();
};

#endif // MAINWINDOW_H
