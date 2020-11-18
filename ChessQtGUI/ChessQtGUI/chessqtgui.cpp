#include "chessqtgui.h"
#include "ui_chessqtgui.h"
#include <QGridLayout>
#include <QColor>
#include <QMessageBox>

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
    lastMoveMarkerGroup = new QGraphicsItemGroup();
    scene->addItem(lastMoveMarkerGroup);
    checkMarker = nullptr;
    scene->addItem(checkMarker);

    //Game classes declaration

    int chessBoardSize = 8;

    this->game = new Game(white, chessBoardSize);
    this->chessBoardPtr = new ChessBoard(chessBoardSize, game);
    this->game->SetChessBoardPtr(chessBoardPtr);
    this->inputPieceDialog = new InputPieceDialog(white, chessBoardPtr, game);
    inputPieceDialog->show();
    inputPieceDialog->close();

    //Adding pieces
        //Adding white pieces
            //Pawns
            AddPiece(0, 1, pawn, white);
            AddPiece(1, 1, pawn, white);
            AddPiece(2, 1, pawn, white);
            AddPiece(3, 1, pawn, white);
            AddPiece(4, 1, pawn, white);
            AddPiece(5, 1, pawn, white);
            AddPiece(6, 1, pawn, white);
            AddPiece(7, 1, pawn, white);
            //Pieces
            AddPiece(0, 0, rook, white);
            AddPiece(1, 0, knight, white);
            AddPiece(2, 0, bishop, white);
            AddPiece(3, 0, queen, white);
            AddPiece(4, 0, king, white);
            AddPiece(5, 0, bishop, white);
            AddPiece(6, 0, knight, white);
            AddPiece(7, 0, rook, white);
        //Adding black pieces
            //Pawns
            AddPiece(0, 6, pawn, black);
            AddPiece(1, 6, pawn, black);
            AddPiece(2, 6, pawn, black);
            AddPiece(3, 6, pawn, black);
            AddPiece(4, 6, pawn, black);
            AddPiece(5, 6, pawn, black);
            AddPiece(6, 6, pawn, black);
            AddPiece(7, 6, pawn, black);
            //Pieces
            AddPiece(0, 7, rook, black);
            AddPiece(1, 7, knight, black);
            AddPiece(2, 7, bishop, black);
            AddPiece(3, 7, queen, black);
            AddPiece(4, 7, king, black);
            AddPiece(5, 7, bishop, black);
            AddPiece(6, 7, knight, black);
            AddPiece(7, 7, rook, black);

}




void ChessQtGUI::SelectAllAvailableSquares(vector<Position> possibleMovesVector)
{
    for (int i = 0; i < possibleMovesVector.size(); i++)
    {
        SquareMarker* squareMarker = new
                SquareMarker(SquareSize(), possibleMove,
                             PositionToQPointF(possibleMovesVector.at(i), true));
        squareMarkerGroup->addToGroup(squareMarker);
    }
}

Position ChessQtGUI::FindRookDisplay(Position kingPosition, Chess::Direction castlingDirection)
{
    Position i = kingPosition + castlingDirection;
    QGraphicsItem* pieceDisplay = nullptr;
    while(pieceDisplay == nullptr)
    {
        pieceDisplay = scene->itemAt(PositionToQPointF(i, true), QTransform());
        i += castlingDirection;
    }
    return i;
}

