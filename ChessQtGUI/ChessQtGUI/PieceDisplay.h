#ifndef PIECEDISPLAY_H
#define PIECEDISPLAY_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

class PieceDisplay : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit PieceDisplay(int size, QObject *parent = nullptr);

protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    int size;

signals:
    void eventPosition(const QPointF&);
    void PieceClicked(const QPointF&);
    void PieceReleased(const QPointF&);

};

#endif // PIECEDISPLAY_H
