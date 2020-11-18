#pragma once
#include <vector>
#include "Piece.h"
#include "Position.h"
#include "PieceType.h"
#include "Game.h"
#include <string>

using namespace std;

class Piece;
class Game;

class ChessBoard
{
public:
    ChessBoard(int size = 8, Game* game = nullptr);
	int GetSize();
	Piece* GetPiecePtr(Position position);
	Piece* GetPiecePtr(int vertical, int horizontal);
	void SetPiecePtr(Position position, Piece* newPiecePtr);
	void SetPiecePtr(int vertical, int horizontal, Piece* newPiecePtr);
	bool InBorders(Position position);
	Position* GetKingPosition(Color color);
    bool TryMove(Position startPosition, Position endPosition, bool& isTaking, bool& isPromotion,
                 Position& castlingRook, Chess::Direction& castlingDirection,
                 bool& enPassant, Position& enPassantPosition);
	Piece*** GetChessBoard();
	Chess::Direction PinDirection(Position piecePosition);
	bool IsCheck(Color kingColor, vector<Position>& defendingMoves);
	bool IsPositionUnderAttack(Position position, Color kingColor);
    Position* GetEnPassantVulnerablePawnPosition();
    void SetEnPassantVulnerablePawnPosition(Position* positionPtr);
    string GetFenChessBoard();
    string GetFenHorizontal(int horizontal);
    string GetFenPiece(Piece* piecePtr);

private:
	Piece*** chessBoard;
	int size;
	Position* whiteKingPosition;
	Position* blackKingPosition;
    Game* game;

	Piece*** CreateChessBoard(int size);
	void FillWithNull(Piece***& chessBoard, int size);

    void MovePiece(Position startPosition, Position endPosition);

	bool IsDirectionFromPieceToKingClear(Chess::Direction direction,
		Position piecePosition, Position kingPosition);
	bool IsPinningPiece(Chess::Direction direction, Position piecePosition,
		PieceType pinningPieceType);
	PieceType PinningPieceType(Chess::Direction direction);

    bool IsPromotion(Piece* piecePtr, Position position);
    Position* enPassantVulnerablePawnPosition;
    Position* PawnTwoSquareMove(Piece* piecePtr, Position startPosition, Position endPosition);
    bool EnPassant(Piece* piecePtr, Position startPosition, Position endPosition);
    bool TryEnPassant(Piece* piecePtr, Position startPosition, Position endPosition,
                      Position& enPassantPosition);


    Chess::Direction CastlingDirection(Piece* piecePtr, Position startPosition, Position endPosition);
    Position FindRook(Position kingPosition, Chess::Direction castlingDirection);
    Position TryCastling(Position kingPosition, Chess::Direction castlingDirection);

	vector<Position> GetCheckingPiecesPosition(Color kingColor);
	vector<Position> GetCheckingPiecesPosition(Position kingPosition, Color kingColor);
	vector<Position> DefendingMoves(Color kingColor, Position kingPosition, 
		vector<Position>& checkingPiecesPositions);

    void IsKingCheck(Position kingPosition, Color kingColor, vector<Position>& checkingPiecesPosition);
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
