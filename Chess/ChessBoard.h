#pragma once
#include <vector>
#include "Figure.h"

using namespace std;

class ChessBoard
{
public:
	ChessBoard(int size = 8)
	{
		this->chessBoard = CreateChessBoard(size);
		this->size = size;
		FillWithNull(this->chessBoard, this->size);/* this method cleans chess board 
												   because default constructor must
												   return clean chess board. But I need
												   another same method which is not class
												   member*/
		
	}

	int GetSize()
	{
		return this->size;
	}

	Figure* GetFigure(Position position)
	{
		return chessBoard[position.horizontal][position.vertical];
	}

	void SelectSquare(Position position)
	{
		Figure* figure = chessBoard[position.horizontal][position.vertical];
		if (figure)
		{
			vector<Position> possibleMovesVector = figure->GetMoves(position);
			RestrictFriendlyEating(possibleMovesVector, figure);
		}

	}

private:
	Figure*** chessBoard;
	int size;

	void RestrictFriendlyEating(vector<Position>& possibleMovesVector, Figure* figure)
	{
		vector<Position>::iterator iterator = possibleMovesVector.begin();
		for (int i = 0; i < possibleMovesVector.size(); i++)
		{
			if (
				chessBoard
				[possibleMovesVector.at(i).horizontal]
			[possibleMovesVector.at(i).vertical]->GetColor() == figure->GetColor())
			{
				possibleMovesVector.erase(iterator + i);
			}
		}
	}

	Figure*** CreateChessBoard(int size)
	{
		Figure*** chessBoard = new Figure * *[size];
		for (int i = 0; i < size; i++)
		{
			chessBoard[i] = new Figure * [size];
		}
		return chessBoard;
	}

	void FillWithNull(Figure***& chessBoard, int size)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				chessBoard[i][j] = NULL;
			}
		}
	}
};

