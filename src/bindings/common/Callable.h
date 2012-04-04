/* 
 * File:   Callable.h
 * Author: Benjamin Rockel, Max Beikirch, Hendrik Sokolowski
 *
 * Created on 4. April 2012, 16:43
 */

#ifndef CALLABLE_H
#define	CALLABLE_H

#include "Connection.h"
#include "Contact.h"
#include "Call.h"

class Callable
{
	public:
		virtual Call* createCall(QList<Contact*> users) = 0;
		virtual Call* createCall(Contact *user) = 0;
		//virtual Call getCall(int callId) = 0;
    
	signals:
		void callReceived(Call *call);
};

#endif	/* CALLABLE_H */

