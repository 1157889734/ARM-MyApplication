/****************************************************************************
** Meta object code from reading C++ file 'recordplaywidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "recordplaywidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'recordplaywidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_recordPlayWidget_t {
    QByteArrayData data[55];
    char stringdata0[1006];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_recordPlayWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_recordPlayWidget_t qt_meta_stringdata_recordPlayWidget = {
    {
QT_MOC_LITERAL(0, 0, 16), // "recordPlayWidget"
QT_MOC_LITERAL(1, 17, 26), // "alarmPushButoonClickSignal"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 15), // "registOutSignal"
QT_MOC_LITERAL(4, 61, 23), // "setRecordPlayFlagSignal"
QT_MOC_LITERAL(5, 85, 5), // "iFlag"
QT_MOC_LITERAL(6, 91, 27), // "recordTableWidgetFillSignal"
QT_MOC_LITERAL(7, 119, 15), // "recordSeletPlay"
QT_MOC_LITERAL(8, 135, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(9, 153, 4), // "item"
QT_MOC_LITERAL(10, 158, 18), // "videoPollingSignal"
QT_MOC_LITERAL(11, 177, 20), // "setSliderValueSignal"
QT_MOC_LITERAL(12, 198, 6), // "iValue"
QT_MOC_LITERAL(13, 205, 31), // "downloadProcessBarDisplaySignal"
QT_MOC_LITERAL(14, 237, 11), // "iEnableFlag"
QT_MOC_LITERAL(15, 249, 32), // "setDownloadProcessBarValueSignal"
QT_MOC_LITERAL(16, 282, 21), // "closeRecordPlaySignal"
QT_MOC_LITERAL(17, 304, 19), // "setRangeLabelSignal"
QT_MOC_LITERAL(18, 324, 24), // "alarmPushButoonClickSlot"
QT_MOC_LITERAL(19, 349, 19), // "alarmHappenCtrlSlot"
QT_MOC_LITERAL(20, 369, 15), // "alarmHappenSlot"
QT_MOC_LITERAL(21, 385, 14), // "alarmClearSlot"
QT_MOC_LITERAL(22, 400, 15), // "recordQuerySlot"
QT_MOC_LITERAL(23, 416, 18), // "recordQueryEndSlot"
QT_MOC_LITERAL(24, 435, 20), // "registOutButtonClick"
QT_MOC_LITERAL(25, 456, 18), // "recordDownloadSlot"
QT_MOC_LITERAL(26, 475, 19), // "recordPlayStartSlot"
QT_MOC_LITERAL(27, 495, 15), // "recordPauseSlot"
QT_MOC_LITERAL(28, 511, 18), // "recordPlayStopSlot"
QT_MOC_LITERAL(29, 530, 25), // "recordPlayFastForwardSlot"
QT_MOC_LITERAL(30, 556, 25), // "recordPlaySlowForwardSlot"
QT_MOC_LITERAL(31, 582, 21), // "recordPlayLastOneSlot"
QT_MOC_LITERAL(32, 604, 21), // "recordPlayNextOneSlot"
QT_MOC_LITERAL(33, 626, 16), // "playPlusStepSlot"
QT_MOC_LITERAL(34, 643, 17), // "playMinusStepSlot"
QT_MOC_LITERAL(35, 661, 15), // "carNoChangeSlot"
QT_MOC_LITERAL(36, 677, 19), // "recordSelectionSlot"
QT_MOC_LITERAL(37, 697, 14), // "recordPlaySlot"
QT_MOC_LITERAL(38, 712, 18), // "playSliderMoveSlot"
QT_MOC_LITERAL(39, 731, 8), // "iPosTime"
QT_MOC_LITERAL(40, 740, 19), // "playSliderPressSlot"
QT_MOC_LITERAL(41, 760, 14), // "positionchaged"
QT_MOC_LITERAL(42, 775, 3), // "pos"
QT_MOC_LITERAL(43, 779, 11), // "getduration"
QT_MOC_LITERAL(44, 791, 8), // "playtime"
QT_MOC_LITERAL(45, 800, 10), // "onTimerOut"
QT_MOC_LITERAL(46, 811, 22), // "setPlaySliderValueSlot"
QT_MOC_LITERAL(47, 834, 29), // "downloadProcessBarDisplaySlot"
QT_MOC_LITERAL(48, 864, 30), // "setDownloadProcessBarValueSlot"
QT_MOC_LITERAL(49, 895, 19), // "closeRecordPlaySlot"
QT_MOC_LITERAL(50, 915, 25), // "recordTableWidgetFillSlot"
QT_MOC_LITERAL(51, 941, 25), // "recordTableWidgetFillFunc"
QT_MOC_LITERAL(52, 967, 17), // "setRangeLabelSlot"
QT_MOC_LITERAL(53, 985, 11), // "setPosition"
QT_MOC_LITERAL(54, 997, 8) // "position"

    },
    "recordPlayWidget\0alarmPushButoonClickSignal\0"
    "\0registOutSignal\0setRecordPlayFlagSignal\0"
    "iFlag\0recordTableWidgetFillSignal\0"
    "recordSeletPlay\0QTableWidgetItem*\0"
    "item\0videoPollingSignal\0setSliderValueSignal\0"
    "iValue\0downloadProcessBarDisplaySignal\0"
    "iEnableFlag\0setDownloadProcessBarValueSignal\0"
    "closeRecordPlaySignal\0setRangeLabelSignal\0"
    "alarmPushButoonClickSlot\0alarmHappenCtrlSlot\0"
    "alarmHappenSlot\0alarmClearSlot\0"
    "recordQuerySlot\0recordQueryEndSlot\0"
    "registOutButtonClick\0recordDownloadSlot\0"
    "recordPlayStartSlot\0recordPauseSlot\0"
    "recordPlayStopSlot\0recordPlayFastForwardSlot\0"
    "recordPlaySlowForwardSlot\0"
    "recordPlayLastOneSlot\0recordPlayNextOneSlot\0"
    "playPlusStepSlot\0playMinusStepSlot\0"
    "carNoChangeSlot\0recordSelectionSlot\0"
    "recordPlaySlot\0playSliderMoveSlot\0"
    "iPosTime\0playSliderPressSlot\0"
    "positionchaged\0pos\0getduration\0playtime\0"
    "onTimerOut\0setPlaySliderValueSlot\0"
    "downloadProcessBarDisplaySlot\0"
    "setDownloadProcessBarValueSlot\0"
    "closeRecordPlaySlot\0recordTableWidgetFillSlot\0"
    "recordTableWidgetFillFunc\0setRangeLabelSlot\0"
    "setPosition\0position"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_recordPlayWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      44,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  234,    2, 0x06 /* Public */,
       3,    0,  235,    2, 0x06 /* Public */,
       4,    1,  236,    2, 0x06 /* Public */,
       6,    0,  239,    2, 0x06 /* Public */,
       7,    1,  240,    2, 0x06 /* Public */,
      10,    0,  243,    2, 0x06 /* Public */,
      11,    1,  244,    2, 0x06 /* Public */,
      13,    1,  247,    2, 0x06 /* Public */,
      15,    1,  250,    2, 0x06 /* Public */,
      16,    0,  253,    2, 0x06 /* Public */,
      17,    0,  254,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      18,    0,  255,    2, 0x0a /* Public */,
      19,    0,  256,    2, 0x0a /* Public */,
      20,    0,  257,    2, 0x0a /* Public */,
      21,    0,  258,    2, 0x0a /* Public */,
      22,    0,  259,    2, 0x0a /* Public */,
      23,    0,  260,    2, 0x0a /* Public */,
      24,    0,  261,    2, 0x0a /* Public */,
      25,    0,  262,    2, 0x0a /* Public */,
      26,    0,  263,    2, 0x0a /* Public */,
      27,    0,  264,    2, 0x0a /* Public */,
      28,    0,  265,    2, 0x0a /* Public */,
      29,    0,  266,    2, 0x0a /* Public */,
      30,    0,  267,    2, 0x0a /* Public */,
      31,    0,  268,    2, 0x0a /* Public */,
      32,    0,  269,    2, 0x0a /* Public */,
      33,    0,  270,    2, 0x0a /* Public */,
      34,    0,  271,    2, 0x0a /* Public */,
      35,    0,  272,    2, 0x0a /* Public */,
      36,    1,  273,    2, 0x0a /* Public */,
      37,    1,  276,    2, 0x0a /* Public */,
      38,    1,  279,    2, 0x0a /* Public */,
      40,    1,  282,    2, 0x0a /* Public */,
      41,    1,  285,    2, 0x0a /* Public */,
      43,    1,  288,    2, 0x0a /* Public */,
      45,    0,  291,    2, 0x0a /* Public */,
      46,    1,  292,    2, 0x0a /* Public */,
      47,    1,  295,    2, 0x0a /* Public */,
      48,    1,  298,    2, 0x0a /* Public */,
      49,    0,  301,    2, 0x0a /* Public */,
      50,    0,  302,    2, 0x0a /* Public */,
      51,    0,  303,    2, 0x0a /* Public */,
      52,    0,  304,    2, 0x0a /* Public */,
      53,    1,  305,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::Int,   39,
    QMetaType::Void, QMetaType::Int,   39,
    QMetaType::Void, QMetaType::LongLong,   42,
    QMetaType::Void, QMetaType::LongLong,   44,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   54,

       0        // eod
};

void recordPlayWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<recordPlayWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->alarmPushButoonClickSignal(); break;
        case 1: _t->registOutSignal(); break;
        case 2: _t->setRecordPlayFlagSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->recordTableWidgetFillSignal(); break;
        case 4: _t->recordSeletPlay((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 5: _t->videoPollingSignal(); break;
        case 6: _t->setSliderValueSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->downloadProcessBarDisplaySignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setDownloadProcessBarValueSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->closeRecordPlaySignal(); break;
        case 10: _t->setRangeLabelSignal(); break;
        case 11: _t->alarmPushButoonClickSlot(); break;
        case 12: _t->alarmHappenCtrlSlot(); break;
        case 13: _t->alarmHappenSlot(); break;
        case 14: _t->alarmClearSlot(); break;
        case 15: _t->recordQuerySlot(); break;
        case 16: _t->recordQueryEndSlot(); break;
        case 17: _t->registOutButtonClick(); break;
        case 18: _t->recordDownloadSlot(); break;
        case 19: _t->recordPlayStartSlot(); break;
        case 20: _t->recordPauseSlot(); break;
        case 21: _t->recordPlayStopSlot(); break;
        case 22: _t->recordPlayFastForwardSlot(); break;
        case 23: _t->recordPlaySlowForwardSlot(); break;
        case 24: _t->recordPlayLastOneSlot(); break;
        case 25: _t->recordPlayNextOneSlot(); break;
        case 26: _t->playPlusStepSlot(); break;
        case 27: _t->playMinusStepSlot(); break;
        case 28: _t->carNoChangeSlot(); break;
        case 29: _t->recordSelectionSlot((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 30: _t->recordPlaySlot((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 31: _t->playSliderMoveSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 32: _t->playSliderPressSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 33: _t->positionchaged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 34: _t->getduration((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 35: _t->onTimerOut(); break;
        case 36: _t->setPlaySliderValueSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 37: _t->downloadProcessBarDisplaySlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 38: _t->setDownloadProcessBarValueSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 39: _t->closeRecordPlaySlot(); break;
        case 40: _t->recordTableWidgetFillSlot(); break;
        case 41: _t->recordTableWidgetFillFunc(); break;
        case 42: _t->setRangeLabelSlot(); break;
        case 43: _t->setPosition((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (recordPlayWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&recordPlayWidget::alarmPushButoonClickSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (recordPlayWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&recordPlayWidget::registOutSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (recordPlayWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&recordPlayWidget::setRecordPlayFlagSignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (recordPlayWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&recordPlayWidget::recordTableWidgetFillSignal)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (recordPlayWidget::*)(QTableWidgetItem * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&recordPlayWidget::recordSeletPlay)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (recordPlayWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&recordPlayWidget::videoPollingSignal)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (recordPlayWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&recordPlayWidget::setSliderValueSignal)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (recordPlayWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&recordPlayWidget::downloadProcessBarDisplaySignal)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (recordPlayWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&recordPlayWidget::setDownloadProcessBarValueSignal)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (recordPlayWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&recordPlayWidget::closeRecordPlaySignal)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (recordPlayWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&recordPlayWidget::setRangeLabelSignal)) {
                *result = 10;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject recordPlayWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_recordPlayWidget.data,
    qt_meta_data_recordPlayWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *recordPlayWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *recordPlayWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_recordPlayWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int recordPlayWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 44)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 44;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 44)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 44;
    }
    return _id;
}

// SIGNAL 0
void recordPlayWidget::alarmPushButoonClickSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void recordPlayWidget::registOutSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void recordPlayWidget::setRecordPlayFlagSignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void recordPlayWidget::recordTableWidgetFillSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void recordPlayWidget::recordSeletPlay(QTableWidgetItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void recordPlayWidget::videoPollingSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void recordPlayWidget::setSliderValueSignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void recordPlayWidget::downloadProcessBarDisplaySignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void recordPlayWidget::setDownloadProcessBarValueSignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void recordPlayWidget::closeRecordPlaySignal()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void recordPlayWidget::setRangeLabelSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE