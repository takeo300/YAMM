/* 
 * File:   ProtocolLayer.h
 * Author: Benjamin Rockel
 *
 * Created on 4. April 2012, 01:30
 */

#ifndef PROTOCOLLAYER_H
#define	PROTOCOLLAYER_H

#include <Qt/QtCore>
#include "CommunicationLayer.h"

class ProtocolLayer : public QObject
{
	Q_OBJECT
	
	public:
		ProtocolLayer();
		bool connect();
		
		//Protocol 1 Funktionen
		bool ping();
		int call(QList<QString> targets, QString &status);
		int call(QString target, QString &status);
	
	public slots:
		void handleNotification(QString notification);
		
	signals:
		void CallNotification(int callId, QString msg);
	private:
		CommunicationLayer *comm;	
};

#endif	/* PROTOCOLLAYER_H */

