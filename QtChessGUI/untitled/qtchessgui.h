#ifndef QTCHESSGUI_H
#define QTCHESSGUI_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class QtChessGUI; }
QT_END_NAMESPACE

class QtChessGUI : public QMainWindow
{
    Q_OBJECT

public:
    QtChessGUI(QWidget *parent = nullptr);
    ~QtChessGUI();

private:
    Ui::QtChessGUI *ui;
};
#endif // QTCHESSGUI_H
