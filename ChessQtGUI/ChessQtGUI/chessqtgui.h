#ifndef CHESSQTGUI_H
#define CHESSQTGUI_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsItemGroup>
#include "../../Chess/Piece.h"
#include "../../Chess/Pieces.h"
#include "../../Chess/ChessBoard.h"
#include "../../Chess/LongRangePiece.h"
#include "PieceDisplay.h"
#include "InputPieceDialog.h"
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
    ChessBoard* chessBoardPtr;
    Game* game;
    QGraphicsScene* scene;
    QGraphicsItemGroup* squareMarkerGroup;
    QGraphicsItemGroup* lastMoveMarkerGroup;
    SquareMarker* checkMarker;
    Position currentPiecePosition;
    void AddPiece(Position position, PieceType type, Color color);
    void AddPiece(Position position, Piece* piecePtr);
    void AddPiece(int vertical, int horizontal, PieceType type, Color color);
    Position QPointFToPosition(QPointF qPointF);
    QPointF PositionToQPointF(Position position, bool isOffset);
    QPointF NearestSquareCenter(QPointF qPointF);
    int SquareSize();
    void DeleteAllMarkers(QGraphicsItemGroup* markerGroup);
    void SelectAllAvailableSquares(vector<Position> possibleMovesVector);
    Position FindRookDisplay(Position kingPosition, Chess::Direction castlingDirection);
    InputPieceDialog* inputPieceDialog;
    void Taking(QGraphicsItem* pieceDisplay, QPointF position);
    void ReturnPieceDisplay(QGraphicsItem* pieceDisplay);
    void Promotion(Color color, QPointF position, Position endChessPosition);
    void Castling(Position rookDisplayPosition, Position endChessPosition,
                               Chess::Direction castlingDirection);
    void GameResultMessage(GameResult gameResult);
    void CheckMarker(Color kingColor);

public slots:
    void SelectPiece(QPointF position);
    void TryMovePiece(QPointF position);
};
#endif // CHESSQTGUI_H
