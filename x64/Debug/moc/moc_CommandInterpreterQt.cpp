/****************************************************************************
** Meta object code from reading C++ file 'CommandInterpreterQt.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../CommandInterpreterQt.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CommandInterpreterQt.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSCommandInterpreterQtENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSCommandInterpreterQtENDCLASS = QtMocHelpers::stringData(
    "CommandInterpreterQt",
    "runButtonClick",
    "",
    "saveFileButtonClick",
    "openFileButtonClick",
    "getReportButtonClick",
    "clearInputButtonClick",
    "clearOutputButtonClick",
    "commentButtonClick",
    "moveButtonClick",
    "pointButtonClick",
    "circleButtonClick",
    "centerButtonClick",
    "planeButtonClick",
    "projectionButtonClick",
    "deviationButtonClick",
    "getCommentResults",
    "command",
    "inputCommands",
    "index",
    "getMoveResults",
    "getPointResults",
    "getCircleResults",
    "getCenterResults",
    "getPlaneResults",
    "getProjectionResults",
    "getDeviationResults",
    "throwError",
    "Errors",
    "error",
    "getNumberCommand",
    "isNumber",
    "QString&",
    "numCommand",
    "determineColorAndOutputResult",
    "r",
    "g",
    "b",
    "nameCommand",
    "result",
    "hasOnlyNumbers",
    "isVectorCorrect",
    "isDeviationCorrect",
    "strDeviation",
    "processButtonClick"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSCommandInterpreterQtENDCLASS_t {
    uint offsetsAndSizes[90];
    char stringdata0[21];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[20];
    char stringdata4[20];
    char stringdata5[21];
    char stringdata6[22];
    char stringdata7[23];
    char stringdata8[19];
    char stringdata9[16];
    char stringdata10[17];
    char stringdata11[18];
    char stringdata12[18];
    char stringdata13[17];
    char stringdata14[22];
    char stringdata15[21];
    char stringdata16[18];
    char stringdata17[8];
    char stringdata18[14];
    char stringdata19[6];
    char stringdata20[15];
    char stringdata21[16];
    char stringdata22[17];
    char stringdata23[17];
    char stringdata24[16];
    char stringdata25[21];
    char stringdata26[20];
    char stringdata27[11];
    char stringdata28[7];
    char stringdata29[6];
    char stringdata30[17];
    char stringdata31[9];
    char stringdata32[9];
    char stringdata33[11];
    char stringdata34[30];
    char stringdata35[2];
    char stringdata36[2];
    char stringdata37[2];
    char stringdata38[12];
    char stringdata39[7];
    char stringdata40[15];
    char stringdata41[16];
    char stringdata42[19];
    char stringdata43[13];
    char stringdata44[19];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSCommandInterpreterQtENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSCommandInterpreterQtENDCLASS_t qt_meta_stringdata_CLASSCommandInterpreterQtENDCLASS = {
    {
        QT_MOC_LITERAL(0, 20),  // "CommandInterpreterQt"
        QT_MOC_LITERAL(21, 14),  // "runButtonClick"
        QT_MOC_LITERAL(36, 0),  // ""
        QT_MOC_LITERAL(37, 19),  // "saveFileButtonClick"
        QT_MOC_LITERAL(57, 19),  // "openFileButtonClick"
        QT_MOC_LITERAL(77, 20),  // "getReportButtonClick"
        QT_MOC_LITERAL(98, 21),  // "clearInputButtonClick"
        QT_MOC_LITERAL(120, 22),  // "clearOutputButtonClick"
        QT_MOC_LITERAL(143, 18),  // "commentButtonClick"
        QT_MOC_LITERAL(162, 15),  // "moveButtonClick"
        QT_MOC_LITERAL(178, 16),  // "pointButtonClick"
        QT_MOC_LITERAL(195, 17),  // "circleButtonClick"
        QT_MOC_LITERAL(213, 17),  // "centerButtonClick"
        QT_MOC_LITERAL(231, 16),  // "planeButtonClick"
        QT_MOC_LITERAL(248, 21),  // "projectionButtonClick"
        QT_MOC_LITERAL(270, 20),  // "deviationButtonClick"
        QT_MOC_LITERAL(291, 17),  // "getCommentResults"
        QT_MOC_LITERAL(309, 7),  // "command"
        QT_MOC_LITERAL(317, 13),  // "inputCommands"
        QT_MOC_LITERAL(331, 5),  // "index"
        QT_MOC_LITERAL(337, 14),  // "getMoveResults"
        QT_MOC_LITERAL(352, 15),  // "getPointResults"
        QT_MOC_LITERAL(368, 16),  // "getCircleResults"
        QT_MOC_LITERAL(385, 16),  // "getCenterResults"
        QT_MOC_LITERAL(402, 15),  // "getPlaneResults"
        QT_MOC_LITERAL(418, 20),  // "getProjectionResults"
        QT_MOC_LITERAL(439, 19),  // "getDeviationResults"
        QT_MOC_LITERAL(459, 10),  // "throwError"
        QT_MOC_LITERAL(470, 6),  // "Errors"
        QT_MOC_LITERAL(477, 5),  // "error"
        QT_MOC_LITERAL(483, 16),  // "getNumberCommand"
        QT_MOC_LITERAL(500, 8),  // "isNumber"
        QT_MOC_LITERAL(509, 8),  // "QString&"
        QT_MOC_LITERAL(518, 10),  // "numCommand"
        QT_MOC_LITERAL(529, 29),  // "determineColorAndOutputResult"
        QT_MOC_LITERAL(559, 1),  // "r"
        QT_MOC_LITERAL(561, 1),  // "g"
        QT_MOC_LITERAL(563, 1),  // "b"
        QT_MOC_LITERAL(565, 11),  // "nameCommand"
        QT_MOC_LITERAL(577, 6),  // "result"
        QT_MOC_LITERAL(584, 14),  // "hasOnlyNumbers"
        QT_MOC_LITERAL(599, 15),  // "isVectorCorrect"
        QT_MOC_LITERAL(615, 18),  // "isDeviationCorrect"
        QT_MOC_LITERAL(634, 12),  // "strDeviation"
        QT_MOC_LITERAL(647, 18)   // "processButtonClick"
    },
    "CommandInterpreterQt",
    "runButtonClick",
    "",
    "saveFileButtonClick",
    "openFileButtonClick",
    "getReportButtonClick",
    "clearInputButtonClick",
    "clearOutputButtonClick",
    "commentButtonClick",
    "moveButtonClick",
    "pointButtonClick",
    "circleButtonClick",
    "centerButtonClick",
    "planeButtonClick",
    "projectionButtonClick",
    "deviationButtonClick",
    "getCommentResults",
    "command",
    "inputCommands",
    "index",
    "getMoveResults",
    "getPointResults",
    "getCircleResults",
    "getCenterResults",
    "getPlaneResults",
    "getProjectionResults",
    "getDeviationResults",
    "throwError",
    "Errors",
    "error",
    "getNumberCommand",
    "isNumber",
    "QString&",
    "numCommand",
    "determineColorAndOutputResult",
    "r",
    "g",
    "b",
    "nameCommand",
    "result",
    "hasOnlyNumbers",
    "isVectorCorrect",
    "isDeviationCorrect",
    "strDeviation",
    "processButtonClick"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSCommandInterpreterQtENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      30,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  194,    2, 0x08,    1 /* Private */,
       3,    0,  195,    2, 0x08,    2 /* Private */,
       4,    0,  196,    2, 0x08,    3 /* Private */,
       5,    0,  197,    2, 0x08,    4 /* Private */,
       6,    0,  198,    2, 0x08,    5 /* Private */,
       7,    0,  199,    2, 0x08,    6 /* Private */,
       8,    0,  200,    2, 0x08,    7 /* Private */,
       9,    0,  201,    2, 0x08,    8 /* Private */,
      10,    0,  202,    2, 0x08,    9 /* Private */,
      11,    0,  203,    2, 0x08,   10 /* Private */,
      12,    0,  204,    2, 0x08,   11 /* Private */,
      13,    0,  205,    2, 0x08,   12 /* Private */,
      14,    0,  206,    2, 0x08,   13 /* Private */,
      15,    0,  207,    2, 0x08,   14 /* Private */,
      16,    3,  208,    2, 0x08,   15 /* Private */,
      20,    3,  215,    2, 0x08,   19 /* Private */,
      21,    3,  222,    2, 0x08,   23 /* Private */,
      22,    3,  229,    2, 0x08,   27 /* Private */,
      23,    3,  236,    2, 0x08,   31 /* Private */,
      24,    3,  243,    2, 0x08,   35 /* Private */,
      25,    3,  250,    2, 0x08,   39 /* Private */,
      26,    3,  257,    2, 0x08,   43 /* Private */,
      27,    2,  264,    2, 0x08,   47 /* Private */,
      30,    1,  269,    2, 0x08,   50 /* Private */,
      31,    1,  272,    2, 0x08,   52 /* Private */,
      34,    5,  275,    2, 0x08,   54 /* Private */,
      40,    2,  286,    2, 0x08,   60 /* Private */,
      41,    2,  291,    2, 0x08,   63 /* Private */,
      42,    2,  296,    2, 0x08,   66 /* Private */,
      44,    1,  301,    2, 0x08,   69 /* Private */,

 // slots: parameters
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList, QMetaType::Int,   17,   18,   19,
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList, QMetaType::Int,   17,   18,   19,
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList, QMetaType::Int,   17,   18,   19,
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList, QMetaType::Int,   17,   18,   19,
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList, QMetaType::Int,   17,   18,   19,
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList, QMetaType::Int,   17,   18,   19,
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList, QMetaType::Int,   17,   18,   19,
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList, QMetaType::Int,   17,   18,   19,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 28,   17,   29,
    QMetaType::QString, QMetaType::QString,   17,
    QMetaType::Bool, 0x80000000 | 32,   33,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString,   35,   36,   37,   38,   39,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString,   17,   38,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString,   17,   38,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString,   38,   43,
    QMetaType::Void, QMetaType::QString,   38,

       0        // eod
};

