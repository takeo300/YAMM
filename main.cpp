/*
 * File:   main.cpp
 * Author: Hendrik
 *
 * Created on 2. April 2012, 21:40
 */

#include <QtGui/QApplication>
#include <iostream>
#include <irc.h>
using namespace std;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    qDebug() << "";
    cout << "" << endl;

    IRC *irc = new IRC("xs4all.nl.quakenet.org", 6667);
    irc->connect();
    irc->writeLine("NICK hensoko");
    irc->writeLine("USER hensoko 0 0 : hensoko");
    return app.exec();
}
