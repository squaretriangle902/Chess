#pragma once
#include "Bishop.h"

Bishop::Bishop(Color color, ChessBoard* chessBoardPtr) :
	LongRangePiece(color, chessBoardPtr)
{
	this->type = bishop;
	this->moveDirectionsVector = vector<Chess::Direction>{
		Chess::leftUp,
		Chess::leftDown,
		Chess::rightDown,
		Chess::rightUp };
}