#pragma once
#include "ChessBoard.h"
#include "King.h"

ChessBoard::ChessBoard(int size, Game* game)
{
	this->chessBoard = CreateChessBoard(size);
	this->size = size;
    this->blackKingPosition = nullptr;
    this->whiteKingPosition = nullptr;
    this->game = game;
	FillWithNull(this->chessBoard, this->size);/* this method cleans chess board
											   because default constructor must
											   return clean chess board. But I need
											   another same method which is not class
											   member*/
    this->enPassantVulnerablePawnPosition = nullptr;

}

int ChessBoard::GetSize()
{
	return this->size;
}

Piece* ChessBoard::GetPiecePtr(Position position)
{
    if(!this->InBorders(position))
    {
        return NULL;
    }
    return this->chessBoard[position.vertical][position.horizontal];
}

Piece* ChessBoard::GetPiecePtr(int vertical, int horizontal)
{
    if(!this->InBorders(Position(vertical, horizontal)))
    {
        return NULL;
    }
    return this->chessBoard[vertical][horizontal];
}

void ChessBoard::SetPiecePtr(Position position, Piece* newPiecePtr)
{
    this->chessBoard[position.vertical][position.horizontal] = newPiecePtr;
	if (newPiecePtr == NULL || newPiecePtr->GetType() != king)
	{
		return;
	}
    switch (newPiecePtr->GetColor())
	{
	case white:
		whiteKingPosition = new Position(position.vertical, position.horizontal);
		break;
	case black:
		blackKingPosition = new Position(position.vertical, position.horizontal);
		break;
	default:
		break;
	}
}

void ChessBoard::SetPiecePtr(int vertical, int horizontal, Piece* newPiecePtr)
{
    this->chessBoard[vertical][horizontal] = newPiecePtr;
	if (newPiecePtr == NULL || newPiecePtr->GetType() != king)
	{
		return;
	}
    switch (newPiecePtr->GetColor())
	{
	case white:
		whiteKingPosition = new Position(vertical, horizontal);
		break;
	case black:
		blackKingPosition = new Position(vertical, horizontal);
		break;
	default:
		break;
	}
}

bool ChessBoard::InBorders(Position position)
{
	return (position.horizontal < size) && 
		(position.horizontal >= 0) &&
		(position.vertical < size) &&
		(position.vertical >= 0);
}

Position* ChessBoard::GetKingPosition(Color color)
{
	switch (color)
	{
	case black:
		return blackKingPosition;
		break;
	case white:
		return whiteKingPosition;
		break;
	}
	return nullptr;
}

bool ChessBoard::TryMove(Position startPosition, Position endPosition, bool& isTaking, bool& isPromotion,
                         Position& castlingRook, Chess::Direction& castlingDirection,
                         bool& enPassant, Position& enPassantPosition)
{
	Piece* startPiecePtr = this->GetPiecePtr(startPosition);
	Piece* endPiecePtr = this->GetPiecePtr(endPosition);
	vector<Position> possibleMovesVector = 
        startPiecePtr->GetPossibleMoves(startPosition);
	if (IncludedInVector(endPosition, possibleMovesVector))
	{
        MovePiece(startPosition, endPosition);
        isTaking = endPiecePtr != NULL;
        isPromotion = this->IsPromotion(startPiecePtr, endPosition);
        castlingDirection = CastlingDirection(startPiecePtr, startPosition, endPosition);
        castlingRook = TryCastling(endPosition, castlingDirection);
        enPassant = TryEnPassant(startPiecePtr, startPosition, endPosition, enPassantPosition);
        enPassantVulnerablePawnPosition = PawnTwoSquareMove(startPiecePtr, startPosition, endPosition);
        this->game->SwitchTurn();
        startPiecePtr->SetMoved(true);
		return true;
	}
    isTaking = false;
    isPromotion = false;
	return false;
}

Piece*** ChessBoard::GetChessBoard()
{
    return this->chessBoard;
}

Piece*** ChessBoard::CreateChessBoard(int size)
{
    Piece*** chessBoard = new Piece** [size];
	for (int i = 0; i < size; ++i)
	{
		chessBoard[i] = new Piece* [size];
	}
	return chessBoard;
}

void ChessBoard::FillWithNull(Piece***& chessBoard, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			chessBoard[i][j] = NULL;
		}
    }
}

