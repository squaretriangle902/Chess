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
}

void ChessBoard::SetPiecePtr(int horizontal, int vertical, Piece* newPiecePtr)
{
	chessBoard[horizontal][vertical] = newPiecePtr;
	newPiecePtr->SetChessBoardPtr(this);
}

bool ChessBoard::InBorders(Position position)
{
	return (position.horizontal < size) && 
		(position.horizontal >= 0) &&
		(position.vertical < size) &&
		(position.vertical >= 0);
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