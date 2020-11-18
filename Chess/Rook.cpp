#pragma once
#include "Rook.h"

Rook::Rook(Color color, ChessBoard* chessBoardPtr, Game* game) :
    LongRangePiece(color, chessBoardPtr, game)
{
	this->type = rook;
	this->moveDirectionsVector = vector<Chess::Direction>{ Chess::up,
	Chess::left,
	Chess::down,
	Chess::right};
}
