#ifndef CONNECTION_ADAPTER_IRC_H
#define CONNECTION_ADAPTER_IRC_H
#include <string>
#include <iostream>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QHostInfo>

#include "connection.adapter.abstract.h"

using namespace std;

class Connection_Adapter_IRC : public Connection_Adapter_Abstract {
Q_OBJECT
public:
    Connection_Adapter_IRC(QString host, int port);
    virtual ~Connection_Adapter_IRC();
    virtual void connect();
    void disconnect();
    bool isConnected();
    int writeLine(QString data);

protected:
    QHostAddress *ip;
    int port;
    QTcpSocket *socket;

public slots:
    void receivedAnswer();
};

#endif // CONNECTION_ADAPTER_IRC_H
