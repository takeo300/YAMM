#include "irc.h"

IRC::IRC(QString host, int port) {
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

IRC::~IRC() {
    this->disconnect();
}

bool IRC::isConnected() {
    return this->socket->isOpen();
}

void IRC::connect() {
    this->socket->connectToHost(*this->ip, (quint16) this->port);
    if (this->socket->waitForConnected()) {
        qDebug() << "[IRC] connection established" << endl;
        QObject::connect(this->socket, SIGNAL(readyRead()), this, SLOT(receivedAnswer()));
    } else {
        qDebug() << "[IRC] connection failed" << endl;
        qDebug() << this->socket->error() << endl;
    }
}

void IRC::disconnect() {
    if (this->isConnected()) {
        this->socket->close();
    }
}

int IRC::writeLine(QString data) {
    data.append("\r\n");

    if (this->isConnected()) {
        return this->socket->write(data.toUtf8());
    }
    else {
        return -1;
    }
}

void IRC::receivedAnswer() {
    QString *answer = new QString(this->socket->readAll());
    cout << "[IRC - Answer] " << answer->toStdString() << endl;
}
