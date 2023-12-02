#include "qsocketthread.h"

QSocketThread::QSocketThread(int descriptor, QObject *parent) :
    QThread(parent), socketDescriptor(descriptor)
{

}

QSocketThread::~QSocketThread()
{
    delete socket;
}

void QSocketThread::run()
{
    socket = new QTcpSocket();
    socket->setSocketDescriptor(socketDescriptor);
    sleep(1);

    connect(socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()), Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(onDisconnected()), Qt::DirectConnection);

    exec();
}

void QSocketThread::onReadyRead()
{

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("CP 866"));
    qDebug() << socket->readAll();
    setlocale(LC_ALL, "rus");

    // Получение перечня обновлений
    QString updates = getUpdates();

    QString response = "HTTP/1.1 200 OK\r\n\r\n%1";
    QString fullResponse = response.arg(updates);
    QJsonArray updatesArray;

    QProcess process;
    process.start("powershell", QStringList() << "Get-HotFix");
    process.waitForFinished();

    QString output = process.readAllStandardOutput();
    if (output.contains("HotFixID"))
        {
            QStringList updatesList = output.split("\n", QString::SkipEmptyParts);
              for (int i = 5; i < updatesList.size(); i++)
            {
                QString updateInfo = updatesList.at(i);
                QStringList updateData = updateInfo.split(QRegExp("\\s+"), QString::SkipEmptyParts);
                if (updateData.size() >= 2)
                {
                    QJsonObject updateObject;
                    updateObject["name"] = updateData.at(3);
                    updateObject["date"] = updateData.at(6);

                    QJsonDocument jsonDoc(updateObject);
                    QByteArray postData = jsonDoc.toJson();
                    updatesArray.append(updateObject);
                    QString wrong = "NT";
    if(updateObject["name"]!=wrong)
{

                socket->write(postData);
                socket->disconnectFromHost();
}

}
}
    }
}
void QSocketThread::onDisconnected()
{
    socket->close();
    quit();
}
bool checkWindowsUpdates()
{
    QProcess process;
    process.start("powershell", QStringList() << "Get-HotFix");
    process.waitForFinished();

    QString output = process.readAllStandardOutput();
    if (output.contains("HotFixID"))
    {
        // Обновления установлены
        return true;
    }
    else
    {
        // Обновления не установлены
        return false;
    }


}

QString QSocketThread::getUpdates()
{
    QJsonArray updatesArray;
    QJsonDocument updatesDocument(updatesArray);
    QByteArray updatesData = updatesDocument.toJson();


    return updatesData;
}


