#pragma once
class Vector2
{
public:
	float x;
	float y;
	Vector2() {};
	Vector2(float x, float y) : x(x), y(y) {}
	Vector2(int x, int y) :x(x), y(y) {}

	~Vector2() {};
	inline float GetX() { return x; }
	inline float GetY() { return y; }
	inline void SetX(float x) { this->x = x; }
	inline void SetY(float y) { this->y = y; }
	inline Vector2 getPos() { return *this; }
};

