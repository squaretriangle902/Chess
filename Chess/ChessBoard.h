#pragma once
#include <vector>
#include "Piece.h"

using namespace std;

class ChessBoard
{
public:
	ChessBoard(int size = 8)
	{
		this->chessBoard = CreateChessBoard(size);
		this->size = size;
		FillWithNull(this->chessBoard, this->size);/* this method cleans chess board 
												   because default constructor must
												   return clean chess board. But I need
												   another same method which is not class
												   member*/
		
	}

	int GetSize()
	{
		return this->size;
	}

	Piece*& GetPiecePtr(Position position)
	{
		return chessBoard[position.horizontal][position.vertical];
	}

	vector<Position> GetPossibleMoves(Position position)
	{
		Piece* piecePtr = GetPiecePtr(position);
		vector<Position> possibleMovesVector;
		if (piecePtr)
		{
			possibleMovesVector = piecePtr->GetMoves(position);
			RestrictFriendlyTaking(possibleMovesVector, piecePtr);
		}
		return possibleMovesVector;
	}

	void SetPiecePtr(Position position, Piece* newPiecePtr)
	{
		Piece*& currentPiecePtr = this->GetPiecePtr(position);
		if (currentPiecePtr == NULL)
		{
			currentPiecePtr = newPiecePtr;
		}
	}

private:
	Piece*** chessBoard;
	int size;

	void RestrictFriendlyTaking(vector<Position>& possibleMovesVector, Piece* figure)
	{
		vector<Position>::iterator iterator = possibleMovesVector.begin();
		for (int i = 0; i < possibleMovesVector.size(); i++)
		{
			Piece* anotherFigure = GetPiecePtr(possibleMovesVector.at(i));
			if (anotherFigure)
			{
				if (anotherFigure->GetColor() == figure->GetColor())
				{
					possibleMovesVector.erase(iterator + i);
				}
			}
		}
	}

	Piece*** CreateChessBoard(int size)
	{
		Piece*** chessBoard = new Piece * *[size];
		for (int i = 0; i < size; i++)
		{
			chessBoard[i] = new Piece * [size];
		}
		return chessBoard;
	}

	void FillWithNull(Piece***& chessBoard, int size)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				chessBoard[i][j] = NULL;
			}
		}
	}
};

