#ifndef ROSTHREAD_H
#define ROSTHREAD_H

#include <sys/mman.h>
#include <fcntl.h>

#include <QThread>
#include <QByteArray>
#include <QTimer>

#include "PODOServer.h"

class ROSThread : public QThread
{
    Q_OBJECT
public:
    ROSThread();

protected:
    void run();
};


class ROSWorker : public QObject
{
    Q_OBJECT
public:
    ROSWorker();

    float   timePrev;
    float   timeCur;
    float   timePeriod;


private slots:
    void onFastTimer();
    void onNewConnection();
    void onDisconnect();

    void onPODO2ROS();
    void onROS2PODO();

private:
    PODO_ROS_Server         *serverPODOROS;
    Ref_Receive_Server      *serverJOINTREF;
    LAN_PODO2ROS            TXData;
    LAN_ROS2PODO            RXData;

    void    SendtoROS();
    void    SendtoJOINTREF();
    void    ReadfromROS();
    void    ReadfromROS_JOINTREF();


};


#endif // ROSTHREAD_H
