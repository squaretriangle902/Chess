#pragma once
#include "pch.h"
#include "CppUnitTest.h"
#include "Bishop.cpp"
#include "ChessBoard.cpp"
#include "Piece.cpp"
#include "Knight.cpp"
#include "Pawn.cpp"
#include "Position.cpp"
#include "Chess.cpp"
#include "Rook.cpp"
#include "Bishop.h"
#include "ChessBoard.h"
#include "Color.h"
#include "Direction.h"
#include "Piece.h"
#include "Knight.h"
#include "Pawn.h"
#include "Pieces.h"
#include "Position.h"
#include "Rook.h"
#include "Common.h"
#include "Queen.cpp"
#include "Queen.h"

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
		std::vector<Position> possibleMovesVector;
		possibleMovesVector.push_back(Position(1, 6));
		possibleMovesVector.push_back(Position(2, 6));
		possibleMovesVector.push_back(Position(2, 5));
		possibleMovesVector.push_back(Position(2, 4));
		possibleMovesVector.push_back(Position(1, 4));
		possibleMovesVector.push_back(Position(0, 4));
		possibleMovesVector.push_back(Position(0, 5));
		possibleMovesVector.push_back(Position(0, 6));
		possibleMovesVector.push_back(Position(1, 7));
		possibleMovesVector.push_back(Position(3, 5));
		possibleMovesVector.push_back(Position(3, 3));
		possibleMovesVector.push_back(Position(1, 3));
		possibleMovesVector.push_back(Position(4, 5));
		possibleMovesVector.push_back(Position(4, 2));
		possibleMovesVector.push_back(Position(1, 2));
		possibleMovesVector.push_back(Position(5, 1));
		possibleMovesVector.push_back(Position(1, 1));
		possibleMovesVector.push_back(Position(6, 0));
		Assert::IsTrue(AreEqual(possibleMovesVector, whiteQueen->GetPossibleMoves(Position(1, 5))));
	}
};

//1: (1, 5) (3, 7) (5, 5) 0 : (1, 1)
//(1, 5) -- (1, 6) (2, 6) (2, 5) (2, 4) (1, 4) (0, 4) (0, 5) (0, 6) (1, 7) (3, 5) (3, 3) (1, 3) (4, 5) (4, 2) (1, 2) (5, 1) (1, 1) (6, 0)
