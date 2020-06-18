#include "chessqtgui.h"
#include "ui_chessqtgui.h"
#include <QGridLayout>
#include <QColor>

ChessQtGUI::ChessQtGUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChessQtGUI)
{
    chessBoard = new ChessBoard(8, white);

    Queen* whiteQueen = new Queen(white, chessBoard);
    Queen* blackQueen = new Queen(black, chessBoard);

    King* whiteKing = new King(white, chessBoard);
    King* blackKing = new King(black, chessBoard);

    Knight* whiteKnight = new Knight(white, chessBoard);
    Knight* blackKnight = new Knight(black, chessBoard);

    Pawn* whitePawn = new Pawn(white, chessBoard);
    Pawn* blackPawn = new Pawn(black, chessBoard);

    Rook* whiteRook = new Rook(white, chessBoard);
    Rook* blackRook = new Rook(black, chessBoard);

    Bishop* whiteBishop = new Bishop(white, chessBoard);
    Bishop* blackBishop = new Bishop(black, chessBoard);


    chessBoard->SetPiecePtr(Position(0,0), whiteKing);
    chessBoard->SetPiecePtr(Position(1,0), whiteQueen);
    chessBoard->SetPiecePtr(Position(2,0), whiteRook);
    chessBoard->SetPiecePtr(Position(3,0), whiteBishop);
    chessBoard->SetPiecePtr(Position(4,0), whiteKnight);
    chessBoard->SetPiecePtr(Position(5,0), whitePawn);

    chessBoard->SetPiecePtr(Position(0,1), blackKing);
    chessBoard->SetPiecePtr(Position(1,1), blackQueen);
    chessBoard->SetPiecePtr(Position(2,1), blackRook);
    chessBoard->SetPiecePtr(Position(3,1), blackBishop);
    chessBoard->SetPiecePtr(Position(4,1), blackKnight);
    chessBoard->SetPiecePtr(Position(5,1), blackPawn);

    ui->setupUi(this);
    int displaySize = 600;
    scene = new QGraphicsScene(0, 0, displaySize, displaySize, ui->graphicsView);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio );
    MakeChessBoardDisplay(chessBoard->GetSize(), ui->graphicsView->width());
    ShowChessBoard();
    ShowPieces(ui->graphicsView->width());
    SelectPiece(Position(4,1));

}

ChessQtGUI::~ChessQtGUI()
{
    delete ui;
}

void ChessQtGUI::SelectPiece(Position position)
{
    Piece* piecePtr = chessBoard->GetPiecePtr(position);
    vector<Position> possibleMovesVector = piecePtr->GetPossibleMoves(position);
    for (int i = 0; i < possibleMovesVector.size(); i++)
    {
        chessBoardDisplay.at(possibleMovesVector.at(i))->IsAvailable(true);
    }
}

void ChessQtGUI::MakeChessBoardDisplay(int chessBoardSize, int displaySize)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < chessBoardSize; j++)
        {
            chessBoardDisplay[Position(i,j)] =
                    new ChessBoardSquareDisplay(i, j, displaySize / chessBoardSize);
        }
    }
}

void ChessQtGUI::ShowChessBoard()
{
    for (auto it = chessBoardDisplay.begin(); it != chessBoardDisplay.end(); ++it)
    {
         scene->addItem(it->second);
    }
}

void ChessQtGUI::ShowPieces(int displaySize)
{
    for (int i = 0; i < chessBoard->GetSize(); i++)
    {
        for (int j = 0; j < chessBoard->GetSize(); j++)
        {
            Piece* piecePtr = chessBoard->GetPiecePtr(i, j);
            if(piecePtr != NULL)
            {
                scene->addItem(new PieceDisplay(i, j, displaySize / chessBoard->GetSize(),
                                             piecePtr->GetColor(),
                                             piecePtr->GetType()));
            }
        }
    }
}

//void ChessQtGUI::SetPieceSelectEventFilter(QEvent* event)
//{
//    for (auto it = chessBoardDisplay.begin(); it != chessBoardDisplay.end(); ++it)
//    {
//         this->eventFilter(it->second, mousePressEvent(event))
//    }
//}
//

