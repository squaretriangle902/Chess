// using standard exceptions
#pragma once
#include <iostream>
#include <exception>
#include "ChessBoard.h"
#include "Pieces.h"

using namespace std;

void VisualizeChessBoard(ChessBoard* chessBoardPtr)
{
	for (int i = chessBoardPtr->GetSize() - 1; i >= 0; i--)
	{
		for (int j = 0; j < chessBoardPtr->GetSize(); j++)
		{
			if (chessBoardPtr->GetPiecePtr(Position(j, i)))
			{
				cout << "1 ";
			}
			else
			{
				cout << "0 ";
			}
		}
		cout << "\n";
	}
	cout << "\n";
}

int main()
{
	//ChessBoard* chessBoardPtr = new ChessBoard(8);
	//VisualizeChessBoard(chessBoardPtr);
	////Knight* whiteKnight1 = new Knight(white, chessBoardPtr);
	//Knight* whiteKnight2 = new Knight(white, chessBoardPtr);
	//Knight* blackKnight = new Knight(black, chessBoardPtr);
	//Bishop* whiteBishop1 = new Bishop(white, chessBoardPtr);
	//Bishop* whiteBishop2 = new Bishop(white, chessBoardPtr);
	//Bishop* blackBishop = new Bishop(black, chessBoardPtr);
	//Rook* whiteRook1 = new Rook(white, chessBoardPtr);
	//Rook* whiteRook2 = new Rook(white, chessBoardPtr);
	//Rook* blackRook = new Rook(black, chessBoardPtr);
	/*chessBoardPtr->SetPiecePtr(6, 3, whiteKnight1);
	chessBoardPtr->SetPiecePtr(7, 1, whiteKnight2);
	chessBoardPtr->SetPiecePtr(5, 1, blackKnight);*/
	//chessBoardPtr.SetPiecePtr(3, 3, whiteBishop);
	//VisualizeChessBoard(chessBoard);
	//chessBoardPtr->SetPiecePtr(3, 3, whiteBishop1);
	//chessBoardPtr->SetPiecePtr(5, 1, whiteBishop2);
	//chessBoardPtr->SetPiecePtr(5, 5, blackBishop);
	//chessBoardPtr->GetPiecePtr(Position(5, 5));
	//chessBoardPtr->SetPiecePtr(5, 3, whiteRook1);
	//chessBoardPtr->SetPiecePtr(3, 3, whiteRook2);
	//chessBoardPtr->SetPiecePtr(1, 3, blackRook);
	//Pawn* whitePawn = new Pawn(white, chessBoardPtr);
	//Pawn* blackPawn = new Pawn(black, chessBoardPtr);
	//chessBoardPtr->SetPiecePtr(Position(0, 1), whitePawn);
	//chessBoardPtr->SetPiecePtr(Position(1, 1), whitePawn);
	//chessBoardPtr->SetPiecePtr(Position(2, 3), whitePawn);
	//chessBoardPtr->SetPiecePtr(Position(1, 2), blackPawn);
	//chessBoardPtr->SetPiecePtr(Position(1, 4), blackPawn);
	//chessBoardPtr->SetPiecePtr(Position(0, 3), blackPawn);
	//chessBoardPtr->SetPiecePtr(Position(3, 4), blackPawn);
	//VisualizeChessBoard(chessBoardPtr);
	//vector<Position> v = whitePawn->GetPossibleMoves(Position(0, 1));
	ChessBoard* chessBoardPtr = new ChessBoard(8);
	Pawn* pawn = new Pawn(white, chessBoardPtr);
	bool a = pawn->GetColor() == Color::white;
	system("pause");
}

