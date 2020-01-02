#include "stdafx.h"
#include "Plasma.h"
#include "GraphicComponent.h"

void Plasma::Init()
{
	
}

void Plasma::Init(Vector2 pos)
{
	
	_trans->pos = pos;
	_name = "Plasma";
	_tag  = "Object";
	_physic = AddComponent<PhysicsBodyComponent>();
	_physic->Init(STATIC, 1);
}

void Plasma::Release()
{

	super::Release();
}

void Plasma::Update()
{
	_trans->SetPos(_physic->GetBodyPosition());
	super::Update();
}

void Plasma::Ability()
{

}
