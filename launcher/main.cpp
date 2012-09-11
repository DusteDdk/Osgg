#include "ui_untitled.h"
#include "wtf.h"

int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);
     QMainWindow *win = new QMainWindow;

     mW myUi(win);
     
     win->show();
     return app.exec();
 }
 
