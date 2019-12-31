#include "stdafx.h"
#include "Tomato.h"
//#include "TransformComponent.h"
//#include "PhysicsBodyComponent.h"

void Tomato::Init()
{
}

void Tomato::Init(Vector2 pos)
{
	_name = "Tomato";
	_tag  = "Item";

	_trans->pos = pos;
	_trans->scale = Vector2(100, 100);

	_physic = AddComponent<PhysicsBodyComponent>();
	_physic->Init(STATIC, 1);
}

void Tomato::Release()
{
}

void Tomato::Update()
{
	_trans->SetPos(_physic->GetBodyPosition());
}

void Tomato::Ability()
{
	//인벤토리에 토마토에 대한 이미지, 위치값 넘어가야함
	// name 인벤토리에서 
	//또 뭐있지...
}
