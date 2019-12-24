#pragma once
class Vector2
{
	float _x;
	float _y;
public:
	Vector2() {};
	Vector2(float x, float y) :_x(x), _y(y) {}
	Vector2(int x, int y) :_x(x), _y(y) {}
	~Vector2() {};
	inline float GetX() { return _x; }
	inline float GetY() { return _y; }
	inline void SetX(float x) { _x = x; }
	inline void SetY(float y) { _y = y; }
	inline Vector2 getPos() { return *this; }
};

