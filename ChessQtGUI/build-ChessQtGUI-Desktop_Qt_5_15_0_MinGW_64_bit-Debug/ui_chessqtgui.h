/********************************************************************************
** Form generated from reading UI file 'chessqtgui.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHESSQTGUI_H
#define UI_CHESSQTGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChessQtGUI
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ChessQtGUI)
    {
        if (ChessQtGUI->objectName().isEmpty())
            ChessQtGUI->setObjectName(QString::fromUtf8("ChessQtGUI"));
        ChessQtGUI->resize(660, 700);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ChessQtGUI->sizePolicy().hasHeightForWidth());
        ChessQtGUI->setSizePolicy(sizePolicy);
        ChessQtGUI->setMinimumSize(QSize(660, 700));
        ChessQtGUI->setMaximumSize(QSize(660, 700));
        centralwidget = new QWidget(ChessQtGUI);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setEnabled(true);
        graphicsView->setFrameShape(QFrame::StyledPanel);
        graphicsView->setLineWidth(5);
        graphicsView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        graphicsView->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(graphicsView, 0, 0, 1, 1);

        ChessQtGUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ChessQtGUI);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 660, 21));
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
