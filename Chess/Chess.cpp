// using standard exceptions
#pragma once
#include <iostream>
#include "ChessBoard.h"
#include "Pieces.h"

using namespace std;

int main()
{
	Position position1 = Position(1,2);
	Position position2 = Position(2,3);
	position1 += position2;
}