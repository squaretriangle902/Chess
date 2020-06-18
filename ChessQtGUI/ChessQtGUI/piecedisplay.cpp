#include "piecedisplay.h"
#include <QImage>

PieceDisplay::PieceDisplay(int vertical, int horizontal, int size, Color color, PieceType type)
{
    setFlag(ItemIsMovable);
    this->vertical = vertical;
    this->horizontal = horizontal;
    this->size = size;
    this->color = color;
    this->type = type;
}

QRectF PieceDisplay::boundingRect() const
{
    return QRectF(vertical * size, 7 * size -  horizontal * size, size, size);
}

void PieceDisplay::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rectangle = boundingRect();
    QImage pieceImage = PieceImage();
    pieceImage = pieceImage.scaledToWidth(size, Qt::SmoothTransformation);
    painter->drawImage(rectangle, pieceImage);
}

void PieceDisplay::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mouseReleaseEvent(event);
    this->setPos(0,0);
    this->setZValue(0);

}

void PieceDisplay::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    this->setZValue(1);
    //this->chessBoard->PieceIsSelected(vertical, horizontal, chessBoard, scene);
    QGraphicsItem::mouseReleaseEvent(event);
}

QImage PieceDisplay::PieceImage()
{
    QString path = "C:/Users/squar/source/repos/Chess/ChessQtGUI/Images";
    switch (this->color)
    {
    case white:
        path += "/WhitePieces";
        break;
    case black:
        path += "/BlackPieces";
        break;
    }
    switch (this->type)
    {
    case pawn:
        path += "/Pawn";
        break;
    case knight:
        path += "/Knight";
        break;
    case bishop:
        path += "/bishop";
        break;
    case rook:
        path += "/Rook";
        break;
    case queen:
        path += "/Queen";
        break;
    case king:
        path += "/King";
        break;
    }
    return QImage(path);
}
