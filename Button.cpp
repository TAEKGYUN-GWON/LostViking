#include "stdafx.h"
#include "Button.h"
#include "GraphicComponent.h"

void Button::Init()
{
}

void Button::Init(Vector2 pos)
{
	_trans->pos = pos;
	_name = "button";
	_tag = "Object";

	_graphic->Init(true, false);
	_graphic->SetPivot(CENTER);


	_graphic->SetFrameX(0);
	_trans->scale = Vector2(_graphic->GetGraphic()->GetFrameWidth(),
		_graphic->GetGraphic()->GetFrameHeight());
	_physic = AddComponent<PhysicsBodyComponent>();
	_physic->Init(STATIC, 1);

	 
}

void Button::Release()
{

	super::Release();
}

void Button::Update()
{
	_trans->SetPos(_physic->GetBodyPosition());
	super::Update();
}

void Button::Ability()
{
}
