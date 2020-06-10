/********************************************************************************
** Form generated from reading UI file 'chessqtgui.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHESSQTGUI_H
#define UI_CHESSQTGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChessQtGUI
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ChessQtGUI)
    {
        if (ChessQtGUI->objectName().isEmpty())
            ChessQtGUI->setObjectName(QString::fromUtf8("ChessQtGUI"));
        ChessQtGUI->resize(560, 535);
        centralwidget = new QWidget(ChessQtGUI);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 20, 450, 449));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 100, 47, 13));
        ChessQtGUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ChessQtGUI);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 560, 21));
        ChessQtGUI->setMenuBar(menubar);
        statusbar = new QStatusBar(ChessQtGUI);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ChessQtGUI->setStatusBar(statusbar);

        retranslateUi(ChessQtGUI);

        QMetaObject::connectSlotsByName(ChessQtGUI);
    } // setupUi

    void retranslateUi(QMainWindow *ChessQtGUI)
    {
        ChessQtGUI->setWindowTitle(QCoreApplication::translate("ChessQtGUI", "ChessQtGUI", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("ChessQtGUI", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChessQtGUI: public Ui_ChessQtGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHESSQTGUI_H
