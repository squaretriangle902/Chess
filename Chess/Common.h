#pragma once

#include "Pieces.h"
#include "Position.h"
#include <vector>

using namespace std;

bool IncludedInVector(Position position, vector<Position> vector);
bool CompareVector(vector<Position> vector1, vector<Position> vector2);
bool TryGetDirection(Chess::Direction& direction, Position position);
vector<Position> Intersection(vector<Position> firstVector, 
	vector<Position> secondVector);
