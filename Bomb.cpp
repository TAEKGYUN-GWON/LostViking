#include "stdafx.h"
#include "Bomb.h"
#include "GraphicComponent.h"

void Bomb::Init()
{
}

void Bomb::Init(Vector2 pos)
{
	_name = "Bomb";
	_tag = "Item";

	_trans->pos = pos;
	//_trans->scale = Vector2(100, 100);

	_graphic->Init(false , false);
	_graphic->SetPivot(CENTER);
	_graphic->SetImgName("bomba");
	_trans->scale = Vector2(_graphic->GetGraphic()->GetFrameWidth(),
		_graphic->GetGraphic()->GetFrameHeight());

	_physic = AddComponent<PhysicsBodyComponent>();
	_physic->Init(STATIC, 1);
}

void Bomb::Release()
{
}

void Bomb::Update()
{
	_trans->SetPos(_physic->GetBodyPosition());
}

void Bomb::Ability()
{

}
