#include "SquareMarker.h"

SquareMarker::SquareMarker(int size, SquareMarkerType type, QPointF position)
{ 
    this->size = size;
    this->type = type;
    this->setPos(mapToScene(position));
}

QRectF SquareMarker::boundingRect() const
{
    switch (this->type)
    {
    case possibleMove:
        return QRectF(-size / 4, -size / 4, size / 2, size / 2);
        break;
    default:
        return QRectF(-size / 2, -size / 2, size, size);
        break;
    }
}

void SquareMarker::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    switch (this->type)
    {
    case possibleMove:
        painter->setPen(Qt::NoPen);
        painter->setBrush(QBrush(QColor(0, 255, 0, 128)));
        painter->drawEllipse(boundingRect());
        break;
    case lastMove:
        painter->setPen(Qt::NoPen);
        painter->setBrush(QBrush(QColor(255, 255, 0, 128)));
        painter->drawRect(boundingRect());
        break;
    case check:
        painter->setPen(Qt::NoPen);
        painter->setBrush(QBrush(QColor(255, 0, 0, 128)));
        painter->drawRect(boundingRect());
        break;
    }
}

SquareMarkerType SquareMarker::GetType()
{
    return this->type;
}