void ChessBoard::MovePiece(Position startPosition, Position endPosition)
{
    Piece* startPiecePtr = GetPiecePtr(startPosition);
    this->SetPiecePtr(endPosition, startPiecePtr);
    this->SetPiecePtr(startPosition, NULL);
}

bool ChessBoard::IsDirectionFromPieceToKingClear(Chess::Direction direction, 
	Position piecePosition, Position kingPosition)
{
	for (Position currentPosition = piecePosition + Position(direction);
		currentPosition != kingPosition;
		currentPosition += Position(direction))
	{
		if (this->GetPiecePtr(currentPosition) != NULL)
		{
			return false;
		}
	}
	return true;
}

bool ChessBoard::IsPinningPiece(Chess::Direction direction, Position piecePosition,
	PieceType pinningPieceType)
{
	for (Position currentPosition = piecePosition - Position(direction);
		this->InBorders(currentPosition);
		currentPosition -= Position(direction))
	{
		Piece* currentPiecePtr = this->GetPiecePtr(currentPosition);
		if (currentPiecePtr == NULL)
		{
			continue;
		}
        if (currentPiecePtr->GetColor() == this->GetPiecePtr(piecePosition)->GetColor())
		{
			return false;
		}
		if (currentPiecePtr->GetType() == queen ||
			currentPiecePtr->GetType() == pinningPieceType)
		{
			return true;
		}
	}
	return false;
}

PieceType ChessBoard::PinningPieceType(Chess::Direction direction)
{
	if (direction == Chess::up ||
		direction == Chess::right ||
		direction == Chess::left ||
		direction == Chess::down)
	{
		return rook;
	}
    return bishop;
}

bool ChessBoard::IsPromotion(Piece *piecePtr, Position position)
{
    return piecePtr->GetType() == pawn &&
            ((piecePtr->GetColor() == white && position.horizontal == (this->GetSize() - 1)) ||
            (piecePtr->GetColor() == black && position.horizontal == 0));

}

Position* ChessBoard::PawnTwoSquareMove(Piece *piecePtr, Position startPosition, Position endPosition)
{
    Position* result = new Position(endPosition.vertical, endPosition.horizontal);
    return piecePtr != nullptr && piecePtr->GetType() == pawn &&
            abs(startPosition.horizontal  - endPosition.horizontal) == 2
            ? result
            : this->enPassantVulnerablePawnPosition;
}

bool ChessBoard::EnPassant(Piece *piecePtr, Position startPosition, Position endPosition)
{
    return piecePtr != nullptr && piecePtr->GetType() == pawn &&
            enPassantVulnerablePawnPosition != nullptr &&
            startPosition.horizontal == enPassantVulnerablePawnPosition->horizontal &&
            endPosition.vertical == enPassantVulnerablePawnPosition->vertical;
}

bool ChessBoard::TryEnPassant(Piece *piecePtr, Position startPosition, Position endPosition,
                              Position& enPassantPosition)
{
    bool result = EnPassant(piecePtr, startPosition, endPosition);
    if (result)
    {
        enPassantPosition = *this->enPassantVulnerablePawnPosition;
        this->SetPiecePtr(enPassantPosition, nullptr);
    }
    this->enPassantVulnerablePawnPosition = nullptr;
    return result;
}

Chess::Direction ChessBoard::CastlingDirection(Piece *piecePtr, Position startPosition, Position endPosition)
{
   return piecePtr != nullptr &&
          piecePtr->GetType() == king &&
          abs(startPosition.vertical - endPosition.vertical) == 2
           ? GetDirection(startPosition, endPosition) : Chess::noDirection;
}

Position ChessBoard::FindRook(Position kingPosition, Chess::Direction castlingDirection)
{
    Position i = kingPosition + castlingDirection;
    while(this->GetPiecePtr(i) == nullptr)
    {
        i += castlingDirection;
    }
    return i;
}

Position ChessBoard::TryCastling(Position kingPosition, Chess::Direction castlingDirection)
{
    if (castlingDirection == Chess::noDirection)
    {
        return Position(0,0);
    }
    Position rookPosition = FindRook(kingPosition, castlingDirection);
    MovePiece(rookPosition, kingPosition - Position(castlingDirection));
    return rookPosition;
}


