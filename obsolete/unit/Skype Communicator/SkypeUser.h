/* 
 * File:   SkypeUser.h
 * Author: Maximilian
 *
 * Created on 24. März 2012, 22:27
 */

#ifndef SKYPEUSER_H
#define	SKYPEUSER_H

#include <string>

#include <SkypeStatus.h>
using namespace std;

class SkypeUser {
public:
    string getUsername();
    SkypeStatus getOnlineStatus();
    SkypeStatus getUserStatus();

protected:
    string _username;
    SkypeStatus _onlineStatus;
    SkypeStatus _userStatus;
};
#endif	/* SKYPEUSER_H */