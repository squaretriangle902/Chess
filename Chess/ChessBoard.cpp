#pragma once
#include "ChessBoard.h"
#include "King.h"

ChessBoard::ChessBoard(int size, Color turn)
{
	this->chessBoard = CreateChessBoard(size);
	this->size = size;
	this->turn = turn;
	this->blackKingPosition = NULL;
	this->whiteKingPosition = NULL;
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

Piece* ChessBoard::GetPiecePtr(Position position)
{
	return chessBoard[position.horizontal][position.vertical];
}

Piece* ChessBoard::GetPiecePtr(int horizontal, int vertical)
{
	return chessBoard[horizontal][vertical];
}

void ChessBoard::SetPiecePtr(Position position, Piece* newPiecePtr)
{
	chessBoard[position.horizontal][position.vertical] = newPiecePtr;
	newPiecePtr->SetChessBoardPtr(this);
	if (newPiecePtr == NULL && newPiecePtr->GetType() != king)
	{
		return;
	}
	switch (newPiecePtr->GetColor())
	{
	case white:
		whiteKingPosition = &position;
		break;
	case black:
		blackKingPosition = &position;
		break;
	default:
		break;
	}
}

void ChessBoard::SetPiecePtr(int horizontal, int vertical, Piece* newPiecePtr)
{
	chessBoard[horizontal][vertical] = newPiecePtr;
	newPiecePtr->SetChessBoardPtr(this);
	if (newPiecePtr == NULL && newPiecePtr->GetType() != king)
	{
		return;
	}
	switch (newPiecePtr->GetColor())
	{
	case white:
		whiteKingPosition = new Position(horizontal, vertical);
		break;
	case black:
		blackKingPosition = new Position(horizontal, vertical);
		break;
	default:
		break;
	}
}

bool ChessBoard::InBorders(Position position)
{
	return (position.horizontal < size) && 
		(position.horizontal >= 0) &&
		(position.vertical < size) &&
		(position.vertical >= 0);
}

Position* ChessBoard::GetKingPosition(Color color)
{
	switch (color)
	{
	case black:
		return this->blackKingPosition;
		break;
	case white:
		return this->whiteKingPosition;
		break;
	}
}

//bool ChessBoard::TryMove(Position startPosition, Position endPoisiton)
//{
//	Piece* startPiecePtr = this->GetPiecePtr(startPosition);
//	Piece* endPiecePtr = this->GetPiecePtr(endPoisiton);
//	King* kingPtr;
//	Position* kingPosition;
//	switch (this->turn)
//	{
//	case black:
//		kingPtr = new King(black, this);
//		kingPosition = blackKingPosition;
//		break;
//	case white:
//		kingPtr = new King(white, this);
//		kingPosition = whiteKingPosition;
//		break;
//	default:
//		break;
//	}
//	if (startPiecePtr == NULL)
//	{
//		return false;
//	}
//	if (startPiecePtr->GetColor() == this->turn &&
//		IncludedInVector(endPoisiton, startPiecePtr->GetPossibleMoves(startPosition)))
//	{
//		this->SetPiecePtr(startPosition, NULL);
//		this->SetPiecePtr(endPoisiton, startPiecePtr);
//	}
//	if (kingPtr->IsCheck(*kingPosition))
//	{
//		this->SetPiecePtr(startPosition, startPiecePtr);
//		this->SetPiecePtr(endPoisiton, endPiecePtr);
//		return false;
//	}
//	return true;
//}

bool ChessBoard::IncludedInVector(Position position, vector<Position> vector)
{
	for (int i = 0; i < vector.size(); i++)
	{
		if (vector.at(i) == position)
		{
			return true;
		}
	}
	return false;
}

Piece*** ChessBoard::CreateChessBoard(int size)
{
	Piece*** chessBoard = new Piece** [size];
	for (int i = 0; i < size; i++)
	{
		chessBoard[i] = new Piece* [size];
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


