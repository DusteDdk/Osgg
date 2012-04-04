/********************************************************************************
** Form generated from reading ui file 'untitled.ui'
**
** Created: Sun Feb 15 16:47:04 2009
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_UNTITLED_H
#define UI_UNTITLED_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGraphicsView>
#include <QtGui/QGroupBox>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *gameTab;
    QGroupBox *groupBox_2;
    QCheckBox *chSound;
    QGroupBox *groupBox_3;
    QCheckBox *chIs;
    QCheckBox *chEditor;
    QGroupBox *groupBox;
    QLabel *label;
    QToolButton *btnSelectBgColor;
    QCheckBox *chVsync;
    QCheckBox *chShowFps;
    QCheckBox *chFullScreen;
    QPushButton *btnStart;
    QGroupBox *groupBoxLevels;
    QTabWidget *tabLvl;
    QWidget *tab;
    QLabel *label_2;
    QSpinBox *numStartLevel;
    QListWidget *lstStdLvl;
    QWidget *tab_2;
    QPushButton *btnRemoveCustom;
    QPushButton *btnAddCustom;
    QPushButton *btnShare;
    QListWidget *lstCustomLvl;
    QPushButton *btnCreate;
    QGraphicsView *lvlPreview;
    QLabel *txtBestTime;
    QLabel *txtTimesPlayed;
    QLabel *txtTimesCompleted;
    QLabel *txtTimesDead;
    QWidget *demoTab;
    QWidget *tab_3;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *txtDataDir;
    QLineEdit *txtExecPath;
    QToolButton *btnBrowseDataDir;
    QToolButton *btnBrowseExecPath;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->resize(421, 507);
    QIcon icon;
    icon.addPixmap(QPixmap(QString::fromUtf8(":/icon/icon.png")), QIcon::Normal, QIcon::Off);
    MainWindow->setWindowIcon(icon);
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    tabWidget = new QTabWidget(centralwidget);
    tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
    tabWidget->setGeometry(QRect(10, 10, 401, 471));
    gameTab = new QWidget();
    gameTab->setObjectName(QString::fromUtf8("gameTab"));
    groupBox_2 = new QGroupBox(gameTab);
    groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
    groupBox_2->setGeometry(QRect(210, 70, 181, 51));
    chSound = new QCheckBox(groupBox_2);
    chSound->setObjectName(QString::fromUtf8("chSound"));
    chSound->setGeometry(QRect(10, 20, 81, 21));
    chSound->setChecked(true);
    groupBox_3 = new QGroupBox(gameTab);
    groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
    groupBox_3->setGeometry(QRect(210, 0, 181, 71));
    chIs = new QCheckBox(groupBox_3);
    chIs->setObjectName(QString::fromUtf8("chIs"));
    chIs->setGeometry(QRect(10, 20, 121, 24));
    chEditor = new QCheckBox(groupBox_3);
    chEditor->setObjectName(QString::fromUtf8("chEditor"));
    chEditor->setGeometry(QRect(10, 40, 91, 24));
    groupBox = new QGroupBox(gameTab);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    groupBox->setGeometry(QRect(10, 60, 191, 91));
    label = new QLabel(groupBox);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(10, 60, 101, 21));
    btnSelectBgColor = new QToolButton(groupBox);
    btnSelectBgColor->setObjectName(QString::fromUtf8("btnSelectBgColor"));
    btnSelectBgColor->setGeometry(QRect(120, 60, 51, 24));
    btnSelectBgColor->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
    chVsync = new QCheckBox(groupBox);
    chVsync->setObjectName(QString::fromUtf8("chVsync"));
    chVsync->setGeometry(QRect(10, 40, 61, 21));
    chVsync->setChecked(true);
    chShowFps = new QCheckBox(groupBox);
    chShowFps->setObjectName(QString::fromUtf8("chShowFps"));
    chShowFps->setGeometry(QRect(120, 20, 71, 21));
    chShowFps->setChecked(false);
    chFullScreen = new QCheckBox(groupBox);
    chFullScreen->setObjectName(QString::fromUtf8("chFullScreen"));
    chFullScreen->setGeometry(QRect(10, 20, 80, 24));
    btnStart = new QPushButton(gameTab);
    btnStart->setObjectName(QString::fromUtf8("btnStart"));
    btnStart->setGeometry(QRect(10, 10, 191, 51));
    btnStart->setIcon(icon);
    btnStart->setIconSize(QSize(32, 32));
    groupBoxLevels = new QGroupBox(gameTab);
    groupBoxLevels->setObjectName(QString::fromUtf8("groupBoxLevels"));
    groupBoxLevels->setGeometry(QRect(10, 150, 381, 291));
    tabLvl = new QTabWidget(groupBoxLevels);
    tabLvl->setObjectName(QString::fromUtf8("tabLvl"));
    tabLvl->setGeometry(QRect(10, 20, 151, 261));
    tab = new QWidget();
    tab->setObjectName(QString::fromUtf8("tab"));
    label_2 = new QLabel(tab);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setGeometry(QRect(10, 10, 81, 18));
    numStartLevel = new QSpinBox(tab);
    numStartLevel->setObjectName(QString::fromUtf8("numStartLevel"));
    numStartLevel->setGeometry(QRect(90, 0, 51, 31));
    lstStdLvl = new QListWidget(tab);
    lstStdLvl->setObjectName(QString::fromUtf8("lstStdLvl"));
    lstStdLvl->setGeometry(QRect(0, 30, 141, 201));
    lstStdLvl->setSortingEnabled(false);
    tabLvl->addTab(tab, QString());
    tab_2 = new QWidget();
    tab_2->setObjectName(QString::fromUtf8("tab_2"));
    btnRemoveCustom = new QPushButton(tab_2);
    btnRemoveCustom->setObjectName(QString::fromUtf8("btnRemoveCustom"));
    btnRemoveCustom->setGeometry(QRect(90, 200, 51, 31));
    btnAddCustom = new QPushButton(tab_2);
    btnAddCustom->setObjectName(QString::fromUtf8("btnAddCustom"));
    btnAddCustom->setGeometry(QRect(0, 200, 51, 31));
    btnShare = new QPushButton(tab_2);
    btnShare->setObjectName(QString::fromUtf8("btnShare"));
    btnShare->setGeometry(QRect(60, 0, 51, 31));
    lstCustomLvl = new QListWidget(tab_2);
    lstCustomLvl->setObjectName(QString::fromUtf8("lstCustomLvl"));
    lstCustomLvl->setGeometry(QRect(0, 30, 141, 171));
    btnCreate = new QPushButton(tab_2);
    btnCreate->setObjectName(QString::fromUtf8("btnCreate"));
    btnCreate->setGeometry(QRect(0, 0, 51, 31));
    tabLvl->addTab(tab_2, QString());
    lvlPreview = new QGraphicsView(groupBoxLevels);
    lvlPreview->setObjectName(QString::fromUtf8("lvlPreview"));
    lvlPreview->setGeometry(QRect(170, 20, 201, 181));
    txtBestTime = new QLabel(groupBoxLevels);
    txtBestTime->setObjectName(QString::fromUtf8("txtBestTime"));
    txtBestTime->setGeometry(QRect(170, 200, 141, 21));
    txtTimesPlayed = new QLabel(groupBoxLevels);
    txtTimesPlayed->setObjectName(QString::fromUtf8("txtTimesPlayed"));
    txtTimesPlayed->setGeometry(QRect(170, 220, 141, 21));
    txtTimesCompleted = new QLabel(groupBoxLevels);
    txtTimesCompleted->setObjectName(QString::fromUtf8("txtTimesCompleted"));
    txtTimesCompleted->setGeometry(QRect(170, 240, 131, 21));
    txtTimesDead = new QLabel(groupBoxLevels);
    txtTimesDead->setObjectName(QString::fromUtf8("txtTimesDead"));
    txtTimesDead->setGeometry(QRect(170, 260, 141, 21));
    tabWidget->addTab(gameTab, QString());
    demoTab = new QWidget();
    demoTab->setObjectName(QString::fromUtf8("demoTab"));
    tabWidget->addTab(demoTab, QString());
    tab_3 = new QWidget();
    tab_3->setObjectName(QString::fromUtf8("tab_3"));
    label_3 = new QLabel(tab_3);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setGeometry(QRect(20, 10, 91, 31));
    label_4 = new QLabel(tab_3);
    label_4->setObjectName(QString::fromUtf8("label_4"));
    label_4->setGeometry(QRect(10, 37, 101, 31));
    txtDataDir = new QLineEdit(tab_3);
    txtDataDir->setObjectName(QString::fromUtf8("txtDataDir"));
    txtDataDir->setGeometry(QRect(110, 10, 221, 28));
    txtExecPath = new QLineEdit(tab_3);
    txtExecPath->setObjectName(QString::fromUtf8("txtExecPath"));
    txtExecPath->setGeometry(QRect(110, 40, 221, 28));
    btnBrowseDataDir = new QToolButton(tab_3);
    btnBrowseDataDir->setObjectName(QString::fromUtf8("btnBrowseDataDir"));
    btnBrowseDataDir->setGeometry(QRect(340, 10, 22, 24));
    btnBrowseExecPath = new QToolButton(tab_3);
    btnBrowseExecPath->setObjectName(QString::fromUtf8("btnBrowseExecPath"));
    btnBrowseExecPath->setGeometry(QRect(340, 40, 22, 24));
    tabWidget->addTab(tab_3, QString());
    MainWindow->setCentralWidget(centralwidget);
    statusbar = new QStatusBar(MainWindow);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    MainWindow->setStatusBar(statusbar);

    retranslateUi(MainWindow);
    QObject::connect(lstStdLvl, SIGNAL(currentRowChanged(int)), numStartLevel, SLOT(setValue(int)));

    tabWidget->setCurrentIndex(0);
    tabLvl->setCurrentIndex(0);


    QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "OldSkoolGravityGame - Launcher", 0, QApplication::UnicodeUTF8));
    groupBox_2->setTitle(QApplication::translate("MainWindow", "Sound", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_TOOLTIP
    chSound->setToolTip(QApplication::translate("MainWindow", "Enable in-game sound effects", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP

    chSound->setText(QApplication::translate("MainWindow", "Sound On", 0, QApplication::UnicodeUTF8));
    groupBox_3->setTitle(QApplication::translate("MainWindow", "Gameplay", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_TOOLTIP
    chIs->setToolTip(QApplication::translate("MainWindow", "Save progress automatically when you land on a base", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP

    chIs->setText(QApplication::translate("MainWindow", "Intermediate Save", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_TOOLTIP
    chEditor->setToolTip(QApplication::translate("MainWindow", "Start in level-editor mode", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP

    chEditor->setText(QApplication::translate("MainWindow", "Level Editor", 0, QApplication::UnicodeUTF8));
    groupBox->setTitle(QApplication::translate("MainWindow", "Screen", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("MainWindow", "Background color:", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_TOOLTIP
    btnSelectBgColor->setToolTip(QString());
#endif // QT_NO_TOOLTIP

    btnSelectBgColor->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_TOOLTIP
    chVsync->setToolTip(QApplication::translate("MainWindow", "Turn on Vsync for smooth gameplay.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP

    chVsync->setText(QApplication::translate("MainWindow", "vsync", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_TOOLTIP
    chShowFps->setToolTip(QApplication::translate("MainWindow", "Show how many fps the game runs at, this value should be close to 60 for optimal play.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP

    chShowFps->setText(QApplication::translate("MainWindow", "showfps", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_TOOLTIP
    chFullScreen->setToolTip(QApplication::translate("MainWindow", "Run game in fullscreen mode", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP

    chFullScreen->setText(QApplication::translate("MainWindow", "Fullscreen", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_TOOLTIP
    btnStart->setToolTip(QApplication::translate("MainWindow", "Start the game!", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP

    btnStart->setText(QApplication::translate("MainWindow", "Start Osgg!", 0, QApplication::UnicodeUTF8));
    groupBoxLevels->setTitle(QApplication::translate("MainWindow", "Levels", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("MainWindow", "Starting Level:", 0, QApplication::UnicodeUTF8));
    tabLvl->setTabText(tabLvl->indexOf(tab), QApplication::translate("MainWindow", "Standard", 0, QApplication::UnicodeUTF8));
    btnRemoveCustom->setText(QApplication::translate("MainWindow", "Remove", 0, QApplication::UnicodeUTF8));
    btnAddCustom->setText(QApplication::translate("MainWindow", "Add", 0, QApplication::UnicodeUTF8));
    btnShare->setText(QApplication::translate("MainWindow", "Share", 0, QApplication::UnicodeUTF8));
    btnCreate->setText(QApplication::translate("MainWindow", "Create", 0, QApplication::UnicodeUTF8));
    tabLvl->setTabText(tabLvl->indexOf(tab_2), QApplication::translate("MainWindow", "Custom", 0, QApplication::UnicodeUTF8));
    txtBestTime->setText(QApplication::translate("MainWindow", "besttime", 0, QApplication::UnicodeUTF8));
    txtTimesPlayed->setText(QApplication::translate("MainWindow", "timesplayed", 0, QApplication::UnicodeUTF8));
    txtTimesCompleted->setText(QApplication::translate("MainWindow", "timescompleted", 0, QApplication::UnicodeUTF8));
    txtTimesDead->setText(QApplication::translate("MainWindow", "timeddead", 0, QApplication::UnicodeUTF8));
    tabWidget->setTabText(tabWidget->indexOf(gameTab), QApplication::translate("MainWindow", "Game", 0, QApplication::UnicodeUTF8));
    tabWidget->setTabText(tabWidget->indexOf(demoTab), QApplication::translate("MainWindow", "Demoes", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("MainWindow", "osgg data path:", 0, QApplication::UnicodeUTF8));
    label_4->setText(QApplication::translate("MainWindow", "osgg executable:", 0, QApplication::UnicodeUTF8));
    btnBrowseDataDir->setText(QApplication::translate("MainWindow", "...", "Browse for the data directory", QApplication::UnicodeUTF8));
    btnBrowseExecPath->setText(QApplication::translate("MainWindow", "...", "Browse for the executable", QApplication::UnicodeUTF8));
    tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Settings", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNTITLED_H
