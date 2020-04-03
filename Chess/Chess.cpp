// using standard exceptions
#include <iostream>
#include <exception>
#include "ChessBoard.h"
#include "Figure.h"

using namespace std;

void VisualizeChessBoard(ChessBoard chessBoard)
{
	for (int i = 0; i < chessBoard.GetSize(); i++)
	{
		for (int j = 0; j < chessBoard.GetSize(); j++)
		{
			if (chessBoard.GetFigure(Position(i, j)))
			{
				cout << " 1 ";
			}
			else
			{
				cout << " 0 ";
			}
		}
		cout << "\n";
	}
}

int main() 
{
	ChessBoard chessBoard = ChessBoard();
	VisualizeChessBoard(chessBoard);
	system("pause");
}