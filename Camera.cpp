#include "stdafx.h"
#include "Camera.h"

HRESULT Camera::init()
{
	_matrix = Matrix3x2F::Scale(SizeF(_scale.x, _scale.y));
	_matrix = _matrix * Matrix3x2F::Rotation(_angle);
	_matrix = _matrix * Matrix3x2F::Translation(_pos.x, _pos.y);

	return S_OK;
}

void Camera::release()
{
}

void Camera::SetMatrix(Vector2 pos)
{
	_matrix = Matrix3x2F::Scale(SizeF(_scale.x, _scale.y));
	_matrix = _matrix * Matrix3x2F::Rotation(_angle);
	_matrix = _matrix * Matrix3x2F::Translation(pos.x, pos.y);
}
