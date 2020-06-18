#ifndef CHESSQTGUI_H
#define CHESSQTGUI_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <map>
#include "chessboardsquaredisplay.h"
#include "piecedisplay.h"
#include "../../Chess/Pieces.h"
#include "../../Chess/ChessBoard.h"
#include <QEvent>


QT_BEGIN_NAMESPACE
namespace Ui { class ChessQtGUI; }
QT_END_NAMESPACE

class ChessQtGUI : public QMainWindow
{
    Q_OBJECT

public:
    ChessQtGUI(QWidget *parent = nullptr);
    ~ChessQtGUI();
    void MakeChessBoardDisplay(int chessBoardSize, int displaySize);
    void ShowChessBoard();
    void ShowPieces(int displaySize);

private:
    Ui::ChessQtGUI *ui;
    QGraphicsScene *scene;
    ChessBoard* chessBoard;
    void SelectPiece(Position position);
    map <Position, ChessBoardSquareDisplay*> chessBoardDisplay;

};
#endif // CHESSQTGUI_H
