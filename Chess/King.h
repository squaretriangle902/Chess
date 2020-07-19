#pragma once
#include "Direction.h"
#include "Piece.h"

class King : public Piece
{
public:
	King(Color color, ChessBoard* chessBoardPtr);
    vector<Position> GetPossibleMoves(Position startingPosition);
	vector<Position> GetCheckingPiecesPosition(Position kingPosition);
	vector<Position> GetDefendingMoves(Position kingPosition, 
		vector<Position> checkingPiecesPosition);
private:
	void IsPawnCheck(Position startingPosition, Chess::Direction firstCheckDirection,
		Chess::Direction secondCheckDirection, vector<Position>& checkingPiecesPosition);
	void IsLongRangeCheck(Position startingPosition, vector<Position>& checkingPiecesPosition);
	void IsCheckOnOffset(Position startingPosition, Position positionOffset, 
		PieceType pieceType, vector<Position>& checkingPiecesPosition);
	void IsKnightCheck(Position startingPosition, vector<Position>& checkingPiecesPosition);
	void IsPawnCheck(Position startingPosition, vector<Position>& checkingPiecesPosition);
	void CheckMove(Position startingPosition, Chess::Direction direction, 
		std::vector<Position>& possibleMovesVector);
	void IsCheckOnDirection(Position startPosition, Chess::Direction direction, 
		PieceType expectingType, vector<Position>& checkingPiecesPosition);
};

