#ifndef CHESSQTGUI_H
#define CHESSQTGUI_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsItemGroup>
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
    Position currentPiecePosition;
    void AddPiece(Position position, Piece* piecePtr);
    void AddPiece(int vertical, int horizontal, Piece* piecePtr);
    Position QPointFToPosition(const QPointF& qPointF);
    QPointF PositionToQPointF(const Position& position, bool isOffset);
    QPointF NearestSquareCenter(const QPointF& qPointF);
    int SquareSize();
    void DeleteAllMarkers();
    void SelectAllAvailableSquares(vector<Position> possibleMovesVector);

public slots:
    void SelectPiece(const QPointF& position);
    void TryMovePiece(const QPointF& position);

};
#endif // CHESSQTGUI_H
