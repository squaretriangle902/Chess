#include "chessboardsquaredisplay.h"
#include <QPixmap>
#include <QImage>

ChessBoardSquareDisplay::ChessBoardSquareDisplay()
{
    selected = false;
    setFlag(ItemIsMovable);
}

QRectF ChessBoardSquareDisplay::boundingRect() const
{
    return QRectF(0,0,100,100);
}

void ChessBoardSquareDisplay::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QBrush brush(Qt::blue);
    if (selected)
    {
        brush.setColor(Qt::red);
    }
    else
    {
        brush.setColor(Qt::blue);
    }
    painter->fillRect(rect,brush);
    painter->drawRect(rect);
}

void ChessBoardSquareDisplay::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    selected = !selected;
    this->setSelected(selected);
    update();
    QGraphicsItem::mousePressEvent(event);
}
