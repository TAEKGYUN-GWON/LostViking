#include "stdafx.h"
#include "Meat.h"
#include "TransformComponent.h"
#include "GraphicComponent.h"

void Meat::Init()
{
}

void Meat::Init(Vector2 pos)
{
	GRAPHICMANAGER->AddImage("meat", L"img/object/meat.png");
	_name = "Meat";
	_tag = "Item";
	_trans->pos = pos;
	_graphic->Init(false, false);
	_graphic->SetPivot(CENTER);
	_graphic->SetImgName("meat");
	_trans->scale = Vector2(_graphic->GetGraphic()->GetFrameWidth(),
		_graphic->GetGraphic()->GetFrameHeight());
	_physic = AddComponent<PhysicsBodyComponent>();
	_physic->Init(STATIC, 1, 1.0f, 0.0f, false, true);

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
