#include "stdafx.h"
#include "Elevator.h"
#include "GraphicComponent.h"

void Elevator::Init()
{
}

void Elevator::Init(Vector2 pos)
{
	_trans->pos = pos;
	_name = "elevator";
	_tag = "Object";
	_graphic->SetPivot(CENTER);
	_graphic->SetImgName("elevator");
	_trans->scale = Vector2(_graphic->GetGraphic()->GetFrameWidth(),
		_graphic->GetGraphic()->GetFrameHeight());
	_physic = AddComponent<PhysicsBodyComponent>();
	_physic->Init(KINEMATIC, 1);

}

void Elevator::Release()
{

	super::Release();
}

void Elevator::Update()
{
	_trans->SetPos(_physic->GetBodyPosition());
	super::Update();
}

void Elevator::Ability()
{
}
