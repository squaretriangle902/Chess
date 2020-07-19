#pragma once
#include "pch.h"
#include "CppUnitTest.h"
#include "ChessBoard.h"
#include "Pieces.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(KingTests)
{
public:

	Piece* PiecePtr(PieceType pieceType, Color pieceColor, ChessBoard* chessBoardPtr)
	{
		switch (pieceType)
		{
		case pawn:
			return new Pawn(pieceColor, chessBoardPtr);
			break;
		case knight:
			return new Knight(pieceColor, chessBoardPtr);
			break;
		case bishop:
			return new Bishop(pieceColor, chessBoardPtr);
			break;
		case rook:
			return new Rook(pieceColor, chessBoardPtr);
			break;
		case queen:
			return new Queen(pieceColor, chessBoardPtr);
			break;
		case king:
			return new King(pieceColor, chessBoardPtr);
			break;
		default:
			return NULL;
			break;
		}
	}

	void IsPawnCheckTest(Position kingPosition, Color kingColor, Position pawnPosition,
		Color pawnColor, bool expected)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Pawn* pawnPtr = new Pawn(pawnColor, chessBoardPtr);
		King* kingPtr = new King(kingColor, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(pawnPosition, pawnPtr);
		chessBoardPtr->SetPiecePtr(kingPosition, kingPtr);
		Assert::AreEqual(expected, kingPtr->IsCheck(kingPosition));
	}

	void LongRangeCheckTest(Position kingPosition, Color kingColor, Position piecePosition, 
		Color pieceColor, PieceType pieceType, bool expected)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		King* kingPtr = new King(kingColor, chessBoardPtr);
		Piece* piecePtr = PiecePtr(pieceType, pieceColor, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(kingPosition, kingPtr);
		chessBoardPtr->SetPiecePtr(piecePosition, piecePtr);
		Assert::AreEqual(expected, kingPtr->IsCheck(kingPosition));
	}

	TEST_METHOD(LongRangeCheckTest_1)
	{
		LongRangeCheckTest(Position(3, 3), white, Position(3, 5), black, queen, true);
	}

	TEST_METHOD(LongRangeCheckTest_2)
	{
		LongRangeCheckTest(Position(3, 3), white, Position(3, 5), white, queen, false);
	}

	TEST_METHOD(LongRangeCheckTest_3)
	{
		LongRangeCheckTest(Position(3, 3), white, Position(3, 5), black, bishop, false);
	}

	TEST_METHOD(LongRangeCheckTest_4)
	{
		LongRangeCheckTest(Position(3, 3), white, Position(5, 3), black, rook, true);
	}

	TEST_METHOD(LongRangeCheckTest2)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Rook* whiteRook = new Rook(white, chessBoardPtr);
		King* blackKing = new King(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(2, 2), blackKing);
		chessBoardPtr->SetPiecePtr(Position(2, 4), whiteRook);
		Assert::IsTrue(blackKing->IsCheck(Position(2, 2)));
	}

	TEST_METHOD(LongRangeCheckTest3)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Bishop* whiteBishop = new Bishop(white, chessBoardPtr);
		King* blackKing = new King(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(2, 2), blackKing);
		chessBoardPtr->SetPiecePtr(Position(2, 4), whiteBishop);
		Assert::IsFalse(blackKing->IsCheck(Position(2, 2)));
	}

	TEST_METHOD(LongRangeCheckTest4)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Queen* whiteQueen = new Queen(white, chessBoardPtr);
		King* blackKing = new King(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(2, 2), blackKing);
		chessBoardPtr->SetPiecePtr(Position(4, 4), whiteQueen);
		Assert::IsTrue(blackKing->IsCheck(Position(2, 2)));
	}

	TEST_METHOD(LongRangeCheckTest5)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Rook* whiteRook = new Rook(white, chessBoardPtr);
		King* blackKing = new King(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(2, 2), blackKing);
		chessBoardPtr->SetPiecePtr(Position(4, 4), whiteRook);
		Assert::IsFalse(blackKing->IsCheck(Position(2, 2)));
	}

	TEST_METHOD(LongRangeCheckTest6)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Bishop* whiteBishop = new Bishop(white, chessBoardPtr);
		King* blackKing = new King(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(2, 2), blackKing);
		chessBoardPtr->SetPiecePtr(Position(4, 4), whiteBishop);
		Assert::IsTrue(blackKing->IsCheck(Position(2, 2)));
	}

	TEST_METHOD(LongRangeCheckTest7)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Queen* whiteQueen = new Queen(white, chessBoardPtr);
		King* blackKing = new King(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(2, 2), blackKing);
		chessBoardPtr->SetPiecePtr(Position(4, 2), whiteQueen);
		Assert::IsTrue(blackKing->IsCheck(Position(2, 2)));
	}

	TEST_METHOD(LongRangeCheckTest8)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Rook* whiteRook = new Rook(white, chessBoardPtr);
		King* blackKing = new King(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(2, 2), blackKing);
		chessBoardPtr->SetPiecePtr(Position(4, 2), whiteRook);
		Assert::IsTrue(blackKing->IsCheck(Position(2, 2)));
	}

	TEST_METHOD(LongRangeCheckTest9)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Bishop* whiteBishop = new Bishop(white, chessBoardPtr);
		King* blackKing = new King(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(2, 2), blackKing);
		chessBoardPtr->SetPiecePtr(Position(4, 2), whiteBishop);
		Assert::IsFalse(blackKing->IsCheck(Position(2, 2)));
	}

	TEST_METHOD(LongRangeCheckTest10)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Queen* whiteQueen = new Queen(white, chessBoardPtr);
		King* blackKing = new King(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(2, 2), blackKing);
		chessBoardPtr->SetPiecePtr(Position(4, 0), whiteQueen);
		Assert::IsTrue(blackKing->IsCheck(Position(2, 2)));
	}

	TEST_METHOD(LongRangeCheckTest11)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Rook* whiteRook = new Rook(white, chessBoardPtr);
		King* blackKing = new King(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(2, 2), blackKing);
		chessBoardPtr->SetPiecePtr(Position(4, 0), whiteRook);
		Assert::IsFalse(blackKing->IsCheck(Position(2, 2)));
	}

	TEST_METHOD(LongRangeCheckTest12)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Bishop* whiteBishop = new Bishop(white, chessBoardPtr);
		King* blackKing = new King(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(2, 2), blackKing);
		chessBoardPtr->SetPiecePtr(Position(4, 0), whiteBishop);
		Assert::IsTrue(blackKing->IsCheck(Position(2, 2)));
	}

	TEST_METHOD(LongRangeCheckTest13)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Queen* whiteQueen = new Queen(white, chessBoardPtr);
		King* blackKing = new King(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(2, 2), blackKing);
		chessBoardPtr->SetPiecePtr(Position(2, 0), whiteQueen);
		Assert::IsTrue(blackKing->IsCheck(Position(2, 2)));
	}

	TEST_METHOD(LongRangeCheckTest14)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Rook* whiteRook = new Rook(white, chessBoardPtr);
		King* blackKing = new King(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(2, 2), blackKing);
		chessBoardPtr->SetPiecePtr(Position(2, 0), whiteRook);
		Assert::IsTrue(blackKing->IsCheck(Position(2, 2)));
	}

	TEST_METHOD(LongRangeCheckTest15)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Bishop* whiteBishop = new Bishop(white, chessBoardPtr);
		King* blackKing = new King(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(2, 2), blackKing);
		chessBoardPtr->SetPiecePtr(Position(2, 0), whiteBishop);
		Assert::IsFalse(blackKing->IsCheck(Position(2, 2)));
	}

	TEST_METHOD(LongRangeCheckTest16)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Queen* whiteQueen = new Queen(white, chessBoardPtr);
		King* blackKing = new King(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(2, 2), blackKing);
		chessBoardPtr->SetPiecePtr(Position(0, 0), whiteQueen);
		Assert::IsTrue(blackKing->IsCheck(Position(2, 2)));
	}

	TEST_METHOD(LongRangeCheckTest17)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Rook* whiteRook = new Rook(white, chessBoardPtr);
		King* blackKing = new King(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(2, 2), blackKing);
		chessBoardPtr->SetPiecePtr(Position(0, 0), whiteRook);
		Assert::IsFalse(blackKing->IsCheck(Position(2, 2)));
	}

	TEST_METHOD(LongRangeCheckTest18)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Bishop* whiteBishop = new Bishop(white, chessBoardPtr);
		King* blackKing = new King(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(2, 2), blackKing);
		chessBoardPtr->SetPiecePtr(Position(0, 0), whiteBishop);
		Assert::IsTrue(blackKing->IsCheck(Position(2, 2)));
	}

	TEST_METHOD(LongRangeCheckTest19)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Queen* whiteQueen = new Queen(white, chessBoardPtr);
		King* blackKing = new King(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(2, 2), blackKing);
		chessBoardPtr->SetPiecePtr(Position(0, 2), whiteQueen);
		Assert::IsTrue(blackKing->IsCheck(Position(2, 2)));
	}

	TEST_METHOD(LongRangeCheckTest20)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Rook* whiteRook = new Rook(white, chessBoardPtr);
		King* blackKing = new King(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(2, 2), blackKing);
		chessBoardPtr->SetPiecePtr(Position(0, 2), whiteRook);
		Assert::IsTrue(blackKing->IsCheck(Position(2, 2)));
	}

	TEST_METHOD(LongRangeCheckTest21)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Bishop* whiteBishop = new Bishop(white, chessBoardPtr);
		King* blackKing = new King(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(2, 2), blackKing);
		chessBoardPtr->SetPiecePtr(Position(0, 2), whiteBishop);
		Assert::IsFalse(blackKing->IsCheck(Position(2, 2)));
	}

	TEST_METHOD(LongRangeCheckTest22)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Queen* whiteQueen = new Queen(white, chessBoardPtr);
		King* blackKing = new King(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(2, 2), blackKing);
		chessBoardPtr->SetPiecePtr(Position(0, 4), whiteQueen);
		Assert::IsTrue(blackKing->IsCheck(Position(2, 2)));
	}

	TEST_METHOD(LongRangeCheckTest23)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Rook* whiteRook = new Rook(white, chessBoardPtr);
		King* blackKing = new King(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(2, 2), blackKing);
		chessBoardPtr->SetPiecePtr(Position(0, 4), whiteRook);
		Assert::IsFalse(blackKing->IsCheck(Position(2, 2)));
	}

	TEST_METHOD(LongRangeCheckTest24)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Bishop* whiteBishop = new Bishop(white, chessBoardPtr);
		King* blackKing = new King(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(2, 2), blackKing);
		chessBoardPtr->SetPiecePtr(Position(0, 4), whiteBishop);
		Assert::IsTrue(blackKing->IsCheck(Position(2, 2)));
	}

	TEST_METHOD(LongRangeCheckTest25)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Queen* whiteQueen = new Queen(white, chessBoardPtr);
		Queen* blackQueen = new Queen(black, chessBoardPtr);
		King* blackKing = new King(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(2, 2), blackKing);
		chessBoardPtr->SetPiecePtr(Position(3, 3), blackQueen);
		chessBoardPtr->SetPiecePtr(Position(4, 4), whiteQueen);
		Assert::IsFalse(blackKing->IsCheck(Position(2, 2)));
	}

	void KnightCheckTest(Position kingPositon, Color kingColor,
		Position knightPositon, Color knightColor, bool expected)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Knight* knight = new Knight(knightColor, chessBoardPtr);
		King* king = new King(kingColor, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(kingPositon, king);
		chessBoardPtr->SetPiecePtr(knightPositon, knight);
		Assert::AreEqual(expected, king->IsCheck(kingPositon));
	}

	TEST_METHOD(KnightCheckTestCase_1)
	{
		KnightCheckTest(Position(3, 3), white, Position(4, 5), black, true);
	}

	TEST_METHOD(KnightCheckTestCase_2)
	{
		KnightCheckTest(Position(3, 3), white, Position(5, 4), black, true);
	}

	TEST_METHOD(KnightCheckTestCase_3)
	{
		KnightCheckTest(Position(3, 3), white, Position(5, 2), black, true);
	}

	TEST_METHOD(KnightCheckTestCase_4)
	{
		KnightCheckTest(Position(3, 3), white, Position(4, 1), black, true);
	}

	TEST_METHOD(KnightCheckTestCase_5)
	{
		KnightCheckTest(Position(3, 3), white, Position(2, 1), black, true);
	}

	TEST_METHOD(KnightCheckTestCase_6)
	{
		KnightCheckTest(Position(3, 3), white, Position(1, 2), black, true);
	}

	TEST_METHOD(KnightCheckTestCase_7)
	{
		KnightCheckTest(Position(3, 3), white, Position(1, 4), black, true);
	}

	TEST_METHOD(KnightCheckTestCase_8)
	{
		KnightCheckTest(Position(3, 3), white, Position(2, 5), black, true);
	}

	TEST_METHOD(KnightCheckTestCase_9)
	{
		KnightCheckTest(Position(3, 3), white, Position(2, 5), white, false);
	}

	TEST_METHOD(KnightCheckTestCase_10)
	{
		KnightCheckTest(Position(3, 3), black, Position(2, 5), black, false);
	}

	TEST_METHOD(KnightCheckTestCase_11)
	{
		KnightCheckTest(Position(3, 3), white, Position(2, 6), black, false);
	}

	TEST_METHOD(KnightCheckTestCase_12)
	{
		KnightCheckTest(Position(3, 3), white, Position(3, 6), black, false);
	}


	TEST_METHOD(IsPawnCheckTestCase_1)
	{
		IsPawnCheckTest(Position(3, 3), white, Position(4, 4), black, true);
	}

	TEST_METHOD(IsPawnCheckTestCase_2)
	{
		IsPawnCheckTest(Position(3, 3), white, Position(2, 4), black, true);
	}

	TEST_METHOD(IsPawnCheckTestCase_3)
	{
		IsPawnCheckTest(Position(3, 3), white, Position(3, 4), black, false);
	}

	TEST_METHOD(IsPawnCheckTestCase_4)
	{
		IsPawnCheckTest(Position(3, 3), white, Position(4, 4), white, false);
	}

};