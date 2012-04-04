#include <iostream>
#include "Skype/CommunicationLayer/DBus.h"
#include <Qt/QtGui>

using namespace std;

int main(int argc, char *argv[])
{
	QApplication app(argc,argv); 

	Client test;	
	new ClientAdaptor(&test);
	
	if(!QDBusConnection::sessionBus().registerObject("/com/Skype/Client",&test))
		cout << "Konnte Object nicht registrieren!" << endl;
	if(!QDBusConnection::sessionBus().registerService("org.YAMM.test"))
		cout << "Konnte Service nicht registrieren!" << endl;
	
	test.test();
	
	return app.exec();
}
