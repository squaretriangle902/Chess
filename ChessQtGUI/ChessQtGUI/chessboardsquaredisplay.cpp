#include "chessboardsquaredisplay.h"
#include <QPixmap>
#include <QImage>

ChessBoardSquareDisplay::ChessBoardSquareDisplay(int vertical, int horizontal, int size)
{
    this->position.vertical = vertical;
    this->position.horizontal = horizontal;
    this->size = size;
    selected = false;
}

ChessBoardSquareDisplay::ChessBoardSquareDisplay(Position position, int size)
{
    this->position = position;
    this->size = size;
    selected = false;
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
    if(selected)
    {
        painter->fillRect(rectangle, QBrush(QColor(0, 255, 0, 128)));
    }
}

void ChessBoardSquareDisplay::Select()
{
    this->selected = true;
}

void ChessBoardSquareDisplay::Unselect()
{
    this->selected = false;
}

void ChessBoardSquareDisplay::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->selected = !this->selected;
    update();
    QGraphicsItem::mousePressEvent(event);
}
