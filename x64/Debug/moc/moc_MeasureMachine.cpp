/****************************************************************************
** Meta object code from reading C++ file 'MeasureMachine.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../MeasureMachine.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MeasureMachine.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSMeasureMachineENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMeasureMachineENDCLASS = QtMocHelpers::stringData(
    "MeasureMachine",
    "getCoordinatePoint",
    "double*",
    "",
    "point",
    "deviation",
    "getNormalVector",
    "firstPoint",
    "secondPoint",
    "thirdPoint",
    "getCoefficientEquation",
    "getValueDeterminant",
    "i",
    "j",
    "k",
    "coefFirstEquat",
    "coefSecondEquat",
    "coefThirdEquat",
    "getNewNormalVector",
    "normalVector",
    "fourthPoint",
    "sidesSquareNorVec",
    "getCenterPoint",
    "getRadius",
    "move",
    "textCommand",
    "tuple<QString,QString>",
    "command",
    "pointDeviation",
    "circle",
    "tuple<QString,double*,double*,double*,double,double,double>",
    "dataCommand",
    "namesPoints",
    "centerDeviation",
    "radiusDeviation",
    "center",
    "tuple<double*,double*,double*>",
    "dataCenter",
    "plane",
    "tuple<QString,double*,double*>",
    "projectionPoint",
    "data",
    "pointPlane",
    "nameCommand"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMeasureMachineENDCLASS_t {
    uint offsetsAndSizes[88];
    char stringdata0[15];
    char stringdata1[19];
    char stringdata2[8];
    char stringdata3[1];
    char stringdata4[6];
    char stringdata5[10];
    char stringdata6[16];
    char stringdata7[11];
    char stringdata8[12];
    char stringdata9[11];
    char stringdata10[23];
    char stringdata11[20];
    char stringdata12[2];
    char stringdata13[2];
    char stringdata14[2];
    char stringdata15[15];
    char stringdata16[16];
    char stringdata17[15];
    char stringdata18[19];
    char stringdata19[13];
    char stringdata20[12];
    char stringdata21[18];
    char stringdata22[15];
    char stringdata23[10];
    char stringdata24[5];
    char stringdata25[12];
    char stringdata26[23];
    char stringdata27[8];
    char stringdata28[15];
    char stringdata29[7];
    char stringdata30[60];
    char stringdata31[12];
    char stringdata32[12];
    char stringdata33[16];
    char stringdata34[16];
    char stringdata35[7];
    char stringdata36[31];
    char stringdata37[11];
    char stringdata38[6];
    char stringdata39[31];
    char stringdata40[16];
    char stringdata41[5];
    char stringdata42[11];
    char stringdata43[12];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMeasureMachineENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMeasureMachineENDCLASS_t qt_meta_stringdata_CLASSMeasureMachineENDCLASS = {
    {
        QT_MOC_LITERAL(0, 14),  // "MeasureMachine"
        QT_MOC_LITERAL(15, 18),  // "getCoordinatePoint"
        QT_MOC_LITERAL(34, 7),  // "double*"
        QT_MOC_LITERAL(42, 0),  // ""
        QT_MOC_LITERAL(43, 5),  // "point"
        QT_MOC_LITERAL(49, 9),  // "deviation"
        QT_MOC_LITERAL(59, 15),  // "getNormalVector"
        QT_MOC_LITERAL(75, 10),  // "firstPoint"
        QT_MOC_LITERAL(86, 11),  // "secondPoint"
        QT_MOC_LITERAL(98, 10),  // "thirdPoint"
        QT_MOC_LITERAL(109, 22),  // "getCoefficientEquation"
        QT_MOC_LITERAL(132, 19),  // "getValueDeterminant"
        QT_MOC_LITERAL(152, 1),  // "i"
        QT_MOC_LITERAL(154, 1),  // "j"
        QT_MOC_LITERAL(156, 1),  // "k"
        QT_MOC_LITERAL(158, 14),  // "coefFirstEquat"
        QT_MOC_LITERAL(173, 15),  // "coefSecondEquat"
        QT_MOC_LITERAL(189, 14),  // "coefThirdEquat"
        QT_MOC_LITERAL(204, 18),  // "getNewNormalVector"
        QT_MOC_LITERAL(223, 12),  // "normalVector"
        QT_MOC_LITERAL(236, 11),  // "fourthPoint"
        QT_MOC_LITERAL(248, 17),  // "sidesSquareNorVec"
        QT_MOC_LITERAL(266, 14),  // "getCenterPoint"
        QT_MOC_LITERAL(281, 9),  // "getRadius"
        QT_MOC_LITERAL(291, 4),  // "move"
        QT_MOC_LITERAL(296, 11),  // "textCommand"
        QT_MOC_LITERAL(308, 22),  // "tuple<QString,QString>"
        QT_MOC_LITERAL(331, 7),  // "command"
        QT_MOC_LITERAL(339, 14),  // "pointDeviation"
        QT_MOC_LITERAL(354, 6),  // "circle"
        QT_MOC_LITERAL(361, 59),  // "tuple<QString,double*,double*..."
        QT_MOC_LITERAL(421, 11),  // "dataCommand"
        QT_MOC_LITERAL(433, 11),  // "namesPoints"
        QT_MOC_LITERAL(445, 15),  // "centerDeviation"
        QT_MOC_LITERAL(461, 15),  // "radiusDeviation"
        QT_MOC_LITERAL(477, 6),  // "center"
        QT_MOC_LITERAL(484, 30),  // "tuple<double*,double*,double*>"
        QT_MOC_LITERAL(515, 10),  // "dataCenter"
        QT_MOC_LITERAL(526, 5),  // "plane"
        QT_MOC_LITERAL(532, 30),  // "tuple<QString,double*,double*>"
        QT_MOC_LITERAL(563, 15),  // "projectionPoint"
        QT_MOC_LITERAL(579, 4),  // "data"
        QT_MOC_LITERAL(584, 10),  // "pointPlane"
        QT_MOC_LITERAL(595, 11)   // "nameCommand"
    },
    "MeasureMachine",
    "getCoordinatePoint",
    "double*",
    "",
    "point",
    "deviation",
    "getNormalVector",
    "firstPoint",
    "secondPoint",
    "thirdPoint",
    "getCoefficientEquation",
    "getValueDeterminant",
    "i",
    "j",
    "k",
    "coefFirstEquat",
    "coefSecondEquat",
    "coefThirdEquat",
    "getNewNormalVector",
    "normalVector",
    "fourthPoint",
    "sidesSquareNorVec",
    "getCenterPoint",
    "getRadius",
    "move",
    "textCommand",
    "tuple<QString,QString>",
    "command",
    "pointDeviation",
    "circle",
    "tuple<QString,double*,double*,double*,double,double,double>",
    "dataCommand",
    "namesPoints",
    "centerDeviation",
    "radiusDeviation",
    "center",
    "tuple<double*,double*,double*>",
    "dataCenter",
    "plane",
    "tuple<QString,double*,double*>",
    "projectionPoint",
    "data",
    "pointPlane",
    "nameCommand"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMeasureMachineENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   98,    3, 0x08,    1 /* Private */,
       6,    3,  103,    3, 0x08,    4 /* Private */,
      10,    1,  110,    3, 0x08,    8 /* Private */,
      11,    6,  113,    3, 0x08,   10 /* Private */,
      18,    4,  126,    3, 0x08,   17 /* Private */,
      22,    3,  135,    3, 0x08,   22 /* Private */,
      23,    4,  142,    3, 0x08,   26 /* Private */,
      24,    1,  151,    3, 0x0a,   31 /* Public */,
       4,    2,  154,    3, 0x0a,   33 /* Public */,
      29,    4,  159,    3, 0x0a,   36 /* Public */,
      35,    1,  168,    3, 0x0a,   41 /* Public */,
      38,    2,  171,    3, 0x0a,   43 /* Public */,
      40,    3,  176,    3, 0x0a,   46 /* Public */,
       5,    3,  183,    3, 0x0a,   50 /* Public */,

 // slots: parameters
    0x80000000 | 2, QMetaType::QString, QMetaType::Double,    4,    5,
    0x80000000 | 2, 0x80000000 | 2, 0x80000000 | 2, 0x80000000 | 2,    7,    8,    9,
    0x80000000 | 2, 0x80000000 | 2,    4,
    QMetaType::Double, QMetaType::Int, QMetaType::Int, QMetaType::Int, 0x80000000 | 2, 0x80000000 | 2, 0x80000000 | 2,   12,   13,   14,   15,   16,   17,
    0x80000000 | 2, 0x80000000 | 2, 0x80000000 | 2, 0x80000000 | 2, QMetaType::Double,   19,    7,   20,   21,
    0x80000000 | 2, 0x80000000 | 2, 0x80000000 | 2, 0x80000000 | 2,    7,    8,    9,
    QMetaType::Double, 0x80000000 | 2, 0x80000000 | 2, 0x80000000 | 2, QMetaType::Double,    7,    8,    9,    5,
    QMetaType::QString, QMetaType::QString,   25,
    0x80000000 | 26, QMetaType::QString, QMetaType::Double,   27,   28,
    0x80000000 | 30, QMetaType::QString, QMetaType::QStringList, QMetaType::Double, QMetaType::Double,   31,   32,   33,   34,
    0x80000000 | 26, 0x80000000 | 36,   37,
    0x80000000 | 39, QMetaType::QString, QMetaType::QStringList,   31,   32,
    0x80000000 | 26, QMetaType::QString, 0x80000000 | 2, 0x80000000 | 2,   41,   19,   42,
    QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   43,   41,    5,

       0        // eod
};

