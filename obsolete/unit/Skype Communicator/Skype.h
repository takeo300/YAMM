/* 
 * File:   Skype.h
 * Author: Maximilian
 *
 * Created on 24. März 2012, 22:19
 */

#ifndef SKYPE_H
#define	SKYPE_H
#include <string>
#include <list>
#include <windows.h>

#include <Logger.h>

#include <SkypeStatus.h>
#include <SkypeUser.h>
using namespace std;

class Skype {
public:
    static const UINT SKYPECONTROLAPI_ATTACH_SUCCESS;
    static const UINT SKYPECONTROLAPI_ATTACH_PENDING_AUTHORIZATION;
    static const UINT SKYPECONTROLAPI_ATTACH_REFUSED;
    static const UINT SKYPECONTROLAPI_ATTACH_NOT_AVAILABLE;
    static const UINT SKYPECONTROLAPI_ATTACH_API_AVAILABLE;
//    static SkypeStatus* getConnectionStatus();
//    static SkypeUser getUser();
//    static list<SkypeUser> getContactList();
    static bool init(HWND windowHandle);
    static bool handleMessage(UINT msg, WPARAM wParam, LPARAM lParam);
    static bool checkApiAttach(UINT msg, WPARAM wParam, LPARAM lParam);
    static bool call();
    
protected:
    static HWND _mainWindow;
    static HWND _skypeWindow;
    
    static bool _initialized;
    
    static SkypeStatus *_connectionStatus;
//    static SkypeUser _user;
//    static list<SkypeUser> _contactList;
    static UINT _skypeControlApiDiscover;
    static UINT _skypeControlApiAttach;
    
    static bool _attach();
    static bool _sendCommand(char *command);
};
#endif	/* SKYPE_H */