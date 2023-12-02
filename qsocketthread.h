#ifndef QSOCKETTHREAD_H
#define QSOCKETTHREAD_H

#include <QThread>
#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QTime>
#include <QPushButton>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QProcess>
#include <QTextCodec>

class QSocketThread : public QThread
{
    Q_OBJECT
public:
    explicit QSocketThread(int descriptor, QObject *parent=0);
    ~QSocketThread();

    void run();
signals:


public slots:
    void onReadyRead();
    void onDisconnected();
    QString getUpdates();

private:
    int socketDescriptor;
    QTcpSocket* socket;

};

#endif // QSOCKETTHREAD_H
