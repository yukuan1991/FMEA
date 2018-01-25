/****************************************************************************
** Meta object code from reading C++ file 'ribbon.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ribbon.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ribbon.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ribbon_t {
    QByteArrayData data[8];
    char stringdata0[71];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ribbon_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ribbon_t qt_meta_stringdata_ribbon = {
    {
QT_MOC_LITERAL(0, 0, 6), // "ribbon"
QT_MOC_LITERAL(1, 7, 8), // "file_new"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 9), // "file_open"
QT_MOC_LITERAL(4, 27, 9), // "file_save"
QT_MOC_LITERAL(5, 37, 11), // "file_saveas"
QT_MOC_LITERAL(6, 49, 9), // "file_exit"
QT_MOC_LITERAL(7, 59, 11) // "set_enabled"

    },
    "ribbon\0file_new\0\0file_open\0file_save\0"
    "file_saveas\0file_exit\0set_enabled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ribbon[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,
       5,    0,   47,    2, 0x06 /* Public */,
       6,    0,   48,    2, 0x06 /* Public */,
       7,    1,   49,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void ribbon::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ribbon *_t = static_cast<ribbon *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->file_new(); break;
        case 1: _t->file_open(); break;
        case 2: _t->file_save(); break;
        case 3: _t->file_saveas(); break;
        case 4: _t->file_exit(); break;
        case 5: _t->set_enabled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ribbon::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ribbon::file_new)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ribbon::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ribbon::file_open)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ribbon::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ribbon::file_save)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (ribbon::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ribbon::file_saveas)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (ribbon::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ribbon::file_exit)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (ribbon::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ribbon::set_enabled)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject ribbon::staticMetaObject = {
    { &QTabWidget::staticMetaObject, qt_meta_stringdata_ribbon.data,
      qt_meta_data_ribbon,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ribbon::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ribbon::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ribbon.stringdata0))
        return static_cast<void*>(const_cast< ribbon*>(this));
    return QTabWidget::qt_metacast(_clname);
}

int ribbon::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ribbon::file_new()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ribbon::file_open()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ribbon::file_save()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ribbon::file_saveas()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ribbon::file_exit()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void ribbon::set_enabled(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
struct qt_meta_stringdata_ribbon_button_t {
    QByteArrayData data[1];
    char stringdata0[14];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ribbon_button_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ribbon_button_t qt_meta_stringdata_ribbon_button = {
    {
QT_MOC_LITERAL(0, 0, 13) // "ribbon_button"

    },
    "ribbon_button"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ribbon_button[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void ribbon_button::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject ribbon_button::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_ribbon_button.data,
      qt_meta_data_ribbon_button,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ribbon_button::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ribbon_button::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ribbon_button.stringdata0))
        return static_cast<void*>(const_cast< ribbon_button*>(this));
    return QPushButton::qt_metacast(_clname);
}

int ribbon_button::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_ribbon_menu_t {
    QByteArrayData data[1];
    char stringdata0[12];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ribbon_menu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ribbon_menu_t qt_meta_stringdata_ribbon_menu = {
    {
QT_MOC_LITERAL(0, 0, 11) // "ribbon_menu"

    },
    "ribbon_menu"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ribbon_menu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void ribbon_menu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject ribbon_menu::staticMetaObject = {
    { &QMenu::staticMetaObject, qt_meta_stringdata_ribbon_menu.data,
      qt_meta_data_ribbon_menu,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ribbon_menu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ribbon_menu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ribbon_menu.stringdata0))
        return static_cast<void*>(const_cast< ribbon_menu*>(this));
    return QMenu::qt_metacast(_clname);
}

int ribbon_menu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMenu::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_ribbon_tool_t {
    QByteArrayData data[1];
    char stringdata0[12];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ribbon_tool_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ribbon_tool_t qt_meta_stringdata_ribbon_tool = {
    {
QT_MOC_LITERAL(0, 0, 11) // "ribbon_tool"

    },
    "ribbon_tool"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ribbon_tool[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void ribbon_tool::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject ribbon_tool::staticMetaObject = {
    { &QToolButton::staticMetaObject, qt_meta_stringdata_ribbon_tool.data,
      qt_meta_data_ribbon_tool,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ribbon_tool::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ribbon_tool::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ribbon_tool.stringdata0))
        return static_cast<void*>(const_cast< ribbon_tool*>(this));
    return QToolButton::qt_metacast(_clname);
}

int ribbon_tool::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QToolButton::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_ribbon_bar_t {
    QByteArrayData data[1];
    char stringdata0[11];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ribbon_bar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ribbon_bar_t qt_meta_stringdata_ribbon_bar = {
    {
QT_MOC_LITERAL(0, 0, 10) // "ribbon_bar"

    },
    "ribbon_bar"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ribbon_bar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void ribbon_bar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject ribbon_bar::staticMetaObject = {
    { &QTabBar::staticMetaObject, qt_meta_stringdata_ribbon_bar.data,
      qt_meta_data_ribbon_bar,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ribbon_bar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ribbon_bar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ribbon_bar.stringdata0))
        return static_cast<void*>(const_cast< ribbon_bar*>(this));
    return QTabBar::qt_metacast(_clname);
}

int ribbon_bar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabBar::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_ribbon_edit_t {
    QByteArrayData data[1];
    char stringdata0[12];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ribbon_edit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ribbon_edit_t qt_meta_stringdata_ribbon_edit = {
    {
QT_MOC_LITERAL(0, 0, 11) // "ribbon_edit"

    },
    "ribbon_edit"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ribbon_edit[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void ribbon_edit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject ribbon_edit::staticMetaObject = {
    { &QLineEdit::staticMetaObject, qt_meta_stringdata_ribbon_edit.data,
      qt_meta_data_ribbon_edit,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ribbon_edit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ribbon_edit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ribbon_edit.stringdata0))
        return static_cast<void*>(const_cast< ribbon_edit*>(this));
    return QLineEdit::qt_metacast(_clname);
}

int ribbon_edit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLineEdit::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_layout_horizontal_t {
    QByteArrayData data[1];
    char stringdata0[18];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_layout_horizontal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_layout_horizontal_t qt_meta_stringdata_layout_horizontal = {
    {
QT_MOC_LITERAL(0, 0, 17) // "layout_horizontal"

    },
    "layout_horizontal"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_layout_horizontal[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void layout_horizontal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject layout_horizontal::staticMetaObject = {
    { &QHBoxLayout::staticMetaObject, qt_meta_stringdata_layout_horizontal.data,
      qt_meta_data_layout_horizontal,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *layout_horizontal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *layout_horizontal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_layout_horizontal.stringdata0))
        return static_cast<void*>(const_cast< layout_horizontal*>(this));
    return QHBoxLayout::qt_metacast(_clname);
}

int layout_horizontal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QHBoxLayout::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_ribbon_menu_item_t {
    QByteArrayData data[1];
    char stringdata0[17];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ribbon_menu_item_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ribbon_menu_item_t qt_meta_stringdata_ribbon_menu_item = {
    {
QT_MOC_LITERAL(0, 0, 16) // "ribbon_menu_item"

    },
    "ribbon_menu_item"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ribbon_menu_item[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void ribbon_menu_item::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject ribbon_menu_item::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ribbon_menu_item.data,
      qt_meta_data_ribbon_menu_item,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ribbon_menu_item::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ribbon_menu_item::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ribbon_menu_item.stringdata0))
        return static_cast<void*>(const_cast< ribbon_menu_item*>(this));
    return QWidget::qt_metacast(_clname);
}

int ribbon_menu_item::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
