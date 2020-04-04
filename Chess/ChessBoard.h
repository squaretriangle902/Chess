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
			RestrictIllegalMoves(possibleMovesVector, piecePtr);
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

	void RestrictFriendlyTaking(std::vector<Position>& possibleMovesVector, 
		int& i, 
		Piece* piece, 
		std::vector<Position>::iterator& iterator)
	{
		Piece* anotherPiece = GetPiecePtr(possibleMovesVector.at(i));
		if (anotherPiece)
		{
			if (anotherPiece->GetColor() == piece->GetColor())
			{
				possibleMovesVector.erase(iterator + i);
				i--;
			}
		}
	}

	void OutOfBorderRestricting(std::vector<Position>& possibleMovesVector, 
		int& i, 
		std::vector<Position>::iterator& iterator)
	{
		if (possibleMovesVector.at(i).horizontal > size ||
			possibleMovesVector.at(i).vertical > size ||
			possibleMovesVector.at(i).horizontal < 0 ||
			possibleMovesVector.at(i).vertical < 0)
		{
			possibleMovesVector.erase(iterator + i);
			i--;
		}
	}

	void RestrictIllegalMoves(vector<Position>& possibleMovesVector, Piece* piece)
	{
		vector<Position>::iterator iterator = possibleMovesVector.begin();
		for (int i = 0; i < possibleMovesVector.size(); i++)
		{
			OutOfBorderRestricting(possibleMovesVector, i, iterator);
		}
		for (int i = 0; i < possibleMovesVector.size(); i++)
		{
			RestrictFriendlyTaking(possibleMovesVector, i, piece, iterator);
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

