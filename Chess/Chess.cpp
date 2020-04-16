// using standard exceptions
#pragma once
#include <iostream>
#include "ChessBoard.h"
#include "Pieces.h"
#include "Chess.h"

using namespace std;

int main()
{
	int i = 6;
	int j = 5;
	NewFunction(i, j);
	Position position = Position(1, 1);
	position += Position(2, 2);
}

void NewFunction(int& i, int j)
{
	i = j + 6;
}
