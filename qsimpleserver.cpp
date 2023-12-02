#include "qsimpleserver.h"

QSimpleServer::QSimpleServer() :
    QTcpServer()
{

    if(this->listen(QHostAddress::Any, 80))
    {
        qDebug()<< "Listeen";
    }
    else
    {
         qDebug()<< "Errooor"<<errorString();
    }

}

void QSimpleServer::incomingConnection(qintptr handle)
{
   QSocketThread* thread = new QSocketThread(handle);
    connect(thread, SIGNAL(finished()),thread, SLOT(deleteLater()));
    thread->start();
}




