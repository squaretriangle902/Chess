#include "ChessBoard.h"
#include "Pieces.h"

int main()
{
	ChessBoard* chessBoardPtr = new ChessBoard(8);
	Piece* whiteBishop = new Bishop(white, chessBoardPtr);
	Piece* blackBishop = new Bishop(black, chessBoardPtr);
	King* whiteKing = new King(white, chessBoardPtr);
	chessBoardPtr->SetPiecePtr(Position(0, 0), whiteKing);
	chessBoardPtr->SetPiecePtr(Position(2, 2), whiteBishop);
	chessBoardPtr->SetPiecePtr(Position(5, 5), blackBishop);
	std::vector<Position> expectedPossibleMovesVector;
	expectedPossibleMovesVector.push_back(Position(1, 1));
	expectedPossibleMovesVector.push_back(Position(3, 3));
	expectedPossibleMovesVector.push_back(Position(4, 4));
	expectedPossibleMovesVector.push_back(Position(5, 5));
	vector<Position> defendingMoves;
	bool test = chessBoardPtr->GetDefendingMoves(white, defendingMoves);

}