void  ChessQtGUI::SelectPiece(QPointF position)
{
    QGraphicsItem* pieceDisplay = scene->itemAt(position, QTransform());
    pieceDisplay->setZValue(1);
    currentPiecePosition = QPointFToPosition(position);
    Piece* piecePtr = this->chessBoardPtr->GetPiecePtr(currentPiecePosition);
    if(piecePtr != NULL)
    {
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

void ChessQtGUI::DeleteAllMarkers(QGraphicsItemGroup* markerGroup)
{
    foreach(QGraphicsItem *item, scene->items(squareMarkerGroup->boundingRect()))
    {
       if(item->group() == markerGroup)
       {
          delete item;
       }
    }
}

void ChessQtGUI::Taking(QGraphicsItem* pieceDisplay, QPointF position)
{
    pieceDisplay->setZValue(-1);
    scene->removeItem(scene->itemAt(position, QTransform()));
}

void ChessQtGUI::ReturnPieceDisplay(QGraphicsItem* pieceDisplay)
{
    {
        pieceDisplay->setPos(PositionToQPointF(currentPiecePosition, true));
    }
}

void ChessQtGUI::Promotion(Color color, QPointF position, Position endChessPosition)
{
    inputPieceDialog->SetColor(color);
    inputPieceDialog->exec();
    scene->removeItem(scene->itemAt(position, QTransform()));
    AddPiece(endChessPosition, inputPieceDialog->GetOutput());
}

void ChessQtGUI::Castling(Position rookDisplayPosition, Position endChessPosition,
                           Chess::Direction castlingDirection)
{
    QGraphicsItem* rookDisplay =
            scene->itemAt(PositionToQPointF(rookDisplayPosition, true), QTransform());
    Position rookNewPosition = endChessPosition - Position(castlingDirection);
    rookDisplay->setPos(PositionToQPointF(rookNewPosition, true));
}

void ChessQtGUI::GameResultMessage(GameResult gameResult)
{
    switch (gameResult)
    {
    case whiteWon:
        QMessageBox::question(this, "White won by checkmate", "Retry?", QMessageBox::Yes | QMessageBox::No);
        break;
    case blackWon:
        QMessageBox::question(this, "Black won by checkmate", "Retry?", QMessageBox::Yes | QMessageBox::No);
        break;
    case stalemate:
        QMessageBox::question(this, "Stalemate", "Retry?", QMessageBox::Yes | QMessageBox::No);
        break;
    }
}

void ChessQtGUI::CheckMarker(Color kingColor)
{
    Position* kingPositionPtr = this->chessBoardPtr->GetKingPosition(kingColor);
    if(kingPositionPtr != nullptr && this->chessBoardPtr->IsPositionUnderAttack(*kingPositionPtr, kingColor))
    {
        checkMarker = new SquareMarker(SquareSize(), check, PositionToQPointF(*kingPositionPtr, true));
        checkMarker->setZValue(0);
        scene->addItem(checkMarker);
    }
}

void ChessQtGUI::TryMovePiece(QPointF position)
{
    QGraphicsItem* pieceDisplay = scene->itemAt(position, QTransform());
    bool isTaking = false, isPromotion = false, isEnPassant = false;
    Chess::Direction castlingDirection = Chess::noDirection;
    Position rookDisplayPosition, enPassantPosition;
    Position endChessPosition = QPointFToPosition(position);
    bool tryMove = this->chessBoardPtr->TryMove(currentPiecePosition, endChessPosition, isTaking, isPromotion,
                                                rookDisplayPosition, castlingDirection, isEnPassant,
                                                enPassantPosition);
    GameResult gameResult;
    if(tryMove)
    {
        scene->removeItem(checkMarker);
        Color color = chessBoardPtr->GetPiecePtr(endChessPosition)->GetColor();
        if(isTaking)
        {
            Taking(pieceDisplay, position);
        }
        if(isPromotion)
        {
            Promotion(color, position, endChessPosition);
        }
        if(castlingDirection != Chess::noDirection)
        {
            Castling(rookDisplayPosition, endChessPosition, castlingDirection);
        }
        if(isEnPassant)
        {
            scene->removeItem(scene->itemAt(PositionToQPointF(enPassantPosition, true), QTransform()));
        }
        pieceDisplay->setPos(NearestSquareCenter(position));
        CheckMarker(NextColor(color));
        gameResult = this->game->GetGameResult();
    }
    else
    {
        ReturnPieceDisplay(pieceDisplay);
        gameResult = none;
    }
    pieceDisplay->setZValue(0.5);
    DeleteAllMarkers(squareMarkerGroup);
    GameResultMessage(gameResult);
}

ChessQtGUI::~ChessQtGUI()
{
    delete ui;
}

void ChessQtGUI::AddPiece(Position position, PieceType type, Color color)
{
    AddPiece(position, CreatePiece(type, color, chessBoardPtr, game));
}

void ChessQtGUI::AddPiece(Position position, Piece *piecePtr)
{
    chessBoardPtr->SetPiecePtr(position, piecePtr);
    PieceDisplay* pieceDisplay = new PieceDisplay(SquareSize(),
                                                  piecePtr->GetType(), piecePtr->GetColor());
    pieceDisplay->setPos(PositionToQPointF(position, true));
    scene->addItem(pieceDisplay);
    pieceDisplay->setZValue(0.5);
    connect(pieceDisplay, SIGNAL(PieceClicked(QPointF)), this, SLOT(SelectPiece(QPointF)));
    connect(pieceDisplay, SIGNAL(PieceReleased(QPointF)), this, SLOT(TryMovePiece(QPointF)));
}

void ChessQtGUI::AddPiece(int vertical, int horizontal, PieceType type, Color color)
{
    Position position = Position(vertical, horizontal);
    AddPiece(position, type, color);
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