Chess::Direction ChessBoard::PinDirection(Position piecePosition)
{
	Piece* piecePtr = this->GetPiecePtr(piecePosition);
    Color pieceColor = this->GetPiecePtr(piecePosition)->GetColor();
	Position* kingPositionPtr = 
        this->GetKingPosition(this->GetPiecePtr(piecePosition)->GetColor());
	if (kingPositionPtr == NULL)
	{
		return Chess::noDirection;
	}
	Position kingPosition = *kingPositionPtr;
	Chess::Direction pinDirection = GetDirection(piecePosition, kingPosition);
	if (pinDirection == Chess::noDirection)
	{
		return Chess::noDirection;
	}
	if (IsDirectionFromPieceToKingClear(pinDirection, piecePosition, kingPosition) &&
		IsPinningPiece(pinDirection, piecePosition, PinningPieceType(pinDirection)))
	{
		return pinDirection;
	}
	return Chess::noDirection;
}

vector<Position> ChessBoard::GetCheckingPiecesPosition(Color kingColor)
{
	Position* kingPositionPtr = this->GetKingPosition(kingColor);
	if (kingPositionPtr == nullptr)
	{
		return vector<Position>();
	}
	Position kingPosition = *kingPositionPtr;
	return this->GetCheckingPiecesPosition(kingPosition, kingColor);
}

bool ChessBoard::IsCheck(Color kingColor, vector<Position>& defendingMoves)
{
	Position* kingPositionPtr = this->GetKingPosition(kingColor);
	if (kingPositionPtr == nullptr)
	{
		return false;
	}
	Position kingPosition = *kingPositionPtr;
	vector<Position> checkingPiecesPosition = this->GetCheckingPiecesPosition(kingPosition,
		kingColor);
    if (checkingPiecesPosition.size() == 0)
	{
		return false;
	}
	defendingMoves = this->DefendingMoves(kingColor, kingPosition, 
		checkingPiecesPosition);
    return true;
}

bool ChessBoard::IsPositionUnderAttack(Position position, Color kingColor)
{
    return !this->GetCheckingPiecesPosition(position, kingColor).empty();
}

Position *ChessBoard::GetEnPassantVulnerablePawnPosition()
{
    return this->enPassantVulnerablePawnPosition;
}

void ChessBoard::SetEnPassantVulnerablePawnPosition(Position *positionPtr)
{
    this->enPassantVulnerablePawnPosition = positionPtr;
}

void ChessBoard::IsCheckOnDirection(Position kingPosition, Color kingColor,
	Chess::Direction direction, PieceType expectingType, 
	vector<Position>& checkingPiecesPosition)
{
	for (Position currentPosition = kingPosition + Position(direction);
		this->InBorders(currentPosition);
		currentPosition += Position(direction))
	{
		Piece* piecePtr = this->GetPiecePtr(currentPosition);
		if (piecePtr == NULL || 
            (piecePtr->GetColor() == kingColor && piecePtr->GetType() == king))
		{
			continue;
		}
        if (piecePtr->GetColor() != kingColor &&
			(piecePtr->GetType() == queen || piecePtr->GetType() == expectingType))
		{
			checkingPiecesPosition.push_back(currentPosition);
		}
		return;
	}
	return;
}

vector<Position> ChessBoard::GetCheckingPiecesPosition(Position kingPosition, 
	Color kingColor)
{
	vector<Position> checkingPiecesPosition;
    IsKingCheck(kingPosition, kingColor, checkingPiecesPosition);
	IsPawnCheck(kingPosition, kingColor, checkingPiecesPosition);
	IsKnightCheck(kingPosition, kingColor, checkingPiecesPosition);
	IsLongRangeCheck(kingPosition, kingColor, checkingPiecesPosition);
	return checkingPiecesPosition;
}

vector<Position> ChessBoard::DefendingMoves(Color kingColor, Position kingPosition,
	vector<Position>& checkingPiecesPositions)
{
	vector<Position> defendingMoves;
    if(checkingPiecesPositions.size() > 1)
    {
        return vector<Position>();
    }
	Position checkingPiecePosition = checkingPiecesPositions.at(0);
	Chess::Direction checkDirection = GetDirection(kingPosition, checkingPiecePosition);
	defendingMoves.push_back(checkingPiecePosition);
	if (checkDirection == Chess::noDirection)
	{
		return defendingMoves;
	}
	for (Position currentPosition = kingPosition + Position(checkDirection);
		checkingPiecePosition != currentPosition;
		currentPosition += Position(checkDirection))
	{
		defendingMoves.push_back(currentPosition);
	}
    return defendingMoves;
}

