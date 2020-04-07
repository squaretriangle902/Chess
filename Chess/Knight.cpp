#include "Knight.h"

Knight::Knight(Color color, ChessBoard* chessBoardPtr) : Piece(color, chessBoardPtr)
{
}

vector<Position> Knight::GetPossibleMoves(Position position)
{
	return vector<Position>();
}


//vector<Position> GetMoves(Position startingPosition)
//{
//	vector<Position> positionsVector;
//	positionsVector.push_back(
//		Position(startingPosition.horizontal + 1, startingPosition.vertical + 2));
//	positionsVector.push_back(
//		Position(startingPosition.horizontal + 2, startingPosition.vertical + 1));
//	positionsVector.push_back(
//		Position(startingPosition.horizontal + 2, startingPosition.vertical - 1));
//	positionsVector.push_back(
//		Position(startingPosition.horizontal + 1, startingPosition.vertical - 2));
//	positionsVector.push_back(
//		Position(startingPosition.horizontal - 1, startingPosition.vertical - 2));
//	positionsVector.push_back(
//		Position(startingPosition.horizontal - 2, startingPosition.vertical - 1));
//	positionsVector.push_back(
//		Position(startingPosition.horizontal - 2, startingPosition.vertical + 1));
//	positionsVector.push_back(
//		Position(startingPosition.horizontal - 1, startingPosition.vertical + 2));
//	return positionsVector;
//}