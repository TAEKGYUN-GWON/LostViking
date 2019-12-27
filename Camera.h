#pragma once

#include "singletonBase.h"
class Camera :public singletonBase<Camera>
{
private:
	D2D1_MATRIX_3X2_F	_matrix;
	Vector2				_scale;
	Vector2				_pos;
	float				_angle;

public:
	Camera() 
	{
		_scale = Vector2(1, 1);
		_pos = Vector2().zero;
		_angle = 0.0f;
	};
	~Camera() {};

	HRESULT init();
	void release();

	void SetScale(Vector2 scale) { _scale = scale; };
	void SetAngle(float angle) { _angle = angle; };
	void SetPosition(Vector2 pos) { _pos = pos; };

	void SetMatrix(Vector2 pos);

	D2D1_MATRIX_3X2_F GetMatrix() { return _matrix; }
};

