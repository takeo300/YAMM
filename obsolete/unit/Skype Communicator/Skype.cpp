/* 
 * File:   Skype.cpp
 * Author: Maximilian
 * 
 * Created on 24. März 2012, 22:19
 */

#include "Skype.h"
const UINT Skype::SKYPECONTROLAPI_ATTACH_SUCCESS = 0;
const UINT Skype::SKYPECONTROLAPI_ATTACH_PENDING_AUTHORIZATION = 1;
const UINT Skype::SKYPECONTROLAPI_ATTACH_REFUSED = 2;
const UINT Skype::SKYPECONTROLAPI_ATTACH_NOT_AVAILABLE = 3;
const UINT Skype::SKYPECONTROLAPI_ATTACH_API_AVAILABLE = 0x8001;


HWND Skype::_mainWindow;
HWND Skype::_skypeWindow;
bool Skype::_initialized = false;

//SkypeStatus* Skype::_connectionStatus = new SkypeStatus(SkypeStatus::CONNECTIONSTATUS_OFFLINE);
//SkypeUser* Skype::_user = new SkypeUser();
//list<SkypeUser> _contactList;
UINT Skype::_skypeControlApiDiscover = 0;
UINT Skype::_skypeControlApiAttach = 0;

//SkypeStatus* Skype::getConnectionStatus() {
//    return Skype::_connectionStatus;
//}

//SkypeUser Skype::getUser() {
//    return Skype::_user;
//}

//list<SkypeUser> Skype::getContactList() {
//    return Skype::_contactList;
//}

bool Skype::init(HWND windowHandle) {
    Skype::_mainWindow = windowHandle;
    
    Logger::log("Trying to register \"SkypeControlAPIDiscover\"", 
            Logger::TYPE_DEBUG,
            "Skype");
    
    Skype::_skypeControlApiDiscover = RegisterWindowMessage("SkypeControlAPIDiscover");
    if (Skype::_skypeControlApiDiscover == 0) {
        Logger::log("Window Message \"SkypeControlAPIDiscover\" konnte nicht registriert werden.", Logger::TYPE_URGENT);
        return false;
    }
    Logger::log("successful", Logger::TYPE_DEBUG, "Skype");
    
    Logger::log("Trying to register \"SkypeControlAPIAttach\"", 
            Logger::TYPE_DEBUG,
            "Skype");
    Skype::_skypeControlApiAttach = RegisterWindowMessage("SkypeControlAPIAttach");
    if (Skype::_skypeControlApiAttach == 0) {
        Logger::log("Window Message \"SkypeControlAPIDiscover\" konnte nicht registriert werden.", Logger::TYPE_URGENT);
        return false;
    }
    Logger::log("successful", Logger::TYPE_DEBUG, "Skype");
    
    if (!Skype::_attach()) {
        return false;
    }
    
    Skype::_initialized = true;
    return true;
}

bool Skype::handleMessage(UINT msg, WPARAM wParam, LPARAM lParam) {
    if (wParam == (WPARAM) Skype::_skypeWindow) {
        PCOPYDATASTRUCT pCopyData=(PCOPYDATASTRUCT)lParam;
        
        char* answer = (char*) pCopyData->lpData;
        
        if (strstr(answer, "CONNSTATUS") != NULL) {
            Logger::log("CONNSTATUS found", Logger::TYPE_DEBUG, "Skype - Answer");
        }
        
        Logger::log(answer, Logger::TYPE_DEBUG, "Skype - Answer");
        
        return true;
    }
    
    return false;
}

bool Skype::checkApiAttach(UINT msg, WPARAM wParam, LPARAM lParam) {
    if(msg == Skype::_skypeControlApiAttach) {
        switch(lParam)
        {
            case Skype::SKYPECONTROLAPI_ATTACH_SUCCESS:
                Logger::log("Connected", Logger::TYPE_DEBUG, "Skype");
                Skype::_skypeWindow = (HWND)wParam;
                break;
            
            case Skype::SKYPECONTROLAPI_ATTACH_PENDING_AUTHORIZATION:
                Logger::log("Pending authorization", Logger::TYPE_DEBUG, "Skype");
                break;
            
            case Skype::SKYPECONTROLAPI_ATTACH_REFUSED:
                Logger::log("Connection refused", Logger::TYPE_ERROR, "Skype");
                break;
            
            case Skype::SKYPECONTROLAPI_ATTACH_NOT_AVAILABLE:
                Logger::log("Skype API not available", Logger::TYPE_ERROR, "Skype");
                break;
            
            case Skype::SKYPECONTROLAPI_ATTACH_API_AVAILABLE:
                Logger::log("Try connect now (API available)",
                        Logger::TYPE_DEBUG, "Skype");
                Skype::_attach();
                break;
        }
        return true;
    } 
    else {
        return false;
    }
}

bool Skype::call() {
    Skype::_sendCommand("CALL hensoko");
}

bool Skype::_attach() {
    Logger::log("Trying to attach to Skype", Logger::TYPE_DEBUG, "Skype");
    if(!SendMessage( HWND_BROADCAST, 
            Skype::_skypeControlApiDiscover, 
            (WPARAM)Skype::_mainWindow, 
            (LPARAM)Skype::_mainWindow)) {
        Logger::log("failed", Logger::TYPE_ERROR, "Skype");
        return false;
    }
    Logger::log("successful", Logger::TYPE_DEBUG, "Skype");
    return true;
}

bool Skype::_sendCommand(char* command) {
    if(Skype::_initialized) {
        COPYDATASTRUCT CopyData;

        CopyData.dwData = 0;
        CopyData.lpData = command;
        
        CopyData.cbData = strlen(command) + 1;
        if(CopyData.cbData != 1) {
                if(SendMessage(Skype::_skypeWindow, 
                        WM_COPYDATA, 
                        (WPARAM)Skype::_mainWindow, 
                        (LPARAM)&CopyData) == 1) {
                    printf("Gesendet!\n");
                        return true;
                }
                return false;
        }
    }
    return false;
}