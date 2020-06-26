#include "PieceDisplay.h"

PieceDisplay::PieceDisplay(int size, PieceType type, Color color, QObject *parent) : QObject(parent)
{
    this->size = size;
    this->type = type;
    this->color = color;
}

QRectF PieceDisplay::boundingRect() const
{
    return QRectF(-this->size / 2, -this->size / 2, this->size, this->size);
}

void PieceDisplay::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QImage pieceImage = PieceImage(this->type);
    pieceImage = pieceImage.scaledToWidth(boundingRect().width(), Qt::SmoothTransformation);
    painter->drawPixmap(boundingRect().topLeft(), QPixmap::fromImage(pieceImage));
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

QImage PieceDisplay::PieceImage(PieceType type)
{
    QString path = "://Images";
    switch (color)
    {
    case white:
        path += "/WhitePieces";
        break;
    case black:
        path += "/BlackPieces";
        break;
    }
    switch (type)
    {
    case bishop:
        path += "/Bishop.png";
        break;
    case king:
        path += "/King.png";
        break;
    case knight:
        path += "/Knight.png";
        break;
    case pawn:
        path += "/Pawn.png";
        break;
    case queen:
        path += "/Queen.png";
        break;
    case rook:
        path += "/Rook.png";
        break;
    case noType:
        break;
    }
    return QImage(path);
}
