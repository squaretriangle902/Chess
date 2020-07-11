#pragma once
#include "Rook.h"

Rook::Rook(Color color, ChessBoard* chessBoardPtr) : 
	LongRangePiece(color, chessBoardPtr)
{
	this->type = rook;
	this->moveDirectionsVector = vector<Chess::Direction>{ Chess::up,
	Chess::left,
	Chess::down,
	Chess::right};
}