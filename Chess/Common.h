#pragma once

#include "Position.h"
#include <vector>

using namespace std;

bool IncludedInVector(Position position, vector<Position> vector);
bool CompareVector(vector<Position> vector1, vector<Position> vector2);
Chess::Direction GetDirection(Position position);
Chess::Direction GetDirection(Position firstPosition, Position secondPosition);
vector<Position> Intersection(vector<Position> firstVector, 
	vector<Position> secondVector);
