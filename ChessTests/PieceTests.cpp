#pragma once
#include "pch.h"
#include "CppUnitTest.h"
#include "ChessBoard.h"
#include "Pieces.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(PieceTests)
{
public:
	TEST_METHOD(WhitePawnGetColorTest)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Pawn* whiteBishop = new Pawn(white, chessBoardPtr);
		Assert::IsTrue(whiteBishop->GetTurn() == white);
	}

	TEST_METHOD(BlackPawnGetColorTest)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Pawn* whiteBishop = new Pawn(black, chessBoardPtr);
		Assert::IsTrue(whiteBishop->GetTurn() == black);
	}

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