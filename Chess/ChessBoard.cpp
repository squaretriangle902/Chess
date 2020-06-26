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
	return chessBoard[position.vertical][position.horizontal];
}

Piece* ChessBoard::GetPiecePtr(int vertical, int horizontal)
{
	return chessBoard[vertical][horizontal];
}

void ChessBoard::SetPiecePtr(Position position, Piece* newPiecePtr)
{
	chessBoard[position.vertical][position.horizontal] = newPiecePtr;
	if (newPiecePtr == NULL || newPiecePtr->GetType() != king)
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

void ChessBoard::SetPiecePtr(int vertical, int horizontal, Piece* newPiecePtr)
{
	chessBoard[vertical][horizontal] = newPiecePtr;
	if (newPiecePtr == NULL || newPiecePtr->GetType() != king)
	{
		return;
	}
	switch (newPiecePtr->GetColor())
	{
	case white:
		whiteKingPosition = new Position(vertical, horizontal);
		break;
	case black:
		blackKingPosition = new Position(vertical, horizontal);
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

bool ChessBoard::TryMove(Position startPosition, Position endPosition)
{
	Piece* startPiecePtr = this->GetPiecePtr(startPosition);
	Piece* endPiecePtr = this->GetPiecePtr(endPosition);
	vector<Position> possibleMovesVector = 
		startPiecePtr->GetPossibleMoves(startPosition);
	if (IncludedInVector(endPosition, possibleMovesVector))
	{
		this->SetPiecePtr(endPosition, startPiecePtr);
		this->SetPiecePtr(startPosition, NULL);
		return true;
	}
	return false;
}

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


