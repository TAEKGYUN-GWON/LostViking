#include "stdafx.h"
#include "Camera.h"

HRESULT Camera::init()
{
	UpdateMatrix();
	return S_OK;
}

void Camera::Update()
{
	if (KEYMANAGER->isStayKeyDown('A'))
	{
		_pos += Vector2(-_speed, 0.f)* TIMEMANAGER->getElapsedTime();
		UpdateMatrix();
	}
	else if (KEYMANAGER->isStayKeyDown('D'))
	{
		_pos += Vector2(_speed, 0.f)* TIMEMANAGER->getElapsedTime();
		UpdateMatrix();
	}	

	if (KEYMANAGER->isStayKeyDown('W'))
	{
		_pos += Vector2(0.f,-_speed)* TIMEMANAGER->getElapsedTime();
		UpdateMatrix();

	}
	else if (KEYMANAGER->isStayKeyDown('S'))
	{
		_pos += Vector2(0.f, _speed)* TIMEMANAGER->getElapsedTime();
		UpdateMatrix();
	}

}

void Camera::UpdateMatrix()
{
	_matrix = Matrix3x2F::Identity();
//	_matrix = _matrix * Matrix3x2F::Scale(SizeF(_scale.x, _scale.y));
	Matrix3x3 scaleMatrix = Matrix3x3(0.3f, 0, 0, 0, 0.3f, 0, 0, 0, 1);
	
	_matrix = _matrix* scaleMatrix.To_D2D1_Matrix_3x2_F() * Matrix3x2F::Translation(-_pos.x,-_pos.y);

}

void Camera::SetPosition(Vector2 pos)
{
	_pos = pos; 
	UpdateMatrix();
}
