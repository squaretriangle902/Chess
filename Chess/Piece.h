#pragma once
#include "Position.h"
#include "Color.h"
#include "ChessBoard.h"
#include "PieceType.h"
#include <vector>

using namespace std;

class ChessBoard;

class Piece
{
public:
	Piece(Color color, ChessBoard* chessBoardPtr);
	Color GetColor();
	PieceType GetType();
	virtual vector<Position> GetPossibleMoves(Position) = 0;
	bool IsMoveValid(Position position);
	void SetChessBoardPtr(ChessBoard* chessBoardPtr);

protected:
	bool IsPin(Position position);
	Chess::Direction FromPieceToKingDirection(Position piecePosition, 
			Position kingPosition);
	PieceType type;
	Color color;
	ChessBoard* chessBoardPtr;
};