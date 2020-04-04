#pragma once
#include "Piece.h"
#include "Direction.cpp"

class Bishop : public Piece
{
public:
	Bishop(Color color) : Piece(color)
	{
		this->jumps = false;
	}

	vector<Position> GetMoves(Position startingPosition, int chessBoardSize, 
		Direction direction)
	{
		vector<Position> positionsVector;
		if (rightUp)
		{
			for (int i = 1; i < chessBoardSize; i++)
			{
				positionsVector.push_back(
					Position(startingPosition.horizontal + i, 
						startingPosition.vertical + i));
			}
		}
		if (rightDown)
		{
			for (int i = 1; i < chessBoardSize; i++)
			{
				positionsVector.push_back(
					Position(startingPosition.horizontal + i, 
						startingPosition.vertical - i));
			}
		}
		if (leftDown)
		{
			for (int i = 1; i < chessBoardSize; i++)
			{
				positionsVector.push_back(
					Position(startingPosition.horizontal - i, 
						startingPosition.vertical + i));
			}
		}
		if (rightUp)
		{
			for (int i = 1; i < chessBoardSize; i++)
			{
				positionsVector.push_back(
					Position(startingPosition.horizontal - i, 
						startingPosition.vertical - i));
			}
		}
		return positionsVector;
	}
};

