#include "InputPieceDialog.h"
#include "ui_InputPieceDialog.h"

InputPieceDialog::InputPieceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputPieceDialog)
{
    ui->setupUi(this);
}

InputPieceDialog::~InputPieceDialog()
{
    delete ui;
}
