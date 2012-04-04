/* 
 * File:   skypeConnection.h
 * Author: Benjamin
 *
 * Created on 4. April 2012, 17:04
 */

#ifndef SKYPECONNECTION_H
#define	SKYPECONNECTION_H

#include <Qt/QtCore>
#include "protocol/ProtocolLayer.h"
#include "../common/Connection.h"
#include "../common/Call.h"
#include "skypeCall.h"
#include "../common/Callable.h"

class skypeConnection : public Connection, public Callable
{
	Q_OBJECT
	
	public:
		skypeConnection();
		
		bool connect();
		bool disconnect();
		
		Call* createCall(QList<Contact*> users);
		Call* createCall(Contact *user);
		
	public slots:
		void handleCallNotifications(int callId,QString msg);
		
	private:
		void registerCall(skypeCall *c);
		ProtocolLayer * pl;
		QList<skypeCall*> *cl;
};

#endif	/* SKYPECONNECTION_H */

