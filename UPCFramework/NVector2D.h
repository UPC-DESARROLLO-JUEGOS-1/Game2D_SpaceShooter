#pragma once

#include <math.h>

class NVector2D
{
public:
	NVector2D(float x, float y) {
		this->X = x;
		this->Y = y;
	}
	~NVector2D();

	float X, Y;

	float Length();
	NVector2D Direction(NVector2D other);
	NVector2D Normalize();
};

