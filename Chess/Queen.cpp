#include "Queen.h"

Queen::Queen(Color color, ChessBoard* chessBoardPtr) :
	LongRangePiece(color, chessBoardPtr)
{
	this->type = queen;
	this->moveDirectionsVector = vector<Chess::Direction>{ Chess::up,
		Chess::leftUp,
	    Chess::left,
	    Chess::leftDown,
	    Chess::down,
	    Chess::rightDown,
	    Chess::right,
	    Chess::rightUp };
}