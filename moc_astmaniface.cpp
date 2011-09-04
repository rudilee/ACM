/****************************************************************************
** Meta object code from reading C++ file 'astmaniface.h'
**
** Created: Thu Oct 7 16:58:42 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "astmaniface.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'astmaniface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AstManIface[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      39,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      26,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,
      31,   12,   12,   12, 0x05,
      52,   12,   12,   12, 0x05,
      85,   66,   12,   12, 0x05,
     148,  131,   12,   12, 0x05,
     213,  193,   12,   12, 0x05,
     276,  261,   12,   12, 0x05,
     364,  298,   12,   12, 0x05,
     446,  423,   12,   12, 0x05,
     502,  479,   12,   12, 0x05,
     579,  541,   12,   12, 0x05,
     648,  622,   12,   12, 0x05,
     722,  690,   12,   12, 0x05,
     835,  771,   12,   12, 0x05,
     902,  541,   12,   12, 0x05,
     961,  947,   12,   12, 0x05,
     997,  989,   12,   12, 0x05,
    1022,  989,   12,   12, 0x05,
    1072, 1045,   12,   12, 0x05,
    1140, 1118,   12,   12, 0x05,
    1187, 1179,   12,   12, 0x05,
    1225, 1208,   12,   12, 0x05,
    1250,  690,   12,   12, 0x05,
    1377, 1297,   12,   12, 0x05,
    1458,   12,   12,   12, 0x05,
    1506, 1480,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
    1574, 1546,   12,   12, 0x0a,
    1636, 1619,   12,   12, 0x0a,
    1686, 1667,   12,   12, 0x0a,
    1733, 1716,   12,   12, 0x0a,
    1763,   12,   12,   12, 0x0a,
    1780,   12,   12,   12, 0x0a,
    1795,   12,   12,   12, 0x0a,
    1812, 1716,   12,   12, 0x0a,
    1851, 1842,   12,   12, 0x0a,
    1882,   12,   12,   12, 0x08,
    1896,   12,   12,   12, 0x08,
    1913,   12,   12,   12, 0x08,
    1951,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AstManIface[] = {
    "AstManIface\0\0SocketConnected()\0"
    "SocketDisconnected()\0SocketError()\0"
    "subject,parameters\0"
    "ResponseEvent(QString,QHash<QString,QString>)\0"
    "event,parameters\0"
    "ReceiveEvent(QString,QHash<QString,QString>)\0"
    "response,parameters\0"
    "ReceiveResponse(QString,QHash<QString,QString>)\0"
    "callDataRecord\0CdrEvent(QStringList)\0"
    "source,destination,callerID,callerIDName,srcUniqueID,destUniqueID\0"
    "DialEvent(QString,QString,QString,QString,QString,QString)\0"
    "channel,uniqueID,cause\0"
    "HangupEvent(QString,QString,int)\0"
    "channel,state,uniqueID\0"
    "MusicOnHoldEvent(QString,bool,QString)\0"
    "channel1,channel2,uniqueID1,uniqueID2\0"
    "LinkEvent(QString,QString,QString,QString)\0"
    "channel,callerID,uniqueID\0"
    "NewcalleridEvent(QString,QString,QString)\0"
    "channel,state,callerID,uniqueID\0"
    "NewchannelEvent(QString,QString,QString,QString)\0"
    "channel,context,extension,priority,application,appData,uniqueID\0"
    "NewextenEvent(QString,QString,QString,int,QString,QString,QString)\0"
    "UnlinkEvent(QString,QString,QString,QString)\0"
    "alarm,channel\0AlarmEvent(QString,QString)\0"
    "channel\0AlarmClearEvent(QString)\0"
    "DNDStateEvent(QString)\0"
    "peer,peerStatus,cause,time\0"
    "PeerStatusEvent(QString,QString,QString,long)\0"
    "channel,domain,status\0"
    "RegistryEvent(QString,QString,QString)\0"
    "message\0ReloadEvent(QString)\0"
    "shutdown,restart\0ShutdownEvent(bool,bool)\0"
    "NewstateEvent(QString,QString,QString,QString)\0"
    "channel,callerID,account,state,context,extension,priority,seconds,link"
    ",uniqueID\0"
    "Status(QString,QString,QString,QString,QString,QString,int,long,QStrin"
    "g,QString)\0"
    "StatusCompleteEvent()\0response,actionID,message\0"
    "ActionResponse(QString,QString,QString)\0"
    "server,port,username,secret\0"
    "ActionLogin(QString,quint16,QString,QString)\0"
    "command,actionID\0ActionCommand(QString,QString)\0"
    "eventMask,actionID\0ActionEvents(QString,QString)\0"
    "channel,actionID\0ActionHangup(QString,QString)\0"
    "ActionIAXpeers()\0ActionLogoff()\0"
    "ActionSIPpeers()\0ActionStatus(QString,QString)\0"
    "actionID\0ActionZapShowChannels(QString)\0"
    "onConnected()\0onDisconnected()\0"
    "onError(QAbstractSocket::SocketError)\0"
    "onReadyRead()\0"
};

const QMetaObject AstManIface::staticMetaObject = {
    { &QTcpSocket::staticMetaObject, qt_meta_stringdata_AstManIface,
      qt_meta_data_AstManIface, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AstManIface::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AstManIface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AstManIface::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AstManIface))
        return static_cast<void*>(const_cast< AstManIface*>(this));
    return QTcpSocket::qt_metacast(_clname);
}

int AstManIface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: SocketConnected(); break;
        case 1: SocketDisconnected(); break;
        case 2: SocketError(); break;
        case 3: ResponseEvent((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QHash<QString,QString>(*)>(_a[2]))); break;
        case 4: ReceiveEvent((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QHash<QString,QString>(*)>(_a[2]))); break;
        case 5: ReceiveResponse((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QHash<QString,QString>(*)>(_a[2]))); break;
        case 6: CdrEvent((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 7: DialEvent((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6]))); break;
        case 8: HangupEvent((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 9: MusicOnHoldEvent((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 10: LinkEvent((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 11: NewcalleridEvent((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 12: NewchannelEvent((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 13: NewextenEvent((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7]))); break;
        case 14: UnlinkEvent((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 15: AlarmEvent((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 16: AlarmClearEvent((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 17: DNDStateEvent((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 18: PeerStatusEvent((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< long(*)>(_a[4]))); break;
        case 19: RegistryEvent((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 20: ReloadEvent((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 21: ShutdownEvent((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 22: NewstateEvent((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 23: Status((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< long(*)>(_a[8])),(*reinterpret_cast< QString(*)>(_a[9])),(*reinterpret_cast< QString(*)>(_a[10]))); break;
        case 24: StatusCompleteEvent(); break;
        case 25: ActionResponse((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 26: ActionLogin((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 27: ActionCommand((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 28: ActionEvents((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 29: ActionHangup((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 30: ActionIAXpeers(); break;
        case 31: ActionLogoff(); break;
        case 32: ActionSIPpeers(); break;
        case 33: ActionStatus((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 34: ActionZapShowChannels((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 35: onConnected(); break;
        case 36: onDisconnected(); break;
        case 37: onError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 38: onReadyRead(); break;
        default: ;
        }
        _id -= 39;
    }
    return _id;
}

// SIGNAL 0
void AstManIface::SocketConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void AstManIface::SocketDisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void AstManIface::SocketError()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void AstManIface::ResponseEvent(QString _t1, QHash<QString,QString> _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void AstManIface::ReceiveEvent(QString _t1, QHash<QString,QString> _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void AstManIface::ReceiveResponse(QString _t1, QHash<QString,QString> _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void AstManIface::CdrEvent(QStringList _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void AstManIface::DialEvent(QString _t1, QString _t2, QString _t3, QString _t4, QString _t5, QString _t6)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void AstManIface::HangupEvent(QString _t1, QString _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void AstManIface::MusicOnHoldEvent(QString _t1, bool _t2, QString _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void AstManIface::LinkEvent(QString _t1, QString _t2, QString _t3, QString _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void AstManIface::NewcalleridEvent(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void AstManIface::NewchannelEvent(QString _t1, QString _t2, QString _t3, QString _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void AstManIface::NewextenEvent(QString _t1, QString _t2, QString _t3, int _t4, QString _t5, QString _t6, QString _t7)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void AstManIface::UnlinkEvent(QString _t1, QString _t2, QString _t3, QString _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void AstManIface::AlarmEvent(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void AstManIface::AlarmClearEvent(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void AstManIface::DNDStateEvent(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void AstManIface::PeerStatusEvent(QString _t1, QString _t2, QString _t3, long _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void AstManIface::RegistryEvent(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void AstManIface::ReloadEvent(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void AstManIface::ShutdownEvent(bool _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}

// SIGNAL 22
void AstManIface::NewstateEvent(QString _t1, QString _t2, QString _t3, QString _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 23
void AstManIface::Status(QString _t1, QString _t2, QString _t3, QString _t4, QString _t5, QString _t6, int _t7, long _t8, QString _t9, QString _t10)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)), const_cast<void*>(reinterpret_cast<const void*>(&_t8)), const_cast<void*>(reinterpret_cast<const void*>(&_t9)), const_cast<void*>(reinterpret_cast<const void*>(&_t10)) };
    QMetaObject::activate(this, &staticMetaObject, 23, _a);
}

// SIGNAL 24
void AstManIface::StatusCompleteEvent()
{
    QMetaObject::activate(this, &staticMetaObject, 24, 0);
}

// SIGNAL 25
void AstManIface::ActionResponse(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 25, _a);
}
QT_END_MOC_NAMESPACE
