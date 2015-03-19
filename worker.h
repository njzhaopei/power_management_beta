#ifndef WORKER
#define WORKER
#include <QObject>
#include <QtCore>
#include <QProcess>
#include <QString>
#include <QThread>
#include <QStringList>
class worker : public QObject
{
    Q_OBJECT
public:
    worker();
    ~worker();
    QString state;
    QString totaltime;
    QString time_to_full;
    QString time_to_lack;
    QString percentage;
signals:
    void refresh_right_widget();
private:
    QProcess *get_battery_time;
    QString temp_info;
    void parse_batterytime_info(QString);
    void set_battery_label();

public slots:
    void onTimeout();
    void readOutput();
    //void do_others(int,QProcess::ExitStatus);

};

#endif // WORKER

