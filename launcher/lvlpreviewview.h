#ifndef LVLPREVIEWVIEW_H
#define LVLPREVIEWVIEW_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QTimer>
#include <QColor>
#include <QWidget>

class lvlpreviewview : public QGraphicsView
{
public:
    lvlpreviewview( QWidget* q);
    void setScene(QGraphicsScene *scene);

protected:
    void 	resizeEvent ( QResizeEvent * event );

};

#endif // LVLPREVIEWVIEW_H
