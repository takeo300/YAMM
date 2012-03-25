/* 
 * File:   SkypeStatus.h
 * Author: Maximilian
 *
 * Created on 24. März 2012, 23:02
 */

#ifndef SKYPESTATUS_H
#define	SKYPESTATUS_H
#include <string>
using namespace std;

class SkypeStatus {
public:
    static const string CONNECTIONSTATUS_OFFLINE;
    static const string CONNECTIONSTATUS_CONNECTING;
    static const string CONNECTIONSTATUS_PAUSING;
    static const string CONNECTIONSTATUS_ONLINE;
    
    static const string USERSTATUS_UNKNOWN;
    static const string USERSTATUS_ONLINE;
    static const string USERSTATUS_OFFLINE;
    static const string USERSTATUS_SKYPEME;
    static const string USERSTATUS_AWAY;
    static const string USERSTATUS_NA;
    static const string USERSTATUS_DND;
    static const string USERSTATUS_INVISIBLE;
    static const string USERSTATUS_LOGGEDOUT;
    
    static const string ONLINESTATUS_UNKNONW;
    static const string ONLINESTATUS_OFFLINE;
    static const string ONLINESTATUS_ONLINE;
    static const string ONLINESTATUS_AWAY;
    static const string ONLINESTATUS_NA;
    static const string ONLINESTATUS_DND;
    
    SkypeStatus(string status);
    string getStatus();
    bool hasStatus(string status);

protected:
    string _status;
};

#endif	/* SKYPESTATUS_H */