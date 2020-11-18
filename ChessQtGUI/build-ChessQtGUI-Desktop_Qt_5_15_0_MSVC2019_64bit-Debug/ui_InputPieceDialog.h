/********************************************************************************
** Form generated from reading UI file 'InputPieceDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUTPIECEDIALOG_H
#define UI_INPUTPIECEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_InputPieceDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QPushButton *knightButton;
    QPushButton *bishopButton;
    QPushButton *rookButton;
    QPushButton *queenButton;

    void setupUi(QDialog *InputPieceDialog)
    {
        if (InputPieceDialog->objectName().isEmpty())
            InputPieceDialog->setObjectName(QString::fromUtf8("InputPieceDialog"));
        InputPieceDialog->setEnabled(true);
        InputPieceDialog->resize(336, 93);
        horizontalLayout = new QHBoxLayout(InputPieceDialog);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        knightButton = new QPushButton(InputPieceDialog);
        knightButton->setObjectName(QString::fromUtf8("knightButton"));
        knightButton->setMinimumSize(QSize(75, 75));
        QFont font;
        font.setPointSize(36);
        knightButton->setFont(font);
        knightButton->setStyleSheet(QString::fromUtf8("qproperty-icon: url(:/Images/WhitePieces/Rook.png)"));
        knightButton->setIconSize(QSize(70, 70));

        horizontalLayout->addWidget(knightButton);

        bishopButton = new QPushButton(InputPieceDialog);
        bishopButton->setObjectName(QString::fromUtf8("bishopButton"));
        bishopButton->setMinimumSize(QSize(75, 75));
        bishopButton->setFont(font);
        bishopButton->setStyleSheet(QString::fromUtf8("qproperty-icon: url(:/Images/WhitePieces/Bishop.png)"));
        bishopButton->setIconSize(QSize(70, 70));

        horizontalLayout->addWidget(bishopButton);

        rookButton = new QPushButton(InputPieceDialog);
        rookButton->setObjectName(QString::fromUtf8("rookButton"));
        rookButton->setMinimumSize(QSize(75, 75));
        rookButton->setFont(font);
        rookButton->setStyleSheet(QString::fromUtf8("qproperty-icon: url(:/Images/WhitePieces/Rook.png)"));
        rookButton->setIconSize(QSize(70, 70));

        horizontalLayout->addWidget(rookButton);

        queenButton = new QPushButton(InputPieceDialog);
        queenButton->setObjectName(QString::fromUtf8("queenButton"));
        queenButton->setMinimumSize(QSize(75, 75));
        queenButton->setFont(font);
        queenButton->setStyleSheet(QString::fromUtf8("qproperty-icon: url(:/Images/WhitePieces/Queen.png)"));
        queenButton->setIconSize(QSize(70, 70));

        horizontalLayout->addWidget(queenButton);


        retranslateUi(InputPieceDialog);

        QMetaObject::connectSlotsByName(InputPieceDialog);
    } // setupUi

    void retranslateUi(QDialog *InputPieceDialog)
    {
        InputPieceDialog->setWindowTitle(QCoreApplication::translate("InputPieceDialog", "Choose piece", nullptr));
        knightButton->setText(QString());
        bishopButton->setText(QString());
        rookButton->setText(QString());
        queenButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class InputPieceDialog: public Ui_InputPieceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTPIECEDIALOG_H
