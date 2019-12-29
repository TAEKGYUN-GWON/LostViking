#pragma once

class Vector2
{
public:
	float x;
	float y;


	Vector2():x(0),y(0) {}
	//float값으로 벡터 설정
	Vector2(float x, float y) : x(x), y(y) {}
	//int 값으로 벡터 설정
	Vector2(int x, int y) :x(x), y(y) {}
	template<typename T, typename T2>
	Vector2(T x, T2 y) : x((float)x), y((float)y) {}
	Vector2(POINT pos):x(pos.x),y(pos.y){}
	Vector2(POINTFLOAT pos) :x(pos.x), y(pos.y) {}
	~Vector2() {};

	static Vector2 up;
	static Vector2 down;
	static Vector2 right;
	static Vector2 left;
	static Vector2 zero;
	static Vector2 one;

	static b2Vec2 b2Up;
	static b2Vec2 b2Down;
	static b2Vec2 b2Right;
	static b2Vec2 b2Left;
	static b2Vec2 b2Zero;
	static b2Vec2 b2One;

	static float Distance(Vector2 a, Vector2 b);
	static float Dot(Vector2 lhs, Vector2 rhs);


	float Magnitude();
	Vector2 Nomalized();
	float SqrMagnitude();
	Vector2 RotateToDegree(float angle);
	Vector2 RotateToRadian(float angle);


	Vector2 operator-(Vector2 to);
	Vector2 operator+(Vector2 to);
	Vector2 operator*(float to);
	Vector2 operator/(int to);
	void operator+=(Vector2 to);
	void operator-=(Vector2 to);
	bool operator==(Vector2 to);
	bool operator!=(Vector2 to);
};

