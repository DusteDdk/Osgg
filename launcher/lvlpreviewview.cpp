#include <iostream>
#include "lvlpreviewview.h"

lvlpreviewview::lvlpreviewview( QWidget* q ) : QGraphicsView(q)
{

}

void lvlpreviewview::resizeEvent ( QResizeEvent * event )
{
    setScene( this->scene() );
}

void lvlpreviewview::setScene(QGraphicsScene *scene)
{
    QGraphicsView::setScene(scene);
    QGraphicsView::fitInView( scene->sceneRect(),Qt::KeepAspectRatio );
}
