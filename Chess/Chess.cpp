// using standard exceptions
#include <iostream>
#include <exception>
#include "ChessBoard.h"
#include "Piece.h"
#include "Knight.h"
#include "Bishop.h"

using namespace std;

void VisualizeChessBoard(ChessBoard chessBoard)
{
	for (int i = chessBoard.GetSize() - 1; i >=0; i--)
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
	ChessBoard chessBoard = ChessBoard(8);
	ChessBoard* chessBoardPtr = &chessBoard;
	VisualizeChessBoard(chessBoard);
	Bishop* whiteBishop = new Bishop(white, chessBoardPtr);
	Bishop* whiteBishop1 = new Bishop(white, chessBoardPtr);
	Bishop* whiteBishop2 = new Bishop(white, chessBoardPtr);
	Bishop* blackBishop1 = new Bishop(black, chessBoardPtr);
	chessBoard.SetPiecePtr(3, 3, whiteBishop);
	VisualizeChessBoard(chessBoard);
	chessBoard.SetPiecePtr(0, 6, whiteBishop1);
	VisualizeChessBoard(chessBoard);
	chessBoard.SetPiecePtr(5, 5, whiteBishop2);
	VisualizeChessBoard(chessBoard);
	chessBoard.SetPiecePtr(6, 0, blackBishop1);
	VisualizeChessBoard(chessBoard);
	vector<Position> v = whiteBishop->GetPossibleMoves(Position(3, 3));
	system("pause");
}