#pragma once
#include "Pieces.h"

Piece* CreatePiece(PieceType type, Color color, ChessBoard* chessBoardPtr, Game* game)
{
    switch (type)
    {
    case pawn:
        return new Pawn(color, chessBoardPtr, game);
        break;
    case knight:
        return new Knight(color, chessBoardPtr, game);
        break;
    case bishop:
        return new Bishop(color, chessBoardPtr, game);
        break;
    case rook:
        return new Rook(color, chessBoardPtr, game);
        break;
    case queen:
        return new Queen(color, chessBoardPtr, game);
        break;
    case king:
        return new King(color, chessBoardPtr, game);
        break;
    }
}
