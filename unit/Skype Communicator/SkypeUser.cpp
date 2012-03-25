/* 
 * File:   SkypeUser.cpp
 * Author: Maximilian
 * 
 * Created on 24. März 2012, 22:27
 */

#include "SkypeUser.h"


using namespace std;

string SkypeUser::getUsername() {
    return this->_username;
}

SkypeStatus SkypeUser::getOnlineStatus() {
    return this->_onlineStatus;
}

SkypeStatus SkypeUser::getUserStatus() {
    return this->_userStatus;
}