#include "stdafx.h"
#include "Meat.h"
#include "GraphicComponent.h"

void Meat::Init()
{
}

void Meat::Init(Vector2 pos)
{
	_name = "Meat";
	_tag = "Item";

	_trans->pos = pos;
	_trans->scale = Vector2(100, 100);

	_physic = AddComponent<PhysicsBodyComponent>();
	_physic->Init(STATIC, 1);

	//_graphic->set

}

void Meat::Release()
{
	
}

void Meat::Update()
{
	_trans->SetPos(_physic->GetBodyPosition());
	
}

void Meat::Ability()
{

}
