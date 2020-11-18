#pragma once
#include <vector>
#include "Piece.h"

class Piece;
class ChessBoard;

enum GameResult
{
	whiteWon = 0,
	blackWon = 1,
    stalemate = 2,
    none = 3,
};

GameResult Checkmate(Color color);

class Game
{
public:
    Game(Color turn = white, int chessBoardSize = 8, ChessBoard* chessBoardPtr = nullptr);
    Color GetTurn();
    GameResult GetGameResult();
    void SetChessBoardPtr(ChessBoard* chessBoardPtr);
    void AddChessPosition(Piece*** chessPosition);

    void SwitchTurn();

private:
	Color turn;
    int chessBoardSize;
    ChessBoard* chessBoardPtr;
    std::vector<Piece***> chessPositions;
    bool IsAnyPossibleMoves(Color color);
    bool CompareChessPositions(Piece*** chessPosition1, Piece*** chessPosition2);
    bool ComparePiecePtrs(Piece* piecePtr1, Piece* piecePtr2);
    int FindDuplicateNumber(Piece*** chessPosition);
};

