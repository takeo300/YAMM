/* 
 * File:   skypeCall.h
 * Author: Benjamin
 *
 * Created on 4. April 2012, 17:19
 */

#ifndef SKYPECALL_H
#define	SKYPECALL_H

#include "../common/Call.h"
#include "protocol/ProtocolLayer.h"
#include "../common/Contact.h"

class skypeCall : public Call
{
	public:
		skypeCall(QList<Contact*> users, ProtocolLayer *pl);
		bool call();
		bool hold();
		bool resume();
		void end();
		bool accept();
		bool canHold();
		int getID();
		void processNotification(QString msg);
	private:
		ProtocolLayer *pl;
};

#endif	/* SKYPECALL_H */

