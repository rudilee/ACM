/****************************************************************************
** Meta object code from reading C++ file 'asthostform.h'
**
** Created: Thu Oct 7 16:58:44 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "asthostform.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'asthostform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AstHostForm[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   13,   12,   12, 0x0a,
      49,   12,   12,   12, 0x2a,
      92,   73,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AstHostForm[] = {
    "AstHostForm\0\0checked\0onConnectionTriggered(bool)\0"
    "onConnectionTriggered()\0subject,parameters\0"
    "onResponseEvent(QString,QHash<QString,QString>)\0"
};

const QMetaObject AstHostForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AstHostForm,
      qt_meta_data_AstHostForm, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AstHostForm::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AstHostForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AstHostForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AstHostForm))
        return static_cast<void*>(const_cast< AstHostForm*>(this));
    return QWidget::qt_metacast(_clname);
}

int AstHostForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: onConnectionTriggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: onConnectionTriggered(); break;
        case 2: onResponseEvent((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QHash<QString,QString>(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
