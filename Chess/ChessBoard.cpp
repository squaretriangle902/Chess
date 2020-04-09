#pragma once
#include "ChessBoard.h"

ChessBoard::ChessBoard(int size = 8)
{
	this->chessBoard = CreateChessBoard(size);
	this->size = size;
	FillWithNull(this->chessBoard, this->size);/* this method cleans chess board
											   because default constructor must
											   return clean chess board. But I need
											   another same method which is not class
											   member*/

}

int ChessBoard::GetSize()
{
	return this->size;
}

Piece*& ChessBoard::GetPiecePtr(Position position)
{
	return chessBoard[position.horizontal][position.vertical];
}

Piece*& ChessBoard::GetPiecePtr(int horizontal, int vertical)
{
	return chessBoard[horizontal][vertical];
}

void ChessBoard::SetPiecePtr(Position position, Piece* newPiecePtr)
{
	Piece*& currentPiecePtr = this->GetPiecePtr(position);
	if (currentPiecePtr == NULL)
	{
		currentPiecePtr = newPiecePtr;
	}
}

void ChessBoard::SetPiecePtr(int horizontal, int vertical, Piece* newPiecePtr)
{
	Piece*& currentPiecePtr = this->GetPiecePtr(horizontal, vertical);
	if (currentPiecePtr == NULL)
	{
		currentPiecePtr = newPiecePtr;
	}
}

Piece*** ChessBoard::CreateChessBoard(int size)
{
	Piece*** chessBoard = new Piece * *[size];
	for (int i = 0; i < size; i++)
	{
		chessBoard[i] = new Piece * [size];
	}
	return chessBoard;
}

void ChessBoard::FillWithNull(Piece***& chessBoard, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			chessBoard[i][j] = NULL;
		}
	}
}

//vector<Position> GetBishopPossibleMoves(Position position, Bishop* bishop)
//{
//	vector<Position> bishopMoves;
//	vector<Position> possibleMoves;
//	for (int i = 0; i < 8; i++)
//	{
//		bishopMoves = bishop->GetMoves(position, this->size, static_cast<Direction>(i));
//		int j = 0;
//		while (j < bishopMoves.size() && GetPiecePtr(bishopMoves.at(j)) == NULL)
//		{
//			possibleMoves.push_back(bishopMoves.at(j));
//		}
//	}
//}

//vector<Position> GetPossibleMoves(Position position)
//{
//	Piece* piecePtr = GetPiecePtr(position);
//	vector<Position> possibleMovesVector;
//	if (piecePtr)
//	{
//		possibleMovesVector = piecePtr->GetMoves(position);
//		RestrictIllegalMoves(possibleMovesVector, piecePtr);
//	}
//	return possibleMovesVector;
//}

	//void RestrictIllegalMoves(vector<Position>& possibleMovesVector, Piece* piece)
	//{
	//	vector<Position>::iterator iterator = possibleMovesVector.begin();//need refactoring
	//	for (int i = 0; i < possibleMovesVector.size(); i++)
	//	{
	//		OverflowRestriction(possibleMovesVector, i, iterator);
	//	}
	//	for (int i = 0; i < possibleMovesVector.size(); i++)
	//	{
	//		RestrictFriendlyTaking(possibleMovesVector, i, piece, iterator);
	//	}
	//}
