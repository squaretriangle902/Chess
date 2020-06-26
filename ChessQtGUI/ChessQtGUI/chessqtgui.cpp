#include "chessqtgui.h"
#include "ui_chessqtgui.h"
#include <QGridLayout>
#include <QColor>
#include "PieceDisplay.h"

ChessQtGUI::ChessQtGUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChessQtGUI)
{
    ui->setupUi(this);

    int windowSize = 620;
    int graphicsViewSize = 600;

    chessBoard = new ChessBoard(8, white);

    Queen* whiteQueen = new Queen(white, chessBoard);
    Queen* blackQueen = new Queen(black, chessBoard);
    King* whiteKing = new King(white, chessBoard);

    this->resize(windowSize,windowSize + 20);
    this->setFixedSize(windowSize,windowSize + 20);

    scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(0, 0, graphicsViewSize / 2, graphicsViewSize / 2);

    ui->graphicsView->resize(graphicsViewSize, graphicsViewSize);
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

    AddPiece(1, 1, whiteQueen);
    AddPiece(0, 0, whiteKing);
    AddPiece(3, 3, blackQueen);
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

void  ChessQtGUI::SelectPiece(const QPointF& position)
{
    currentPiecePosition = QPointFToPosition(position);
    Piece* piecePtr = this->chessBoard->GetPiecePtr(currentPiecePosition);
    if(piecePtr != NULL)
    {
        SelectAllAvailableSquares(piecePtr->GetPossibleMoves(currentPiecePosition));
    }
}

QPointF ChessQtGUI::NearestSquareCenter(const QPointF& position)
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

void ChessQtGUI::TryMovePiece(const QPointF& position)
{
    QGraphicsItem* pieceDisplay = scene->itemAt(position, QTransform());
    if(chessBoard->TryMove(currentPiecePosition, QPointFToPosition(position)))
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
    int graphicsViewSize = ui->graphicsView->width();
    chessBoard->SetPiecePtr(position, piecePtr);
    PieceDisplay* pieceDisplay = new PieceDisplay(graphicsViewSize / chessBoard->GetSize(),
                                                  piecePtr->GetType(), piecePtr->GetColor());
    pieceDisplay->setPos(PositionToQPointF(position, true));
    scene->addItem(pieceDisplay);
    connect(pieceDisplay, SIGNAL(PieceClicked(const QPointF&)), this, SLOT(SelectPiece(const QPointF&)));
    connect(pieceDisplay, SIGNAL(PieceReleased(const QPointF&)), this, SLOT(TryMovePiece(const QPointF&)));
}

void ChessQtGUI::AddPiece(int vertical, int horizontal, Piece *piecePtr)
{

    Position position = Position(vertical, horizontal);
    AddPiece(position, piecePtr);
}

int ChessQtGUI::SquareSize()
{
    int chessBoardSize = this->chessBoard->GetSize();
    int chessBoardDisplaySize = ui->graphicsView->width();
    return chessBoardDisplaySize / chessBoardSize;
}

Position ChessQtGUI::QPointFToPosition(const QPointF& qPointF)
{
    int x = qPointF.toPoint().x();
    int y = qPointF.toPoint().y();
    int squareSize = SquareSize();
    return Position(x / squareSize, y / squareSize);
}

QPointF ChessQtGUI::PositionToQPointF(const Position& position, bool isOffset)
{
    int squareSize = SquareSize();
    int offset = isOffset ? (squareSize / 2) : 0;
    return QPointF(QPoint(position.vertical * squareSize + offset,
                          position.horizontal * squareSize + offset));
}

