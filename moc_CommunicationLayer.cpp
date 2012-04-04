/****************************************************************************
** Meta object code from reading C++ file 'CommunicationLayer.h'
**
** Created:
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/protocols/skype/CommunicationLayer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CommunicationLayer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CommunicationLayer[] = {

 // content:
       6,       // revision
       0,       // classname
       1,   14, // classinfo
       2,   16, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // classinfo: key, value
      40,   19,

 // signals: signature, parameters, type, tag, flags
      70,   57,   56,   56, 0x05,

 // slots: signature, parameters, type, tag, flags
      92,   88,   56,   56, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CommunicationLayer[] = {
    "CommunicationLayer\0com.Skype.API.Client\0"
    "D-Bus Interface\0\0notification\0"
    "notified(QString)\0msg\0Notify(QString)\0"
};

void CommunicationLayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CommunicationLayer *_t = static_cast<CommunicationLayer *>(_o);
        switch (_id) {
        case 0: _t->notified((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->Notify((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CommunicationLayer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CommunicationLayer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CommunicationLayer,
      qt_meta_data_CommunicationLayer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CommunicationLayer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CommunicationLayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CommunicationLayer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CommunicationLayer))
        return static_cast<void*>(const_cast< CommunicationLayer*>(this));
    return QObject::qt_metacast(_clname);
}

int CommunicationLayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void CommunicationLayer::notified(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
