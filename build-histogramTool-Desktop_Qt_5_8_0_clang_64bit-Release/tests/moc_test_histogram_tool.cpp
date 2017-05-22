/****************************************************************************
** Meta object code from reading C++ file 'test_histogram_tool.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../HistogramTool/tests/test_histogram_tool.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'test_histogram_tool.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TestHistogramTool_t {
    QByteArrayData data[8];
    char stringdata0[98];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TestHistogramTool_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TestHistogramTool_t qt_meta_stringdata_TestHistogramTool = {
    {
QT_MOC_LITERAL(0, 0, 17), // "TestHistogramTool"
QT_MOC_LITERAL(1, 18, 10), // "emptyImage"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 10), // "red256x256"
QT_MOC_LITERAL(4, 41, 12), // "green256x256"
QT_MOC_LITERAL(5, 54, 11), // "blue256x256"
QT_MOC_LITERAL(6, 66, 10), // "rgb256x256"
QT_MOC_LITERAL(7, 77, 20) // "rgb256x256_2_threads"

    },
    "TestHistogramTool\0emptyImage\0\0red256x256\0"
    "green256x256\0blue256x256\0rgb256x256\0"
    "rgb256x256_2_threads"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestHistogramTool[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TestHistogramTool::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TestHistogramTool *_t = static_cast<TestHistogramTool *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->emptyImage(); break;
        case 1: _t->red256x256(); break;
        case 2: _t->green256x256(); break;
        case 3: _t->blue256x256(); break;
        case 4: _t->rgb256x256(); break;
        case 5: _t->rgb256x256_2_threads(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject TestHistogramTool::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TestHistogramTool.data,
      qt_meta_data_TestHistogramTool,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TestHistogramTool::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestHistogramTool::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TestHistogramTool.stringdata0))
        return static_cast<void*>(const_cast< TestHistogramTool*>(this));
    return QObject::qt_metacast(_clname);
}

int TestHistogramTool::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
