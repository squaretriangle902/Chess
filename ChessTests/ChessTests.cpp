#pragma once
#include "pch.h"
#include "CppUnitTest.h"

#include "ChessBoard.h"
#include "Pieces.h"
#include "Common.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(GetColorTests)
{
public:
	TEST_METHOD(WhitePawnGetColorTest)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Pawn* whiteBishop = new Pawn(white, chessBoardPtr);
		Assert::IsTrue(whiteBishop->GetColor() == white);
	}

	TEST_METHOD(BlackPawnGetColorTest)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Pawn* whiteBishop = new Pawn(black, chessBoardPtr);
		Assert::IsTrue(whiteBishop->GetColor() == black);
	}
};

TEST_CLASS(IsMoveValidTests)
{
public:

	TEST_METHOD(IsMoveInBordersTest1)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Pawn* whiteBishop = new Pawn(white, chessBoardPtr);
		Assert::IsTrue(whiteBishop->IsMoveValid(Position(1, 2)));
	}

	TEST_METHOD(IsMoveInBordersTest2)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Pawn* whiteBishop = new Pawn(white, chessBoardPtr);
		Assert::IsTrue(whiteBishop->IsMoveValid(Position(7, 7)));
	}

	TEST_METHOD(IsMoveInBordersTest3)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Pawn* whiteBishop = new Pawn(white, chessBoardPtr);
		Assert::IsTrue(whiteBishop->IsMoveValid(Position(0, 0)));
	}

	TEST_METHOD(IsMoveInBordersTest9)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(9);
		Pawn* whiteBishop = new Pawn(white, chessBoardPtr);
		Assert::IsTrue(whiteBishop->IsMoveValid(Position(8, 0)));
	}


	TEST_METHOD(IsMoveInBordersTest4)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Pawn* whiteBishop = new Pawn(white, chessBoardPtr);
		Assert::IsFalse(whiteBishop->IsMoveValid(Position(-1, 0)));
	}

	TEST_METHOD(IsMoveInBordersTest5)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Pawn* whiteBishop = new Pawn(white, chessBoardPtr);
		Assert::IsFalse(whiteBishop->IsMoveValid(Position(0, -2)));
	}

	TEST_METHOD(IsMoveInBordersTest6)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Pawn* whiteBishop = new Pawn(white, chessBoardPtr);
		Assert::IsFalse(whiteBishop->IsMoveValid(Position(8, 8)));
	}

	TEST_METHOD(IsMoveInBordersTest7)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Pawn* whiteBishop = new Pawn(white, chessBoardPtr);
		Assert::IsFalse(whiteBishop->IsMoveValid(Position(0, 8)));
	}

	TEST_METHOD(IsMoveInBordersTest8)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Pawn* whiteBishop = new Pawn(white, chessBoardPtr);
		Assert::IsFalse(whiteBishop->IsMoveValid(Position(8, 0)));
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
		std::vector<Position> vector;
		for (int i = 0; i < 5; i++)
		{
			vector.push_back(Position(i, i));
		}
		Assert::IsTrue(IncludedInVector(Position(2, 2), vector));
	}

	TEST_METHOD(IncludedInVectorTest2)
	{
		std::vector<Position> vector;
		for (int i = 0; i < 5; i++)
		{
			vector.push_back(Position(i, i));
		}
		Assert::IsFalse(IncludedInVector(Position(6, 6), vector));
	}

	TEST_METHOD(AreEqualTest2)
	{
		std::vector<Position> vector1;
		std::vector<Position> vector2;
		for (int i = 0; i < 5; i++)
		{
			vector1.push_back(Position(i, i));
			vector2.push_back(Position(4 - i, 4 - i));
		}
		Assert::IsTrue(AreEqual(vector1, vector2));
	}

	TEST_METHOD(AreEqualTest3)
	{
		std::vector<Position> vector1;
		std::vector<Position> vector2;
		for (int i = 0; i < 5; i++)
		{
			vector1.push_back(Position(i, i));
			vector2.push_back(Position(5 - i, 5 - i));
		}
		Assert::IsFalse(AreEqual(vector1, vector2));
	}

	TEST_METHOD(AreEqualTest4)
	{
		std::vector<Position> vector1;
		std::vector<Position> vector2;
		vector1.push_back(Position(3,3));
		vector2.push_back(Position(3, 3));
		Assert::IsTrue(AreEqual(vector1, vector2));
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
		Pawn* whiteBishop = new Pawn(white, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(1, 2), whiteBishop);
		Assert::IsTrue(chessBoardPtr->GetPiecePtr(1,2) != NULL);
	}

	TEST_METHOD(ChessBoardGetPiecePtrTest2)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Pawn* whiteBishop = new Pawn(white, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(2, 1), whiteBishop);
		Assert::IsTrue(chessBoardPtr->GetPiecePtr(1, 2) == NULL);
	}

};

