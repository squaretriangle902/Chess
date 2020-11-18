#pragma once
#include "Piece.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"

Piece* CreatePiece(PieceType type, Color color, ChessBoard* chessBoardPtr, Game* game);
