#include "chessqtgui.h"
#include "ui_chessqtgui.h"
#include <QGridLayout>
#include <QColor>

ChessQtGUI::ChessQtGUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChessQtGUI)
{
    ChessBoard* chessBoard = new ChessBoard();
    Queen* whiteQueen = new Queen(white, chessBoard);
    chessBoard->SetPiecePtr(Position(1,1), whiteQueen);
    ui->setupUi(this);
    int squareSize = 50;
    scene = new QGraphicsScene(0,0,400,400, ui->graphicsView);
    ui->graphicsView->setScene(scene);
    chessBoardSquare = new ChessBoardSquareDisplay();
    QPen pen(QColor(0,0,0));
    QBrush brounBrush(QColor(110,0,0));
    QBrush biegeBrush(QColor(245,245,220));
    QBrush blackBrush(QColor(0,0,0));
    scene->addRect(-25, -25, 450, 450, pen, blackBrush);
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if ((i + j) % 2 == 0)
            {
                scene->addRect(i * squareSize, j * squareSize, squareSize, squareSize, pen, biegeBrush);
            }
            else
            {
                scene->addRect(i * squareSize, j * squareSize, squareSize, squareSize, pen, brounBrush);
            }
        }
    }
    PieceDisplay *pieceDisplay = new PieceDisplay(0, 0, chessBoard, scene);
    scene->addItem(pieceDisplay);
    SelectPiece(chessBoard, 1, 1, scene);
}

ChessQtGUI::~ChessQtGUI()
{
    delete ui;
}

void ChessQtGUI::SelectPiece(ChessBoard *chessBoard, int vertical, int horizontal, QGraphicsScene *scene)
{
    Piece* piecePtr = chessBoard->GetPiecePtr(Position(vertical, horizontal));
    vector<Position> positionVector = piecePtr->GetPossibleMoves(Position(vertical, horizontal));
    QPen pen(QColor(0,0,0));
    QBrush redBrush(QColor(255,0,0));
    for (int i = 0; i < positionVector.size(); i++)
    {
        Position position = positionVector.at(i);
        scene->addRect(50 * position.vertical,
                       50 * position.horizontal,
                       50,
                       50,
                       pen,
                       redBrush);
    }
}