Q_CONSTINIT const QMetaObject MeasureMachine::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSMeasureMachineENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMeasureMachineENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMeasureMachineENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MeasureMachine, std::true_type>,
        // method 'getCoordinatePoint'
        QtPrivate::TypeAndForceComplete<double *, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'getNormalVector'
        QtPrivate::TypeAndForceComplete<double *, std::false_type>,
        QtPrivate::TypeAndForceComplete<double *, std::false_type>,
        QtPrivate::TypeAndForceComplete<double *, std::false_type>,
        QtPrivate::TypeAndForceComplete<double *, std::false_type>,
        // method 'getCoefficientEquation'
        QtPrivate::TypeAndForceComplete<double *, std::false_type>,
        QtPrivate::TypeAndForceComplete<double *, std::false_type>,
        // method 'getValueDeterminant'
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<double *, std::false_type>,
        QtPrivate::TypeAndForceComplete<double *, std::false_type>,
        QtPrivate::TypeAndForceComplete<double *, std::false_type>,
        // method 'getNewNormalVector'
        QtPrivate::TypeAndForceComplete<double *, std::false_type>,
        QtPrivate::TypeAndForceComplete<double *, std::false_type>,
        QtPrivate::TypeAndForceComplete<double *, std::false_type>,
        QtPrivate::TypeAndForceComplete<double *, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'getCenterPoint'
        QtPrivate::TypeAndForceComplete<double *, std::false_type>,
        QtPrivate::TypeAndForceComplete<double *, std::false_type>,
        QtPrivate::TypeAndForceComplete<double *, std::false_type>,
        QtPrivate::TypeAndForceComplete<double *, std::false_type>,
        // method 'getRadius'
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double *, std::false_type>,
        QtPrivate::TypeAndForceComplete<double *, std::false_type>,
        QtPrivate::TypeAndForceComplete<double *, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'move'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'point'
        QtPrivate::TypeAndForceComplete<tuple<QString,QString>, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'circle'
        QtPrivate::TypeAndForceComplete<tuple<QString,double*,double*,double*,double,double,double>, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'center'
        QtPrivate::TypeAndForceComplete<tuple<QString,QString>, std::false_type>,
        QtPrivate::TypeAndForceComplete<tuple<double*,double*,double*>, std::false_type>,
        // method 'plane'
        QtPrivate::TypeAndForceComplete<tuple<QString,double*,double*>, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        // method 'projectionPoint'
        QtPrivate::TypeAndForceComplete<tuple<QString,QString>, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<double *, std::false_type>,
        QtPrivate::TypeAndForceComplete<double *, std::false_type>,
        // method 'deviation'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>
    >,
    nullptr
} };

