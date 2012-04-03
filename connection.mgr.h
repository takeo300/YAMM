#ifndef CONN_MGR_H
#define CONN_MGR_H

#include <QObject>
#include <conn.adapter.abstract.h>

class ConnMgr : public QObject
{
    Q_OBJECT
public:
    ConnMgr(QObject *parent = 0);
    bool addAdapter(Conn_Adapter_Abstract adapter);

protected:

public slots:
    
};

#endif // CONN_MGR_H
