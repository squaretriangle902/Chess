#ifndef PIECEDISPLAY_H
#define PIECEDISPLAY_H

#include <QPainter>
#include <QGraphicsItem>
#include "..\..\Chess\PieceType.h"
#include "..\..\Chess\Color.h"

class PieceDisplay : public QGraphicsItem
{
public:
    PieceDisplay(int vertical, int horizontal, int size, Color color, PieceType type);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
protected:
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    QImage PieceImage();

    int vertical;
    int horizontal;
    int size;
    Color color;
    PieceType type;

};

#endif // PIECEDISPLAY_H
