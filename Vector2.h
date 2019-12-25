#pragma once

class Vector2
{
public:
	float x;
	float y;

	float Magnitude();
	Vector2 Nomalized();
	float SqrMagnitude();


	
	Vector2():x(0),y(0) {};
	//float������ ���� ����
	Vector2(float x, float y) : x(x), y(y) {}
	//int ������ ���� ����
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

	static float Distance(Vector2 a, Vector2 b);
	static float Dot(Vector2 lhs, Vector2 rhs);
};

