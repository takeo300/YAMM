#include "ProtocolLayer.h"
#include <iostream>

using namespace std;

ProtocolLayer::ProtocolLayer()
{
	comm = new CommunicationLayer(this,SLOT(handleNotification(QString)),QString("PROTOCOL 8"));
}

bool ProtocolLayer::connect()
{
	return comm->connect();
}

void ProtocolLayer::handleNotification(QString notification)
{
	cout << notification.toStdString() << endl;
	if(notification.startsWith("CALL"))
	{
		QStringList l = notification.split(" ");
		emit CallNotification(l.at(1).toInt(), l.at(2)+" "+l.at(3));
	}
}

bool ProtocolLayer::ping()
{
	QString s = comm->invoke("PING");
	if(s==QString("PONG"))
		return true;
	return false;
}

int ProtocolLayer::call(QList<QString> targets, QString &status)
{
	QString s("CALL ");
	for(int i = 0; i < targets.length()-1;i++)
		s.append(targets.at(i)+",");
	s.append(targets.at(targets.length()-1));
	QString r = comm->invoke(s);
	QStringList ID = r.split(" ");
	status = ID.at(3);
	return ID.at(1).toInt();
}

int ProtocolLayer::call(QString target, QString &status)
{
	QList<QString> *s=new QList<QString>();
	s->append(target);
	return call(*s,status);
}