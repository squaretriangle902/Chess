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
	bool IsPinned(Position position);

protected:
	bool TryGetDirection(Chess::Direction& direction, Position position);
	bool TryGetDirectionFromPieceToKing(Chess::Direction& direction,
		Position piecePosition, Position kingPosition);
	bool IsDirectionFromPieceToKingClear(Chess::Direction direction,
		Position piecePosition, Position kingPosition);
	bool IsPinningPiece(Chess::Direction direction, Position piecePosition, 
		PieceType pinningPieceType);
	PieceType PinningPieceType(Chess::Direction direction);
	PieceType type;
	Color color;
	ChessBoard* chessBoardPtr;
};