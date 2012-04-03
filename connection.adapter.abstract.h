#ifndef CONNECTION_ADAPTER_ABSTRACT_H
#define CONNECTION_ADAPTER_ABSTRACT_H
#include <QObject>
class Connection_Adapter_Abstract : public QObject {
    Q_OBJECT

public:
    virtual void connect() = 0;
};

#endif // CONNECTION_ADAPTER_ABSTRACT_H
