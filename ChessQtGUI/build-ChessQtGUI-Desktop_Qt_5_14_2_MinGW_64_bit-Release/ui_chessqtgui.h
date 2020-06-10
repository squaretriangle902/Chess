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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChessQtGUI
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ChessQtGUI)
    {
        if (ChessQtGUI->objectName().isEmpty())
            ChessQtGUI->setObjectName(QString::fromUtf8("ChessQtGUI"));
        ChessQtGUI->resize(500, 500);
        centralwidget = new QWidget(ChessQtGUI);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        horizontalLayout->addWidget(graphicsView);

        ChessQtGUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ChessQtGUI);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 500, 21));
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
    } // retranslateUi

};

namespace Ui {
    class ChessQtGUI: public Ui_ChessQtGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHESSQTGUI_H
