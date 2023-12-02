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

    QSimpleServer();
    void incomingConnection(qintptr handle);

signals:


public slots:


};

#endif // QSIMPLESERVER_H
