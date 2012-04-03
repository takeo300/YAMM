#include "connection.adapter.irc.h"

Connection_Adapter_IRC::Connection_Adapter_IRC(QString host, int port) {
    QHostAddress *haddr = new QHostAddress();
    haddr->setAddress(host);
    if (haddr->protocol() != QAbstractSocket::IPv4Protocol
            && haddr->protocol() != QAbstractSocket::IPv6Protocol) {
        qDebug() << "[IRC] hostname found, trying to resolve...";
        haddr->setAddress(QHostInfo::fromName(host).addresses().at(0).toString());
    }

    if (haddr->isNull()) {
        qDebug() << "[IRC] Invalid address" << endl;
    }

    this->ip = haddr;
    this->port = port;
    this->socket = new QTcpSocket();
}

Connection_Adapter_IRC::~Connection_Adapter_IRC() {
    this->disconnect();
}

bool Connection_Adapter_IRC::isConnected() {
    return this->socket->isOpen();
}

void Connection_Adapter_IRC::connect() {
    this->socket->connectToHost(*this->ip, (quint16) this->port);
    if (this->socket->waitForConnected()) {
        qDebug() << "[IRC] connection established" << endl;
        QObject::connect(this->socket, SIGNAL(readyRead()), this, SLOT(receivedAnswer()));
    } else {
        qDebug() << "[IRC] connection failed" << endl;
        qDebug() << this->socket->error() << endl;
    }
}

void Connection_Adapter_IRC::disconnect() {
    if (this->isConnected()) {
        this->socket->close();
    }
}

int Connection_Adapter_IRC::writeLine(QString data) {
    data.append("\r\n");

    if (this->isConnected()) {
        return this->socket->write(data.toUtf8());
    }
    else {
        return -1;
    }
}

void Connection_Adapter_IRC::receivedAnswer() {
    QString *answer = new QString(this->socket->readAll());
    cout << "[IRC - Answer] " << answer->toStdString() << endl;
}
