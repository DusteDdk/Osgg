/********************************************************************************
** Form generated from reading UI file 'untitled.ui'
**
** Created: Fri Apr 12 14:48:42 2013
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UNTITLED_H
#define UI_UNTITLED_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <lvlpreviewview.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *gameTab;
    QVBoxLayout *verticalLayout_3;
    QPushButton *btnStart;
    QGroupBox *groupBoxLevels;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabLvl;
    QWidget *tab;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSpinBox *numStartLevel;
    QListWidget *lstStdLvl;
    QWidget *tab_2;
    QGridLayout *gridLayout_8;
    QPushButton *btnCreate;
    QPushButton *btnEdit;
    QListWidget *lstCustomLvl;
    QPushButton *btnAddCustom;
    QPushButton *btnRemoveCustom;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QLabel *txtTimesPlayed;
    QLabel *txtBestTime;
    QLabel *txtTimesCompleted;
    QLabel *txtTimesDead;
    lvlpreviewview *lvlPreview;
    QWidget *demoTab;
    QVBoxLayout *verticalLayout_4;
    QPushButton *btnPlayDemo;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QLineEdit *txtDemoLevel;
    QPushButton *btnDemoBrowse;
    QListWidget *lstDemo;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_2;
    QLineEdit *txtExecPath;
    QToolButton *btnBrowseExecPath;
    QLabel *label_3;
    QLineEdit *txtDataDir;
    QToolButton *btnBrowseDataDir;
    QLabel *label_4;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QCheckBox *chFullScreen;
    QCheckBox *chShowFps;
    QCheckBox *chVsync;
    QLabel *label;
    QToolButton *btnSelectBgColor;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout_3;
    QCheckBox *chSound;
    QGroupBox *groupBox_3;
    QFormLayout *formLayout_2;
    QCheckBox *chIs;
    QSpacerItem *verticalSpacer;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(484, 466);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy1);
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy2);
        gameTab = new QWidget();
        gameTab->setObjectName(QString::fromUtf8("gameTab"));
        verticalLayout_3 = new QVBoxLayout(gameTab);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        btnStart = new QPushButton(gameTab);
        btnStart->setObjectName(QString::fromUtf8("btnStart"));
        btnStart->setIcon(icon);
        btnStart->setIconSize(QSize(32, 32));

        verticalLayout_3->addWidget(btnStart);

        groupBoxLevels = new QGroupBox(gameTab);
        groupBoxLevels->setObjectName(QString::fromUtf8("groupBoxLevels"));
        gridLayout_4 = new QGridLayout(groupBoxLevels);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, -1, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tabLvl = new QTabWidget(groupBoxLevels);
        tabLvl->setObjectName(QString::fromUtf8("tabLvl"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tabLvl->sizePolicy().hasHeightForWidth());
        tabLvl->setSizePolicy(sizePolicy3);
        tabLvl->setMinimumSize(QSize(0, 0));
        tabLvl->setMaximumSize(QSize(201, 16777215));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout = new QGridLayout(tab);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        numStartLevel = new QSpinBox(tab);
        numStartLevel->setObjectName(QString::fromUtf8("numStartLevel"));

        horizontalLayout_3->addWidget(numStartLevel);


        verticalLayout_7->addLayout(horizontalLayout_3);

        lstStdLvl = new QListWidget(tab);
        lstStdLvl->setObjectName(QString::fromUtf8("lstStdLvl"));
        lstStdLvl->setSortingEnabled(false);

        verticalLayout_7->addWidget(lstStdLvl);


        gridLayout->addLayout(verticalLayout_7, 0, 0, 1, 1);

        tabLvl->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_8 = new QGridLayout(tab_2);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        btnCreate = new QPushButton(tab_2);
        btnCreate->setObjectName(QString::fromUtf8("btnCreate"));

        gridLayout_8->addWidget(btnCreate, 0, 0, 1, 1);

        btnEdit = new QPushButton(tab_2);
        btnEdit->setObjectName(QString::fromUtf8("btnEdit"));

        gridLayout_8->addWidget(btnEdit, 0, 1, 1, 1);

        lstCustomLvl = new QListWidget(tab_2);
        lstCustomLvl->setObjectName(QString::fromUtf8("lstCustomLvl"));

        gridLayout_8->addWidget(lstCustomLvl, 1, 0, 1, 2);

        btnAddCustom = new QPushButton(tab_2);
        btnAddCustom->setObjectName(QString::fromUtf8("btnAddCustom"));

        gridLayout_8->addWidget(btnAddCustom, 2, 0, 1, 1);

        btnRemoveCustom = new QPushButton(tab_2);
        btnRemoveCustom->setObjectName(QString::fromUtf8("btnRemoveCustom"));

        gridLayout_8->addWidget(btnRemoveCustom, 2, 1, 1, 1);

        tabLvl->addTab(tab_2, QString());

        horizontalLayout->addWidget(tabLvl);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        txtTimesPlayed = new QLabel(groupBoxLevels);
        txtTimesPlayed->setObjectName(QString::fromUtf8("txtTimesPlayed"));

        verticalLayout_5->addWidget(txtTimesPlayed);

        txtBestTime = new QLabel(groupBoxLevels);
        txtBestTime->setObjectName(QString::fromUtf8("txtBestTime"));

        verticalLayout_5->addWidget(txtBestTime);

        txtTimesCompleted = new QLabel(groupBoxLevels);
        txtTimesCompleted->setObjectName(QString::fromUtf8("txtTimesCompleted"));

        verticalLayout_5->addWidget(txtTimesCompleted);

        txtTimesDead = new QLabel(groupBoxLevels);
        txtTimesDead->setObjectName(QString::fromUtf8("txtTimesDead"));

        verticalLayout_5->addWidget(txtTimesDead);


        verticalLayout_6->addLayout(verticalLayout_5);

        lvlPreview = new lvlpreviewview(groupBoxLevels);
        lvlPreview->setObjectName(QString::fromUtf8("lvlPreview"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(1);
        sizePolicy4.setVerticalStretch(1);
        sizePolicy4.setHeightForWidth(lvlPreview->sizePolicy().hasHeightForWidth());
        lvlPreview->setSizePolicy(sizePolicy4);

        verticalLayout_6->addWidget(lvlPreview);


        horizontalLayout->addLayout(verticalLayout_6);


        gridLayout_4->addLayout(horizontalLayout, 0, 0, 1, 1);


        verticalLayout_3->addWidget(groupBoxLevels);

        tabWidget->addTab(gameTab, QString());
        demoTab = new QWidget();
        demoTab->setObjectName(QString::fromUtf8("demoTab"));
        verticalLayout_4 = new QVBoxLayout(demoTab);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        btnPlayDemo = new QPushButton(demoTab);
        btnPlayDemo->setObjectName(QString::fromUtf8("btnPlayDemo"));

        verticalLayout_4->addWidget(btnPlayDemo);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        label_5 = new QLabel(demoTab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy5);

        horizontalLayout_2->addWidget(label_5);

        txtDemoLevel = new QLineEdit(demoTab);
        txtDemoLevel->setObjectName(QString::fromUtf8("txtDemoLevel"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(txtDemoLevel->sizePolicy().hasHeightForWidth());
        txtDemoLevel->setSizePolicy(sizePolicy6);

        horizontalLayout_2->addWidget(txtDemoLevel);

        btnDemoBrowse = new QPushButton(demoTab);
        btnDemoBrowse->setObjectName(QString::fromUtf8("btnDemoBrowse"));
        QSizePolicy sizePolicy7(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(btnDemoBrowse->sizePolicy().hasHeightForWidth());
        btnDemoBrowse->setSizePolicy(sizePolicy7);
        btnDemoBrowse->setAutoFillBackground(false);

        horizontalLayout_2->addWidget(btnDemoBrowse);


        verticalLayout_4->addLayout(horizontalLayout_2);

        lstDemo = new QListWidget(demoTab);
        lstDemo->setObjectName(QString::fromUtf8("lstDemo"));

        verticalLayout_4->addWidget(lstDemo);

        tabWidget->addTab(demoTab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        QSizePolicy sizePolicy8(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(tab_3->sizePolicy().hasHeightForWidth());
        tab_3->setSizePolicy(sizePolicy8);
        verticalLayout_8 = new QVBoxLayout(tab_3);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        txtExecPath = new QLineEdit(tab_3);
        txtExecPath->setObjectName(QString::fromUtf8("txtExecPath"));

        gridLayout_2->addWidget(txtExecPath, 0, 1, 1, 1);

        btnBrowseExecPath = new QToolButton(tab_3);
        btnBrowseExecPath->setObjectName(QString::fromUtf8("btnBrowseExecPath"));

        gridLayout_2->addWidget(btnBrowseExecPath, 0, 2, 1, 1);

        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        txtDataDir = new QLineEdit(tab_3);
        txtDataDir->setObjectName(QString::fromUtf8("txtDataDir"));

        gridLayout_2->addWidget(txtDataDir, 1, 1, 1, 1);

        btnBrowseDataDir = new QToolButton(tab_3);
        btnBrowseDataDir->setObjectName(QString::fromUtf8("btnBrowseDataDir"));

        gridLayout_2->addWidget(btnBrowseDataDir, 1, 2, 1, 1);

        label_4 = new QLabel(tab_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);


        verticalLayout_8->addLayout(verticalLayout_2);

        groupBox = new QGroupBox(tab_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy9(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy9);
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setHorizontalSpacing(4);
        formLayout->setVerticalSpacing(4);
        chFullScreen = new QCheckBox(groupBox);
        chFullScreen->setObjectName(QString::fromUtf8("chFullScreen"));

        formLayout->setWidget(0, QFormLayout::LabelRole, chFullScreen);

        chShowFps = new QCheckBox(groupBox);
        chShowFps->setObjectName(QString::fromUtf8("chShowFps"));
        chShowFps->setChecked(false);

        formLayout->setWidget(1, QFormLayout::LabelRole, chShowFps);

        chVsync = new QCheckBox(groupBox);
        chVsync->setObjectName(QString::fromUtf8("chVsync"));
        chVsync->setChecked(true);

        formLayout->setWidget(2, QFormLayout::LabelRole, chVsync);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label);

        btnSelectBgColor = new QToolButton(groupBox);
        btnSelectBgColor->setObjectName(QString::fromUtf8("btnSelectBgColor"));
        btnSelectBgColor->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        formLayout->setWidget(3, QFormLayout::FieldRole, btnSelectBgColor);


        verticalLayout_8->addWidget(groupBox);

        groupBox_2 = new QGroupBox(tab_3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        sizePolicy9.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy9);
        formLayout_3 = new QFormLayout(groupBox_2);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        chSound = new QCheckBox(groupBox_2);
        chSound->setObjectName(QString::fromUtf8("chSound"));
        chSound->setChecked(true);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, chSound);


        verticalLayout_8->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(tab_3);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        sizePolicy9.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy9);
        formLayout_2 = new QFormLayout(groupBox_3);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        chIs = new QCheckBox(groupBox_3);
        chIs->setObjectName(QString::fromUtf8("chIs"));
        sizePolicy6.setHeightForWidth(chIs->sizePolicy().hasHeightForWidth());
        chIs->setSizePolicy(sizePolicy6);
        chIs->setBaseSize(QSize(0, 0));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, chIs);


        verticalLayout_8->addWidget(groupBox_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer);

        tabWidget->addTab(tab_3, QString());

        verticalLayout->addWidget(tabWidget);


        gridLayout_3->addLayout(verticalLayout, 0, 0, 1, 1);

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
#ifndef QT_NO_TOOLTIP
        btnStart->setToolTip(QApplication::translate("MainWindow", "Start the game!", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnStart->setText(QApplication::translate("MainWindow", "Start Osgg!", 0, QApplication::UnicodeUTF8));
        groupBoxLevels->setTitle(QApplication::translate("MainWindow", "Levels", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Starting Level:", 0, QApplication::UnicodeUTF8));
        tabLvl->setTabText(tabLvl->indexOf(tab), QApplication::translate("MainWindow", "Standard", 0, QApplication::UnicodeUTF8));
        btnCreate->setText(QApplication::translate("MainWindow", "Create", 0, QApplication::UnicodeUTF8));
        btnEdit->setText(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
        btnAddCustom->setText(QApplication::translate("MainWindow", "Add", 0, QApplication::UnicodeUTF8));
        btnRemoveCustom->setText(QApplication::translate("MainWindow", "Remove", 0, QApplication::UnicodeUTF8));
        tabLvl->setTabText(tabLvl->indexOf(tab_2), QApplication::translate("MainWindow", "Custom", 0, QApplication::UnicodeUTF8));
        txtTimesPlayed->setText(QApplication::translate("MainWindow", "timesplayed", 0, QApplication::UnicodeUTF8));
        txtBestTime->setText(QApplication::translate("MainWindow", "besttime", 0, QApplication::UnicodeUTF8));
        txtTimesCompleted->setText(QApplication::translate("MainWindow", "timescompleted", 0, QApplication::UnicodeUTF8));
        txtTimesDead->setText(QApplication::translate("MainWindow", "timeddead", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(gameTab), QApplication::translate("MainWindow", "Game", 0, QApplication::UnicodeUTF8));
        btnPlayDemo->setText(QApplication::translate("MainWindow", "Play Demo!", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "LevelFile:", 0, QApplication::UnicodeUTF8));
        btnDemoBrowse->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(demoTab), QApplication::translate("MainWindow", "Demoes", 0, QApplication::UnicodeUTF8));
        txtExecPath->setText(QApplication::translate("MainWindow", "./osgg", 0, QApplication::UnicodeUTF8));
        btnBrowseExecPath->setText(QApplication::translate("MainWindow", "...", "Browse for the executable", QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "osgg data path:", 0, QApplication::UnicodeUTF8));
        txtDataDir->setText(QApplication::translate("MainWindow", "./", 0, QApplication::UnicodeUTF8));
        btnBrowseDataDir->setText(QApplication::translate("MainWindow", "...", "Browse for the data directory", QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "osgg executable:", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Screen", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        chFullScreen->setToolTip(QApplication::translate("MainWindow", "Run game in fullscreen mode", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        chFullScreen->setText(QApplication::translate("MainWindow", "Fullscreen", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        chShowFps->setToolTip(QApplication::translate("MainWindow", "Show how many fps the game runs at, this value should be close to 60 for optimal play.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        chShowFps->setText(QApplication::translate("MainWindow", "showfps", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        chVsync->setToolTip(QApplication::translate("MainWindow", "Turn on Vsync for smooth gameplay.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        chVsync->setText(QApplication::translate("MainWindow", "vsync", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Background color:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btnSelectBgColor->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        btnSelectBgColor->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Sound", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        chSound->setToolTip(QApplication::translate("MainWindow", "Enable in-game sound effects", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        chSound->setText(QApplication::translate("MainWindow", "Sound On", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Gameplay", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        chIs->setToolTip(QApplication::translate("MainWindow", "Save progress automatically when you land on a base", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        chIs->setText(QApplication::translate("MainWindow", "Save at every platform", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Settings", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNTITLED_H
