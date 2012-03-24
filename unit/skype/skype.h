#ifndef SKYPE_H_INCLUDED
#define SKYPE_H_INCLUDED
#include <windows.h>
#include <iostream>
#include <string.h>
#include <stdio.h>

extern HWND hWndskype;
extern HWND hWnd;

using namespace std;

extern UINT WM_SkypeControlAPIDiscover    ;
extern UINT WM_SkypeControlAPIAttach      ;

enum
{
    SKYPECONTROLAPI_ATTACH_SUCCESS=0,								// Client is successfully attached and API window handle can be found in wParam parameter
    SKYPECONTROLAPI_ATTACH_PENDING_AUTHORIZATION=1,	// Skype has acknowledged connection request and is waiting for confirmation from the user.
    // The client is not yet attached and should wait for SKYPECONTROLAPI_ATTACH_SUCCESS message
    SKYPECONTROLAPI_ATTACH_REFUSED=2,								// User has explicitly denied access to client
    SKYPECONTROLAPI_ATTACH_NOT_AVAILABLE=3,					// API is not available at the moment. For example, this happens when no user is currently logged in.
    // Client should wait for SKYPECONTROLAPI_ATTACH_API_AVAILABLE broadcast before making any further
    // connection attempts.
    SKYPECONTROLAPI_ATTACH_API_AVAILABLE=0x8001
};

bool SkypesendCommand(char* InputCommand);
bool SkypesendAttach(HWND WindowHandle);
bool SkypeInit(void);
int  SkypecheckAPIAttach(HWND WindowHandle, UINT msg, WPARAM wParam, LPARAM lParam);
int  SkypeCreateCall(string target1,...);

#endif // SKYPE_H_INCLUDED
