/****************************************************************************
** Meta object code from reading C++ file 'CommunicationLayerAdaptor.h'
**
** Created:
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/protocols/skype/CommunicationLayerAdaptor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CommunicationLayerAdaptor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CommunicationLayerAdaptor[] = {

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
      47,   26,
     210,   63,

 // slots: signature, parameters, type, tag, flags
     235,  231,  230,  230, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CommunicationLayerAdaptor[] = {
    "CommunicationLayerAdaptor\0"
    "com.Skype.API.Client\0D-Bus Interface\0"
    "  <interface name=\"com.Skype.API.Client\">\n    <method name=\"Notify"
    "\">\n      <arg direction=\"in\" type=\"s\" name=\"msg\"/>\n    </meth"
    "od>\n  </interface>\n\0"
    "D-Bus Introspection\0\0msg\0Notify(QString)\0"
};

void CommunicationLayerAdaptor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CommunicationLayerAdaptor *_t = static_cast<CommunicationLayerAdaptor *>(_o);
        switch (_id) {
        case 0: _t->Notify((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CommunicationLayerAdaptor::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CommunicationLayerAdaptor::staticMetaObject = {
    { &QDBusAbstractAdaptor::staticMetaObject, qt_meta_stringdata_CommunicationLayerAdaptor,
      qt_meta_data_CommunicationLayerAdaptor, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CommunicationLayerAdaptor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CommunicationLayerAdaptor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CommunicationLayerAdaptor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CommunicationLayerAdaptor))
        return static_cast<void*>(const_cast< CommunicationLayerAdaptor*>(this));
    return QDBusAbstractAdaptor::qt_metacast(_clname);
}

int CommunicationLayerAdaptor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
