#pragma once
#include "pch.h"
#include "CppUnitTest.h"

#include "ChessBoard.h"
#include "Pieces.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(PawnTests)
{
public:

	TEST_METHOD(PawnGetPossibleMovesTest1)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Piece* whitePawn = new Pawn(white, chessBoardPtr);
		Piece* blackPawn = new Pawn(black, chessBoardPtr);
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
		Assert::IsTrue(CompareVector(possibleMovesVector, whitePawn->GetPossibleMovesInternal(Position(0, 1))));
	}

	TEST_METHOD(PawnGetPossibleMovesTest2)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Piece* whitePawn = new Pawn(white, chessBoardPtr);
		Piece* blackPawn = new Pawn(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(0, 1), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(3, 2), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(5, 1), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(5, 3), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(1, 2), blackPawn);
		chessBoardPtr->SetPiecePtr(Position(4, 4), blackPawn);
		chessBoardPtr->SetPiecePtr(Position(6, 4), blackPawn);
		std::vector<Position> possibleMovesVector;
		possibleMovesVector.push_back(Position(3, 3));
		Assert::IsTrue(CompareVector(possibleMovesVector, whitePawn->GetPossibleMovesInternal(Position(3, 2))));
	}

	TEST_METHOD(PawnGetPossibleMovesTest3)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Piece* whitePawn = new Pawn(white, chessBoardPtr);
		Piece* blackPawn = new Pawn(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(0, 1), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(3, 2), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(5, 1), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(5, 3), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(1, 2), blackPawn);
		chessBoardPtr->SetPiecePtr(Position(4, 4), blackPawn);
		chessBoardPtr->SetPiecePtr(Position(6, 4), blackPawn);
		std::vector<Position> possibleMovesVector;
		possibleMovesVector.push_back(Position(5, 2));
		Assert::IsTrue(CompareVector(possibleMovesVector, whitePawn->GetPossibleMovesInternal(Position(5, 1))));
	}

	TEST_METHOD(PawnGetPossibleMovesTest4)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Piece* whitePawn = new Pawn(white, chessBoardPtr);
		Piece* blackPawn = new Pawn(black, chessBoardPtr);
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
		Assert::IsTrue(CompareVector(possibleMovesVector, whitePawn->GetPossibleMovesInternal(Position(5, 3))));
	}

	TEST_METHOD(PawnGetPossibleMovesTest5)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Piece* whitePawn = new Pawn(white, chessBoardPtr);
		Piece* blackPawn = new Pawn(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(2, 1), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(2, 7), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(2, 2), blackPawn);
		std::vector<Position> possibleMovesVector;
		Assert::IsTrue(CompareVector(possibleMovesVector, whitePawn->GetPossibleMovesInternal(Position(2, 1))));
	}

	TEST_METHOD(PawnGetPossibleMovesTest6)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Piece* whitePawn = new Pawn(white, chessBoardPtr);
		Piece* blackPawn = new Pawn(black, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(2, 1), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(2, 7), whitePawn);
		chessBoardPtr->SetPiecePtr(Position(2, 2), blackPawn);
		std::vector<Position> possibleMovesVector;
		Assert::IsTrue(CompareVector(possibleMovesVector, whitePawn->GetPossibleMovesInternal(Position(2, 7))));
	}

	TEST_METHOD(PawnGetPossibleMovesTest7)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Piece* whitePawn = new Pawn(white, chessBoardPtr);
		Piece* blackPawn = new Pawn(black, chessBoardPtr);
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
		Assert::IsTrue(CompareVector(possibleMovesVector, blackPawn->GetPossibleMovesInternal(Position(1, 3))));
	}

	TEST_METHOD(PawnGetPossibleMovesTest8)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Piece* whitePawn = new Pawn(white, chessBoardPtr);
		Piece* blackPawn = new Pawn(black, chessBoardPtr);
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
		Assert::IsTrue(CompareVector(possibleMovesVector, blackPawn->GetPossibleMovesInternal(Position(2, 6))));
	}

	TEST_METHOD(PawnGetPossibleMovesTest9)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Piece* whitePawn = new Pawn(white, chessBoardPtr);
		Piece* blackPawn = new Pawn(black, chessBoardPtr);
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
		Assert::IsTrue(CompareVector(possibleMovesVector, blackPawn->GetPossibleMovesInternal(Position(4, 6))));
	}

	TEST_METHOD(PawnGetPossibleMovesTest10)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Piece* blackPawn = new Pawn(black, chessBoardPtr);
		Piece* whitePawn = new Pawn(white, chessBoardPtr);
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
		Assert::IsTrue(CompareVector(possibleMovesVector, blackPawn->GetPossibleMovesInternal(Position(5, 6))));
	}

	TEST_METHOD(PawnGetPossibleMovesTest11)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Piece* whitePawn = new Pawn(white, chessBoardPtr);
		Piece* blackPawn = new Pawn(black, chessBoardPtr);
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
		Assert::IsTrue(CompareVector(possibleMovesVector, blackPawn->GetPossibleMovesInternal(Position(6, 6))));
	}

};



