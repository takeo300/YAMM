#ifndef CONN_MGR_H
#define CONN_MGR_H

#include <QObject>
#include <vector>

#include "connection.adapter.abstract.h"

using std::vector;

class Connection_Manager : public QObject
{
    Q_OBJECT
public:
    Connection_Manager();
    bool addAdapter(Connection_Adapter_Abstract *adapter);

protected:
    vector<Connection_Adapter_Abstract*> *adapters;

public slots:
    
};

#endif // CONN_MGR_H
