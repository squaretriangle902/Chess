#include "PieceDisplay.h"

PieceDisplay::PieceDisplay(int size, QObject *parent) : QObject(parent)
{
    this->size = size;
}

QRectF PieceDisplay::boundingRect() const
{
    return QRectF(-this->size / 2, -this->size / 2, this->size, this->size);
}

void PieceDisplay::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::black);
    painter->setBrush(Qt::green);
    painter->drawRect(boundingRect());
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void PieceDisplay::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    this->setPos(mapToScene(event->pos()));
}

void PieceDisplay::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit PieceClicked(mapToScene(event->pos()));
    Q_UNUSED(event);
}

void PieceDisplay::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    emit PieceReleased(mapToScene(event->pos()));
    Q_UNUSED(event);
}
