/* 
 * File:   SkypeStatus.cpp
 * Author: Maximilian
 * 
 * Created on 24. März 2012, 23:02
 */

#include "SkypeStatus.h"

const string SkypeStatus::CONNECTIONSTATUS_OFFLINE = "SkypeStatus::connectionstatus:offline";
const string SkypeStatus::CONNECTIONSTATUS_CONNECTING = "SkypeStatus::connectionstatus:connecting";
const string SkypeStatus::CONNECTIONSTATUS_PAUSING = "SkypeStatus::connectionstatus:pausing";
const string SkypeStatus::CONNECTIONSTATUS_ONLINE = "SkypeStatus::connectionstatus:online";

const string SkypeStatus::USERSTATUS_UNKNOWN = "SkypeStatus::userstatus:unknown";
const string SkypeStatus::USERSTATUS_ONLINE = "SkypeStatus::userstatus:online";
const string SkypeStatus::USERSTATUS_OFFLINE = "SkypeStatus::userstatus:offline";
const string SkypeStatus::USERSTATUS_SKYPEME = "SkypeStatus::userstatus:skypeme";
const string SkypeStatus::USERSTATUS_AWAY = "SkypeStatus::userstatus:away";
const string SkypeStatus::USERSTATUS_NA = "SkypeStatus::userstatus:na";
const string SkypeStatus::USERSTATUS_DND = "SkypeStatus::userstatus:dnd";
const string SkypeStatus::USERSTATUS_INVISIBLE = "SkypeStatus::userstatus:invisible";
const string SkypeStatus::USERSTATUS_LOGGEDOUT = "SkypeStatus::userstatus:loggedout";

const string SkypeStatus::ONLINESTATUS_UNKNONW = "SkypeStatus::onlinestatus:unknown";
const string SkypeStatus::ONLINESTATUS_OFFLINE = "SkypeStatus::onlinestatus:offline";
const string SkypeStatus::ONLINESTATUS_ONLINE = "SkypeStatus::onlinestatus:online";
const string SkypeStatus::ONLINESTATUS_AWAY = "SkypeStatus::onlinestatus:away";
const string SkypeStatus::ONLINESTATUS_NA = "SkypeStatus::onlinestatus:na";
const string SkypeStatus::ONLINESTATUS_DND = "SkypeStatus::onlinestatus:dnd";

SkypeStatus::SkypeStatus(string status) {
    this->_status = status;
}

string SkypeStatus::getStatus() {
    return this->_status;
}

bool SkypeStatus::hasStatus(string status) {
    if (status == this->_status) {
        return true;
    }
    else {
        return false;
    }
}