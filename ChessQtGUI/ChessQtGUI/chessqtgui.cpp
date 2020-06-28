#include "chessqtgui.h"
#include "ui_chessqtgui.h"
#include <QGridLayout>
#include <QColor>

ChessQtGUI::ChessQtGUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChessQtGUI)
{
    ui->setupUi(this);

    //Cosmetics

    int windowSize = 900;
    int graphicsViewSize = 800;

    this->resize(windowSize,windowSize);
    this->setFixedSize(windowSize,windowSize);

    scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(0, 0, graphicsViewSize / 2, graphicsViewSize / 2);

    ui->graphicsView->resize(graphicsViewSize, graphicsViewSize);
    ui->graphicsView->setFixedSize(graphicsViewSize, graphicsViewSize);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    ui->graphicsView->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio );

    QImage chessBoardImage("://Images/ChessBoard/ChessBoard.png");
    chessBoardImage = chessBoardImage.scaledToWidth(ui->graphicsView->width(),Qt::SmoothTransformation);
    scene->addPixmap(QPixmap::fromImage(chessBoardImage));

    squareMarkerGroup = new QGraphicsItemGroup();
    scene->addItem(squareMarkerGroup);

    //Game classes declaration

    this->chessBoardPtr = new ChessBoard(8);

        //Pieces poniters declaration
            //White pieces poniters
            Pawn*   whitePawn   = new Pawn(white, chessBoardPtr);
            Knight* whiteKnight = new Knight(white, chessBoardPtr);
            Bishop* whiteBishop = new Bishop(white, chessBoardPtr);
            Rook*   whiteRook   = new Rook(white, chessBoardPtr);
            Queen*  whiteQueen  = new Queen(white, chessBoardPtr);
            King*   whiteKing   = new King(white, chessBoardPtr);
            //Black pieces poniters
            Pawn*   blackPawn   = new Pawn(black, chessBoardPtr);
            Knight* blackKnight = new Knight(black, chessBoardPtr);
            Bishop* blackBishop = new Bishop(black, chessBoardPtr);
            Rook*   blackRook   = new Rook(black, chessBoardPtr);
            Queen*  blackQueen  = new Queen(black, chessBoardPtr);
            King*   blackKing   = new King(black, chessBoardPtr);

        //Adding pieces
            //Adding white pieces
                //Pawns
                AddPiece(0, 1, whitePawn);
                AddPiece(1, 1, whitePawn);
                AddPiece(2, 1, whitePawn);
                AddPiece(3, 1, whitePawn);
                AddPiece(4, 1, whitePawn);
                AddPiece(5, 1, whitePawn);
                AddPiece(6, 1, whitePawn);
                AddPiece(7, 1, whitePawn);
                //Pieces
                AddPiece(0, 0, whiteRook);
                AddPiece(1, 0, whiteKnight);
                AddPiece(2, 0, whiteBishop);
                AddPiece(3, 0, whiteQueen);
                AddPiece(4, 0, whiteKing);
                AddPiece(5, 0, whiteBishop);
                AddPiece(6, 0, whiteKnight);
                AddPiece(7, 0, whiteRook);
            //Adding black pieces
                //Pawns
                AddPiece(0, 6, blackPawn);
                AddPiece(1, 6, blackPawn);
                AddPiece(2, 6, blackPawn);
                AddPiece(3, 6, blackPawn);
                AddPiece(4, 6, blackPawn);
                AddPiece(5, 6, blackPawn);
                AddPiece(6, 6, blackPawn);
                AddPiece(7, 6, blackPawn);
                //Pieces
                AddPiece(0, 7, blackRook);
                AddPiece(1, 7, blackKnight);
                AddPiece(2, 7, blackBishop);
                AddPiece(3, 7, blackQueen);
                AddPiece(4, 7, blackKing);
                AddPiece(5, 7, blackBishop);
                AddPiece(6, 7, blackKnight);
                AddPiece(7, 7, blackRook);

}




