/****************************************************************************
** Meta object code from reading C++ file 'Report.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Report.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Report.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSReportENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSReportENDCLASS = QtMocHelpers::stringData(
    "Report",
    "generateCodeForPoint",
    "",
    "nameCommand",
    "dataCommand",
    "generateCodeForCircle",
    "generateCodeForPlane",
    "generateCodeForDeviation",
    "createReport",
    "QHash<int,QHash<QString,QString>>",
    "commandsResults",
    "fileName"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSReportENDCLASS_t {
    uint offsetsAndSizes[24];
    char stringdata0[7];
    char stringdata1[21];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[12];
    char stringdata5[22];
    char stringdata6[21];
    char stringdata7[25];
    char stringdata8[13];
    char stringdata9[34];
    char stringdata10[16];
    char stringdata11[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSReportENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSReportENDCLASS_t qt_meta_stringdata_CLASSReportENDCLASS = {
    {
        QT_MOC_LITERAL(0, 6),  // "Report"
        QT_MOC_LITERAL(7, 20),  // "generateCodeForPoint"
        QT_MOC_LITERAL(28, 0),  // ""
        QT_MOC_LITERAL(29, 11),  // "nameCommand"
        QT_MOC_LITERAL(41, 11),  // "dataCommand"
        QT_MOC_LITERAL(53, 21),  // "generateCodeForCircle"
        QT_MOC_LITERAL(75, 20),  // "generateCodeForPlane"
        QT_MOC_LITERAL(96, 24),  // "generateCodeForDeviation"
        QT_MOC_LITERAL(121, 12),  // "createReport"
        QT_MOC_LITERAL(134, 33),  // "QHash<int,QHash<QString,QStri..."
        QT_MOC_LITERAL(168, 15),  // "commandsResults"
        QT_MOC_LITERAL(184, 8)   // "fileName"
    },
    "Report",
    "generateCodeForPoint",
    "",
    "nameCommand",
    "dataCommand",
    "generateCodeForCircle",
    "generateCodeForPlane",
    "generateCodeForDeviation",
    "createReport",
    "QHash<int,QHash<QString,QString>>",
    "commandsResults",
    "fileName"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSReportENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   44,    2, 0x08,    1 /* Private */,
       5,    2,   49,    2, 0x08,    4 /* Private */,
       6,    2,   54,    2, 0x08,    7 /* Private */,
       7,    1,   59,    2, 0x08,   10 /* Private */,
       8,    2,   62,    2, 0x0a,   12 /* Public */,

 // slots: parameters
    QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::QString, QMetaType::QString,    4,
    QMetaType::QString, 0x80000000 | 9, QMetaType::QString,   10,   11,

       0        // eod
};

Q_CONSTINIT const QMetaObject Report::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSReportENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSReportENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSReportENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Report, std::true_type>,
        // method 'generateCodeForPoint'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'generateCodeForCircle'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'generateCodeForPlane'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'generateCodeForDeviation'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'createReport'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QHash<int,QHash<QString,QString>>, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>
    >,
    nullptr
} };

void Report::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Report *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { QString _r = _t->generateCodeForPoint((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 1: { QString _r = _t->generateCodeForCircle((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 2: { QString _r = _t->generateCodeForPlane((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 3: { QString _r = _t->generateCodeForDeviation((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 4: { QString _r = _t->createReport((*reinterpret_cast< std::add_pointer_t<QHash<int,QHash<QString,QString>>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject *Report::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Report::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSReportENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Report::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
