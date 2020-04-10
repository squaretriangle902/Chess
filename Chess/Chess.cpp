// using standard exceptions
#pragma once
#include <iostream>
#include <exception>
#include "ChessBoard.h"
#include "Pieces.h"
#include "Queen.h"

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
	Queen* whiteQueen = new Queen(white, chessBoardPtr);
	Queen* blackQueen = new Queen(black, chessBoardPtr);
	chessBoardPtr->SetPiecePtr(Position(1, 5), whiteQueen);
	chessBoardPtr->SetPiecePtr(Position(3, 7), whiteQueen);
	chessBoardPtr->SetPiecePtr(Position(5, 7), whiteQueen);
	chessBoardPtr->SetPiecePtr(Position(1, 1), blackQueen);
	std::vector<Position> possibleMovesVector=whiteQueen->GetPossibleMoves(Position(1, 5));

	system("pause");
}

//(1, 5) -- (1, 6) (2, 6) (2, 5) (2, 4) (1, 4) (0, 4) (0, 5) (0, 6) (1, 7) (3, 5) (3, 3) (1, 3) (4, 5) (4, 2) (1, 2) (5, 1) (1, 1) (6, 0)