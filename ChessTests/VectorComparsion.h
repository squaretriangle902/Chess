#ifndef VECTORCOMPARSION_H
#define VECTORCOMPARSION_H
#include "Pieces.h"
#include "Position.h"
#include <vector>

using namespace std;

bool IncludedInVector(Position position, vector<Position> vector);
bool CompareVector(vector<Position> vector1, vector<Position> vector2);

#endif 