#include "stdafx.h"
#include "Bomb.h"
#include "GraphicComponent.h"
#include "PhysicsBodyComponent.h"

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
	_physic->Init(STATIC, 1, 1.0f, 0.0f, false, true);
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

void Bomb::IsExplosion(Vector2 pos)
{
	_trans->SetPos(pos);
	_physic->SetBodyPosition();
	_physic->SetBodyActive(true);
	_physic->GetBody()->GetFixtureList()->SetSensor(true);

	//b2PolygonShape shape;
	//Vector2 pSize =_trans->scale + Vector2(30, 30);
	//pSize = PhysicsBodyComponent::Convert(pSize);
	//shape.SetAsBox(pSize.x, pSize.y);

	//b2FixtureDef fixture;
	//fixture.isSensor = false;//충돌함수는 실행하지만 박스를 밀어낼것인가 안밀어내것인가?
	//fixture.shape = &shape;
	//fixture.density = 0;
	//fixture.friction = 0;
	//fixture.restitution = 0;
	//a->GetBody()->CreateFixture(&fixture);

	_timer += TIMEMANAGER->getElapsedTime();

	if (_timer >= 3)
	{
		_isBomb = true;

		_isActive = false;
		_physic->SetBodyActive(false);

	}

}
