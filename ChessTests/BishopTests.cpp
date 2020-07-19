#pragma once
#include "pch.h"
#include "CppUnitTest.h"

#include "ChessBoard.h"
#include "Pieces.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(BishopTests)
{
public:

	TEST_METHOD(BishopGetPossibleMovesTest1)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Piece* whiteBishop = new Bishop(white, chessBoardPtr);
		Piece* blackBishop = new Bishop(black, chessBoardPtr);
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
		Assert::IsTrue(CompareVector(possibleMovesVector, whiteBishop->GetPossibleMoves(Position(4, 4))));
	}
	TEST_METHOD(BishopGetPossibleMovesTest2)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Piece* whiteBishop = new Bishop(white, chessBoardPtr);
		Piece* blackBishop = new Bishop(black, chessBoardPtr);
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
		Assert::IsTrue(CompareVector(possibleMovesVector, whiteBishop->GetPossibleMoves(Position(1, 1))));
	}

	TEST_METHOD(BishopGetPossibleMovesTest3)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Piece* whiteBishop = new Bishop(white, chessBoardPtr);
		Piece* blackBishop = new Bishop(black, chessBoardPtr);
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
		Assert::IsTrue(CompareVector(possibleMovesVector, blackBishop->GetPossibleMoves(Position(6, 2))));
	}

	TEST_METHOD(BishopGetPossibleMovesTest4)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Piece* whiteBishop = new Bishop(white, chessBoardPtr);
		Piece* blackBishop = new Bishop(black, chessBoardPtr);
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
		Assert::IsTrue(CompareVector(possibleMovesVector, blackBishop->GetPossibleMoves(Position(2, 6))));
	}

	TEST_METHOD(BishopGetPossibleMovesTest5)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Piece* whiteBishop = new Bishop(white, chessBoardPtr);
		Piece* blackBishop = new Bishop(black, chessBoardPtr);
		King* whiteKing = new King(white, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(0, 0), whiteKing);
		chessBoardPtr->SetPiecePtr(Position(2, 2), whiteBishop);
		chessBoardPtr->SetPiecePtr(Position(5, 5), blackBishop);
		std::vector<Position> expectedPossibleMovesVector;
		expectedPossibleMovesVector.push_back(Position(1, 1));
		expectedPossibleMovesVector.push_back(Position(3, 3));
		expectedPossibleMovesVector.push_back(Position(4, 4));
		expectedPossibleMovesVector.push_back(Position(5, 5));
		Assert::IsTrue(CompareVector(expectedPossibleMovesVector, whiteBishop->GetPossibleMoves(Position(2, 2))));
	}

	TEST_METHOD(BishopGetPossibleMovesTest6)
	{
		ChessBoard* chessBoardPtr = new ChessBoard(8);
		Piece* whiteBishop = new Bishop(white, chessBoardPtr);
		Piece* blackRook = new Rook(black, chessBoardPtr);
		Piece* whiteKing = new King(white, chessBoardPtr);
		chessBoardPtr->SetPiecePtr(Position(0, 3), whiteKing);
		chessBoardPtr->SetPiecePtr(Position(2, 3), whiteBishop);
		chessBoardPtr->SetPiecePtr(Position(5, 3), blackRook);
		std::vector<Position> expectedPossibleMovesVector(0);
		Assert::IsTrue(CompareVector(expectedPossibleMovesVector, whiteBishop->GetPossibleMoves(Position(2, 3))));
	}

};