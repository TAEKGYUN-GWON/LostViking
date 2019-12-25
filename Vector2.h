#pragma once
static float Distance(Vector2 a, Vector2 b);
static float Dot(Vector2 lhs, Vector2 rhs);
class Vector2
{
public:
	float x;
	float y;

	float Magnitude();
	Vector2 Nomalized();
	float SqrMagnitude();


	
	Vector2():x(0),y(0) {};
	//float값으로 벡터 설정
	Vector2(float x, float y) : x(x), y(y) {}
	//int 값으로 벡터 설정
	Vector2(int x, int y) :x(x), y(y) {}
	Vector2(POINT pos):x(pos.x),y(pos.y){}
	Vector2(POINTFLOAT pos) :x(pos.x), y(pos.y) {}
	~Vector2() {};

	static const Vector2 up;
	static const Vector2 down;
	static const Vector2 right;
	static const Vector2 left;
	static const Vector2 zero;
	static const Vector2 one;


	inline float GetX() { return x; }
	inline float GetY() { return y; }

	inline void SetX(float x) { this->x = x; }
	inline void SetY(float y) { this->y = y; }
	
	inline Vector2 getPos() { return *this; }
};

