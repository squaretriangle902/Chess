#pragma once
#include "Piece.h"

enum GameResult
{
	whiteWon = 0,
	blackWon = 1,
	draw = 2,
	none = 3,
};

class Game
{
	Game();
	bool EndOfGame(Piece*** ChessPosition);

private:
	Color turn;
	bool whiteKingSideCastlingAllowed;
	bool blackKingSideCastlingAllowed;
	bool whiteQueenSideCastlingAllowed;
	bool blackQueenSideCastlingAllowed;
	vector<Piece***> ChessPositions;
};