TEST_CLASS(BishopTests)
{
public:

	TEST_METHOD(BishopGetPossibleMovesTest1)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Bishop* whiteBishop = new Bishop(white, chessBoardPtr);
		Bishop* blackBishop = new Bishop(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(4, 4), whiteBishop);
		chessBoardPtr->SetPiecePtr(Position(7, 7), whiteBishop);
		chessBoardPtr->SetPiecePtr(Position(1, 1), whiteBishop);
		chessBoardPtr->SetPiecePtr(Position(6, 2), blackBishop);
		std::vector<Position> possibleMovesVector;
		//(5, 5) (5, 3) (3, 3) (3, 5) (6, 6) (6, 2) (2, 2) (2, 6) (1, 7)
		possibleMovesVector.push_back(Position(5, 5));
		possibleMovesVector.push_back(Position(5, 3));
		possibleMovesVector.push_back(Position(3, 3));
		possibleMovesVector.push_back(Position(3, 5));
		possibleMovesVector.push_back(Position(6, 6));
		possibleMovesVector.push_back(Position(6, 2));
		possibleMovesVector.push_back(Position(2, 2));
		possibleMovesVector.push_back(Position(2, 6));
		possibleMovesVector.push_back(Position(1, 7));
		Assert::IsTrue(AreEqual(possibleMovesVector, whiteBishop->GetPossibleMoves(Position(4, 4))));
	}
	TEST_METHOD(BishopGetPossibleMovesTest2)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Bishop* whiteBishop = new Bishop(white, chessBoardPtr);
		Bishop* blackBishop = new Bishop(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(4, 4), whiteBishop);
		chessBoardPtr->SetPiecePtr(Position(7, 7), whiteBishop);
		chessBoardPtr->SetPiecePtr(Position(1, 1), whiteBishop);
		chessBoardPtr->SetPiecePtr(Position(6, 2), blackBishop);
		std::vector<Position> possibleMovesVector;
		//(2,2) (2,0) (0,0) (0,2) (3,3)
		possibleMovesVector.push_back(Position(2, 2));
		possibleMovesVector.push_back(Position(2, 0));
		possibleMovesVector.push_back(Position(0, 0));
		possibleMovesVector.push_back(Position(0, 2));
		possibleMovesVector.push_back(Position(3, 3));
		Assert::IsTrue(AreEqual(possibleMovesVector, whiteBishop->GetPossibleMoves(Position(1, 1))));
	}

	TEST_METHOD(BishopGetPossibleMovesTest3)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Bishop* whiteBishop = new Bishop(white, chessBoardPtr);
		Bishop* blackBishop = new Bishop(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(4, 4), whiteBishop);
		chessBoardPtr->SetPiecePtr(Position(7, 7), whiteBishop);
		chessBoardPtr->SetPiecePtr(Position(1, 1), whiteBishop);
		chessBoardPtr->SetPiecePtr(Position(6, 2), blackBishop);
		std::vector<Position> possibleMovesVector;
		//(7,3) (7,1) (5,1) (5,3) (4,0) (4,4)
		possibleMovesVector.push_back(Position(7, 3));
		possibleMovesVector.push_back(Position(7, 1));
		possibleMovesVector.push_back(Position(5, 1));
		possibleMovesVector.push_back(Position(5, 3));
		possibleMovesVector.push_back(Position(4, 0));
		possibleMovesVector.push_back(Position(4, 4));
		Assert::IsTrue(AreEqual(possibleMovesVector, blackBishop->GetPossibleMoves(Position(6, 2))));
	}

	TEST_METHOD(BishopGetPossibleMovesTest4)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Bishop* whiteBishop = new Bishop(white, chessBoardPtr);
		Bishop* blackBishop = new Bishop(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(4, 4), whiteBishop);
		chessBoardPtr->SetPiecePtr(Position(7, 7), whiteBishop);
		chessBoardPtr->SetPiecePtr(Position(1, 1), whiteBishop);
		chessBoardPtr->SetPiecePtr(Position(6, 2), blackBishop);
		chessBoardPtr->SetPiecePtr(Position(2, 6), blackBishop);
		std::vector<Position> possibleMovesVector;
		//(1, 7) (3, 7) (3, 5) (1, 5) (0, 4) (4, 4)
		possibleMovesVector.push_back(Position(1, 7));
		possibleMovesVector.push_back(Position(3, 7));
		possibleMovesVector.push_back(Position(3, 5));
		possibleMovesVector.push_back(Position(1, 5));
		possibleMovesVector.push_back(Position(0, 4));
		possibleMovesVector.push_back(Position(4, 4));
		Assert::IsTrue(AreEqual(possibleMovesVector, blackBishop->GetPossibleMoves(Position(2, 6))));
	}
};


