/*
 * File:   main.cpp
 * Author: Benjamin Rockel
 *
 * Created on 4. April 2012, 00:18
 */

#include <Qt/QtGui>
#include "bindings/skype/skypeConnection.h"
#include <iostream>

int main(int argc, char *argv[]) 
{
	QApplication app(argc, argv);

	skypeConnection *sc = new skypeConnection();
	sc->connect();
	Contact *con = new Contact("test","echo123");
	Call *c = sc->createCall(con);

	return app.exec();
}
