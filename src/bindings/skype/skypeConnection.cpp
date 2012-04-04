#include "skypeConnection.h"

skypeConnection::skypeConnection()
{
	pl = new ProtocolLayer();
	cl = new QList<skypeCall*>();
	QObject::connect(pl,SIGNAL(CallNotification(int,QString)),this,SLOT(handleCallNotifications(int,QString)));
}

bool skypeConnection::connect()
{
	return pl->connect();
}

bool skypeConnection::disconnect()
{
	return false;//disconnect code einfügen
}

Call* skypeConnection::createCall(QList<Contact*> users)
{
	skypeCall *c = new skypeCall(users,pl);
	c->call();
	registerCall(c);
	return c;
}

Call* skypeConnection::createCall(Contact* user)
{
	QList<Contact*> *con = new QList<Contact*>();
	con->append(user);
	return createCall(*con);
}

void skypeConnection::registerCall(skypeCall* c)
{
	cl->append(c);//mit effizienterer referenzierung verbinden
}

void skypeConnection::handleCallNotifications(int callId,QString msg)
{
	for(int i= 0;i<cl->length();i++)
		if(cl->at(i)->getID()==callId)
			cl->at(i)->processNotification(msg);
}