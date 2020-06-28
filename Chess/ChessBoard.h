#pragma once
#include <vector>
#include "Piece.h"
#include "Position.h"

using namespace std;

class Piece;

class ChessBoard
{
public:
	ChessBoard(int size = 8, Color color = white);
	int GetSize();
	Piece* GetPiecePtr(Position position);
	Piece* GetPiecePtr(int vertical, int horizontal);
	void SetPiecePtr(Position position, Piece* newPiecePtr);
	void SetPiecePtr(int vertical, int horizontal, Piece* newPiecePtr);
	bool InBorders(Position position);
	Position* GetKingPosition(Color color);
	bool TryMove(Position startPosition, Position endPosition);
	Piece*** GetChessBoard();

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
