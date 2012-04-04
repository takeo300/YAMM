/* 
 * File:   CommunicationLayer.h
 * Author: Benjamin Rockel
 *
 * Created on 4. April 2012, 00:37
 */

#ifndef COMMUNICATIONLAYER_H
#define	COMMUNICATIONLAYER_H

#include <Qt/QtDBus>
#include <Qt/QtCore>
#include "CommunicationLayerAdaptor.h"

class CommunicationLayer : public QObject
{
	Q_OBJECT
	Q_CLASSINFO("D-Bus Interface", "com.Skype.API.Client")
	
	public:
		CommunicationLayer(QObject *tbn, const char* notifySlot, QString protocol);
		CommunicationLayer(QString protocol);
		bool connect();
		QString invoke(QString arg);
	
	public slots:
		void Notify(const QString &msg);
	signals:
		void notified(QString notification);
	private:
		QDBusInterface *interface;
		QString protocol;
};

#endif	/* COMMUNICATIONLAYER_H */

