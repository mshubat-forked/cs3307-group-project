/****************************************************************************
** Meta object code from reading C++ file 'summarywindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../TestingGUI/summarywindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'summarywindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SummaryWindow_t {
    QByteArrayData data[12];
    char stringdata0[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SummaryWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SummaryWindow_t qt_meta_stringdata_SummaryWindow = {
    {
QT_MOC_LITERAL(0, 0, 13), // "SummaryWindow"
QT_MOC_LITERAL(1, 14, 9), // "make_root"
QT_MOC_LITERAL(2, 24, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(3, 41, 0), // ""
QT_MOC_LITERAL(4, 42, 6), // "parent"
QT_MOC_LITERAL(5, 49, 8), // "category"
QT_MOC_LITERAL(6, 58, 4), // "date"
QT_MOC_LITERAL(7, 63, 12), // "faculty_name"
QT_MOC_LITERAL(8, 76, 9), // "num_hours"
QT_MOC_LITERAL(9, 86, 12), // "num_students"
QT_MOC_LITERAL(10, 99, 10), // "make_child"
QT_MOC_LITERAL(11, 110, 33) // "on_actionTeaching_Graph_trigg..."

    },
    "SummaryWindow\0make_root\0QTreeWidgetItem*\0"
    "\0parent\0category\0date\0faculty_name\0"
    "num_hours\0num_students\0make_child\0"
    "on_actionTeaching_Graph_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SummaryWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    6,   29,    3, 0x08 /* Private */,
      10,    6,   42,    3, 0x08 /* Private */,
      11,    0,   55,    3, 0x08 /* Private */,

 // slots: parameters
    0x80000000 | 2, 0x80000000 | 2, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    4,    5,    6,    7,    8,    9,
    0x80000000 | 2, 0x80000000 | 2, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    4,    5,    6,    7,    8,    9,
    QMetaType::Void,

       0        // eod
};

void SummaryWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SummaryWindow *_t = static_cast<SummaryWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QTreeWidgetItem* _r = _t->make_root((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])));
            if (_a[0]) *reinterpret_cast< QTreeWidgetItem**>(_a[0]) = _r; }  break;
        case 1: { QTreeWidgetItem* _r = _t->make_child((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])));
            if (_a[0]) *reinterpret_cast< QTreeWidgetItem**>(_a[0]) = _r; }  break;
        case 2: _t->on_actionTeaching_Graph_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject SummaryWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SummaryWindow.data,
      qt_meta_data_SummaryWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SummaryWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SummaryWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SummaryWindow.stringdata0))
        return static_cast<void*>(const_cast< SummaryWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int SummaryWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
