#include "Game.h"

Game::Game(Color turn, int chessBoardSize, ChessBoard* chessBoardPtr)
{
    this->turn = turn;
    this->chessBoardSize = chessBoardSize;
    this->chessBoardPtr = chessBoardPtr;
    this->chessPositions = std::vector<Piece***>();
}

bool Game::IsAnyPossibleMoves(Color color)
{
    for (int i = 0; i < this->chessBoardSize; i++)
    {
        for (int j = 0; j < this->chessBoardSize; j++)
        {
            Position position = Position(i,j);
            Piece* piecePtr = this->chessBoardPtr->GetPiecePtr(position);
            if(piecePtr != nullptr &&
               piecePtr->GetColor() == color &&
               !piecePtr->GetPossibleMoves(position).empty())
            {
                return true;
            }
        }
    }
    return false;
}

Color Game::GetTurn()
{
    return this->turn;
}

GameResult Checkmate(Color color)
{
    switch (color)
    {
    case white:
        return blackWon;
        break;
    case black:
        return whiteWon;
        break;
    }
}

GameResult Game::GetGameResult()
{
    Position* kingPositionPtr = this->chessBoardPtr->GetKingPosition(turn);
    if(!IsAnyPossibleMoves(turn))
    {
        return kingPositionPtr != nullptr &&
               this->chessBoardPtr->IsPositionUnderAttack(*kingPositionPtr, turn) ?
               Checkmate(turn) :
               stalemate;
    }
    else
    {
        return none;
    }
}

void Game::SetChessBoardPtr(ChessBoard *chessBoardPtr)
{
    this->chessBoardPtr = chessBoardPtr;
    this->AddChessPosition(chessBoardPtr->GetChessBoard());
}

void Game::AddChessPosition(Piece*** chessPosition)
{
    this->chessPositions.push_back(chessPosition);
}


void Game::SwitchTurn()
{
    switch (this->turn)
    {
    case black:
        this->turn = white;
        break;
    case white:
        this->turn = black;
        break;
    }
}
