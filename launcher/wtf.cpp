#include "wtf.h"

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <QDir>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QColorDialog>
#include <QTextStream>
#include <QInputDialog>
#include <QPainter>
#include <QImage>

using namespace std;

void mW::on_btnStart_clicked()
{
  string cmdLine;
  
  /* Save settings */
  saveSettings();
  
  cmdLine = "cd \"";
  cmdLine += osggDataDir.toStdString();
  cmdLine += "\" && \"";
  cmdLine += osggExecPath.toStdString();
  cmdLine += "\"";
  
  /** This HAS to be first because osgg only takes a int as argument 1 **/

  if( isDemo )
  {
    cmdLine += " --levelfile \"";
    cmdLine += txtDemoLevel->text().toStdString();
    cmdLine += "\"";
    cmdLine += " --playdemo \"demos/"+lstDemo->currentItem()->text().toStdString() + "\"";

  } else {
    if(tabLvl->currentIndex() == 1) //Custom level
    {
      /* Check that something is selected */
      if(lstCustomLvl->currentRow() != -1)
      {
        cmdLine += " --levelfile \"";
        cmdLine += osggUserDir.toStdString();
        cmdLine += "/levels/";
        cmdLine += osggCustomLevel.toStdString();
        cmdLine += ".level\"";
      } else {
        QMessageBox info;
        info.setText("Error: No level selected.");
        info.exec();
        return;
      }

    } else { //std level
      ostringstream t;
      t.clear();
      t << " " << numStartLevel->value();
      cmdLine += t.str();
    }
  }
  
  if(runEditor)
    cmdLine += " --edit";
  
  if(chIs->isChecked())
    cmdLine += " --is";
  if(chFullScreen->isChecked())
    cmdLine += " --fullscreen";
  
  if(!chVsync->isChecked())
    cmdLine += " --sleep";
  
  if(chShowFps->isChecked())
    cmdLine += " --showfps";
  
  if(!chSound->isChecked())
    cmdLine += " --nosound";
  
  if(osggBackgroundColor != QString("000000"))
  {
    cmdLine += " --bgcolor ";
    cmdLine += osggBackgroundColor.toStdString();
  }
  
  //TODO: append --savedemo


  FILE *stream;
  QStringList output;
  char buffer[2048];
  
  cout << "Running: " << cmdLine << endl << endl;
  stream = popen(cmdLine.data(), "r");
  while( fgets(buffer, 2048, stream) != NULL )
  {
    cout <<" osgg > " << buffer;
    output << buffer;
  }
  
  //Clear isDemo and runEditor
  isDemo=0;
  runEditor=0;
}

/* Populate tables */
void mW::listLevels()
{
  QStringList filter;
  QFileInfoList fileInfoList;
  QString name;

  lstStdLvl->clear();
  lstCustomLvl->clear();

  filter << "*.level";
  QDir qd(osggDataDir+"/levels/");
  qd.setNameFilters(filter);
  /* Standard Levels */
  if( qd.exists() )
  {
    fileInfoList = qd.entryInfoList();
    int i;
    for(i=0; i < fileInfoList.size(); i++)
    {
      name.sprintf("%03i", i);
      lstStdLvl->insertItem(0, name);
    }
    numStartLevel->setMaximum(i-1);

    lstStdLvl->sortItems(Qt::AscendingOrder);
  } else {
    QMessageBox info;
    info.setText("Standard level dir '"+osggDataDir+"levels/' does not exist, check settings.");
    info.exec();
  }

  /* Custom (user) levels */
  qd.cd(osggUserDir+"/levels/");
  if( qd.exists() )
  {
    fileInfoList = qd.entryInfoList();
    int i;
    for(i=0; i < fileInfoList.size(); i++)
    {
      name = fileInfoList.at(i).fileName();
      name = name.left( name.indexOf('.') );
      lstCustomLvl->insertItem(0, name );
    }


  }

}

