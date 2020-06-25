#ifndef PIECEDISPLAY_H
#define PIECEDISPLAY_H

#include <QObject>

class PieceDisplay : public QObject
{
    Q_OBJECT
public:
    explicit PieceDisplay(QObject *parent = nullptr);

signals:

};

#endif // PIECEDISPLAY_H
