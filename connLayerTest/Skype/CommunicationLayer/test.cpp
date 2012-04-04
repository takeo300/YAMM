#include <Qt/QtGui>
#include <Qt/QtDBus>
#include <Qt/QtCore>
#include <iostream>

using namespace std;

int main(int argc,char *argv[])
{
	QApplication* app = new QApplication(argc,argv);
	cout << "app" << endl;
	QDBusInterface *test =new QDBusInterface("org.YAMM.test","/com/Skype/Client");
	cout << "interface" << endl;
	test->call("Notify","bla");
	cout << "call" << endl;
}