/* Populate tables */
void mW::listDemos()
{
  QStringList filter;
  QFileInfoList fileInfoList;

  filter << "*.bin";
  QDir qd(osggDataDir+"/demos/");
  qd.setNameFilters(filter);

  if( qd.exists() )
  {
    fileInfoList = qd.entryInfoList();
    int i;
    for(i=0; i < fileInfoList.size(); i++)
    {
      QFileInfo fileInfo = fileInfoList.at(i);
      QString name = fileInfo.fileName();
      lstDemo->insertItem(0, name );
    }

    lstDemo->sortItems(Qt::AscendingOrder);
  } else {
    QMessageBox info;
    info.setText("Demo dir '"+osggDataDir+"demos/' does not exist, check settings.");
    info.exec();
  }

}



void mW::saveSettings()
{
  QDir qd(osggUserDir);
  
  if( qd.exists() )
  {
    QFile cfgFile( osggUserDir+"/osgglaunch.cfg" );
    if(cfgFile.open(QFile::WriteOnly | QFile::Truncate) )
    {
      QTextStream t(&cfgFile);
      t <<"dataDir="<<osggDataDir<<endl;
      t << "execPath="<<osggExecPath << endl;
      t << "soundOff=" << chSound->isChecked() << endl;
      t << "fullScreen=" << chFullScreen->isChecked() << endl;
      t << "bgColor="<<osggBackgroundColor << endl;
      t << "vsync="<<chVsync->isChecked() << endl;
      t << "showfps=" << chShowFps->isChecked() << endl;
      cfgFile.close();
    }
  }
}

void mW::loadSettings()
{
  osggDataDir="./";
  osggExecPath="./osgg";
  osggUserDir=QDir::homePath();
  osggUserDir.append("/.osgg");
  
  osggBackgroundColor="000000";
  
  QDir qd(osggUserDir);

  if(qd.exists(osggUserDir))
  {
    /* Open Settings file */
    QString fileName = osggUserDir+"/osgglaunch.cfg";
    
    ifstream conf;
    string line,set,val;
    conf.open( fileName.toStdString().data() );
    if(conf.is_open())
    {
      while(!conf.eof())
      {
        getline(conf, line);
        if(line.find('=') != string::npos)
        {
          set=line.substr(0,line.find('='));
          val=line.substr(line.find('=')+1);

          if(set=="dataDir")
          {
            osggDataDir = val.data();
          } else if(set=="execPath")
          {
            osggExecPath = val.data();
          } else if(set=="is")
          {
            chIs->setChecked( atoi(val.data()) );
          } else if(set=="soundOff")
          {
            chSound->setChecked( atoi(val.data()) );
          } else if(set=="fullScreen")
          {
            chFullScreen->setChecked( atoi(val.data()) );
          } else if(set=="bgColor")
          {
            osggBackgroundColor=val.data();
            int r,g,b;
            char rgb[5];
            sprintf(rgb,"0x%c%c", osggBackgroundColor.at(0).toAscii(), osggBackgroundColor.at(1).toAscii() );
            r=strtol(rgb, NULL, 16);
            sprintf(rgb,"0x%c%c", osggBackgroundColor.at(2).toAscii(), osggBackgroundColor.at(3).toAscii() );
            g=strtol(rgb, NULL, 16);
            sprintf(rgb,"0x%c%c", osggBackgroundColor.at(4).toAscii(), osggBackgroundColor.at(5).toAscii() );
            b=strtol(rgb, NULL, 16);
            QString bgColorStyleSheet;
            char sh[64];
            sprintf(sh, "background-color: rgb(%i, %i, %i);", r,g,b);
            bgColorStyleSheet=sh;
            btnSelectBgColor->setStyleSheet(bgColorStyleSheet);
          } else if(set=="showfps")
          {
            chShowFps->setChecked( atoi(val.data()) );
          } else if(set=="vsync")
          {
            chVsync->setChecked( atoi(val.data()) );
          }
        }
      }
      conf.close();
    }
    
  } else {
    QMessageBox info;
    if(qd.mkdir(osggUserDir))
    {
      info.setText("Created directory in '"+osggUserDir+"'");
      qd.mkdir(osggUserDir+"/levels/");
      qd.mkdir(osggUserDir+"/demos/");
    } else {
      info.setText("Could not create directory in '"+osggUserDir+"'");
    }
    info.exec();
  }
  
  
}

void mW::refreshSettings()
{
  txtExecPath->setText(osggExecPath);
  txtDataDir->setText(osggDataDir);
}

