/****************************************************************************
** Meta object code from reading C++ file 'video_player.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../video/video_player.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'video_player.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_video_player_t {
    QByteArrayData data[13];
    char stringdata0[206];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_video_player_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_video_player_t qt_meta_stringdata_video_player = {
    {
QT_MOC_LITERAL(0, 0, 12), // "video_player"
QT_MOC_LITERAL(1, 13, 13), // "state_changed"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 24), // "video_player::state_enum"
QT_MOC_LITERAL(4, 53, 16), // "position_changed"
QT_MOC_LITERAL(5, 70, 16), // "duration_changed"
QT_MOC_LITERAL(6, 87, 12), // "mute_changed"
QT_MOC_LITERAL(7, 100, 16), // "seekable_changed"
QT_MOC_LITERAL(8, 117, 13), // "speed_changed"
QT_MOC_LITERAL(9, 131, 12), // "file_changed"
QT_MOC_LITERAL(10, 144, 14), // "volume_changed"
QT_MOC_LITERAL(11, 159, 22), // "start_position_changed"
QT_MOC_LITERAL(12, 182, 23) // "notify_interval_changed"

    },
    "video_player\0state_changed\0\0"
    "video_player::state_enum\0position_changed\0"
    "duration_changed\0mute_changed\0"
    "seekable_changed\0speed_changed\0"
    "file_changed\0volume_changed\0"
    "start_position_changed\0notify_interval_changed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_video_player[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    1,   67,    2, 0x06 /* Public */,
       5,    1,   70,    2, 0x06 /* Public */,
       6,    1,   73,    2, 0x06 /* Public */,
       7,    0,   76,    2, 0x06 /* Public */,
       8,    1,   77,    2, 0x06 /* Public */,
       9,    1,   80,    2, 0x06 /* Public */,
      10,    1,   83,    2, 0x06 /* Public */,
      11,    1,   86,    2, 0x06 /* Public */,
      12,    0,   89,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Float,    2,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void,

       0        // eod
};

void video_player::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        video_player *_t = static_cast<video_player *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->state_changed((*reinterpret_cast< video_player::state_enum(*)>(_a[1]))); break;
        case 1: _t->position_changed((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 2: _t->duration_changed((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 3: _t->mute_changed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->seekable_changed(); break;
        case 5: _t->speed_changed((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 6: _t->file_changed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->volume_changed((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 8: _t->start_position_changed((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 9: _t->notify_interval_changed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (video_player::*_t)(video_player::state_enum );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&video_player::state_changed)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (video_player::*_t)(qint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&video_player::position_changed)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (video_player::*_t)(qint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&video_player::duration_changed)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (video_player::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&video_player::mute_changed)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (video_player::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&video_player::seekable_changed)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (video_player::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&video_player::speed_changed)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (video_player::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&video_player::file_changed)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (video_player::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&video_player::volume_changed)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (video_player::*_t)(qint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&video_player::start_position_changed)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (video_player::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&video_player::notify_interval_changed)) {
                *result = 9;
                return;
            }
        }
    }
}

const QMetaObject video_player::staticMetaObject = {
    { &QtAV::GLWidgetRenderer2::staticMetaObject, qt_meta_stringdata_video_player.data,
      qt_meta_data_video_player,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *video_player::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *video_player::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_video_player.stringdata0))
        return static_cast<void*>(const_cast< video_player*>(this));
    return QtAV::GLWidgetRenderer2::qt_metacast(_clname);
}

int video_player::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QtAV::GLWidgetRenderer2::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void video_player::state_changed(video_player::state_enum _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void video_player::position_changed(qint64 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void video_player::duration_changed(qint64 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void video_player::mute_changed(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void video_player::seekable_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void video_player::speed_changed(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void video_player::file_changed(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void video_player::volume_changed(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void video_player::start_position_changed(qint64 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void video_player::notify_interval_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
