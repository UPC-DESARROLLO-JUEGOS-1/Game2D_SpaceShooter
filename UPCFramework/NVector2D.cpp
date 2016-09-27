#include "NVector2D.h"

float NVector2D::Length() {
	return sqrt(X * X + Y * Y);
}

NVector2D NVector2D::Direction(NVector2D other)
{
	float length = Length();

	NVector2D* result = new NVector2D(0, 0);
	result->X = (other.X - X) / length;
	result->X = (other.Y - Y) / length;

	return *result;
}

NVector2D NVector2D::Normalize()
{
	float length = Length();
	return NVector2D(X / length, Y / length);
}

NVector2D::~NVector2D()
{
}
