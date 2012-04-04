#include "connection.manager.h"

Connection_Manager::Connection_Manager() {
    this->adapters = new vector<Connection_Adapter_Abstract*>();
}

bool Connection_Manager::addAdapter(Connection_Adapter_Abstract *adapter) {
    this->adapters->push_back(adapter);
    return true;
}
