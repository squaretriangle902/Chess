#ifndef INPUTPIECEDIALOG_H
#define INPUTPIECEDIALOG_H

#include <QDialog>

namespace Ui {
class InputPieceDialog;
}

class InputPieceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InputPieceDialog(QWidget *parent = nullptr);
    ~InputPieceDialog();

private:
    Ui::InputPieceDialog *ui;
};

#endif // INPUTPIECEDIALOG_H
