#ifndef QSIMPLESERVER_H
#define QSIMPLESERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QDateTime>
#include <QObject>
#include "qsocketthread.h"


class QSimpleServer : public QTcpServer
{
    Q_OBJECT
public:
   /* explicit QSimpleServer(QObject *parent =nullptr);*/
    QSimpleServer();
    void incomingConnection(qintptr handle);

signals:


public slots:
//    void onReadyRead();
//    void onDisconnected();

};

#endif // QSIMPLESERVER_H
