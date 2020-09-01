#include "ChessBoard.h"
#include "Pieces.h"

int main()
{
	ChessBoard* chessBoardPtr = new ChessBoard();
	Piece* blackQueen = new Queen(black, chessBoardPtr);
	Piece* whiteKing = new King(white, chessBoardPtr);
	Piece* whiteQueen = new Queen(white, chessBoardPtr);
	chessBoardPtr->SetPiecePtr(Position(0, 0), whiteKing);
	chessBoardPtr->SetPiecePtr(Position(1, 2), whiteQueen);
	chessBoardPtr->SetPiecePtr(Position(0, 3), blackQueen);
	vector<Position> possibleMovesVector = whiteQueen->GetPossibleMoves(Position(1, 2));

}
