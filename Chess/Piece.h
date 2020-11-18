#pragma once
#include "Position.h"
#include "Color.h"
#include "PieceType.h"
#include "ChessBoard.h"
#include "Game.h"
#include <vector>

using namespace std;

class Game;

class ChessBoard;

class Piece
{
public:
    Piece(Color color, ChessBoard* chessBoardPtr, Game* game);
    Color GetColor();
	PieceType GetType();
	bool IsMoveValid(Position position);
	void SetChessBoardPtr(ChessBoard* chessBoardPtr);
	vector<Position> GetPossibleMoves(Position);
    void SetMoved(bool moved);
    bool GetMoved();

protected:
	virtual vector<Position> GetPossibleMovesInternal(Position) = 0;
	PieceType type;
    bool moved;
	Color color;
	ChessBoard* chessBoardPtr;
    Game* game;
};