void mW::on_btnBrowseDataDir_clicked()
{
  QFileDialog fd(this);
  fd.setFileMode(QFileDialog::DirectoryOnly);
  if(fd.exec())
  {
    QStringList dir = fd.selectedFiles();
    osggDataDir = dir.at(0);
    if(osggDataDir.at( osggDataDir.length()-1 ) != '/')
    {
      osggDataDir+="/";
    }
    refreshSettings();
    listLevels();
  }
}

void mW::on_btnDemoBrowse_clicked()
{
  QFileDialog fd(this);
  fd.setFileMode(QFileDialog::ExistingFile);
  if(fd.exec())
  {
    QStringList dir = fd.selectedFiles();
    txtDemoLevel->setText( dir.at(0) );
  }
}
void mW::on_btnPlayDemo_clicked()
{
  QMessageBox info;
  //Check that the filelist is not empty
  if( lstDemo->count() < 1 )
  {
      info.setText("No demos found in the demo dir.");
      info.exec();
      return;
  }

  QListWidgetItem *item =  lstDemo->currentItem();
  //Check that a demo has been selected
  if( item->text().length() == 0 )
  {
      info.setText("No demo selected.");
      info.exec();
  }
  
  //Check that a demo-level has been selected
  if( txtDemoLevel->text().length() < 3  )
  {
      info.setText("No level selected to play demo inside.");
      info.exec();
      return;
  }

  //Set "isDemo" and call
  isDemo=1;
  on_btnStart_clicked();
}

void mW::on_btnBrowseExecPath_clicked()
{
  QFileDialog fd(this);
  fd.setFileMode(QFileDialog::ExistingFile);
  if(fd.exec())
  {
    QStringList dir = fd.selectedFiles();
    osggExecPath = dir.at(0);
    refreshSettings();
  }
}

void mW::on_btnSelectBgColor_clicked()
{
  int r,g,b;
  QColor myColor;
  myColor.setRgba(QColorDialog::getRgba(0x00));
  myColor.getRgb(&r,&g,&b);
  
  QString bgColorStyleSheet;
  char sh[64];
  sprintf(sh, "background-color: rgb(%i, %i, %i);", r,g,b);
  bgColorStyleSheet=sh;
  btnSelectBgColor->setStyleSheet(bgColorStyleSheet);
  sprintf(sh, "%02x%02x%02x",r,g,b);
  osggBackgroundColor=sh;
}

void mW::on_lstCustomLvl_currentTextChanged(QString text)
{
  osggCustomLevel = text;

  ostringstream t;
  t.clear();
  t << osggUserDir.toStdString() << "/levels/" << osggCustomLevel.toStdString() << ".level";
  preview( t.str().data() );

}

void mW::on_numStartLevel_valueChanged(int l)
{
  lstStdLvl->setCurrentRow(l);
  
  ostringstream t;
  t.clear();
  t <<  osggDataDir.toStdString() <<"/levels/" << numStartLevel->value() << ".level";
  preview( t.str().data());
}

void mW::preview(const char* file)
{
  delete pScene;
    pScene = new lvlPrevScene();
    pScene->load(file);

    lvlPreview->scale(0.5, -0.5);
    lvlPreview->setRenderHints(QPainter::Antialiasing);

    lvlPreview->setScene( pScene );
}

void mW::on_btnAddCustom_clicked()
{
  QString lvl;
  /* Browse for the file */
  QFileDialog fd(this);
  fd.setNameFilter("*.level");
  fd.setFileMode(QFileDialog::ExistingFile);
  if(fd.exec())
  {
    /* Copy file to home/.osgg/levels */
    QStringList dir = fd.selectedFiles();
    lvl= dir.at(0);
    QFile lvlFile(lvl);
    if(lvlFile.exists())
    {
      QFileInfo fi(lvlFile);
      if(lvlFile.copy( osggUserDir+"/levels/"+fi.fileName() ) )
      {
        /* Update list */
        listLevels();
      } else {
        QMessageBox info;
        info.setText("Could not copy file to levels directory..");
        info.exec();
      }
    }

  }

}

