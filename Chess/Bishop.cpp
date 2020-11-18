#pragma once
#include "Bishop.h"

Bishop::Bishop(Color color, ChessBoard* chessBoardPtr, Game* game) :
    LongRangePiece(color, chessBoardPtr, game)
{
	this->type = bishop;
	this->moveDirectionsVector = vector<Chess::Direction>{
		Chess::leftUp,
		Chess::leftDown,
		Chess::rightDown,
		Chess::rightUp };
}
