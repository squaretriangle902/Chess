#include "InputPieceDialog.h"
#include "ui_InputPieceDialog.h"

InputPieceDialog::InputPieceDialog(Color color, ChessBoard* chessBoardPtr, Game* game,
                                   QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputPieceDialog)
{
    this->setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
    this->color = color;
    this->chessBoardPtr = chessBoardPtr;
    this->game = game;
    ui->setupUi(this);
    this->SetIcons();
}

Piece *InputPieceDialog::GetOutput()
{
    return this->output;
}

void InputPieceDialog::SetColor(Color color)
{
    this->color = color;
    this->SetIcons();
}

InputPieceDialog::~InputPieceDialog()
{
    delete ui;
}

void InputPieceDialog::on_knightButton_clicked()
{
    this->output = new Knight(this->color, this->chessBoardPtr, this->game);
    this->close();
}

void InputPieceDialog::on_bishopButton_clicked()
{
    this->output = new Bishop(this->color, this->chessBoardPtr, this->game);
    this->close();
}

void InputPieceDialog::on_rookButton_clicked()
{
    this->output = new Rook(this->color, this->chessBoardPtr, this->game);
    this->close();
}

void InputPieceDialog::on_queenButton_clicked()
{
    this->output = new Queen(this->color, this->chessBoardPtr, this->game);
    this->close();
}

void InputPieceDialog::SetIcons()
{
    switch (this->color) {
    case white:
        ui->knightButton->setStyleSheet("qproperty-icon: url(:/Images/WhitePieces/Knight.png)");
        ui->bishopButton->setStyleSheet("qproperty-icon: url(:/Images/WhitePieces/Bishop.png)");
        ui->rookButton->setStyleSheet("qproperty-icon: url(:/Images/WhitePieces/Rook.png)");
        ui->queenButton->setStyleSheet("qproperty-icon: url(:/Images/WhitePieces/Queen.png)");
        break;
    case black:
        ui->knightButton->setStyleSheet("qproperty-icon: url(:/Images/BlackPieces/Knight.png)");
        ui->bishopButton->setStyleSheet("qproperty-icon: url(:/Images/BlackPieces/Bishop.png)");
        ui->rookButton->setStyleSheet("qproperty-icon: url(:/Images/BlackPieces/Rook.png)");
        ui->queenButton->setStyleSheet("qproperty-icon: url(:/Images/BlackPieces/Queen.png)");
        break;
    }
}
