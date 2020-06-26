#ifndef SQUAREMARKER_H
#define SQUAREMARKER_H

#include <QGraphicsItem>
#include <QPainter>

class SquareMarker : public QGraphicsItem
{
public:
    SquareMarker(int size, QPointF position);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
protected:
    int size;
};

#endif // SQUAREMARKER_H
