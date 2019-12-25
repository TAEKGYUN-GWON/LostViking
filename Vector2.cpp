#include "stdafx.h"
#include "Vector2.h"
const Vector2 Vector2::zero = Vector2(0, 0);
const Vector2 Vector2::up = Vector2(0, -1);
const Vector2 Vector2::down = Vector2(0, 1);
const Vector2 Vector2::left = Vector2(-1, 0);
const Vector2 Vector2::right = Vector2(1, 0);
const Vector2 Vector2::one = Vector2(1, 1);


Vector2 Vector2::operator-(Vector2 to)
{
	
	return Vector2(x-to.x,y-to.y);
}

Vector2 Vector2::operator+(Vector2 to)
{
	return Vector2(x + to.x, y + to.y);
}

Vector2 Vector2::operator*(float to)
{
	return Vector2(x *to, y*to);
}

Vector2 Vector2::operator/(int to)
{
	return Vector2(x/to,y/to);
}

void Vector2::operator+=(Vector2 to)
{
	x += to.x;
	y += to.y;
}

void Vector2::operator-=(Vector2 to)
{
	x -= to.x;
	y -= to.y;
}

bool Vector2::operator==(Vector2 to)
{
	if (x == to.x && y == to.y)	return true;
	else return false;
}

bool Vector2::operator!=(Vector2 to)
{
	if (x == to.x && y == to.y)	return false;
	else return true;
}

float Vector2::Magnitude()
{
	return sqrt(x * x + y * y);
}

Vector2 Vector2::Nomalized()
{
	Vector2 result;
	float size = Magnitude();

	if (!size)	
		return Vector2::zero;

	result.x /= size;
	result.y /= size;

	return result;
}

float Vector2::SqrMagnitude()
{
	return (x * x + y * y);

}

Vector2 Vector2::RotateToDegree(float angle)
{
	float newX = x * cos(angle*DEGREE) - y * sin(angle*DEGREE);
	float newY = y * cos(angle*DEGREE) + x* sin(angle*DEGREE);

	return Vector2(newX, newY);
}

Vector2 Vector2::RotateToRadian(float angle)
{
	float newX = x * cos(angle) - y * sin(angle);
	float newY = y * cos(angle) + x * sin(angle);

	return Vector2(newX, newY);
}


float Vector2::Distance(Vector2 a, Vector2 b)
{
	float x = b.x - a.x;
	float y = b.y - a.y;

	return sqrtf(x * x + y * y);
}

float Vector2::Dot(Vector2 lhs, Vector2 rhs)
{
	return lhs.x * rhs.x + lhs.y * rhs.y;
}
