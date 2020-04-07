#include "Piece.h"
#include "ChessBoard.h"

Piece::Piece(Color color, ChessBoard* chessBoardPtr)
{
	this->color = color;
	this->chessBoardPtr = chessBoardPtr;
}

Color Piece::GetColor()
{
	return this->color;
}

bool Piece::IsMoveValid(Position position)
{
	int size = this->chessBoardPtr->GetSize();
	bool inBorders = (position.horizontal < size) && (position.horizontal >= 0) && 
		(position.vertical < size) &&
		(position.vertical >= 0);
	if (!inBorders)
	{
		return false;
	}
	Piece* piecePtr = this->chessBoardPtr->GetPiecePtr(position);
	return !piecePtr || piecePtr->color != this->color;

}

//void OverflowRestriction(std::vector<Position>& possibleMovesVector, 
//	int& i, 
//	std::vector<Position>::iterator& iterator)
//{
//	if (possibleMovesVector.at(i).horizontal > size - 1 ||
//		possibleMovesVector.at(i).vertical > size - 1 ||
//		possibleMovesVector.at(i).horizontal < 0 ||
//		possibleMovesVector.at(i).vertical < 0)
//	{
//		possibleMovesVector.erase(iterator + i);
//		i--;
//	}
//}


//void RestrictFriendlyTaking(std::vector<Position>& possibleMovesVector, 
//	int& i, 
//	Piece* piece, 
//	std::vector<Position>::iterator& iterator)
//{
//	Piece* anotherPiece = GetPiecePtr(possibleMovesVector.at(i));
//	if (anotherPiece)
//	{
//		if (anotherPiece->GetColor() == piece->GetColor())
//		{
//			possibleMovesVector.erase(iterator + i);
//			i--;
//		}
//	}
//}