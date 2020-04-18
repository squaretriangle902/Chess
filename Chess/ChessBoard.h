#pragma once
#include <vector>
#include "Piece.h"

using namespace std;

class Piece;

class ChessBoard
{
public:
	ChessBoard(int size = 8, Color color = white);
	int GetSize();
	Piece* GetPiecePtr(Position position);
	Piece* GetPiecePtr(int horizontal, int vertical);
	void SetPiecePtr(Position position, Piece* newPiecePtr);
	void SetPiecePtr(int horizontal, int vertical, Piece* newPiecePtr);
	bool InBorders(Position position);
	bool TryMove(Position startPosition, Position endPoisiton);

private:
	Piece*** chessBoard;
	int size;
	Color turn;
	Position* whiteKingPosition;
	Position* blackKingPosition;

	bool IncludedInVector(Position position, vector<Position> vector);//COPIED METHOD!
	Piece*** CreateChessBoard(int size);
	void FillWithNull(Piece***& chessBoard, int size);
};
