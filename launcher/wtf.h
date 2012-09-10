#include "ui_untitled.h"
#include "lvlPrevScene.h"
#include <iostream>
using namespace std;


class mW : public QMainWindow, private Ui::MainWindow
{
  Q_OBJECT
  
  private:
    QString osggDataDir;
    QString osggExecPath;
    QString osggUserDir;
    QString osggBackgroundColor;
    QString osggCustomLevel;

    int isDemo;
    
    void saveSettings();
    void loadSettings();
    void listLevels();
    void listDemos();
    void refreshSettings();
    
    lvlPrevScene* pScene;
    void preview(const char* file);

  private slots:
    void on_txtDataDir_textChanged(QString s);
    void on_txtExecPath_textChanged(QString s);
    void on_btnStart_clicked();
    void on_btnBrowseDataDir_clicked();
    void on_btnBrowseExecPath_clicked();
    void on_btnSelectBgColor_clicked();
    void on_lstCustomLvl_currentTextChanged(QString text);
    void on_numStartLevel_valueChanged(int l);
    void on_btnAddCustom_clicked();
    void on_btnRemoveCustom_clicked();
    void on_btnCreate_clicked();

    void on_btnDemoBrowse_clicked();
    void on_btnPlayDemo_clicked();

  public:
    mW(QMainWindow* p);
    ~mW();
};
