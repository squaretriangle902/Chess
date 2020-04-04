#pragma once
#include <vector>
#include "Piece.h"
#include "Bishop.h"
#include "TypeChecker.cpp"

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

	vector<Position> GetBishopPossibleMoves(Position position, Bishop* bishop)
	{
		vector<Position> bishopMoves;
		vector<Position> possibleMoves;
		for (int i = 0; i < 8; i++)
		{
			bishopMoves = bishop->GetMoves(position, this->size, static_cast<Direction>(i));
			int j = 0;
			while (j < bishopMoves.size() && GetPiecePtr(bishopMoves.at(j)) == NULL)
			{
				possibleMoves.push_back(bishopMoves.at(j));
			}
		}
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
			currentPiecePtr->SetChessBoard(&(this->chessBoard));
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

	void OverflowRestriction(std::vector<Position>& possibleMovesVector, 
		int& i, 
		std::vector<Position>::iterator& iterator)
	{
		if (possibleMovesVector.at(i).horizontal > size - 1 ||
			possibleMovesVector.at(i).vertical > size - 1 ||
			possibleMovesVector.at(i).horizontal < 0 ||
			possibleMovesVector.at(i).vertical < 0)
		{
			possibleMovesVector.erase(iterator + i);
			i--;
		}
	}

	void RestrictIllegalMoves(vector<Position>& possibleMovesVector, Piece* piece)
	{
		vector<Position>::iterator iterator = possibleMovesVector.begin();//need refactoring
		for (int i = 0; i < possibleMovesVector.size(); i++)
		{
			OverflowRestriction(possibleMovesVector, i, iterator);
		}
		for (int i = 0; i < possibleMovesVector.size(); i++)
		{
			RestrictFriendlyTaking(possibleMovesVector, i, piece, iterator);
		}
	}

	Piece*** CreateChessBoard(int size)
	{
		Piece*** chessBoard = new Piece** [size];
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

