#ifndef PIECEDISPLAY_H
#define PIECEDISPLAY_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <SquareMarker.h>
#include "../../Chess/PieceType.h"
#include "../../Chess/Color.h"

class PieceDisplay : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit PieceDisplay(int size, PieceType type, Color color, QObject *parent = nullptr);

protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    QImage PieceImage(PieceType type);
    PieceType type;
    Color color;
    int size;

signals:
    void PieceClicked(QPointF);
    void PieceReleased(QPointF);

};

#endif // PIECEDISPLAY_H
