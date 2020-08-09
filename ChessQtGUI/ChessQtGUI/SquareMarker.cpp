#include "SquareMarker.h"

SquareMarker::SquareMarker(int size, QPointF position)
{ 
    this->size = size;
    this->setPos(mapToScene(position));
}

QRectF SquareMarker::boundingRect() const
{
    return QRectF(-size / 4, -size / 4, size / 2, size / 2);
}

void SquareMarker::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(QBrush(QColor(0,255,0,128)));
    painter->drawEllipse(boundingRect());
}