TEST_CLASS(PawnTests)
{
public:

	TEST_METHOD(PawnGetPossibleMovesTest1)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Pawn* whitePawn = new Pawn(white, chessBoardPtr);
		Pawn* blackPawn = new Pawn(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(0, 1), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(3, 2), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(5, 1), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(5, 3), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(1, 2), blackPawn);
		chessBoardPtr->SetPiecePtr(Position(4, 4), blackPawn);
		chessBoardPtr->SetPiecePtr(Position(6, 4), blackPawn);
		std::vector<Position> possibleMovesVector;
		possibleMovesVector.push_back(Position(0, 2));
		possibleMovesVector.push_back(Position(0, 3));
		possibleMovesVector.push_back(Position(1, 2));
		Assert::IsTrue(AreEqual(possibleMovesVector, whitePawn->GetPossibleMoves(Position(0, 1))));
	}

	TEST_METHOD(PawnGetPossibleMovesTest2)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Pawn* whitePawn = new Pawn(white, chessBoardPtr);
		Pawn* blackPawn = new Pawn(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(0, 1), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(3, 2), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(5, 1), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(5, 3), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(1, 2), blackPawn);
		chessBoardPtr->SetPiecePtr(Position(4, 4), blackPawn);
		chessBoardPtr->SetPiecePtr(Position(6, 4), blackPawn);
		std::vector<Position> possibleMovesVector;
		possibleMovesVector.push_back(Position(3, 3));
		Assert::IsTrue(AreEqual(possibleMovesVector, whitePawn->GetPossibleMoves(Position(3, 2))));
	}

	TEST_METHOD(PawnGetPossibleMovesTest3)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Pawn* whitePawn = new Pawn(white, chessBoardPtr);
		Pawn* blackPawn = new Pawn(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(0, 1), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(3, 2), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(5, 1), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(5, 3), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(1, 2), blackPawn);
		chessBoardPtr->SetPiecePtr(Position(4, 4), blackPawn);
		chessBoardPtr->SetPiecePtr(Position(6, 4), blackPawn);
		std::vector<Position> possibleMovesVector;
		possibleMovesVector.push_back(Position(5, 2));
		Assert::IsTrue(AreEqual(possibleMovesVector, whitePawn->GetPossibleMoves(Position(5, 1))));
	}

	TEST_METHOD(PawnGetPossibleMovesTest4)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Pawn* whitePawn = new Pawn(white, chessBoardPtr);
		Pawn* blackPawn = new Pawn(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(0, 1), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(3, 2), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(5, 1), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(5, 3), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(1, 2), blackPawn);
		chessBoardPtr->SetPiecePtr(Position(4, 4), blackPawn);
		chessBoardPtr->SetPiecePtr(Position(6, 4), blackPawn);
		std::vector<Position> possibleMovesVector;
		possibleMovesVector.push_back(Position(4, 4));
		possibleMovesVector.push_back(Position(5, 4));
		possibleMovesVector.push_back(Position(6, 4));
		Assert::IsTrue(AreEqual(possibleMovesVector, whitePawn->GetPossibleMoves(Position(5, 3))));
	}

	TEST_METHOD(PawnGetPossibleMovesTest5)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Pawn* whitePawn = new Pawn(white, chessBoardPtr);
		Pawn* blackPawn = new Pawn(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(2, 1), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(2, 7), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(2, 2), blackPawn);
		std::vector<Position> possibleMovesVector;
		Assert::IsTrue(AreEqual(possibleMovesVector, whitePawn->GetPossibleMoves(Position(2, 1))));
	}

	TEST_METHOD(PawnGetPossibleMovesTest6)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Pawn* whitePawn = new Pawn(white, chessBoardPtr);
		Pawn* blackPawn = new Pawn(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(2, 1), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(2, 7), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(2, 2), blackPawn);
		std::vector<Position> possibleMovesVector;
		Assert::IsTrue(AreEqual(possibleMovesVector, whitePawn->GetPossibleMoves(Position(2, 7))));
	}

	TEST_METHOD(PawnGetPossibleMovesTest7)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Pawn* whitePawn = new Pawn(white, chessBoardPtr);
		Pawn* blackPawn = new Pawn(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(1, 3), blackPawn);
		chessBoardPtr->SetPiecePtr(Position(2, 6), blackPawn);
		chessBoardPtr->SetPiecePtr(Position(4, 6), blackPawn);
		chessBoardPtr->SetPiecePtr(Position(5, 6), blackPawn);
		chessBoardPtr->SetPiecePtr(Position(6, 6), blackPawn);
		chessBoardPtr->SetPiecePtr(Position(0, 2), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(1, 5), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(2, 2), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(3, 5), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(4, 3), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(5, 4), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(6, 5), whitePawn);
		std::vector<Position> possibleMovesVector;
		possibleMovesVector.push_back(Position(0, 2));
		possibleMovesVector.push_back(Position(1, 2));
		possibleMovesVector.push_back(Position(2, 2));
		Assert::IsTrue(AreEqual(possibleMovesVector, blackPawn->GetPossibleMoves(Position(1, 3))));
	}

	TEST_METHOD(PawnGetPossibleMovesTest8)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Pawn* whitePawn = new Pawn(white, chessBoardPtr);
		Pawn* blackPawn = new Pawn(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(1, 3), blackPawn);
		chessBoardPtr->SetPiecePtr(Position(2, 6), blackPawn);
		chessBoardPtr->SetPiecePtr(Position(4, 6), blackPawn);
		chessBoardPtr->SetPiecePtr(Position(5, 6), blackPawn);
		chessBoardPtr->SetPiecePtr(Position(6, 6), blackPawn);
		chessBoardPtr->SetPiecePtr(Position(0, 2), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(1, 5), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(2, 2), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(3, 5), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(4, 3), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(5, 4), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(6, 5), whitePawn);
		std::vector<Position> possibleMovesVector;
		possibleMovesVector.push_back(Position(1, 5));
		possibleMovesVector.push_back(Position(2, 5));
		possibleMovesVector.push_back(Position(2, 4));
		possibleMovesVector.push_back(Position(3, 5));
		Assert::IsTrue(AreEqual(possibleMovesVector, blackPawn->GetPossibleMoves(Position(2, 6))));
	}

	TEST_METHOD(PawnGetPossibleMovesTest9)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Pawn* whitePawn = new Pawn(white, chessBoardPtr);
		Pawn* blackPawn = new Pawn(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(1, 3), blackPawn);
		chessBoardPtr->SetPiecePtr(Position(2, 6), blackPawn);
		chessBoardPtr->SetPiecePtr(Position(4, 6), blackPawn);
		chessBoardPtr->SetPiecePtr(Position(5, 6), blackPawn);
		chessBoardPtr->SetPiecePtr(Position(6, 6), blackPawn);
		chessBoardPtr->SetPiecePtr(Position(0, 2), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(1, 5), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(2, 2), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(3, 5), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(4, 3), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(5, 4), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(6, 5), whitePawn);
		std::vector<Position> possibleMovesVector;
		possibleMovesVector.push_back(Position(3, 5));
		possibleMovesVector.push_back(Position(4, 4));
		possibleMovesVector.push_back(Position(4, 5));
		Assert::IsTrue(AreEqual(possibleMovesVector, blackPawn->GetPossibleMoves(Position(4, 6))));
	}

	TEST_METHOD(PawnGetPossibleMovesTest10)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Pawn* blackPawn = new Pawn(black, chessBoardPtr);
		Pawn* whitePawn = new Pawn(white, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(1, 3), blackPawn);
		chessBoardPtr->SetPiecePtr(Position(2, 6), blackPawn);
		chessBoardPtr->SetPiecePtr(Position(4, 6), blackPawn);
		chessBoardPtr->SetPiecePtr(Position(5, 6), blackPawn);
		chessBoardPtr->SetPiecePtr(Position(6, 6), blackPawn);
		chessBoardPtr->SetPiecePtr(Position(0, 2), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(1, 5), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(2, 2), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(3, 5), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(4, 3), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(5, 4), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(6, 5), whitePawn);
		std::vector<Position> possibleMovesVector;
		possibleMovesVector.push_back(Position(5, 5));
		possibleMovesVector.push_back(Position(6, 5));
		Assert::IsTrue(AreEqual(possibleMovesVector, blackPawn->GetPossibleMoves(Position(5, 6))));
	}

	TEST_METHOD(PawnGetPossibleMovesTest11)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Pawn* whitePawn = new Pawn(white, chessBoardPtr);
		Pawn* blackPawn = new Pawn(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(1, 3), blackPawn);
		chessBoardPtr->SetPiecePtr(Position(2, 6), blackPawn);
		chessBoardPtr->SetPiecePtr(Position(4, 6), blackPawn);
		chessBoardPtr->SetPiecePtr(Position(5, 6), blackPawn);
		chessBoardPtr->SetPiecePtr(Position(6, 6), blackPawn);
		chessBoardPtr->SetPiecePtr(Position(0, 2), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(1, 5), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(2, 2), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(3, 5), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(4, 3), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(5, 4), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(6, 5), whitePawn);
		std::vector<Position> possibleMovesVector;
		Assert::IsTrue(AreEqual(possibleMovesVector, blackPawn->GetPossibleMoves(Position(6, 6))));
	}

};

