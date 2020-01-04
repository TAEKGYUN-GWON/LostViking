#include "stdafx.h"
#include "Computer.h"
#include "GraphicComponent.h"

void Computer::Init()
{
}

void Computer::Init(Vector2 pos)
{
	_trans->pos = pos;
	_name = "Computer";
	_tag = "Object";
	_graphic->Init(false, false);
	_graphic->SetPivot(CENTER);
	_graphic->SetImgName("computer");
	_trans->scale = Vector2(_graphic->GetGraphic()->GetFrameWidth(),
		_graphic->GetGraphic()->GetFrameHeight());
	_physic = AddComponent<PhysicsBodyComponent>();
	_physic->Init(STATIC, 1, 1.0f, 0.0f, false, true);


}

void Computer::Release()
{

	super::Release();
}

void Computer::Update()
{
	if (hp <= 0) _isActive = false;
	_trans->SetPos(_physic->GetBodyPosition());
	super::Update();
}

void Computer::Ability()
{
}
