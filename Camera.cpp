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
		_pos += Vector2(-_speed, 0.f) * TIMEMANAGER->getElapsedTime();
		UpdateMatrix();
	}
	else if (KEYMANAGER->isStayKeyDown('D'))
	{
		_pos += Vector2(_speed, 0.f) * TIMEMANAGER->getElapsedTime();
		UpdateMatrix();
	}	

	if (KEYMANAGER->isStayKeyDown('W'))
	{
		_pos += Vector2(0.f,-_speed) * TIMEMANAGER->getElapsedTime();
		UpdateMatrix();

	}
	else if (KEYMANAGER->isStayKeyDown('S'))
	{
		_pos += Vector2(0.f, _speed) * TIMEMANAGER->getElapsedTime();
		UpdateMatrix();
	}

	if (!_isMoving)
	{
		UpdateMatrix();
		return;
	}

	_lerpCount += 1.0f / 60 / _moveTime;
	_pos = Vector2::Lerp(_startPos, _endPos, _lerpCount);

	if (_lerpCount >= 1)
	{
		_isMoving = false;
		_lerpCount = 0;
	}

	UpdateMatrix();
}

void Camera::UpdateMatrix()
{
	_matrix = Matrix3x2F::Identity();
	//_matrix = _matrix * Matrix3x2F::Scale(SizeF(_scale.x, _scale.y));
	//_matrix = _matrix * Matrix3x2F::Translation(-_pos.x,-_pos.y);


	Matrix3x3 * a;
	a = new Matrix3x3(_distance,		0,		0,
						  0,		_distance,  0,
						  0,			0,		1);

	_matrix = _matrix * a->To_D2D1_Matrix_3x2_F() * Matrix3x2F::Translation(-_pos.x, -_pos.y);
}

void Camera::SetPosition(Vector2 pos)
{
	//_pos = pos; 
	_pos.x = pos.x - WINSIZEX / 2;
	_pos.y = pos.y - WINSIZEY / 2;

	UpdateMatrix();
}

void Camera::MoveTo(Vector2 endPos, float time)
{
	_startPos = _pos;
	//_endPos = endPos;
	_endPos.x = endPos.x - WINSIZEX / 2;
	_endPos.y = endPos.y - WINSIZEY / 2;
	_moveTime = time;
	_isMoving = true;
}

bool Camera::IsMoving()
{
	if (_isMoving) return true;
	else return false;
}