void ChessBoard::IsKingCheck(Position kingPosition, Color kingColor, vector<Position> &checkingPiecesPosition)
{
    for(Chess::Direction i = Chess::up; i != Chess::noDirection; i++)
    {
        IsCheckOnOffset(kingPosition, kingColor, Position(i), king,
            checkingPiecesPosition);
    }
}

void ChessBoard::IsLongRangeCheck(Position kingPosition, Color kingColor,
	vector<Position>& checkingPiecesPosition)
{
	IsCheckOnDirection(kingPosition, kingColor, Chess::up, rook, checkingPiecesPosition);
	IsCheckOnDirection(kingPosition, kingColor, Chess::rightUp, bishop, checkingPiecesPosition);
	IsCheckOnDirection(kingPosition, kingColor, Chess::right, rook, checkingPiecesPosition);
	IsCheckOnDirection(kingPosition, kingColor, Chess::rightDown, bishop, checkingPiecesPosition);
	IsCheckOnDirection(kingPosition, kingColor, Chess::down, rook, checkingPiecesPosition);
	IsCheckOnDirection(kingPosition, kingColor, Chess::leftDown, bishop, checkingPiecesPosition);
	IsCheckOnDirection(kingPosition, kingColor, Chess::left, rook, checkingPiecesPosition);
	IsCheckOnDirection(kingPosition, kingColor, Chess::leftUp, bishop, checkingPiecesPosition);
}


void ChessBoard::IsCheckOnOffset(Position kingPosition, Color kingColor,
	Position positionOffset,
	PieceType pieceType, vector<Position>& checkingPiecesPosition)
{
	Position piecePositon = kingPosition + positionOffset;
	Piece* piecePtr = this->GetPiecePtr(piecePositon);
	if (piecePtr != NULL &&
        piecePtr->GetColor() != kingColor &&
		piecePtr->GetType() == pieceType)
	{
		checkingPiecesPosition.push_back(piecePositon);
	}
}

void ChessBoard::IsKnightCheck(Position kingPosition, Color kingColor,
	vector<Position>& checkingPiecesPosition)
{
	IsCheckOnOffset(kingPosition, kingColor, Position(1, 2), knight, checkingPiecesPosition);
	IsCheckOnOffset(kingPosition, kingColor, Position(2, 1), knight, checkingPiecesPosition);
	IsCheckOnOffset(kingPosition, kingColor, Position(2, -1), knight, checkingPiecesPosition);
	IsCheckOnOffset(kingPosition, kingColor, Position(1, -2), knight, checkingPiecesPosition);
	IsCheckOnOffset(kingPosition, kingColor, Position(-1, -2), knight, checkingPiecesPosition);
	IsCheckOnOffset(kingPosition, kingColor, Position(-2, -1), knight, checkingPiecesPosition);
	IsCheckOnOffset(kingPosition, kingColor, Position(-2, 1), knight, checkingPiecesPosition);
	IsCheckOnOffset(kingPosition, kingColor, Position(-1, 2), knight, checkingPiecesPosition);
}

void ChessBoard::IsPawnCheck(Position kingPosition, Color kingColor,
	vector<Position>& checkingPiecesPosition)
{
	switch (kingColor)
	{
	case white:
		IsPawnCheck(kingPosition, kingColor, Chess::leftUp, Chess::rightUp,
			checkingPiecesPosition);
		break;
	case black:
		IsPawnCheck(kingPosition, kingColor, Chess::leftDown, Chess::rightDown,
			checkingPiecesPosition);
		break;
	}
}

void ChessBoard::IsPawnCheck(Position kingPosition, Color kingColor,
	Chess::Direction firstCheckDirection,
	Chess::Direction secondCheckDirection, vector<Position>& checkingPiecesPosition)
{
	IsCheckOnOffset(kingPosition, kingColor, Position(firstCheckDirection), pawn,
		checkingPiecesPosition);
	IsCheckOnOffset(kingPosition, kingColor, Position(secondCheckDirection), pawn,
		checkingPiecesPosition);
}


