#include "chessboardsquaredisplay.h"
#include <QPixmap>
#include <QImage>

ChessBoardSquareDisplay::ChessBoardSquareDisplay(int vertical, int horizontal, int size)
{
    this->position.vertical = vertical;
    this->position.horizontal = horizontal;
    this->size = size;
    isAvailable = false;
    isSelected = false;
}

ChessBoardSquareDisplay::ChessBoardSquareDisplay(Position position, int size)
{
    this->position = position;
    this->size = size;
    isAvailable = false;
}

QRectF ChessBoardSquareDisplay::boundingRect() const
{
    return QRectF(size * this->position.vertical,
                  size * 7 - size * this->position.horizontal,
                  size,
                  size);
}

void ChessBoardSquareDisplay::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rectangle = boundingRect();
    QBrush brush(QColor(245,245,220));
    if ((this->position.vertical + this->position.horizontal) % 2 == 0)
    {
        brush.setColor(QColor(110,0,0));
    }
    painter->fillRect(rectangle,brush);
    if(isAvailable)
    {
        painter->fillRect(rectangle, QBrush(QColor(0, 255, 0, 128)));
    }
    if(isSelected)
    {
        painter->fillRect(rectangle, QBrush(QColor(255, 255, 0, 128)));
    }
}

void ChessBoardSquareDisplay::IsAvailable(bool flag)
{
    this->isAvailable = flag;
}

void ChessBoardSquareDisplay::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::RightButton)
    {
        this->isSelected = !this->isSelected;
        update();
    }
    QGraphicsItem::mousePressEvent(event);
}
