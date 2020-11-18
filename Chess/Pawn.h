#pragma once
#include "SubsidiaryPiece.h"

class Pawn : public SubsidiaryPiece
{
public:
    Pawn(Color color = white, ChessBoard* chessBoard = nullptr, Game* game = nullptr);
private:
	vector<Position> GetPossibleMovesInternal(Position position, Chess::Direction pinDirection);
	vector<Position> GetPossibleMovesInternal(Position position, Chess::Direction pinDirection,
		Chess::Direction moveDirection, Chess::Direction firstTakeDirection, 
		Chess::Direction secondTakeDirection, int longMoveHorizontal);
	void CheckMove(Position position, Chess::Direction pinDirection,
		Chess::Direction moveDirection, int distance,
		std::vector<Position>& possibleMovesVector);
	void CheckTaking(Position position, Chess::Direction pinDirection,
		Chess::Direction takeDirection,
		std::vector<Position>& possibleMovesVector);
    void CheckEnPassant(Position position, Chess::Direction pinDirection,
        Chess::Direction enPassant, Chess::Direction enemyPawnDirection,
        std::vector<Position>& possibleMovesVector);
};
