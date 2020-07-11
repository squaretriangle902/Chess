#pragma once
#include "SubsidiaryPiece.h"
#include "Direction.h"

class LongRangePiece : public SubsidiaryPiece
{
public:
	LongRangePiece(Color color, ChessBoard* chessBoardPtr);
protected:
	vector<Position> GetPossibleMoves(Position position, Chess::Direction* pinDirection);
	void CheckDirectionsOverDistance(Position position, int distance,
		std::vector<Chess::Direction>& blockedDirectionsVector,
		std::vector<Position>& possibleMovesVector);
	void CheckPositionInDirection(Position startingPosition, int distance,
		std::vector<Chess::Direction>& blockedDirectionsVector,
		std::vector<Position>& possibleMovesVector,
		Chess::Direction direction);
	bool IsDirectionFree(Chess::Direction direction,
		vector<Chess::Direction> blockedDirectionsVector);
	void BlockAllExceptPinDirection(vector<Chess::Direction>& blockedDirectionsVector,
		Position position);
	vector<Chess::Direction> moveDirectionsVector;
};

