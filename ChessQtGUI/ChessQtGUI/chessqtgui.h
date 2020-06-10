#ifndef CHESSQTGUI_H
#define CHESSQTGUI_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ChessQtGUI; }
QT_END_NAMESPACE

class ChessQtGUI : public QMainWindow
{
    Q_OBJECT

public:
    ChessQtGUI(QWidget *parent = nullptr);
    ~ChessQtGUI();

private:
    Ui::ChessQtGUI *ui;
};
#endif // CHESSQTGUI_H
