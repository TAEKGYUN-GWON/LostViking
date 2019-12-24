#include "stdafx.h"
#include "TransformComponent.h"

TransformComponent::TransformComponent(Object* object)
{
	_object = object;
}


TransformComponent::~TransformComponent()
{
}




void TransformComponent::Update()
{
	// _posÀÇ ÁÂÇ¥°¡ left, top
	//_rc = RectMake(_pos.x, _pos.y, _scale.x, _scale.y);
	
	// _posÀÇ ÁÂÇ¥°¡ ÁßÁ¡ÁÂÇ¥
	_rc = RectMakeCenter(_pos.GetX(), _pos.GetY(), _scale.GetX(), _scale.GetY());
}
