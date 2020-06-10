#ifndef CHESSBOARDSQUAREDISPLAY_H
#define CHESSBOARDSQUAREDISPLAY_H
#include <QPainter>
#include <QGraphicsItem>

class ChessBoardSquareDisplay : public QGraphicsItem
{
public:
    ChessBoardSquareDisplay();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    bool selected;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // CHESSBOARDSQUAREDISPLAY_H
