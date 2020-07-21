#include "ChessBoard.h"
#include "Pieces.h"

int main()
{
	ChessBoard* chessBoardPtr = new ChessBoard();
	Piece* blackQueen = new Knight(black, chessBoardPtr);
	Piece* whiteKing = new King(white, chessBoardPtr);
	chessBoardPtr->SetPiecePtr(Position(0, 0), whiteKing);
	chessBoardPtr->SetPiecePtr(Position(0, 3), blackQueen);
	vector<Position> possibleMovesVector = whiteKing->GetPossibleMoves(Position(4, 0));

}
