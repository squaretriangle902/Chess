#ifndef PIECEDISPLAY_H
#define PIECEDISPLAY_H

#include <QPainter>
#include <QGraphicsItem>
#include "..\..\Chess\ChessBoard.h"

class PieceDisplay : public QGraphicsItem
{
public:
    PieceDisplay(int horizontal, int vertical, ChessBoard* chessBoard, QGraphicsScene* scene);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
protected:
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
private:
    int horizontal;
    int vertical;
    ChessBoard* chessBoard;
    QGraphicsScene* scene;

};

#endif // PIECEDISPLAY_H
