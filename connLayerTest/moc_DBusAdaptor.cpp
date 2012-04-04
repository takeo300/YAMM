/****************************************************************************
** Meta object code from reading C++ file 'DBusAdaptor.h'
**
** Created:
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Skype/CommunicationLayer/DBusAdaptor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DBusAdaptor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ClientAdaptor[] = {

 // content:
       6,       // revision
       0,       // classname
       2,   14, // classinfo
       1,   18, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // classinfo: key, value
      35,   14,
     198,   51,

 // slots: signature, parameters, type, tag, flags
     223,  219,  218,  218, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ClientAdaptor[] = {
    "ClientAdaptor\0com.Skype.API.Client\0"
    "D-Bus Interface\0"
    "  <interface name=\"com.Skype.API.Client\">\n    <method name=\"Notify"
    "\">\n      <arg direction=\"in\" type=\"s\" name=\"msg\"/>\n    </meth"
    "od>\n  </interface>\n\0"
    "D-Bus Introspection\0\0msg\0Notify(QString)\0"
};

void ClientAdaptor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ClientAdaptor *_t = static_cast<ClientAdaptor *>(_o);
        switch (_id) {
        case 0: _t->Notify((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ClientAdaptor::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ClientAdaptor::staticMetaObject = {
    { &QDBusAbstractAdaptor::staticMetaObject, qt_meta_stringdata_ClientAdaptor,
      qt_meta_data_ClientAdaptor, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ClientAdaptor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ClientAdaptor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ClientAdaptor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ClientAdaptor))
        return static_cast<void*>(const_cast< ClientAdaptor*>(this));
    return QDBusAbstractAdaptor::qt_metacast(_clname);
}

int ClientAdaptor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDBusAbstractAdaptor::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
