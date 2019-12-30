#include "stdafx.h"
#include "Wall.h"
#include "PhysicsBodyComponent.h"
#include "TransformComponent.h"
#include "GraphicComponent.h"
Wall::Wall()
{
}


Wall::~Wall()
{
}

void Wall::Init()
{
	_trans->SetScale(2757, 100);
	_trans->SetPos(_trans->scale.x/2, 695);
	physics = AddComponent<PhysicsBodyComponent>();
	physics->Init(STATIC, 0.5f);
}
