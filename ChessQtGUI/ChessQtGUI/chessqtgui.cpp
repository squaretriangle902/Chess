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

    this->resize(windowSize,windowSize + 20);
    this->setFixedSize(windowSize,windowSize + 20);

    scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(0,0,graphicsViewSize / 2,graphicsViewSize / 2);

    squareMarkerGroup = new QGraphicsItemGroup();
    scene->addItem(squareMarkerGroup);

    ui->graphicsView->resize(graphicsViewSize, graphicsViewSize);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    ui->graphicsView->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio );

    QImage chessBoardImage("C:/Users/squar/source/repos/Chess/ChessQtGUI/Images/ChessBoard/ChessBoard.png");
    chessBoardImage = chessBoardImage.scaledToWidth(ui->graphicsView->width(),Qt::SmoothTransformation);
    scene->addPixmap(QPixmap::fromImage(chessBoardImage));

    Position position = Position(1,1);
    AddPiece(position, whiteQueen);
}




void  ChessQtGUI::SelectPiece(const QPointF& position)
{
    Position chessPosition = QPointFToPosition(position);
    Piece* piecePtr = this->chessBoard->GetPiecePtr(chessPosition);
    vector<Position> possibleMovesVector;

    int chessBoardSize = this->chessBoard->GetSize();
    int chessBoardDisplaySize = ui->graphicsView->width();
    int squareSize = chessBoardDisplaySize / chessBoardSize;

    if(piecePtr != NULL)
    {
        possibleMovesVector = piecePtr->GetPossibleMoves(chessPosition);
    }
    for (int i = 0; i < possibleMovesVector.size(); i++)
    {
        QPointF leftTop = PositionToQPointF(possibleMovesVector.at(i), false);
        QPointF rightBottom = QPointF(leftTop.x() + squareSize, leftTop.y() + squareSize);
        QGraphicsItem* rect = scene->addRect(QRectF(leftTop, rightBottom),
                       QPen(QColor(0,0,0,0)),
                       QBrush(QColor(0,255,0,128)));
        squareMarkerGroup->addToGroup(rect);
    }
}

void  ChessQtGUI::ReturnPiece(const QPointF& position)
{
    ui->label->setText("(" + QString::number(position.x()) + ","
                       + QString::number(position.y()) + ")");
}

void ChessQtGUI::TryMovePiece(const QPointF& position)
{
    int x = position.toPoint().x();
    int y = position.toPoint().y();
    int chessBoardSize = this->chessBoard->GetSize();
    int chessBoardDisplaySize = ui->graphicsView->width();
    int offset = chessBoardDisplaySize / (2 * chessBoardSize);
    int squareCenterX = x - x % (chessBoardDisplaySize / chessBoardSize) + offset;
    int squareCenterY = y - y % (chessBoardDisplaySize / chessBoardSize) + offset;
    scene->itemAt(position, QTransform())->setPos(squareCenterX,squareCenterY);
}

ChessQtGUI::~ChessQtGUI()
{
    delete ui;
}

void ChessQtGUI::AddPiece(Position position, Piece *piecePtr)
{
    int graphicsViewSize = ui->graphicsView->width();
    chessBoard->SetPiecePtr(position, piecePtr);
    PieceDisplay* pieceDisplay = new PieceDisplay(graphicsViewSize / chessBoard->GetSize());
    pieceDisplay->setPos(PositionToQPointF(position, true));
    scene->addItem(pieceDisplay);
    connect(pieceDisplay, SIGNAL(PieceClicked(const QPointF&)), this, SLOT(SelectPiece(const QPointF&)));
    connect(pieceDisplay, SIGNAL(PieceReleased(const QPointF&)), this, SLOT(TryMovePiece(const QPointF&)));

}

void ChessQtGUI::AddPiece(int vertical, int horizontal, Piece *piecePtr)
{
    int graphicsViewSize = ui->graphicsView->width();
    Position position = Position(vertical, horizontal);
    chessBoard->SetPiecePtr(position, piecePtr);
    PieceDisplay* pieceDisplay = new PieceDisplay(graphicsViewSize / chessBoard->GetSize());
    pieceDisplay->setPos(PositionToQPointF(position, true));
    scene->addItem(pieceDisplay);
    connect(pieceDisplay, SIGNAL(PieceClicked(const QPointF&)), this, SLOT(SelectPiece(const QPointF&)));
    connect(pieceDisplay, SIGNAL(PieceReleased(const QPointF&)), this, SLOT(TryMovePiece(const QPointF&)));


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
    return  Position(x / squareSize, y / squareSize);
}

QPointF ChessQtGUI::PositionToQPointF(const Position& position, bool isOffset)
{
    int squareSize = SquareSize();
    int offset = isOffset ? (squareSize / 2) : 0;
    return QPointF(QPoint(position.vertical * squareSize + offset,
                          position.horizontal * squareSize + offset));
}

