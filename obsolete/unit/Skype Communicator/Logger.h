/* 
 * File:   Logger.h
 * Author: Maximilian
 *
 * Created on 25. März 2012, 01:10
 */

#ifndef LOGGER_H
#define	LOGGER_H

#include <string>
#include <stdio.h>
#include <sstream>

using namespace std;

class Logger {
public:
    static const string TYPE_URGENT;
    static const string TYPE_ERROR;
    static const string TYPE_WARNING;
    static const string TYPE_DEBUG;
    
    static void log(string message, string type, string prefix = "");
    
    static void showDebugMessages(bool value);
private:
    static bool _showDebugMessages;
};
#endif	/* LOGGER_H */

