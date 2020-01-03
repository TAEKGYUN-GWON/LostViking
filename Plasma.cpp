#include "stdafx.h"
#include "Plasma.h"
#include "GraphicComponent.h"

void Plasma::Init()
{
	
}

void Plasma::Init(Vector2 pos)
{
	
	_trans->pos = pos;
	_tag  = "Plasma";
	_graphic->Init(true, true);
	_graphic->SetPivot(CENTER);
	_graphic->SetImgName("plasma");
	_trans->scale = Vector2(_graphic->GetGraphic()->GetFrameWidth(), 
		_graphic->GetGraphic()->GetFrameHeight());
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
