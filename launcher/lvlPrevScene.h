#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QTimer>
#include <QColor>
#include <QWidget>

class lvlPrevScene : public QGraphicsScene
{

  private:
  qreal y;
  
  public:
    lvlPrevScene();

    void load(const char* file);

};
