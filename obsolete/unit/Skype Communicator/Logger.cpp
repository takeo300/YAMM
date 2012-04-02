/* 
 * File:   Logger.cpp
 * Author: Maximilian
 * 
 * Created on 25. März 2012, 01:10
 */

#include "Logger.h"

const string Logger::TYPE_URGENT = "Logger::type:urgent";
const string Logger::TYPE_ERROR = "Logger::type:error";
const string Logger::TYPE_WARNING = "Logger::type:warning";
const string Logger::TYPE_DEBUG = "Logger::type:debug";

bool Logger::_showDebugMessages = false;

void Logger::log(string message, string type, string prefix) {
    if (Logger::_showDebugMessages == false && type == Logger::TYPE_DEBUG) {
        return;
    }
    
    string errorType;
    
    if (type.compare(Logger::TYPE_DEBUG) == 0) {
            errorType = "DEBUG";
    }
    else if(type.compare(Logger::TYPE_WARNING) == 0) {
        errorType = "WARNING";
    }
    else if(type.compare(Logger::TYPE_ERROR) == 0) {
        errorType = "ERROR";
    }
    else if(type.compare(Logger::TYPE_URGENT) == 0) {
        errorType = "URGENT";
    }
    else {
        return;
    }
    
    if (prefix.empty()) {
        printf("[%s]: %s\n", errorType.c_str(), message.c_str());
    } else {
        printf("[%s][%s]: %s\n", errorType.c_str(), prefix.c_str(), message.c_str());
    }
    
    fflush(stdout);
}

void Logger::showDebugMessages(bool value) {
    Logger::_showDebugMessages = value;
}