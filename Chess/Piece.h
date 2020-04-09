#pragma once
#include "Position.h"
#include "Color.h"
#include "ChessBoard.h"
#include <vector>

using namespace std;

class ChessBoard;

class Piece
{
public:
	Piece(Color color, ChessBoard* chessBoard);
	Color GetColor();
	virtual vector<Position> GetPossibleMoves(Position) = 0;
	bool IsMoveValid(Position position);

protected:
	Color color;
	ChessBoard* chessBoardPtr;
};