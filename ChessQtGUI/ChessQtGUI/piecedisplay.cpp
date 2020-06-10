#include "piecedisplay.h"
#include <QImage>

PieceDisplay::PieceDisplay(int horizontal, int vertical, ChessBoard* chessBoard, QGraphicsScene* scene)
{
    setFlag(ItemIsMovable);
    this->horizontal = horizontal;
    this->vertical = vertical;
    this->chessBoard = chessBoard;
    this->scene = scene;
}

QRectF PieceDisplay::boundingRect() const
{
    return QRectF(50, 50, 50, 50);
}

void PieceDisplay::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QImage image("C:/Users/squar/source/repos/Chess/ChessQtGUI/Images/WhitePieces/Queen");
    painter->drawImage(rect, image);
}

void PieceDisplay::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mouseReleaseEvent(event);
    this->pos();
    if(this->x() > 350)
    {
        this->setPos(0,0);
    }
}

void PieceDisplay::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    //this->chessBoard->PieceIsSelected(vertical, horizontal, chessBoard, scene);
    QGraphicsItem::mouseReleaseEvent(event);
}
