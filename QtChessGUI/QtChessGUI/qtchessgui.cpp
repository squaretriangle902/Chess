#include "qtchessgui.h"
#include "ui_qtchessgui.h"

QtChessGUI::QtChessGUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QtChessGUI)
{
    ui->setupUi(this);
}

QtChessGUI::~QtChessGUI()
{
    delete ui;
}

