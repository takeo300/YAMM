#include "Contact.h"

Contact::Contact(QString name, QString skypeName)
{
	this->name = name;
	this->skypeName = skypeName;
}

QString Contact::getSkypeName()
{
	return skypeName;
}