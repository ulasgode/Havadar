#ifndef COMMUNICATIONMODULE_H
#define COMMUNICATIONMODULE_H

#include <QObject>
#include <QtNetwork>
#include <QTcpServer>
#include <QTcpSocket>

#include "structure/edge.h"

#define HOST "127.0.0.1"
#define PORT 5005
#define WAIT 1000

class CommunicationModule : public QObject
{
    Q_OBJECT

private:
    QVector<QString> * _packageList;
    QTcpServer * _server;

public:
    CommunicationModule(QObject* parent): QObject(parent)
    {
        _packageList = new QVector<QString>();
        _server = new QTcpServer(this);
        connect(_server, SIGNAL(newConnection()), this, SLOT(ReceiveData()));

        if(!_server->listen(QHostAddress(HOST), PORT))
        {
            qDebug() << "Server couldn't start listening";
        }
    }

    QVector<QString> * GetPackageList()
    {
        return _packageList;
    }

    ~CommunicationModule()
    {
        _server->close();
        //delete _packageList;
        //delete _server;
    }

private slots:
    void ReceiveData()
    {
        QTcpSocket * agent = _server->nextPendingConnection();
        char buffer[2048] = {0};

        agent->waitForReadyRead(5000);
        agent->read(buffer, agent->bytesAvailable());

        QString message(buffer);
        qDebug() << "SERVER'A GELEN PAKET: " << message;

        _packageList->push_front(message);
        agent->close();
    }
};

#endif // COMMUNICATIONMODULE_H


