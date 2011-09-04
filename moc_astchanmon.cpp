/****************************************************************************
** Meta object code from reading C++ file 'astchanmon.h'
**
** Created: Thu Oct 7 16:58:41 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "astchanmon.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'astchanmon.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AstChanMon[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   12,   11,   11, 0x08,
      56,   11,   11,   11, 0x28,

       0        // eod
};

static const char qt_meta_stringdata_AstChanMon[] = {
    "AstChanMon\0\0checked\0"
    "on_actionConnection_triggered(bool)\0"
    "on_actionConnection_triggered()\0"
};

const QMetaObject AstChanMon::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_AstChanMon,
      qt_meta_data_AstChanMon, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AstChanMon::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AstChanMon::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AstChanMon::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AstChanMon))
        return static_cast<void*>(const_cast< AstChanMon*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int AstChanMon::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_actionConnection_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: on_actionConnection_triggered(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