void mW::on_btnRemoveCustom_clicked()
{
  if(lstCustomLvl->currentRow() != -1)
  {
    QFile levelfile( osggUserDir+"/levels/"+osggCustomLevel+".level" );
    if(!levelfile.remove())
    {
      QMessageBox info;
      info.setText("Could not delete file..");
      info.exec();
    } else {
      listLevels();
    }
  }
}

void mW::on_txtDataDir_textChanged(QString s)
{
  osggDataDir = s;
}

void mW::on_txtExecPath_textChanged(QString s)
{
  osggExecPath = s;
}

void mW::on_btnCreate_clicked()
{
  bool ok=0;
  QMessageBox info;
  QString lvl = QInputDialog::getText(this, tr("Create New Level"), tr("Enter Level Name"), QLineEdit::Normal, "NewLevel", &ok);
  if(ok)
  {
    osggCustomLevel = lvl;
    QFile newLvl( osggUserDir + "/levels/" + osggCustomLevel + ".level" );
    if(newLvl.exists())
    {
      info.setText("Error: File exists!");
      info.exec();
      return;
    }
    
    
    /* Write a small standard file */
    QString ld;
    ld = "StartEntity\n0\n0\n1\n90\n-1\nEndEntity\nStartEntity\n2.43333\n0.953333\n2\n90\n1\nEndEntity\n";
    if( newLvl.open(QIODevice::WriteOnly) )
    {
      newLvl.write( ld.toAscii() );
      newLvl.close();
    } else {
      info.setText("Error: Could not open file for write.");
      info.exec();
      return;
    }
    /* Refresh list */
    listLevels();
    /* Find the new level */
    QList<QListWidgetItem *> list = lstCustomLvl->findItems( osggCustomLevel,Qt::MatchFixedString );
    /* Set it */
    lstCustomLvl->setCurrentItem( list.at(0) );
    //Run it
    runEditor=1;
    on_btnStart_clicked();

  }
}

void mW::on_btnEdit_clicked()
{
    runEditor=1;
    on_btnStart_clicked();
}


mW::mW(QMainWindow* p) : QMainWindow(p)
{
  setupUi(p);

  loadSettings();
  refreshSettings();

  listLevels();
  listDemos();
  
  QObject::connect(txtDataDir, SIGNAL(textChanged(QString)), this, SLOT(on_txtDataDir_textChanged(QString)));
  QObject::connect(txtExecPath, SIGNAL(textChanged(QString)), this, SLOT(on_txtExecPath_textChanged(QString)));
  QObject::connect(btnStart, SIGNAL(clicked()), this, SLOT(on_btnStart_clicked()));
  QObject::connect(btnBrowseDataDir, SIGNAL(clicked()), this, SLOT(on_btnBrowseDataDir_clicked()));
  QObject::connect(btnBrowseExecPath, SIGNAL(clicked()), this, SLOT(on_btnBrowseExecPath_clicked()));
  QObject::connect(btnSelectBgColor, SIGNAL(clicked()), this, SLOT(on_btnSelectBgColor_clicked()));
  QObject::connect(numStartLevel, SIGNAL(valueChanged(int)), this, SLOT(on_numStartLevel_valueChanged(int)));
  QObject::connect(lstCustomLvl, SIGNAL(currentTextChanged(QString)), this, SLOT(on_lstCustomLvl_currentTextChanged(QString)));
  QObject::connect(btnAddCustom, SIGNAL(clicked()), this, SLOT(on_btnAddCustom_clicked()));
  QObject::connect(btnRemoveCustom, SIGNAL(clicked()), this, SLOT(on_btnRemoveCustom_clicked()));
  QObject::connect(btnCreate, SIGNAL(clicked()), this, SLOT(on_btnCreate_clicked()));
  QObject::connect(btnEdit, SIGNAL(clicked()), this, SLOT(on_btnEdit_clicked()));

  QObject::connect(btnDemoBrowse, SIGNAL(clicked()), this, SLOT(on_btnDemoBrowse_clicked()));
  QObject::connect(btnPlayDemo, SIGNAL(clicked()), this, SLOT(on_btnPlayDemo_clicked()));

  on_numStartLevel_valueChanged(0);
  isDemo=0;
  runEditor=0;
  
}

mW::~mW()
{
  saveSettings();
}
