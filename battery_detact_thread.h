#ifndef BATTERY_DETACT_THREAD_H
#define BATTERY_DETACT_THREAD_H
#include <QThread>
#include <QTimer>
#include <QProcess>
//#include <worker.h>
#include <QDebug>
#include <QObject>
#include <QString>
class battery_detact_thread : public  QThread
{
    Q_OBJECT
public:
    explicit battery_detact_thread(QObject *parent = 0);

    QString state;
    QString totaltime;
    QString time_to_full;
    QString time_to_lack;
    QString percentage;
protected:
    void run();
signals:
    void refresh_widget_signal(QString,QString,QString);
private:
    QProcess *get_battery_time;
    QString temp_info;
    void parse_batterytime_info(QString);
    void set_battery_label();
    QTimer *t;

private slots:
    void onTimeout();
    void readOutput();
};

#endif // BATTERY_DETACT_THREAD_H