TEST_CLASS(QueenTests)
{
public:

	TEST_METHOD(QueenGetPossibleMovesTest1)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Queen* whiteQueen = new Queen(white, chessBoardPtr);
		Queen* blackQueen = new Queen(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(1, 5), whiteQueen);
		chessBoardPtr->SetPiecePtr(Position(3, 7), whiteQueen);
		chessBoardPtr->SetPiecePtr(Position(5, 7), whiteQueen);
		chessBoardPtr->SetPiecePtr(Position(5, 5), whiteQueen);
		chessBoardPtr->SetPiecePtr(Position(1, 1), blackQueen);
		std::vector<Position> expectedMovesVector{Position(1, 6), 
			Position(2, 6),
			Position(2, 5),
			Position(2, 4),
			Position(1, 4),
			Position(0, 4),
			Position(0, 5),
			Position(0, 6),
			Position(1, 7),
			Position(3, 5),
			Position(3, 3),
			Position(1, 3),
			Position(4, 5),
			Position(4, 2),
			Position(1, 2),
			Position(5, 1),
			Position(1, 1),
			Position(6, 0)};
		Assert::IsTrue(AreEqual(expectedMovesVector, whiteQueen->GetPossibleMoves(Position(1, 5))));
	}
};

TEST_CLASS(GetTypeTests)
{
public:

	TEST_METHOD(WhitePawnTest)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Pawn* whitePawn = new Pawn(white, chessBoardPtr);
		Assert::IsTrue(whitePawn->GetType() == pawn);
	}

	TEST_METHOD(WhiteKnightTest)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Knight* whiteKnight = new Knight(white, chessBoardPtr);
		Assert::IsTrue(whiteKnight->GetType() == knight);
	}

};

