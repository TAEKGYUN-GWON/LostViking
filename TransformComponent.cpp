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
	RectMakeCenter(pos.x, pos.y, scale.x, scale.y);
}
