/* 
 * File:   User.h
 * Author: Benjamin
 *
 * Created on 4. April 2012, 16:53
 */

#ifndef USER_H
#define	USER_H

#include <Qt/QtCore>

class Contact
{
	public:
		Contact(QString name, QString skypeName);
		QString getSkypeName();
	private:
		QString name;
		QString skypeName;
};

#endif	/* USER_H */

