// using standard exceptions
#include <iostream>
#include <exception>
#include "ChessBoard.h"
#include "Piece.h"
#include "Knight.h"

using namespace std;

void VisualizeChessBoard(ChessBoard chessBoard)
{
	for (int i = 0; i < chessBoard.GetSize(); i++)
	{
		for (int j = 0; j < chessBoard.GetSize(); j++)
		{
			if (chessBoard.GetPiecePtr(Position(i, j)))
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
	ChessBoard chessBoard = ChessBoard();
	VisualizeChessBoard(chessBoard);
	Knight* blackKnight1Ptr = new Knight(black);
	Knight* blackKnight2Ptr = new Knight(black);
	Knight* whiteKnight1Ptr = new Knight(white);
	chessBoard.SetPiecePtr(Position(0, 0), blackKnight1Ptr);
	chessBoard.SetPiecePtr(Position(2, 1), blackKnight2Ptr);
	chessBoard.SetPiecePtr(Position(5, 4), whiteKnight1Ptr);
	VisualizeChessBoard(chessBoard);
	vector<Position> possibleMovesVector = chessBoard.GetPossibleMoves(Position(0, 0));
	system("pause");
}