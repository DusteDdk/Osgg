/****************************************************************************
** Meta object code from reading C++ file 'wtf.h'
**
** Created: Thu Sep 13 11:04:22 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "wtf.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wtf.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_mW[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       6,    4,    3,    3, 0x08,
      41,    4,    3,    3, 0x08,
      77,    3,    3,    3, 0x08,
      99,    3,    3,    3, 0x08,
     129,    3,    3,    3, 0x08,
     160,    3,    3,    3, 0x08,
     195,  190,    3,    3, 0x08,
     241,  239,    3,    3, 0x08,
     276,    3,    3,    3, 0x08,
     302,    3,    3,    3, 0x08,
     331,    3,    3,    3, 0x08,
     354,    3,    3,    3, 0x08,
     375,    3,    3,    3, 0x08,
     402,    3,    3,    3, 0x08,
     433,  427,    3,    3, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_mW[] = {
    "mW\0\0s\0on_txtDataDir_textChanged(QString)\0"
    "on_txtExecPath_textChanged(QString)\0"
    "on_btnStart_clicked()\0"
    "on_btnBrowseDataDir_clicked()\0"
    "on_btnBrowseExecPath_clicked()\0"
    "on_btnSelectBgColor_clicked()\0text\0"
    "on_lstCustomLvl_currentTextChanged(QString)\0"
    "l\0on_numStartLevel_valueChanged(int)\0"
    "on_btnAddCustom_clicked()\0"
    "on_btnRemoveCustom_clicked()\0"
    "on_btnCreate_clicked()\0on_btnEdit_clicked()\0"
    "on_btnDemoBrowse_clicked()\0"
    "on_btnPlayDemo_clicked()\0index\0"
    "on_tabLvlCurrentChanged(int)\0"
};

const QMetaObject mW::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_mW,
      qt_meta_data_mW, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &mW::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *mW::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *mW::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_mW))
        return static_cast<void*>(const_cast< mW*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int mW::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_txtDataDir_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: on_txtExecPath_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: on_btnStart_clicked(); break;
        case 3: on_btnBrowseDataDir_clicked(); break;
        case 4: on_btnBrowseExecPath_clicked(); break;
        case 5: on_btnSelectBgColor_clicked(); break;
        case 6: on_lstCustomLvl_currentTextChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: on_numStartLevel_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: on_btnAddCustom_clicked(); break;
        case 9: on_btnRemoveCustom_clicked(); break;
        case 10: on_btnCreate_clicked(); break;
        case 11: on_btnEdit_clicked(); break;
        case 12: on_btnDemoBrowse_clicked(); break;
        case 13: on_btnPlayDemo_clicked(); break;
        case 14: on_tabLvlCurrentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
