#include "ChessBoard.h"
#include "Pieces.h"

int main()
{
	ChessBoard* chessBoardPtr = new ChessBoard(8);
	Piece* whitePawn = new Pawn(white, chessBoardPtr);
	Piece* blackPawn = new Pawn(black, chessBoardPtr);
	chessBoardPtr->SetPiecePtr(Position(0, 1), whitePawn);
	chessBoardPtr->SetPiecePtr(Position(3, 2), whitePawn);
	chessBoardPtr->SetPiecePtr(Position(5, 1), whitePawn);
	chessBoardPtr->SetPiecePtr(Position(5, 3), whitePawn);
	chessBoardPtr->SetPiecePtr(Position(1, 2), blackPawn);
	chessBoardPtr->SetPiecePtr(Position(4, 4), blackPawn);
	chessBoardPtr->SetPiecePtr(Position(6, 4), blackPawn);
	std::vector<Position> expectedPossibleMovesVector;
	expectedPossibleMovesVector.push_back(Position(0, 2));
	expectedPossibleMovesVector.push_back(Position(0, 3));
	expectedPossibleMovesVector.push_back(Position(1, 2));
	std::vector<Position> actualPossibleMovesVector =
		whitePawn->GetPossibleMoves(Position(0, 1));
	CompareVector(expectedPossibleMovesVector, whitePawn->GetPossibleMoves(Position(0, 1)));
}