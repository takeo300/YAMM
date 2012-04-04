/* 
 * File:   IMConnection.h
 * Author: Benjamin Rockel, Max Beikirch, Hendrik Sokolowski
 *
 * Created on 4. April 2012, 16:40
 */

/*#ifndef IMCONNECTION_H
#define	IMCONNECTION_H

#include "Connection.h"
#include "Contact.h"

class IMConnection
{
	Q_OBJECT
	public:
		virtual Chat createChat(QList<Contact*> users) = 0;
};

#endif	/* IMCONNECTION_H */