TEST_CLASS(KingTests)
{
public:

	TEST_METHOD(LongRangeCheckTest1)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Queen* whiteQueen = new Queen(white, chessBoardPtr);
		King* blackKing = new King(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(2, 2), blackKing);
		chessBoardPtr->SetPiecePtr(Position(2, 4), whiteQueen);
		Assert::IsTrue(blackKing->IsCheck(Position(2, 2)));
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

	void KnightCheckTestCaseTrue(Position kingPositon, Position knightPositon)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Knight* whiteKnight = new Knight(white, chessBoardPtr);
		King* blackKing = new King(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(kingPositon, blackKing);
		chessBoardPtr->SetPiecePtr(knightPositon, whiteKnight);
		Assert::IsTrue(blackKing->IsCheck(kingPositon));
	}

	TEST_METHOD(KnightCheckTest1)
	{
		KnightCheckTestCaseTrue(Position(3,3), Position(4, 5));
	}

	TEST_METHOD(KnightCheckTest2)
	{
		KnightCheckTestCaseTrue(Position(3, 3), Position(5, 4));
	}

	TEST_METHOD(KnightCheckTest3)
	{
		KnightCheckTestCaseTrue(Position(3, 3), Position(5, 2));
	}

	TEST_METHOD(KnightCheckTest4)
	{
		KnightCheckTestCaseTrue(Position(3, 3), Position(4, 1));
	}

	TEST_METHOD(KnightCheckTest5)
	{
		KnightCheckTestCaseTrue(Position(3, 3), Position(2, 1));
	}

	TEST_METHOD(KnightCheckTest6)
	{
		KnightCheckTestCaseTrue(Position(3, 3), Position(1, 2));
	}

	TEST_METHOD(KnightCheckTest7)
	{
		KnightCheckTestCaseTrue(Position(3, 3), Position(1, 4));
	}

	TEST_METHOD(KnightCheckTest8)
	{
		KnightCheckTestCaseTrue(Position(3, 3), Position(2, 5));
	}

	void KnightCheckTestCaseFalse(Position kingPositon, Position knightPositon)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Knight* whiteKnight = new Knight(white, chessBoardPtr);
		King* blackKing = new King(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(kingPositon, blackKing);
		chessBoardPtr->SetPiecePtr(knightPositon, whiteKnight);
		Assert::IsFalse(blackKing->IsCheck(kingPositon));
	}

	TEST_METHOD(KnightCheckTest9)
	{
		KnightCheckTestCaseFalse(Position(3, 3), Position(1, 1));
	}

	TEST_METHOD(KnightCheckTest10)
	{
		KnightCheckTestCaseFalse(Position(3, 3), Position(1, 5));
	}

	TEST_METHOD(KnightCheckTest11)
	{
		KnightCheckTestCaseFalse(Position(3, 3), Position(2, 3));
	}

	TEST_METHOD(KnightCheckTest12)
	{
		KnightCheckTestCaseFalse(Position(3, 3), Position(5, 1));
	}
	TEST_METHOD(KnightCheckTest13)
	{
		KnightCheckTestCaseFalse(Position(3, 3), Position(5, 5));
	}

};
