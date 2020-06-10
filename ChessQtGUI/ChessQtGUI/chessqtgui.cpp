#include "chessqtgui.h"
#include "ui_chessqtgui.h"

ChessQtGUI::ChessQtGUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChessQtGUI)
{
    ui->setupUi(this);
}

ChessQtGUI::~ChessQtGUI()
{
    delete ui;
}

