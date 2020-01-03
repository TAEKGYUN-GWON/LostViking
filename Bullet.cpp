#include "stdafx.h"
#include "Bullet.h"
#include "TransformComponent.h"
#include "PhysicsBodyComponent.h"
#include "GraphicComponent.h"
#include "bulletScript.h"

void Bullet::Init(string imgKey, string tag, string name)
{
	_tag = tag;
	_name = name;

	_graphic->Init();
	_graphic->SetImgName(imgKey);
	_trans->scale = Vector2(_graphic->GetGraphic()->GetFrameWidth(), _graphic->GetGraphic()->GetFrameHeight());

	_physics = AddComponent<PhysicsBodyComponent>();
	_physics->Init(BodyType::DYNAMIC, 1.0f);

	AddComponent<bulletScript>();

	_physics->GetBody()->SetFixedRotation(true);

	_physics->GetBody()->SetGravityScale(0);
	_physics->GetBody()->SetActive(false);
	_isActive = false;
}

void Bullet::Update()
{
	Move();
	_trans->pos = _physics->GetBodyPosition();

	super::Update();
}

void Bullet::Fire(Vector2 pos, float angle, float speed)
{
	_speed = speed;
	_trans->pos = pos;
	_physics->SetBodyPosition();
	_trans->SetRotateToRadian(angle);
	_physics->SetBodyActive(true);
	_isActive = true;
}

void Bullet::Move()
{
	_physics->GetBody()->SetLinearVelocity(b2Vec2(cosf(_trans->GetRotateRadian()) * _speed,
		-sinf(_trans->GetRotateRadian()) * _speed) * TIMEMANAGER->getElapsedTime());

	if (_trans->pos.x > CAMERA->GetPosition().x + WINSIZEX || _trans->pos.x < CAMERA->GetPosition().x ||
		_trans->pos.y > CAMERA->GetPosition().y + WINSIZEY || _trans->pos.y < CAMERA->GetPosition().y)
	{
		_isActive = false;
	}
}
 