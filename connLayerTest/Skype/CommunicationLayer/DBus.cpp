#include "DBus.h"
#include <iostream>
#include <string.h>

using namespace std;

void Client::test()
{
	interface = new QDBusInterface("com.Skype.API","/com/Skype");
	QDBusReply<QString> reply = interface->call("Invoke","NAME test");
	if(reply.isValid())
	{
		std::cout << reply.value().toStdString() << std::endl;
		if(reply.value().toStdString() == "OK")
		{
			reply = interface->call("Invoke","PROTOCOL 8");
			cout << reply.value().toStdString() << endl;
		}
	}
}

void Client::Notify(const QString &msg)
{
	cout << msg.toStdString() << endl;
}
