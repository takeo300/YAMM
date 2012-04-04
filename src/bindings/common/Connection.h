/* 
 * File:   connection.h
 * Author: Benjamin Rockel, Max Beikirch, Hendrik Sokolowski
 *
 * Created on 4. April 2012, 15:30
 */

#ifndef CONNECTION_H
#define	CONNECTION_H

#include <Qt/QtCore>

class Connection : public QObject
{
	Q_OBJECT
	public:
		virtual bool connect() = 0;
		virtual bool disconnect() = 0;
};

#endif	/* PROTOCOLLAYER_H */
