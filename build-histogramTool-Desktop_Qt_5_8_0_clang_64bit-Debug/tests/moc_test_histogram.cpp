/****************************************************************************
** Meta object code from reading C++ file 'test_histogram.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../HistogramTool/tests/test_histogram.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'test_histogram.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TestHistogram_t {
    QByteArrayData data[15];
    char stringdata0[281];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TestHistogram_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TestHistogram_t qt_meta_stringdata_TestHistogram = {
    {
QT_MOC_LITERAL(0, 0, 13), // "TestHistogram"
QT_MOC_LITERAL(1, 14, 16), // "incrementBuckets"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 10), // "Histogram&"
QT_MOC_LITERAL(4, 43, 1), // "h"
QT_MOC_LITERAL(5, 45, 25), // "constructWithValidBuckets"
QT_MOC_LITERAL(6, 71, 24), // "constructWithZeroBuckets"
QT_MOC_LITERAL(7, 96, 27), // "constructWithDefaultBuckets"
QT_MOC_LITERAL(8, 124, 28), // "incrementBucketChangesValues"
QT_MOC_LITERAL(9, 153, 19), // "computeBucketTotals"
QT_MOC_LITERAL(10, 173, 22), // "addSameSizedHistograms"
QT_MOC_LITERAL(11, 196, 27), // "addDifferentSizedHistograms"
QT_MOC_LITERAL(12, 224, 12), // "resetBuckets"
QT_MOC_LITERAL(13, 237, 20), // "requestInvalidBucket"
QT_MOC_LITERAL(14, 258, 22) // "incrementInvalidBucket"

    },
    "TestHistogram\0incrementBuckets\0\0"
    "Histogram&\0h\0constructWithValidBuckets\0"
    "constructWithZeroBuckets\0"
    "constructWithDefaultBuckets\0"
    "incrementBucketChangesValues\0"
    "computeBucketTotals\0addSameSizedHistograms\0"
    "addDifferentSizedHistograms\0resetBuckets\0"
    "requestInvalidBucket\0incrementInvalidBucket"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestHistogram[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    0,   79,    2, 0x08 /* Private */,
      13,    0,   80,    2, 0x08 /* Private */,
      14,    0,   81,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TestHistogram::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TestHistogram *_t = static_cast<TestHistogram *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->incrementBuckets((*reinterpret_cast< Histogram(*)>(_a[1]))); break;
        case 1: _t->constructWithValidBuckets(); break;
        case 2: _t->constructWithZeroBuckets(); break;
        case 3: _t->constructWithDefaultBuckets(); break;
        case 4: _t->incrementBucketChangesValues(); break;
        case 5: _t->computeBucketTotals(); break;
        case 6: _t->addSameSizedHistograms(); break;
        case 7: _t->addDifferentSizedHistograms(); break;
        case 8: _t->resetBuckets(); break;
        case 9: _t->requestInvalidBucket(); break;
        case 10: _t->incrementInvalidBucket(); break;
        default: ;
        }
    }
}

const QMetaObject TestHistogram::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TestHistogram.data,
      qt_meta_data_TestHistogram,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TestHistogram::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestHistogram::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TestHistogram.stringdata0))
        return static_cast<void*>(const_cast< TestHistogram*>(this));
    return QObject::qt_metacast(_clname);
}

int TestHistogram::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
