// using standard exceptions
#include <iostream>
#include <exception>
#include "ChessBoard.h"
#include "Piece.h"
#include "Knight.h"
#include "Bishop.h"

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
	ChessBoard* chessBoardPtr = new ChessBoard(8);
	VisualizeChessBoard(chessBoardPtr);
	Knight* whiteKnight1 = new Knight(white, chessBoardPtr);
	Knight* whiteKnight2 = new Knight(white, chessBoardPtr);
	Knight* blackKnight = new Knight(black, chessBoardPtr);
	Bishop* whiteBishop1 = new Bishop(white, chessBoardPtr);
	Bishop* whiteBishop2 = new Bishop(white, chessBoardPtr);
	Bishop* blackBishop = new Bishop(black, chessBoardPtr);
	chessBoardPtr->SetPiecePtr(6, 3, whiteKnight1);
	chessBoardPtr->SetPiecePtr(7, 1, whiteKnight2);
	chessBoardPtr->SetPiecePtr(5, 1, blackKnight);
	//chessBoardPtr.SetPiecePtr(3, 3, whiteBishop);
	//VisualizeChessBoard(chessBoard);
	//chessBoardPtr->SetPiecePtr(3, 3, whiteBishop1);
	//chessBoardPtr->SetPiecePtr(5, 1, whiteBishop2);
	//chessBoardPtr->SetPiecePtr(5, 5, blackBishop);
	//chessBoardPtr->GetPiecePtr(Position(5, 5));
	VisualizeChessBoard(chessBoardPtr);
	vector<Position> v = whiteKnight1->GetPossibleMoves(Position(6, 3));
	system("pause");
}