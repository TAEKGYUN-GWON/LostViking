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
	// _pos�� ��ǥ�� left, top
	//_rc = RectMake(_pos.x, _pos.y, _scale.x, _scale.y);
	
	// _pos�� ��ǥ�� ������ǥ
	_rc = RectMakeCenter(_pos.GetX(), _pos.GetY(), _scale.GetX(), _scale.GetY());
}
