#include "stdafx.h"
#include "Vector2.h"
const Vector2 Vector2::zero = Vector2(0, 0);
const Vector2 Vector2::up = Vector2(0, -1);
const Vector2 Vector2::down = Vector2(0, 1);
const Vector2 Vector2::left = Vector2(-1, 0);
const Vector2 Vector2::right = Vector2(1, 0);
const Vector2 Vector2::one = Vector2(1, 1);

float Vector2::Magnitude()
{
	return sqrt(x * x + y * y);
}

Vector2 Vector2::Nomalized()
{
	Vector2 result;
	float size = this->Magnitude();

	if (size != 0)
	{
		result.x = x / size;
		result.y = y / size;

	}

	return result;
}

float Vector2::SqrMagnitude()
{
	return (x * x + y * y);

}

float Distance(Vector2 a, Vector2 b)
{
	float x = b.x - a.x;
	float y = b.y - a.y;

	return sqrtf(x * x + y * y);
}

float Dot(Vector2 lhs, Vector2 rhs)
{
	float x = rhs.x - lhs.x;
	float y = rhs.y - lhs.y;

	float distance = sqrtf(x * x + y * y);

	float angle = acosf(x / distance);

	if (rhs.y > lhs.y)
	{
		angle = PI2 - angle;

		if (angle >= PI2) angle -= PI2;
	}

	return 0.0f;
}
