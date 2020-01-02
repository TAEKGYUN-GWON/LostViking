#include "stdafx.h"
#include "Wall.h"
#include "PhysicsBodyComponent.h"
#include "GraphicComponent.h"
Wall::Wall()
{
	_tag = "Wall";
}


Wall::~Wall()
{
}

void Wall::Init()
{
}

void Wall::AddPbody()
{
	_pBody = AddComponent<PhysicsBodyComponent>();
	_pBody->Init(STATIC, 1.f);
}
