#pragma once
#include "Piece.h"
#include "Common.h"

class SubsidiaryPiece : public Piece
{
public: 
	SubsidiaryPiece(Color color, ChessBoard* chessBoardPtr);
	vector<Position> GetPossibleMoves(Position position);
protected:
	virtual vector<Position> GetPossibleMoves(Position position, 
		Chess::Direction pinDirection) = 0;
	bool TryGetDirectionFromPieceToKing(Chess::Direction& direction,
		Position piecePosition, Position kingPosition);
	bool IsDirectionFromPieceToKingClear(Chess::Direction direction,
		Position piecePosition, Position kingPosition);
	bool IsPinningPiece(Chess::Direction direction, Position piecePosition,
		PieceType pinningPieceType);
	PieceType PinningPieceType(Chess::Direction direction);
	bool IsPinned(Position position, Chess::Direction& direction);
};