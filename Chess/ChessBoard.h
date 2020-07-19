#pragma once
#include <vector>
#include "Piece.h"
#include "Position.h"
#include "PieceType.h"

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
    bool TryMove(Position startPosition, Position endPosition, bool& isTaking);
	Piece*** GetChessBoard();
	Chess::Direction PinDirection(Position piecePosition);
	vector<Position> GetCheckingPiecesPosition(Color kingColor);
	vector<Position> GetDefendingMoves(Color kingColor,
		vector<Position> checkingPiecesPosition);

private:
	Piece*** chessBoard;
	int size;
	Color turn;
	Position* whiteKingPosition;
	Position* blackKingPosition;

	Piece*** CreateChessBoard(int size);
	void FillWithNull(Piece***& chessBoard, int size);

	bool IsDirectionFromPieceToKingClear(Chess::Direction direction,
		Position piecePosition, Position kingPosition);
	bool IsPinningPiece(Chess::Direction direction, Position piecePosition,
		PieceType pinningPieceType);
	PieceType PinningPieceType(Chess::Direction direction);

	vector<Position> GetCheckingPiecesPosition(Position kingPosition, Color kingColor);
	void IsPawnCheck(Position kingPosition, Color kingColor,
		Chess::Direction firstCheckDirection, Chess::Direction secondCheckDirection, 
		vector<Position>& checkingPiecesPosition);
	void IsLongRangeCheck(Position kingPosition, Color kingColor,
		vector<Position>& checkingPiecesPosition);
	void IsCheckOnOffset(Position kingPosition, Color kingColor, Position positionOffset,
		PieceType pieceType, vector<Position>& checkingPiecesPosition);
	void IsKnightCheck(Position kingPosition, Color kingColor,
		vector<Position>& checkingPiecesPosition);
	void IsPawnCheck(Position kingPosition, Color kingColor,
		vector<Position>& checkingPiecesPosition);
	void IsCheckOnDirection(Position kingPosition, Color kingColor,
		Chess::Direction direction, PieceType expectingType, 
		vector<Position>& checkingPiecesPosition);
};
