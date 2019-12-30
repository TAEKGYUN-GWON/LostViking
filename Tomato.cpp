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

}
