#include "stdafx.h"
#include "RedgunTower.h"
#include "GraphicComponent.h"

void RedgunTower::Init()
{
}

void RedgunTower::Init(Vector2 pos, int frameY)
{
	_tag = "RedgunTower";
	_trans->pos = pos;
	_graphic->Init(true, true);
	_graphic->SetPivot(CENTER);
	_graphic->SetImgName("Tower");
	_graphic->SetFrameY(frameY);
	_graphic->SetFPS(0.3f);
	_trans->scale = Vector2(_graphic->GetGraphic()->GetFrameWidth(),
		_graphic->GetGraphic()->GetFrameHeight());
	_physic = AddComponent<PhysicsBodyComponent>();
	_physic->Init(STATIC, 1);
	_fireCount = 0;
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
	_fireCount += TIMEMANAGER->getElapsedTime();

	if (_fireCount >= 2.0f)
	{
		_fireCount = 0;
		return true;
	}
	
	return false;
}
