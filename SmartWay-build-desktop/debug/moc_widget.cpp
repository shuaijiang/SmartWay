/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created: Tue Sep 30 17:17:01 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SmartWay/widget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Widget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x08,
      42,    7,    7,    7, 0x08,
      73,    7,    7,    7, 0x08,
     107,    7,    7,    7, 0x08,
     135,    7,    7,    7, 0x08,
     166,    7,    7,    7, 0x08,
     203,    7,    7,    7, 0x08,
     236,    7,    7,    7, 0x08,
     267,    7,    7,    7, 0x08,
     296,    7,    7,    7, 0x08,
     326,    7,    7,    7, 0x08,
     336,    7,    7,    7, 0x08,
     351,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Widget[] = {
    "Widget\0\0on_pushButton_BusChange_clicked()\0"
    "on_pushButton_Update_clicked()\0"
    "on_pushButton_DeleteBus_clicked()\0"
    "on_pushButton_Add_clicked()\0"
    "on_pushButton_OneBus_clicked()\0"
    "on_pushButton_StationQuery_clicked()\0"
    "on_pushButton_QueryAll_clicked()\0"
    "on_pushButton_Logout_clicked()\0"
    "on_pushButton_Quit_clicked()\0"
    "on_pushButton_Login_clicked()\0showOTO()\0"
    "showOTOPrice()\0showOTODistance()\0"
};

const QMetaObject Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget,
      qt_meta_data_Widget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Widget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Widget))
        return static_cast<void*>(const_cast< Widget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_pushButton_BusChange_clicked(); break;
        case 1: on_pushButton_Update_clicked(); break;
        case 2: on_pushButton_DeleteBus_clicked(); break;
        case 3: on_pushButton_Add_clicked(); break;
        case 4: on_pushButton_OneBus_clicked(); break;
        case 5: on_pushButton_StationQuery_clicked(); break;
        case 6: on_pushButton_QueryAll_clicked(); break;
        case 7: on_pushButton_Logout_clicked(); break;
        case 8: on_pushButton_Quit_clicked(); break;
        case 9: on_pushButton_Login_clicked(); break;
        case 10: showOTO(); break;
        case 11: showOTOPrice(); break;
        case 12: showOTODistance(); break;
        default: ;
        }
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
