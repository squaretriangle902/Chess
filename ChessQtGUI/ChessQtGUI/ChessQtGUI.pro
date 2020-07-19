QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += C:/Users/squar/sourse/repos/Chess/Chess

SOURCES += \
    ../../Chess/Bishop.cpp \
    ../../Chess/ChessBoard.cpp \
    ../../Chess/Color.cpp \
    ../../Chess/Common.cpp \
    ../../Chess/Direction.cpp \
    ../../Chess/King.cpp \
    ../../Chess/Knight.cpp \
    ../../Chess/LongRangePiece.cpp \
    ../../Chess/Pawn.cpp \
    ../../Chess/Piece.cpp \
    ../../Chess/Position.cpp \
    ../../Chess/Queen.cpp \
    ../../Chess/GCD.cpp \
    ../../Chess/Rook.cpp \
    ../../Chess/Source.cpp \
    ../../Chess/SubsidiaryPiece.cpp \
    PieceDisplay.cpp \
    SquareMarker.cpp \
    main.cpp \
    chessqtgui.cpp

HEADERS += \
    ../../Chess/Bishop.h \
    ../../Chess/ChessBoard.h \
    ../../Chess/Color.h \
    ../../Chess/Common.h \
    ../../Chess/Direction.h \
    ../../Chess/King.h \
    ../../Chess/Knight.h \
    ../../Chess/LongRangePiece.h \
    ../../Chess/Pawn.h \
    ../../Chess/Piece.h \
    ../../Chess/PieceType.h \
    ../../Chess/Pieces.h \
    ../../Chess/Position.h \
    ../../Chess/Queen.h \
    ../../Chess/GCD.h \
    ../../Chess/Rook.h \
    ../../Chess/SubsidiaryPiece.h \
    PieceDisplay.h \
    SquareMarker.h \
    chessqtgui.h

FORMS += \
    chessqtgui.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../../Chess/Chess.vcxproj \
    ../../Chess/Chess.vcxproj.filters \
    ../../Chess/x64/Debug/Bishop.obj \
    ../../Chess/x64/Debug/Chess.Build.CppClean.log \
    ../../Chess/x64/Debug/Chess.log \
    ../../Chess/x64/Debug/Chess.tlog/CL.command.1.tlog \
    ../../Chess/x64/Debug/Chess.tlog/CL.read.1.tlog \
    ../../Chess/x64/Debug/Chess.tlog/CL.write.1.tlog \
    ../../Chess/x64/Debug/Chess.tlog/Chess.lastbuildstate \
    ../../Chess/x64/Debug/Chess.tlog/link-cvtres.read.1.tlog \
    ../../Chess/x64/Debug/Chess.tlog/link-cvtres.write.1.tlog \
    ../../Chess/x64/Debug/Chess.tlog/link-rc.read.1.tlog \
    ../../Chess/x64/Debug/Chess.tlog/link-rc.write.1.tlog \
    ../../Chess/x64/Debug/Chess.tlog/link.1004-cvtres.read.1.tlog \
    ../../Chess/x64/Debug/Chess.tlog/link.1004-cvtres.write.1.tlog \
    ../../Chess/x64/Debug/Chess.tlog/link.1004-rc.read.1.tlog \
    ../../Chess/x64/Debug/Chess.tlog/link.1004-rc.write.1.tlog \
    ../../Chess/x64/Debug/Chess.tlog/link.1004.read.1.tlog \
    ../../Chess/x64/Debug/Chess.tlog/link.1004.write.1.tlog \
    ../../Chess/x64/Debug/Chess.tlog/link.command.1.tlog \
    ../../Chess/x64/Debug/Chess.tlog/link.read.1.tlog \
    ../../Chess/x64/Debug/Chess.tlog/link.write.1.tlog \
    ../../Chess/x64/Debug/Chess.tlog/unsuccessfulbuild \
    ../../Chess/x64/Debug/Chess.vcxproj.FileListAbsolute.txt \
    ../../Chess/x64/Debug/ChessBoard.obj \
    ../../Chess/x64/Debug/Common.obj \
    ../../Chess/x64/Debug/Direction.obj \
    ../../Chess/x64/Debug/GCD.obj \
    ../../Chess/x64/Debug/King.obj \
    ../../Chess/x64/Debug/Knight.obj \
    ../../Chess/x64/Debug/LongRangePiece.obj \
    ../../Chess/x64/Debug/Pawn.obj \
    ../../Chess/x64/Debug/Piece.obj \
    ../../Chess/x64/Debug/Position.obj \
    ../../Chess/x64/Debug/Queen.obj \
    ../../Chess/x64/Debug/Rook.obj \
    ../../Chess/x64/Debug/Source.obj \
    ../../Chess/x64/Debug/SubsidiaryPiece.obj \
    ../../Chess/x64/Debug/TypeChecker.obj \
    ../../Chess/x64/Debug/vc142.idb \
    ../../Chess/x64/Debug/vc142.pdb \
    ../../Chess/x64/Release/Bishop.obj \
    ../../Chess/x64/Release/Chess.log \
    ../../Chess/x64/Release/Chess.obj \
    ../../Chess/x64/Release/Chess.tlog/CL.command.1.tlog \
    ../../Chess/x64/Release/Chess.tlog/CL.read.1.tlog \
    ../../Chess/x64/Release/Chess.tlog/CL.write.1.tlog \
    ../../Chess/x64/Release/Chess.tlog/Chess.lastbuildstate \
    ../../Chess/x64/Release/Chess.tlog/Chess.write.1u.tlog \
    ../../Chess/x64/Release/Chess.tlog/link.command.1.tlog \
    ../../Chess/x64/Release/Chess.tlog/link.read.1.tlog \
    ../../Chess/x64/Release/Chess.tlog/link.write.1.tlog \
    ../../Chess/x64/Release/ChessBoard.obj \
    ../../Chess/x64/Release/King.obj \
    ../../Chess/x64/Release/Knight.obj \
    ../../Chess/x64/Release/LongRangePiece.obj \
    ../../Chess/x64/Release/Pawn.obj \
    ../../Chess/x64/Release/Piece.obj \
    ../../Chess/x64/Release/Position.obj \
    ../../Chess/x64/Release/Queen.obj \
    ../../Chess/x64/Release/Rook.obj \
    ../../Chess/x64/Release/TypeChecker.obj \
    ../../Chess/x64/Release/vc142.pdb \
    .gitignore

RESOURCES += \
    resources.qrc
