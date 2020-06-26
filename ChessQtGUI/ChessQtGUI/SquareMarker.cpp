#include "SquareMarker.h"

SquareMarker::SquareMarker(int size, QPointF position)
{ 
    this->size = size;
    this->setPos(mapToScene(position));
}

QRectF SquareMarker::boundingRect() const
{
    return QRectF(-size / 2, -size / 2, size, size);
}

void SquareMarker::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->fillRect(boundingRect(), QBrush(QColor(0,255,0,128)));
}
