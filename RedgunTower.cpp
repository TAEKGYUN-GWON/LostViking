#include "stdafx.h"
#include "RedgunTower.h"

void RedgunTower::Init()
{
}

void RedgunTower::Init(Vector2 pos)
{

	_name = "Tower";
	_tag = "Object";
	_trans->pos = pos;
	
	_physic = AddComponent<PhysicsBodyComponent>();
	_physic->Init(STATIC, 1);
}

void RedgunTower::Release()
{

	super::Release();
}

void RedgunTower::Update()
{
	_trans->SetPos(_physic->GetBodyPosition());
	super::Update();
}

bool RedgunTower::IsBulletFire()
{
	return false;
}