void MeasureMachine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MeasureMachine *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { double* _r = _t->getCoordinatePoint((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])));
            if (_a[0]) *reinterpret_cast< double**>(_a[0]) = std::move(_r); }  break;
        case 1: { double* _r = _t->getNormalVector((*reinterpret_cast< std::add_pointer_t<double*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double*>>(_a[3])));
            if (_a[0]) *reinterpret_cast< double**>(_a[0]) = std::move(_r); }  break;
        case 2: { double* _r = _t->getCoefficientEquation((*reinterpret_cast< std::add_pointer_t<double*>>(_a[1])));
            if (_a[0]) *reinterpret_cast< double**>(_a[0]) = std::move(_r); }  break;
        case 3: { double _r = _t->getValueDeterminant((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<double*>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<double*>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<double*>>(_a[6])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 4: { double* _r = _t->getNewNormalVector((*reinterpret_cast< std::add_pointer_t<double*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double*>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[4])));
            if (_a[0]) *reinterpret_cast< double**>(_a[0]) = std::move(_r); }  break;
        case 5: { double* _r = _t->getCenterPoint((*reinterpret_cast< std::add_pointer_t<double*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double*>>(_a[3])));
            if (_a[0]) *reinterpret_cast< double**>(_a[0]) = std::move(_r); }  break;
        case 6: { double _r = _t->getRadius((*reinterpret_cast< std::add_pointer_t<double*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double*>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[4])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 7: { QString _r = _t->move((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 8: { tuple<QString,QString> _r = _t->point((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])));
            if (_a[0]) *reinterpret_cast< tuple<QString,QString>*>(_a[0]) = std::move(_r); }  break;
        case 9: { tuple<QString,double*,double*,double*,double,double,double> _r = _t->circle((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[4])));
            if (_a[0]) *reinterpret_cast< tuple<QString,double*,double*,double*,double,double,double>*>(_a[0]) = std::move(_r); }  break;
        case 10: { tuple<QString,QString> _r = _t->center((*reinterpret_cast< std::add_pointer_t<tuple<double*,double*,double*>>>(_a[1])));
            if (_a[0]) *reinterpret_cast< tuple<QString,QString>*>(_a[0]) = std::move(_r); }  break;
        case 11: { tuple<QString,double*,double*> _r = _t->plane((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[2])));
            if (_a[0]) *reinterpret_cast< tuple<QString,double*,double*>*>(_a[0]) = std::move(_r); }  break;
        case 12: { tuple<QString,QString> _r = _t->projectionPoint((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double*>>(_a[3])));
            if (_a[0]) *reinterpret_cast< tuple<QString,QString>*>(_a[0]) = std::move(_r); }  break;
        case 13: { QString _r = _t->deviation((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject *MeasureMachine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MeasureMachine::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMeasureMachineENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MeasureMachine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
