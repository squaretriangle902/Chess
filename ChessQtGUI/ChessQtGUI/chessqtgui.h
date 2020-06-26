#ifndef CHESSQTGUI_H
#define CHESSQTGUI_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include "../../Chess/Pieces.h"
#include "../../Chess/ChessBoard.h"
#include "PieceDisplay.h"
#include <vector>


QT_BEGIN_NAMESPACE
namespace Ui { class ChessQtGUI; }
QT_END_NAMESPACE

class ChessQtGUI : public QMainWindow
{
    Q_OBJECT

public:
    ChessQtGUI(QWidget *parent = nullptr);
    ~ChessQtGUI();

private:
    Ui::ChessQtGUI *ui;
    ChessBoard* chessBoard;
    QGraphicsScene* scene;
    QGraphicsItemGroup* squareMarkerGroup;
    void AddPiece(Position position, Piece* piecePtr);
    void AddPiece(int vertical, int horizontal, Piece* piecePtr);
    Position QPointFToPosition(const QPointF& qPointF);
    QPointF PositionToQPointF(const Position& position, bool isOffset);
    int SquareSize();

public slots:
    void SelectPiece(const QPointF& position);
    void ReturnPiece(const QPointF& position);
    void TryMovePiece(const QPointF& position);

};
#endif // CHESSQTGUI_H