Q_CONSTINIT const QMetaObject CommandInterpreterQt::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSCommandInterpreterQtENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSCommandInterpreterQtENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSCommandInterpreterQtENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<CommandInterpreterQt, std::true_type>,
        // method 'runButtonClick'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'saveFileButtonClick'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openFileButtonClick'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'getReportButtonClick'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'clearInputButtonClick'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'clearOutputButtonClick'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'commentButtonClick'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'moveButtonClick'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'pointButtonClick'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'circleButtonClick'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'centerButtonClick'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'planeButtonClick'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'projectionButtonClick'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'deviationButtonClick'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'getCommentResults'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getMoveResults'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getPointResults'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getCircleResults'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getCenterResults'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getPlaneResults'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getProjectionResults'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getDeviationResults'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'throwError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<Errors, std::false_type>,
        // method 'getNumberCommand'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'isNumber'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString &, std::false_type>,
        // method 'determineColorAndOutputResult'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'hasOnlyNumbers'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'isVectorCorrect'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'isDeviationCorrect'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'processButtonClick'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>
    >,
    nullptr
} };

void CommandInterpreterQt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CommandInterpreterQt *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->runButtonClick(); break;
        case 1: _t->saveFileButtonClick(); break;
        case 2: _t->openFileButtonClick(); break;
        case 3: _t->getReportButtonClick(); break;
        case 4: _t->clearInputButtonClick(); break;
        case 5: _t->clearOutputButtonClick(); break;
        case 6: _t->commentButtonClick(); break;
        case 7: _t->moveButtonClick(); break;
        case 8: _t->pointButtonClick(); break;
        case 9: _t->circleButtonClick(); break;
        case 10: _t->centerButtonClick(); break;
        case 11: _t->planeButtonClick(); break;
        case 12: _t->projectionButtonClick(); break;
        case 13: _t->deviationButtonClick(); break;
        case 14: _t->getCommentResults((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 15: _t->getMoveResults((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 16: _t->getPointResults((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 17: _t->getCircleResults((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 18: _t->getCenterResults((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 19: _t->getPlaneResults((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 20: _t->getProjectionResults((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 21: _t->getDeviationResults((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 22: _t->throwError((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Errors>>(_a[2]))); break;
        case 23: { QString _r = _t->getNumberCommand((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 24: { bool _r = _t->isNumber((*reinterpret_cast< std::add_pointer_t<QString&>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 25: _t->determineColorAndOutputResult((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5]))); break;
        case 26: { bool _r = _t->hasOnlyNumbers((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 27: { bool _r = _t->isVectorCorrect((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 28: { bool _r = _t->isDeviationCorrect((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 29: _t->processButtonClick((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *CommandInterpreterQt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CommandInterpreterQt::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSCommandInterpreterQtENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int CommandInterpreterQt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 30)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 30;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 30)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 30;
    }
    return _id;
}
QT_WARNING_POP
