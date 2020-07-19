#pragma once
#include "pch.h"
#include "CppUnitTest.h"
#include "ChessBoard.h"
#include "Pieces.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(ChessBoardTests)
{
public:

	void GetSizeTest(int chessBoardSize)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(chessBoardSize);
		Assert::AreEqual(chessBoardSize, chessBoardPtr->GetSize());
	}

	TEST_METHOD(GetSizeTestCase_1)
	{
		GetSizeTest(4);
	}

	TEST_METHOD(GetSizeTestCase_2)
	{
		GetSizeTest(8);
	}

	TEST_METHOD(GetSizeTestCase_3)
	{
		GetSizeTest(16);
	}

	void InBorderTest(Position position, int chessBoardSize, bool isCorrect)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(chessBoardSize);
		Assert::AreEqual(isCorrect, chessBoardPtr->InBorders(position));
	}

	TEST_METHOD(InBorderTestCase_1)
	{
		InBorderTest(Position(3, 3), 8, true);
	}

	TEST_METHOD(InBorderTestCase_2)
	{
		InBorderTest(Position(0, 0), 8, true);
	}

	TEST_METHOD(InBorderTestCase_3)
	{
		InBorderTest(Position(0, 7), 8, true);
	}

	TEST_METHOD(InBorderTestCase_4)
	{
		InBorderTest(Position(7, 7), 8, true);
	}

	TEST_METHOD(InBorderTestCase_5)
	{
		InBorderTest(Position(7, 0), 8, true);
	}

	TEST_METHOD(InBorderTestCase_6)
	{
		InBorderTest(Position(0, 3), 8, true);
	}

	TEST_METHOD(InBorderTestCase_7)
	{
		InBorderTest(Position(3, 7), 8, true);
	}

	TEST_METHOD(InBorderTestCase_8)
	{
		InBorderTest(Position(7, 3), 8, true);
	}

	TEST_METHOD(InBorderTestCase_9)
	{
		InBorderTest(Position(3, 0), 8, true);
	}

	TEST_METHOD(InBorderTestCase_10)
	{
		InBorderTest(Position(-1, -1), 8, false);
	}

	TEST_METHOD(InBorderTestCase_11)
	{
		InBorderTest(Position(-1, 8), 8, false);
	}

	TEST_METHOD(InBorderTestCase_12)
	{
		InBorderTest(Position(8, 8), 8, false);
	}

	TEST_METHOD(InBorderTestCase_13)
	{
		InBorderTest(Position(8, -1), 8, false);
	}

	TEST_METHOD(GetPiecePtrTestCase_1)
	{
		ChessBoard* chessBoardPtr = new ChessBoard();
		Bishop* whiteBishop = new Bishop(white, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(4, 4), whiteBishop);
		Assert::IsNull(chessBoardPtr->GetKingPosition(white));
	}

	TEST_METHOD(GetPiecePtrTestCase_2)
	{
		ChessBoard* chessBoardPtr = new ChessBoard();
		Bishop* blackBishop = new Bishop(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(4, 4), blackBishop);
		Assert::IsNull(chessBoardPtr->GetKingPosition(black));
	}

	TEST_METHOD(GetPiecePtrTestCase_3)
	{
		ChessBoard* chessBoardPtr = new ChessBoard();
		King* blackKing = new King(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(4, 4), blackKing);
		Assert::IsNull(chessBoardPtr->GetKingPosition(white));
	}

	TEST_METHOD(GetPiecePtrTestCase_4)
	{
		ChessBoard* chessBoardPtr = new ChessBoard();
		King* blackKing = new King(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(4, 4), blackKing);
		Assert::IsNotNull(chessBoardPtr->GetKingPosition(black));
	}

	TEST_METHOD(GetPiecePtrTestCase_5)
	{
		ChessBoard* chessBoardPtr = new ChessBoard();
		King* whiteKing = new King(white, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(4, 4), whiteKing);
		Assert::IsNull(chessBoardPtr->GetKingPosition(black));
	}

	TEST_METHOD(GetPiecePtrTestCase_6)
	{
		ChessBoard* chessBoardPtr = new ChessBoard();
		King* whiteKing = new King(white, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(4, 4), whiteKing);
		Assert::IsNotNull(chessBoardPtr->GetKingPosition(white));
	}

	TEST_METHOD(DefendingMovesTestCase_1)
	{
		ChessBoard* chessBoardPtr = new ChessBoard();
		Piece* whiteKing = new King(white, chessBoardPtr);
		Piece* blackQueen = new Queen(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(1, 1), whiteKing);
		chessBoardPtr->SetPiecePtr(Position(5, 5), blackQueen);
		std::vector<Position> actualDefendingMoves;
		bool isCheck = chessBoardPtr->IsCheck(white, actualDefendingMoves);
		std::vector<Position> expectedDefendingMoves{ Position(2, 2), Position(3, 3),
		Position(4, 4) , Position(5, 5) };
		Assert::IsTrue(CompareVector(expectedDefendingMoves, actualDefendingMoves));
	}

};