void ChessQtGUI::SelectAllAvailableSquares(vector<Position> possibleMovesVector)
{
    for (int i = 0; i < possibleMovesVector.size(); i++)
    {
        SquareMarker* squareMarker = new
                SquareMarker(SquareSize(),
                             PositionToQPointF(possibleMovesVector.at(i), true));
        squareMarkerGroup->addToGroup(squareMarker);
    }
}

void  ChessQtGUI::SelectPiece(QPointF position)
{
    QGraphicsItem* pieceDisplay = scene->itemAt(position, QTransform());
    pieceDisplay->setZValue(1);
    currentPiecePosition = QPointFToPosition(position);
    Piece* piecePtr = this->chessBoardPtr->GetPiecePtr(currentPiecePosition);
    if(piecePtr != NULL)
    {
        vector<Position> tmp = piecePtr->GetPossibleMoves(currentPiecePosition);
        SelectAllAvailableSquares(piecePtr->GetPossibleMoves(currentPiecePosition));
    }
}

QPointF ChessQtGUI::NearestSquareCenter(QPointF position)
{
    int x = position.toPoint().x();
    int y = position.toPoint().y();
    int squareSize = SquareSize();
    int offset = squareSize / 2;
    return QPointF(x - x % squareSize + offset, y - y % squareSize + offset);
}

void ChessQtGUI::DeleteAllMarkers()
{
    foreach(QGraphicsItem *item, scene->items(squareMarkerGroup->boundingRect()))
    {
       if( item->group() == squareMarkerGroup )
       {
          delete item;
       }
    }
}

void ChessQtGUI::TryMovePiece(QPointF position)
{
    QGraphicsItem* pieceDisplay = scene->itemAt(position, QTransform());
    bool isTaking = false;
    bool tryMove = this->chessBoardPtr->TryMove(currentPiecePosition, QPointFToPosition(position), isTaking);
    pieceDisplay->setZValue(0);
    if(isTaking)
    {
        pieceDisplay->setZValue(-1);
        scene->removeItem(scene->itemAt(position, QTransform()));
        pieceDisplay->setZValue(0);
    }
    if(tryMove)
    {
        pieceDisplay->setPos(NearestSquareCenter(position));
    }
    else
    {
        pieceDisplay->setPos(PositionToQPointF(currentPiecePosition, true));
    }
    DeleteAllMarkers();
}

ChessQtGUI::~ChessQtGUI()
{
    delete ui;
}

void ChessQtGUI::AddPiece(Position position, Piece *piecePtr)
{
    chessBoardPtr->SetPiecePtr(position, piecePtr);
    PieceDisplay* pieceDisplay = new PieceDisplay(SquareSize(),
                                                  piecePtr->GetType(), piecePtr->GetColor());
    pieceDisplay->setPos(PositionToQPointF(position, true));
    scene->addItem(pieceDisplay);
    connect(pieceDisplay, SIGNAL(PieceClicked(QPointF)), this, SLOT(SelectPiece(QPointF)));
    connect(pieceDisplay, SIGNAL(PieceReleased(QPointF)), this, SLOT(TryMovePiece(QPointF)));
}

void ChessQtGUI::AddPiece(int vertical, int horizontal, Piece *piecePtr)
{

    Position position = Position(vertical, horizontal);
    AddPiece(position, piecePtr);
}

int ChessQtGUI::SquareSize()
{
    int chessBoardSize = this->chessBoardPtr->GetSize();
    int chessBoardDisplaySize = ui->graphicsView->width();
    return chessBoardDisplaySize / chessBoardSize;
}

Position ChessQtGUI::QPointFToPosition(QPointF qPointF)
{
    int x = qPointF.toPoint().x();
    int y = qPointF.toPoint().y();
    int squareSize = SquareSize();
    return Position(x / squareSize,
                    this->chessBoardPtr->GetSize() - y / squareSize - 1);
}

QPointF ChessQtGUI::PositionToQPointF(Position position, bool isOffset)
{
    qreal chessBoardDisplaySize = ui->graphicsView->width();
    qreal squareSize = SquareSize();
    qreal offset = isOffset ? (squareSize / 2) : 0;
    return QPointF(position.vertical * squareSize + offset,
                   chessBoardDisplaySize - (position.horizontal + 1) * squareSize + offset);
}

