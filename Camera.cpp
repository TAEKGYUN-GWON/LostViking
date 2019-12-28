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
		_pos += Vector2(-speed, 0.f)* TIMEMANAGER->getElapsedTime();
		UpdateMatrix();
	}
	else if (KEYMANAGER->isStayKeyDown('D'))
	{
		_pos += Vector2(speed, 0.f)* TIMEMANAGER->getElapsedTime();
		UpdateMatrix();
	}	

	if (KEYMANAGER->isStayKeyDown('W'))
	{
		_pos += Vector2(0.f,-speed)* TIMEMANAGER->getElapsedTime();
		UpdateMatrix();

	}
	else if (KEYMANAGER->isStayKeyDown('S'))
	{
		_pos += Vector2(0.f, speed)* TIMEMANAGER->getElapsedTime();
		UpdateMatrix();
	}

}

void Camera::UpdateMatrix()
{
	_matrix = Matrix3x2F::Identity();
//	_matrix = _matrix * Matrix3x2F::Scale(SizeF(_scale.x, _scale.y));
	_matrix = _matrix * Matrix3x2F::Translation(-_pos.x,-_pos.y);

}

void Camera::SetPosition(Vector2 pos)
{
	_pos = pos; 
	UpdateMatrix();
}
