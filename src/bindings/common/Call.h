/* 
 * File:   Call.h
 * Author: Benjamin Rockel, Max Beikirch, Hendrik Sokolowski
 *
 * Created on 4. April 2012, 16:50
 */

#ifndef CALL_H
#define	CALL_H

#include "Contact.h"

class Call
{
	public:
		virtual bool call() = 0;
		virtual bool hold() = 0;
		virtual bool resume() = 0;
		virtual void end() = 0;
		virtual bool accept() = 0;
		virtual bool canHold() = 0;
		virtual int getID() = 0;
	protected:
		bool held;
		Contact *Caller;
		long int callTime;
		int ID;
		QList<Contact*> users;
};

#endif	/* CALL_H */

