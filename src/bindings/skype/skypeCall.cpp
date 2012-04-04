#include "skypeCall.h"
#include <iostream>

using namespace std;

skypeCall::skypeCall(QList<Contact*> users, ProtocolLayer *pl)
{
	this->users = users;
	this->pl = pl;
}

bool skypeCall::call()
{
	QList<QString> *us = new QList<QString>();
	for(int i = 0;i<users.length();i++)
		us->append(users.at(i)->getSkypeName());
	QString s("");
	ID = pl->call(*us,s);
	if(ID==0)
		return false;
	cout << s.toStdString() << endl;
	return true;
}

bool skypeCall::hold()
{
	
}

bool skypeCall::resume()
{
	
}

void skypeCall::end()
{
	
}

bool skypeCall::accept()
{
	
}

bool skypeCall::canHold()
{
	return true;
}

int skypeCall::getID()
{
	return ID;
}

void skypeCall::processNotification(QString msg)
{
	cout << msg.toStdString() << endl;
}