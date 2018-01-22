/****************************************************************************
** Meta object code from reading C++ file 'video_widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../video/video_widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'video_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_video_widget_t {
    QByteArrayData data[22];
    char stringdata0[384];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_video_widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_video_widget_t qt_meta_stringdata_video_widget = {
    {
QT_MOC_LITERAL(0, 0, 12), // "video_widget"
QT_MOC_LITERAL(1, 13, 13), // "speed_changed"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 13), // "state_changed"
QT_MOC_LITERAL(4, 42, 24), // "video_player::state_enum"
QT_MOC_LITERAL(5, 67, 16), // "duration_changed"
QT_MOC_LITERAL(6, 84, 12), // "file_changed"
QT_MOC_LITERAL(7, 97, 20), // "stepped_into_invalid"
QT_MOC_LITERAL(8, 118, 15), // "on_play_clicked"
QT_MOC_LITERAL(9, 134, 15), // "on_stop_clicked"
QT_MOC_LITERAL(10, 150, 25), // "on_volume_bar_sliderMoved"
QT_MOC_LITERAL(11, 176, 8), // "position"
QT_MOC_LITERAL(12, 185, 15), // "on_mute_clicked"
QT_MOC_LITERAL(13, 201, 26), // "on_player_duration_changed"
QT_MOC_LITERAL(14, 228, 8), // "max_time"
QT_MOC_LITERAL(15, 237, 23), // "on_player_state_changed"
QT_MOC_LITERAL(16, 261, 5), // "state"
QT_MOC_LITERAL(17, 267, 22), // "on_player_mute_changed"
QT_MOC_LITERAL(18, 290, 7), // "is_mute"
QT_MOC_LITERAL(19, 298, 29), // "on_progress_bar_sliderPressed"
QT_MOC_LITERAL(20, 328, 30), // "on_progress_bar_sliderReleased"
QT_MOC_LITERAL(21, 359, 24) // "playable_section_control"

    },
    "video_widget\0speed_changed\0\0state_changed\0"
    "video_player::state_enum\0duration_changed\0"
    "file_changed\0stepped_into_invalid\0"
    "on_play_clicked\0on_stop_clicked\0"
    "on_volume_bar_sliderMoved\0position\0"
    "on_mute_clicked\0on_player_duration_changed\0"
    "max_time\0on_player_state_changed\0state\0"
    "on_player_mute_changed\0is_mute\0"
    "on_progress_bar_sliderPressed\0"
    "on_progress_bar_sliderReleased\0"
    "playable_section_control"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_video_widget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       3,    1,   92,    2, 0x06 /* Public */,
       5,    1,   95,    2, 0x06 /* Public */,
       6,    1,   98,    2, 0x06 /* Public */,
       7,    2,  101,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,  106,    2, 0x08 /* Private */,
       9,    0,  107,    2, 0x08 /* Private */,
      10,    1,  108,    2, 0x08 /* Private */,
      12,    0,  111,    2, 0x08 /* Private */,
      13,    1,  112,    2, 0x08 /* Private */,
      15,    1,  115,    2, 0x08 /* Private */,
      17,    1,  118,    2, 0x08 /* Private */,
      19,    0,  121,    2, 0x08 /* Private */,
      20,    0,  122,    2, 0x08 /* Private */,
      21,    1,  123,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Float,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,   14,
    QMetaType::Void, 0x80000000 | 4,   16,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,   11,

       0        // eod
};

void video_widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        video_widget *_t = static_cast<video_widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->speed_changed((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: _t->state_changed((*reinterpret_cast< video_player::state_enum(*)>(_a[1]))); break;
        case 2: _t->duration_changed((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 3: _t->file_changed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->stepped_into_invalid((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 5: _t->on_play_clicked(); break;
        case 6: _t->on_stop_clicked(); break;
        case 7: _t->on_volume_bar_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_mute_clicked(); break;
        case 9: _t->on_player_duration_changed((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 10: _t->on_player_state_changed((*reinterpret_cast< video_player::state_enum(*)>(_a[1]))); break;
        case 11: _t->on_player_mute_changed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->on_progress_bar_sliderPressed(); break;
        case 13: _t->on_progress_bar_sliderReleased(); break;
        case 14: _t->playable_section_control((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (video_widget::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&video_widget::speed_changed)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (video_widget::*_t)(video_player::state_enum );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&video_widget::state_changed)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (video_widget::*_t)(qint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&video_widget::duration_changed)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (video_widget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&video_widget::file_changed)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (video_widget::*_t)(qint64 , qint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&video_widget::stepped_into_invalid)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject video_widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_video_widget.data,
      qt_meta_data_video_widget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *video_widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *video_widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_video_widget.stringdata0))
        return static_cast<void*>(const_cast< video_widget*>(this));
    return QWidget::qt_metacast(_clname);
}

int video_widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void video_widget::speed_changed(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void video_widget::state_changed(video_player::state_enum _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void video_widget::duration_changed(qint64 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void video_widget::file_changed(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void video_widget::stepped_into_invalid(qint64 _t1, qint64 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
