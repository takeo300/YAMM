/****************************************************************************
** Meta object code from reading C++ file 'skypeConnection.h'
**
** Created:
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/bindings/skype/skypeConnection.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'skypeConnection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_skypeConnection[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      28,   17,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_skypeConnection[] = {
    "skypeConnection\0\0callId,msg\0"
    "handleCallNotifications(int,QString)\0"
};

void skypeConnection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        skypeConnection *_t = static_cast<skypeConnection *>(_o);
        switch (_id) {
        case 0: _t->handleCallNotifications((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData skypeConnection::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject skypeConnection::staticMetaObject = {
    { &Connection::staticMetaObject, qt_meta_stringdata_skypeConnection,
      qt_meta_data_skypeConnection, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &skypeConnection::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *skypeConnection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *skypeConnection::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_skypeConnection))
        return static_cast<void*>(const_cast< skypeConnection*>(this));
    if (!strcmp(_clname, "Callable"))
        return static_cast< Callable*>(const_cast< skypeConnection*>(this));
    return Connection::qt_metacast(_clname);
}

int skypeConnection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Connection::qt_metacall(_c, _id, _a);
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
