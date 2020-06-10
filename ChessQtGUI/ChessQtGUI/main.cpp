#include "chessqtgui.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChessQtGUI w;
    w.show();
    return a.exec();  
}
