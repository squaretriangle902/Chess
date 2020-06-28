#include "chessqtgui.h"
#include "ui_chessqtgui.h"
#include <QGridLayout>
#include <QColor>

ChessQtGUI::ChessQtGUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChessQtGUI)
{
    ui->setupUi(this);

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


    this->chessBoardPtr = new ChessBoard(8);

    Queen* whiteQueen = new Queen(white, chessBoardPtr);
    Queen* blackQueen = new Queen(black, chessBoardPtr);
    King* whiteKing = new King(white, chessBoardPtr);


    AddPiece(Position(1,1), whiteQueen);
    AddPiece(Position(0,0), whiteKing);
    AddPiece(Position(6,6), blackQueen);

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
    if(this->chessBoardPtr->TryMove(currentPiecePosition, QPointFToPosition(position)))
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

