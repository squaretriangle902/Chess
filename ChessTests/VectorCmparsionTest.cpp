#pragma once
#include "pch.h"
#include "CppUnitTest.h"

#include "ChessBoard.h"
#include "Pieces.h"
#include "VectorComparsion.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

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
		std::vector<Position> 
			vector1{ Position(1,1), Position(7,3), Position(5,9) };
		std::vector<Position> 
			vector2{ Position(5,9), Position(7,3), Position(1,1) };
		Assert::AreEqual(true, CompareVector(vector1, vector2));
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
		Assert::IsFalse(CompareVector(vector1, vector2));
	}

	TEST_METHOD(AreEqualTest4)
	{
		std::vector<Position> vector1;
		std::vector<Position> vector2;
		vector1.push_back(Position(3, 3));
		vector2.push_back(Position(3, 3));
		Assert::IsTrue(CompareVector(vector1, vector2));
	}

};