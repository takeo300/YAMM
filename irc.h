#ifndef IRC_H
#define IRC_H
#include <string>
#include <iostream>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QHostInfo>

using namespace std;

class IRC : QObject {
    Q_OBJECT

public:
    IRC(QString host, int port);
    virtual ~IRC();
    void connect();
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

#endif // IRC_H
