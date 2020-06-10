#ifndef CHESSQTGUI_H
#define CHESSQTGUI_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include "chessboardsquaredisplay.h"
#include "piecedisplay.h"
#include "../../Chess/Pieces.h"
#include "../../Chess/ChessBoard.h"


QT_BEGIN_NAMESPACE
namespace Ui { class ChessQtGUI; }
QT_END_NAMESPACE

class ChessQtGUI : public QMainWindow
{
    Q_OBJECT

public:
    ChessQtGUI(QWidget *parent = nullptr);
    ~ChessQtGUI();
    void SelectPiece(ChessBoard* chessBoard, int vertical, int horizontal, QGraphicsScene *scene);

private:
    Ui::ChessQtGUI *ui;
    QGraphicsScene *scene;
    ChessBoardSquareDisplay *chessBoardSquare;

};
#endif // CHESSQTGUI_H