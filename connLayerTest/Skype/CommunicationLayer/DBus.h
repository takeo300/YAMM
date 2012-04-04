#ifndef DBUS_H_INCLUDED
#define DBUS_H_INCLUDED

#include <Qt/QtDBus>
#include <Qt/QtCore>
#include "DBusAdaptor.h"

class Client : public QObject
{
	Q_OBJECT
	Q_CLASSINFO("D-Bus Interface", "com.Skype.API.Client")
	public:
		void test();
	public slots:
		void Notify(const QString &msg);
	private:
		QDBusInterface *interface;
};

#endif // DBUS_H_INCLUDED
