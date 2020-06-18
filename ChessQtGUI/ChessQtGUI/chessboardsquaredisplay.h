#ifndef CHESSBOARDSQUAREDISPLAY_H
#define CHESSBOARDSQUAREDISPLAY_H
#include <QPainter>
#include <QGraphicsItem>
#include "../../Chess/Position.h"

class ChessBoardSquareDisplay : public QGraphicsItem
{
public:
    ChessBoardSquareDisplay(int vertical, int horizontal, int size);
    ChessBoardSquareDisplay(Position position, int size);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void Select();
    void Unselect();

     void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

protected:   

    bool selected;
    Position position;
    int size;
};

#endif // CHESSBOARDSQUAREDISPLAY_H
