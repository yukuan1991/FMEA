/****************************************************************************
** Meta object code from reading C++ file 'progress_label.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../video/progress_label.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'progress_label.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_progress_label_t {
    QByteArrayData data[5];
    char stringdata0[71];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_progress_label_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_progress_label_t qt_meta_stringdata_progress_label = {
    {
QT_MOC_LITERAL(0, 0, 14), // "progress_label"
QT_MOC_LITERAL(1, 15, 16), // "duration_changed"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 16), // "position_changed"
QT_MOC_LITERAL(4, 50, 20) // "stepped_into_invalid"

    },
    "progress_label\0duration_changed\0\0"
    "position_changed\0stepped_into_invalid"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_progress_label[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       3,    1,   32,    2, 0x06 /* Public */,
       4,    2,   35,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    2,    2,

       0        // eod
};

void progress_label::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        progress_label *_t = static_cast<progress_label *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->duration_changed((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 1: _t->position_changed((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 2: _t->stepped_into_invalid((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (progress_label::*_t)(qint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&progress_label::duration_changed)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (progress_label::*_t)(qint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&progress_label::position_changed)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (progress_label::*_t)(qint64 , qint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&progress_label::stepped_into_invalid)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject progress_label::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_progress_label.data,
      qt_meta_data_progress_label,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *progress_label::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *progress_label::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_progress_label.stringdata0))
        return static_cast<void*>(const_cast< progress_label*>(this));
    return QLabel::qt_metacast(_clname);
}

int progress_label::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void progress_label::duration_changed(qint64 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void progress_label::position_changed(qint64 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void progress_label::stepped_into_invalid(qint64 _t1, qint64 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
