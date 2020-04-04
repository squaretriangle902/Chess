#pragma once
#include "Position.h"
#include "Color.cpp"
#include <vector>

using namespace std;

class Piece
{
public:
	Piece(Color color, Piece**** chessBoard)
	{
		this->color = color;
		this->chessBoard = chessBoard;
	}

	virtual vector<Position> GetMoves(Position) = 0;

	Color GetColor()
	{
		return this->color;
	}

	void SetChessBoard(Piece**** chessBoard)
	{
		this->chessBoard = chessBoard;
	}

protected:
	Color color;
	Piece**** chessBoard;
};

