#include "ChessBoard.h"
#include "Pieces.h"

int main()
{
	ChessBoard* chessBoardPtr = new ChessBoard(8);
	chessBoardPtr->GetPiecePtr(1, 1);
	Queen* whiteQueen = new Queen(white, chessBoardPtr);
	Queen* blackQueen = new Queen(black, chessBoardPtr);
	King* whiteKing = new King(white, chessBoardPtr);
	chessBoardPtr->SetPiecePtr(Position(0, 0), whiteKing);
	chessBoardPtr->SetPiecePtr(Position(0, 1), whiteQueen);
	chessBoardPtr->SetPiecePtr(Position(0, 7), blackQueen);
	std::vector<Position> possibleMovesVector =
		whiteQueen->GetPossibleMoves(Position(0, 1));

}