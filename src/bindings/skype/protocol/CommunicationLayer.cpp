#include "CommunicationLayer.h"
#include <iostream>

using namespace std;

CommunicationLayer::CommunicationLayer(QObject *tbn, const char* notifySlot, QString protocol)
{
	QObject::connect(this,SIGNAL(notified(QString)),tbn,notifySlot);
	interface = new QDBusInterface("com.Skype.API","/com/Skype");
	this->protocol = protocol;
}

CommunicationLayer::CommunicationLayer(QString protocol)
{
	interface = new QDBusInterface("com.Skype.API","/com/Skype");
	this->protocol = protocol;
}

bool CommunicationLayer::connect()
{
	new CommunicationLayerAdaptor(this);
	
	if(!QDBusConnection::sessionBus().registerObject("/com/Skype/Client",this))
	{
		cout << "Konnte Object nicht registrieren!" << endl;
		return false;
	}
	if(!QDBusConnection::sessionBus().registerService("org.YAMM.test"))
	{
		cout << "Konnte Service nicht registrieren!" << endl;
		return false;
	}
	
	QDBusReply<QString> reply = interface->call("Invoke","NAME YAMM");
	if(reply.isValid())
	{
		std::cout << reply.value().toStdString() << std::endl;
		if(reply.value().toStdString() == "OK")
		{
			reply = interface->call("Invoke",protocol);
			if(reply.isValid() && reply.value() == protocol)
			{
				cout << reply.value().toStdString() << endl;
				return true;
			}
		}
	}
	cout << "Verbindung zu Skype-Interface gescheitert!" << endl;
	return false;
}

QString CommunicationLayer::invoke(QString arg)
{
	QDBusReply<QString> reply = interface->call("Invoke",arg);
	if(reply.isValid())
		return reply.value();
	else
		return 0;
}

void CommunicationLayer::Notify(const QString& msg)
{
	//cout << msg.toStdString() << endl;
	emit notified(msg);
}