#pragma once
#include "pch.h"
#include "CppUnitTest.h"

#include "ChessBoard.h"
#include "Pieces.h"
#include "VectorComparsion.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

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
		std::vector<Position> expectedMovesVector{ Position(1, 6),
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
			Position(6, 0) };
		Assert::IsTrue(CompareVector(expectedMovesVector, whiteQueen->GetPossibleMoves(Position(1, 5))));
	}
};