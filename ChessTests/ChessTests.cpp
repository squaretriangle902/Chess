#pragma once
#include "pch.h"
#include "CppUnitTest.h"
#include "Bishop.cpp"
#include "ChessBoard.cpp"
#include "Piece.cpp"
#include "Knight.cpp"
#include "Pawn.cpp"
//#include "Position.cpp"
//#include "Chess.cpp"
#include "Rook.cpp"
//#include "Bishop.h"
//#include "ChessBoard.h"
#include "Color.h"
#include "Direction.h"
//#include "Piece.h"
//#include "Knight.h"
//#include "Pawn.h"
//#include "Pieces.h"
//#include "Position.h"
//#include "Rook.h"
#include "Common.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(GetColorTests)
{
public:
	TEST_METHOD(WhitePawnGetColorTest)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Pawn* pawn = new Pawn(white, chessBoardPtr);
		Assert::IsTrue(pawn->GetColor() == white);
	}

	TEST_METHOD(BlackPawnGetColorTest)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Pawn* pawn = new Pawn(black, chessBoardPtr);
		Assert::IsTrue(pawn->GetColor() == black);
	}
};

TEST_CLASS(IsMoveValidTests)
{
public:

	TEST_METHOD(IsMoveInBordersTest1)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Pawn* pawn = new Pawn(white, chessBoardPtr);
		Assert::IsTrue(pawn->IsMoveValid(Position(1, 2)));
	}

	TEST_METHOD(IsMoveInBordersTest2)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Pawn* pawn = new Pawn(white, chessBoardPtr);
		Assert::IsTrue(pawn->IsMoveValid(Position(7, 7)));
	}

	TEST_METHOD(IsMoveInBordersTest3)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Pawn* pawn = new Pawn(white, chessBoardPtr);
		Assert::IsTrue(pawn->IsMoveValid(Position(0, 0)));
	}

	TEST_METHOD(IsMoveInBordersTest9)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(9);
		Pawn* pawn = new Pawn(white, chessBoardPtr);
		Assert::IsTrue(pawn->IsMoveValid(Position(8, 0)));
	}


	TEST_METHOD(IsMoveInBordersTest4)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Pawn* pawn = new Pawn(white, chessBoardPtr);
		Assert::IsFalse(pawn->IsMoveValid(Position(-1, 0)));
	}

	TEST_METHOD(IsMoveInBordersTest5)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Pawn* pawn = new Pawn(white, chessBoardPtr);
		Assert::IsFalse(pawn->IsMoveValid(Position(0, -2)));
	}

	TEST_METHOD(IsMoveInBordersTest6)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Pawn* pawn = new Pawn(white, chessBoardPtr);
		Assert::IsFalse(pawn->IsMoveValid(Position(8, 8)));
	}

	TEST_METHOD(IsMoveInBordersTest7)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Pawn* pawn = new Pawn(white, chessBoardPtr);
		Assert::IsFalse(pawn->IsMoveValid(Position(0, 8)));
	}

	TEST_METHOD(IsMoveInBordersTest8)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Pawn* pawn = new Pawn(white, chessBoardPtr);
		Assert::IsFalse(pawn->IsMoveValid(Position(8, 0)));
	}

	TEST_METHOD(IsFriendlyPieceTest1)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Pawn* whitePawn = new Pawn(white, chessBoardPtr);
		Pawn* blackPawn = new Pawn(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(4, 2, blackPawn);
		Assert::IsTrue(whitePawn->IsMoveValid(Position(4, 2)));
	}

	TEST_METHOD(IsFriendlyPieceTest2)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Pawn* whitePawn = new Pawn(white, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(4, 2, whitePawn);
		Assert::IsFalse(whitePawn->IsMoveValid(Position(4, 2)));
	}

};

TEST_CLASS(VectorComparsionTests)
{
public:
	TEST_METHOD(IncludedInVectorTest1)
	{
		vector<Position> vector;
		for (int i = 0; i < 5; i++)
		{
			vector.push_back(Position(i, i));
		}
		Assert::IsTrue(IncludedInVector(Position(2, 2), vector));
	}

	TEST_METHOD(IncludedInVectorTest2)
	{
		vector<Position> vector;
		for (int i = 0; i < 5; i++)
		{
			vector.push_back(Position(i, i));
		}
		Assert::IsFalse(IncludedInVector(Position(6, 6), vector));
	}

	TEST_METHOD(AreEqualTest2)
	{
		vector<Position> vector1;
		vector<Position> vector2;
		for (int i = 0; i < 5; i++)
		{
			vector1.push_back(Position(i, i));
			vector2.push_back(Position(4 - i, 4 - i));
		}
		Assert::IsTrue(AreEqual(vector1, vector2));
	}

	TEST_METHOD(AreEqualTest3)
	{
		vector<Position> vector1;
		vector<Position> vector2;
		for (int i = 0; i < 5; i++)
		{
			vector1.push_back(Position(i, i));
			vector2.push_back(Position(5 - i, 5 - i));
		}
		Assert::IsFalse(AreEqual(vector1, vector2));
	}

};

TEST_CLASS(ChessBoardTests)
{
public:

	TEST_METHOD(ChessBoardGetSizeTest1)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Assert::IsTrue(chessBoardPtr->GetSize() == 8);
	}

	TEST_METHOD(ChessBoardGetSizeTest2)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(12);
		Assert::IsTrue(chessBoardPtr->GetSize() != 7);
	}

	TEST_METHOD(ChessBoardGetPiecePtrTest1)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Pawn* pawn = new Pawn(white, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(1, 2), pawn);
		Assert::IsTrue(chessBoardPtr->GetPiecePtr(1,2) != NULL);
	}

	TEST_METHOD(ChessBoardGetPiecePtrTest2)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Pawn* pawn = new Pawn(white, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(2, 1), pawn);
		Assert::IsTrue(chessBoardPtr->GetPiecePtr(1, 2) == NULL);
	}

};