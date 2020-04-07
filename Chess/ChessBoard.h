#pragma once
#include <vector>
#include "Piece.h"
#include "TypeChecker.cpp"

using namespace std;

class Piece;

class ChessBoard
{
public:
	ChessBoard(int size);
	int GetSize();
	Piece*& GetPiecePtr(Position position);
	Piece*& GetPiecePtr(int horizontal, int vertical);
	void SetPiecePtr(Position position, Piece* newPiecePtr);

	void SetPiecePtr(int horizontal, int vertical, Piece* newPiecePtr);

private:
	Piece*** chessBoard;
	int size;

	Piece*** CreateChessBoard(int size);
	void FillWithNull(Piece***& chessBoard, int size);
};

