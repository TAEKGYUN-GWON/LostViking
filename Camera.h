#pragma once
#include "singletonBase.h"

class Camera :public singletonBase<Camera>
{
private:
	D2D1_MATRIX_3X2_F	_matrix;
	Vector2				_scale;
	Vector2				_pos;
	float				_angle;
	float speed;
public:
	Camera() 
	{
		_scale = Vector2(1, 1);
		_pos = Vector2().zero;
		_angle = 0.0f;
		speed = 70.f;
	};
	~Camera() {};

	HRESULT init();
	void Update( );
	//void release();

	void UpdateMatrix();

	//void SetScale(Vector2 scale) { _scale = scale; };
	//void SetAngle(float angle) { _angle = angle; };
	void SetPosition(Vector2 pos);

	Vector2 GetPosition() { return _pos; }

	D2D1_MATRIX_3X2_F GetMatrix() { return _matrix; }
};

