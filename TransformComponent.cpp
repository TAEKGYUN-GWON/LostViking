#include "stdafx.h"
#include "TransformComponent.h"

void TransformComponent::Init()
{
	SetRect();
}

void TransformComponent::Update()
{
	SetRect();
}

void TransformComponent::SetRect()
{
	RectMakeCenter(_pos.x, _pos.y, _scale.x, _scale.y);
}
