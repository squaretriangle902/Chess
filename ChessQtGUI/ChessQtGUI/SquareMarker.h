#ifndef SQUAREMARKER_H
#define SQUAREMARKER_H

#include <QGraphicsItem>
#include <QPainter>

enum SquareMarkerType
{
    possibleMove = 0,
    lastMove = 1,
    check = 2,
};

class SquareMarker : public QGraphicsItem
{
public:
    SquareMarker(int size, SquareMarkerType type, QPointF position);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    SquareMarkerType GetType();
protected:
    int size;
    SquareMarkerType type;
};

#endif // SQUAREMARKER_H
