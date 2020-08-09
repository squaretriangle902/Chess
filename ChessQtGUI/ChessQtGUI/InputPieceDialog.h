#ifndef INPUTPIECEDIALOG_H
#define INPUTPIECEDIALOG_H

#include <QDialog>
#include "../../Chess/ChessBoard.h"
#include "../../Chess/Pieces.h"

namespace Ui {
class InputPieceDialog;
}

class InputPieceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InputPieceDialog(Color color = white, ChessBoard* chessBoardPtr = nullptr,
                              QWidget *parent = nullptr);
    Piece* GetOutput();
    void SetColor(Color color);
    ~InputPieceDialog();
    void SetIcons();

private slots:
    void on_knightButton_clicked();

    void on_bishopButton_clicked();

    void on_rookButton_clicked();

    void on_queenButton_clicked();

private:
    Color color;
    ChessBoard* chessBoardPtr;
    Piece* output;
    Ui::InputPieceDialog *ui;
};

#endif // INPUTPIECEDIALOG_H
